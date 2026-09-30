# I2S (audio)

> **Estado: especificación preliminar (checkpoint 1).** Los registros y diagramas pueden cambiar en el checkpoint 2 (ASM). Todo cambio que afecte a otros equipos se acuerda por *issue* en el repositorio general.

| | |
|---|---|
| **Equipo responsable** | Grupo 6 — I2S y audio |
| **Responsable del RTL** | G6-A (ver [`planificacion/equipos.md`](../../planificacion/equipos.md)) |
| **Región de memoria** | `0x470000 – 0x47FFFF` |
| **Archivo RTL** | `cores/i2s/rtl/perip_i2s.v` |

## Función

Enviar muestras de audio a un DAC I2S para reproducir efectos de sonido y música del juego.

## Protocolo

I2S maestro: `BCLK`, `LRCLK` (selección de canal) y `SDATA`, 16 bits por canal, MSB primero, con un ciclo de retardo tras el cambio de LRCLK. DAC de referencia: MAX98357A o PCM5102. Frecuencia de muestreo objetivo: 22.05 kHz o 44.1 kHz.

**Pines externos:** `i2s_bclk`, `i2s_lrclk`, `i2s_sdata`.

## Interfaz con el bus (igual para todos los periféricos)

```verilog
module perip_i2s (
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

Direcciones relativas a `0x470000`. Todos los registros son de 32 bits.

| Desplazamiento | Nombre | Acceso | Descripción |
|---|---|---|---|
| `0x00` | `CONTROL` | R/W | Bit 0 `ENABLE`. Bit 1 `MODE`: 0 = FIFO, 1 = generador de tono. |
| `0x04` | `SAMPLE` | W | Muestra estéreo: bits 31:16 izquierdo, 15:0 derecho. Entra a la FIFO. |
| `0x08` | `STATUS` | R | Bit 0 `FIFO_FULL`. Bit 1 `FIFO_EMPTY`. Bit 2 `UNDERRUN`. |
| `0x0C` | `CLK_DIV` | R/W | Divisor para BCLK. |
| `0x10` | `TONE` | R/W | Período del generador de tono cuadrado (para efectos simples sin cargar la CPU). |

## Diseño

- Diagramas de bloques y de flujo: [`diagramas/`](diagramas/README.md)
- Estados previstos: Contador de bits (0–31) que genera BCLK/LRCLK; registro de desplazamiento de 32 bits; FIFO de muestras; generador de tono opcional.

## Plan de verificación (checkpoint 3)

Cada prueba del testbench imprime `PASS` o `FAIL` y declara estímulo, resultado esperado y criterio de aprobación.

1. Escribir la muestra 0x8001_7FFE y verificar la serialización en SDATA respecto a LRCLK.
2. Verificar la frecuencia de LRCLK con el divisor configurado.
3. Caso límite: FIFO vacía → salida en 0 y `UNDERRUN=1`; FIFO llena → `FIFO_FULL=1`.

## Firmware previsto

Funciones del driver en `firmware/`: `i2s_init(div)`, `i2s_push(left, right)`, `sound_beep(freq, ms)`, `sound_effect(id)`.

## Avance

| Checkpoint | Entregable | Estado |
|---|---|---|
| 1 | Flowchart + registros CSR | 🟡 en desarrollo (este documento) |
| 2 | ASM del datapath y del control | ⚪ pendiente |
| 3 | RTL + testbench (`make sim`) | ⚪ pendiente |
| 4 | Integración en la FPGA | ⚪ pendiente |
| 5 | Demo final | ⚪ pendiente |
