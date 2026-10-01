# Teclado PS/2

> **Estado: especificación preliminar (checkpoint 1).** Los registros y diagramas pueden cambiar en el checkpoint 2 (ASM). Todo cambio que afecte a otros equipos se acuerda por *issue* en el repositorio general.

| | |
|---|---|
| **Equipo responsable** | Grupo E — Teclado PS/2 (ver [`planificacion/equipos.md`](../../planificacion/equipos.md)) |
| **Región de memoria** | `0x430000 – 0x43FFFF` |
| **Archivo RTL** | `cores/ps2_keyboard/rtl/perip_ps2kbd.v` |

## Función

Recibir las teclas presionadas en un teclado PS/2 para controlar el juego y navegar el menú.

## Protocolo

PS/2 dispositivo→host: el teclado genera el reloj (10–16.7 kHz). Trama de 11 bits: inicio (0), 8 datos LSB primero, paridad impar, parada (1). Scan codes set 2; `0xF0` = tecla liberada, `0xE0` = tecla extendida.

**Pines externos:** `ps2_clk`, `ps2_data` (colector abierto con pull-up).

## Interfaz con el bus (igual para todos los periféricos)

```verilog
module perip_ps2kbd (
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
| `0x00` | `DATA` | R | Siguiente scan code de la FIFO (bits 7:0). Leer lo saca de la FIFO. |
| `0x04` | `STATUS` | R | Bit 0 `VALID`: FIFO no vacía. Bit 1 `PARITY_ERR`. Bit 2 `OVERFLOW`: FIFO llena, se perdió un código. |
| `0x08` | `CONTROL` | R/W | Bit 0 `ENABLE`. Bit 1 `CLEAR`: vacía la FIFO y limpia errores. |

## Diseño

- Diagramas de bloques y de flujo: [`diagramas/`](diagramas/README.md)
- Estados previstos: `IDLE`, `DATA` (contador 0–7), `PARITY`, `STOP`. Datapath: sincronizador de 2 flip-flops, filtro del reloj PS/2, registro de desplazamiento, FIFO de 8–16 posiciones.

## Teclas relevantes (comando común)

Solo estas teclas se traducen al comando común que usa el software de juegos (Grupo K); las demás se ignoran.

| Tecla | Comando |
|---|---|
| `W` / `A` / `S` / `D` | Arriba / Izquierda / Abajo / Derecha |
| `J` | A |
| `K` | B |
| `Enter` | Start |
| `Espacio` | Select |

## Plan de verificación (checkpoint 3)

Cada prueba del testbench imprime `PASS` o `FAIL` y declara estímulo, resultado esperado y criterio de aprobación.

1. El testbench genera la trama de la tecla `A` (0x1C) y su liberación (0xF0, 0x1C); verificar la FIFO.
2. Paridad incorrecta → `PARITY_ERR=1` y el código no entra a la FIFO.
3. Enviar más códigos que la capacidad de la FIFO → `OVERFLOW=1`.

## Firmware previsto

Funciones del driver en `firmware/`: `kbd_available()`, `kbd_read_scancode()`, `kbd_get_key()` (traduce scan codes a teclas del juego: flechas, espacio, enter).

## Avance

| Checkpoint | Entregable | Estado |
|---|---|---|
| 1 | Flowchart + registros CSR | 🟡 en desarrollo (este documento) |
| 2 | ASM del datapath y del control | ⚪ pendiente |
| 3 | RTL + testbench (`make sim`) | ⚪ pendiente |
| 4 | Integración en la FPGA | ⚪ pendiente |
| 5 | Demo final | ⚪ pendiente |
