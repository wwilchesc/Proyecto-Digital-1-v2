# I2C (EEPROM de puntajes)

> **Estado: especificación preliminar (checkpoint 1).** Los registros y diagramas pueden cambiar en el checkpoint 2 (ASM). Todo cambio que afecte a otros equipos se acuerda por *issue* en el repositorio general.

| | |
|---|---|
| **Equipo responsable** | Grupo H — I2C (EEPROM de puntajes) (ver [`planificacion/equipos.md`](../../planificacion/equipos.md)) |
| **Región de memoria** | `0x460000 – 0x46FFFF` |
| **Archivo RTL** | `cores/i2c/rtl/perip_i2c.v` |

## Función

Guardar y leer los puntajes más altos (top 5 con nombre) en una EEPROM I2C para que no se pierdan al apagar, y comprobar al encender que los elementos I2C responden.

## Protocolo

I2C maestro a 100 kHz. EEPROM de referencia 24LC256 (dirección 0x50). Escritura: START, 0xA0, dirección alta, dirección baja, dato, STOP. Lectura aleatoria: escritura de dirección, START repetido, 0xA1, dato, NACK, STOP.

**Pines externos:** `i2c_scl`, `i2c_sda` (colector abierto con pull-up).

## Interfaz con el bus (igual para todos los periféricos)

```verilog
module perip_i2c (
    input  wire        clk,
    input  wire        rst,
    input  wire [31:0] d_in,    // dato que escribe la CPU
    input  wire        cs,      // selección desde el decodificador de direcciones
    input  wire [4:0]  addr,    // desplazamiento local (ancho según el número de registros)
    input  wire        rd,
    input  wire        wr,
    output reg  [31:0] d_out    // dato que lee la CPU
    // + pines externos del protocolo
);
```

## Registros CSR (preliminar)

Direcciones relativas a la base de la región. Todos los registros son de 32 bits.

| Desplazamiento | Nombre | Acceso | Descripción |
|---|---|---|---|
| `0x00` | `CONTROL` | R/W | Bit 0 `START`, bit 1 `STOP`, bit 2 `WRITE`, bit 3 `READ`, bit 4 `ACK_OUT` (ACK a enviar tras leer). |
| `0x04` | `TX_DATA` | R/W | Byte a enviar. |
| `0x08` | `RX_DATA` | R | Byte recibido. |
| `0x0C` | `STATUS` | R | Bit 0 `BUSY`. Bit 1 `ACK_IN`: 0 = el esclavo respondió ACK. Bit 2 `DONE`. |
| `0x10` | `CLK_DIV` | R/W | Divisor para generar SCL. |

## Diseño

- Diagramas de bloques y de flujo: [`diagramas/`](diagramas/README.md)
- Estados previstos: `IDLE`, `START`, `BIT` (contador 0–7), `ACK`, `STOP`, cada uno dividido en fases del reloj SCL. El firmware arma la secuencia completa de la EEPROM con estas órdenes básicas.

## Plan de verificación (checkpoint 3)

Cada prueba del testbench imprime `PASS` o `FAIL` y declara estímulo, resultado esperado y criterio de aprobación.

1. Modelo de EEPROM en el testbench: escribir 0x3C en la dirección 0x0010 y leerlo de vuelta.
2. Verificar las condiciones START y STOP en la forma de onda.
3. Caso de error: dirección de esclavo incorrecta → `ACK_IN=1` (NACK).

## Firmware previsto

Funciones del driver en `firmware/`: `i2c_start()`, `i2c_write(byte)`, `i2c_read(ack)`, `i2c_stop()`, `eeprom_write(addr, byte)`, `eeprom_read(addr)`, `score_save()`, `score_load()`.

## Avance

| Checkpoint | Entregable | Estado |
|---|---|---|
| 1 | Flowchart + registros CSR | 🟡 en desarrollo (este documento) |
| 2 | ASM del datapath y del control | ⚪ pendiente |
| 3 | RTL + testbench (`make sim`) | ⚪ pendiente |
| 4 | Integración en la FPGA | ⚪ pendiente |
| 5 | Demo final | ⚪ pendiente |
