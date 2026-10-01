# Pantallas RGB e indicadores LED de puerto

> **Estado: especificación preliminar (checkpoint 1).** Los registros y diagramas pueden cambiar en el checkpoint 2 (ASM). Todo cambio que afecte a otros equipos se acuerda por *issue* en el repositorio general.

| | |
|---|---|
| **Equipo responsable** | Grupo L — Pantallas RGB e indicadores (ver [`planificacion/equipos.md`](../../planificacion/equipos.md)) |
| **Región de memoria** | por asignar (propuesta 0x510000) |
| **Archivo RTL** | `cores/indicadores/rtl/perip_indicadores.v` |

## Función

Encender el LED RGB de cada puerto según el tipo de control conectado (NES, teclado o mouse) y manejar las pantallas RGB laterales; mostrar el patrón de error («ERR» o «X») cuando el sistema lo pida (*Ac. Indicador*).

## Protocolo

Matriz de LED 8×32 con MAX7219 por SPI (`CS`, `DIN`, `CLK`): se inicializan los registros Shutdown, Decode, ScanLimit e Intensity y luego se envían 64 bits por fila.

**Pines externos:** `max_cs`, `max_din`, `max_clk`, LEDs RGB de puerto (`led_p1_rgb[2:0]`, `led_p2_rgb[2:0]`).

## Interfaz con el bus (igual para todos los periféricos)

```verilog
module perip_indicadores (
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
| `0x00` | `CONTROL` | R/W | Bit 0 `INIT`: inicializa el MAX7219. Bit 1 `ERROR`: activa el parpadeo del patrón de falla. |
| `0x04` | `LED_PUERTO_1` | R/W | Color RGB del LED del puerto 1 (bits 2:0). |
| `0x08` | `LED_PUERTO_2` | R/W | Color RGB del LED del puerto 2 (bits 2:0). |
| `0x0C` | `PATRON` | R/W | Selección del patrón a mostrar (0 = limpio, 1 = ERR, 2 = X). |
| `0x10` | `STATUS` | R | Bit 0 `BUSY`: envío SPI en curso. |

## Diseño

- Diagramas de bloques y de flujo: [`diagramas/`](diagramas/README.md)
- Estados previstos: `INIT`, `LOAD`, `SHOW` (500 ms), `OFF` (500 ms), `CLEAR`. Datapath: maestro SPI de 16 bits, buffer de 8×32 y temporizador de 500 ms.

## Plan de verificación (checkpoint 3)

Cada prueba del testbench imprime `PASS` o `FAIL` y declara estímulo, resultado esperado y criterio de aprobación.

1. Verificar la trama SPI de inicialización (registros Shutdown, Decode, ScanLimit, Intensity).
2. Activar `ERROR` y comprobar en la forma de onda el parpadeo cada 500 ms.
3. Escribir colores en `LED_PUERTO_1/2` y verificar las salidas RGB.

## Firmware previsto

Funciones del driver en `firmware/`: `ind_init()`, `ind_port_led(port, rgb)`, `ind_error(on)`.

## Avance

| Checkpoint | Entregable | Estado |
|---|---|---|
| 1 | Flowchart + registros CSR | 🟡 en desarrollo (este documento) |
| 2 | ASM del datapath y del control | ⚪ pendiente |
| 3 | RTL + testbench (`make sim`) | ⚪ pendiente |
| 4 | Integración en la FPGA | ⚪ pendiente |
| 5 | Demo final | ⚪ pendiente |
