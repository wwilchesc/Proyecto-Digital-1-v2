# Display (panel LED / framebuffer)

> **Estado: especificación preliminar (checkpoint 1).** Los registros y diagramas pueden cambiar en el checkpoint 2 (ASM). Todo cambio que afecte a otros equipos se acuerda por *issue* en el repositorio general.

| | |
|---|---|
| **Equipo responsable** | Grupo J — Display (ver [`planificacion/equipos.md`](../../planificacion/equipos.md)) |
| **Región de memoria** | `0x480000 – 0x4FFFFF` |
| **Archivo RTL** | `cores/display/rtl/perip_display.v` |

## Función

Mostrar en el panel LED lo que el software de juegos (Grupo K) pide en cada frame: menú, paneles de juegos, avisos, errores y el juego.

## Protocolo

Framebuffer de 512 KB mapeado en memoria. El driver del panel (WS2812 o HUB75 64×64/32×32, según lo que defina el curso) recorre el framebuffer y refresca el panel.

**Pines externos:** Según el panel: `ws2812_dout`, o las líneas HUB75 (`R1 G1 B1 R2 G2 B2`, `A–E`, `CLK`, `LAT`, `OE`).

## Interfaz con el bus (igual para todos los periféricos)

```verilog
module perip_display (
    input  wire        clk,
    input  wire        rst,
    input  wire [31:0] d_in,    // dato que escribe la CPU
    input  wire        cs,      // selección desde el decodificador de direcciones
    input  wire [18:0] addr,    // desplazamiento dentro del framebuffer (512 KB)
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
| `0x00000 – 0x7FFFF` | `FRAMEBUFFER` | R/W | Un píxel por palabra (formato de color por definir con el Grupo K). |

## Diseño

- Diagramas de bloques y de flujo: [`diagramas/`](diagramas/README.md)
- Estados previstos: Contador de filas y columnas que recorre el framebuffer y la máquina de envío al panel (según el tipo de panel).

## Plan de verificación (checkpoint 3)

Cada prueba del testbench imprime `PASS` o `FAIL` y declara estímulo, resultado esperado y criterio de aprobación.

1. Escribir un patrón conocido en el framebuffer y verificar el orden de los datos que salen al panel.
2. Verificar el tiempo de refresco de un frame completo.
3. Caso límite: escribir en la última dirección del framebuffer.

## Firmware previsto

Funciones del driver en `firmware/`: `display_clear()`, `display_pixel(x, y, color)`, `display_draw(sprite, x, y)`, `display_text(x, y, str)`.

## Avance

| Checkpoint | Entregable | Estado |
|---|---|---|
| 1 | Flowchart + registros CSR | 🟡 en desarrollo (este documento) |
| 2 | ASM del datapath y del control | ⚪ pendiente |
| 3 | RTL + testbench (`make sim`) | ⚪ pendiente |
| 4 | Integración en la FPGA | ⚪ pendiente |
| 5 | Demo final | ⚪ pendiente |
