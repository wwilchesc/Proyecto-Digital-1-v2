# UART (depuración)

> **Estado: especificación preliminar (checkpoint 1).** Los registros y diagramas pueden cambiar en el checkpoint 2 (ASM). Todo cambio que afecte a otros equipos se acuerda por *issue* en el repositorio general.

| | |
|---|---|
| **Equipo responsable** | Grupo 1 — Integración, SoC y UART |
| **Responsable del RTL** | G1-B (ver [`planificacion/equipos.md`](../../planificacion/equipos.md)) |
| **Región de memoria** | `0x400000 – 0x40FFFF` |
| **Archivo RTL** | `cores/uart/rtl/perip_uart.v` |

## Función

Enviar y recibir bytes por el puerto serie entre la FPGA y el PC. Se usa para imprimir mensajes de depuración (`printf`) y reportar el resultado de las pruebas de arranque.

## Protocolo

UART asíncrono 8N1 (1 bit de inicio, 8 de datos, sin paridad, 1 de parada). Velocidad objetivo: 115200 baudios. El divisor de baudios es configurable por CSR.

**Pines externos:** `uart_tx` (salida), `uart_rx` (entrada).

## Interfaz con el bus (igual para todos los periféricos)

```verilog
module perip_uart (
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

Direcciones relativas a `0x400000`. Todos los registros son de 32 bits.

| Desplazamiento | Nombre | Acceso | Descripción |
|---|---|---|---|
| `0x00` | `TX_DATA` | W | Escribir un byte inicia la transmisión (bits 7:0). |
| `0x04` | `RX_DATA` | R | Último byte recibido (bits 7:0). Leerlo limpia `STATUS.RX_VALID`. |
| `0x08` | `STATUS` | R | Bit 0 `TX_BUSY`: transmisión en curso. Bit 1 `RX_VALID`: hay un byte sin leer. Bit 2 `RX_OVERRUN`: llegó un byte sin haber leído el anterior. |
| `0x0C` | `BAUD_DIV` | R/W | Ciclos de reloj por bit (ej. 50 MHz / 115200 ≈ 434). |

## Diseño

- Diagramas de bloques y de flujo: [`diagramas/`](diagramas/README.md)
- Estados previstos: `IDLE`, `START`, `DATA` (contador de 8 bits), `STOP` — una máquina para TX y otra para RX.

## Plan de verificación (checkpoint 3)

Cada prueba del testbench imprime `PASS` o `FAIL` y declara estímulo, resultado esperado y criterio de aprobación.

1. Enviar 0x55 y 0xA3; comparar la trama serializada con la esperada bit a bit.
2. Recibir un byte generado por el testbench y verificar `RX_DATA` y `RX_VALID`.
3. Caso límite: dos bytes seguidos sin leer → `RX_OVERRUN=1`.

## Firmware previsto

Funciones del driver en `firmware/`: `uart_putc()`, `uart_getc()`, `uart_puts()`, `uart_init(baud_div)`.

## Avance

| Checkpoint | Entregable | Estado |
|---|---|---|
| 1 | Flowchart + registros CSR | 🟡 en desarrollo (este documento) |
| 2 | ASM del datapath y del control | ⚪ pendiente |
| 3 | RTL + testbench (`make sim`) | ⚪ pendiente |
| 4 | Integración en la FPGA | ⚪ pendiente |
| 5 | Demo final | ⚪ pendiente |
