# Control NES

> **Estado: especificación preliminar (checkpoint 1).** Los registros y diagramas pueden cambiar en el checkpoint 2 (ASM). Todo cambio que afecte a otros equipos se acuerda por *issue* en el repositorio general.

| | |
|---|---|
| **Equipo responsable** | Grupo 4 — Control NES y pantalla |
| **Responsable del RTL** | G4-A (ver [`planificacion/equipos.md`](../../planificacion/equipos.md)) |
| **Región de memoria** | `0x450000 – 0x45FFFF` |
| **Archivo RTL** | `cores/nes_ctrl/rtl/perip_nes.v` |

## Función

Leer los 8 botones de uno o dos controles tipo NES para jugar.

## Protocolo

Registro de desplazamiento 4021 dentro del control: pulso `LATCH` (12 µs) captura los botones; luego 8 pulsos de `CLK` (6 µs) sacan los bits por `DATA` en orden A, B, Select, Start, Arriba, Abajo, Izquierda, Derecha. Activos en bajo. Lectura automática a ~60 Hz.

**Pines externos:** `nes_latch`, `nes_clk` (salidas compartidas), `nes_data1`, `nes_data2` (entradas con pull-up).

## Interfaz con el bus (igual para todos los periféricos)

```verilog
module perip_nes (
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

Direcciones relativas a `0x450000`. Todos los registros son de 32 bits.

| Desplazamiento | Nombre | Acceso | Descripción |
|---|---|---|---|
| `0x00` | `BUTTONS_P1` | R | Bits 7:0 del jugador 1 (1 = presionado). |
| `0x04` | `BUTTONS_P2` | R | Bits 7:0 del jugador 2. |
| `0x08` | `CONTROL` | R/W | Bit 0 `ENABLE`: lectura automática. |
| `0x0C` | `POLL_DIV` | R/W | Ciclos de reloj entre lecturas (≈ f_clk / 60). |

## Diseño

- Diagramas de bloques y de flujo: [`diagramas/`](diagramas/README.md)
- Estados previstos: `IDLE`, `LATCH`, `READ`, `SHIFT`, `DONE`. Datapath: divisor de tiempo, contador de bits (0–7), dos registros de desplazamiento.

## Plan de verificación (checkpoint 3)

Cada prueba del testbench imprime `PASS` o `FAIL` y declara estímulo, resultado esperado y criterio de aprobación.

1. Modelo del 4021 en el testbench con Start y Derecha presionados → `BUTTONS_P1 = 0x88` (según el orden de bits documentado).
2. Verificar anchos de `LATCH` y `CLK` en la forma de onda.
3. Caso límite: sin control conectado (DATA siempre 1 por el pull-up) → `BUTTONS = 0x00`.

## Firmware previsto

Funciones del driver en `firmware/`: `nes_read(player)`, macros `NES_A`, `NES_B`, `NES_START`, `NES_UP`…

## Avance

| Checkpoint | Entregable | Estado |
|---|---|---|
| 1 | Flowchart + registros CSR | 🟡 en desarrollo (este documento) |
| 2 | ASM del datapath y del control | ⚪ pendiente |
| 3 | RTL + testbench (`make sim`) | ⚪ pendiente |
| 4 | Integración en la FPGA | ⚪ pendiente |
| 5 | Demo final | ⚪ pendiente |
