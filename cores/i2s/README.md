# I2S (audio)

> **Estado: especificación preliminar (checkpoint 1).** Los registros y diagramas pueden cambiar en el checkpoint 2 (ASM). Todo cambio que afecte a otros equipos se acuerda por *issue* en el repositorio general.

| | |
|---|---|
| **Equipo responsable** | Grupo I — I2S (audio) (ver [`planificacion/equipos.md`](../../planificacion/equipos.md)) |
| **Región de memoria** | `0x470000 – 0x47FFFF` |
| **Archivo RTL** | `cores/i2s/rtl/perip_i2s.v` |

## Función

Reproducir los sonidos del juego (inicio, menú, daño, recompensa) a partir de archivos .WAV, enviándolos a un DAC por I2S.

## Protocolo

I2S maestro: `BCLK`, `LRCLK` (selección de canal) y `SDATA`. Se leen los metadatos del .WAV; si es estéreo se usa un solo canal. Por cada muestra se cambia `LRCLK` y se envían 8 bits al DAC, un bit por pulso de `BCLK`. DAC de referencia: MAX98357A o PCM5102.

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

Direcciones relativas a la base de la región. Todos los registros son de 32 bits.

| Desplazamiento | Nombre | Acceso | Descripción |
|---|---|---|---|
| `0x00` | `CONTROL` | R/W | Bit 0 `ENABLE`. Bit 1 `PLAY`: inicia la reproducción. |
| `0x04` | `SAMPLE` | W | Muestra de audio de 8 bits (bits 7:0). Entra a la FIFO. |
| `0x08` | `STATUS` | R | Bit 0 `FIFO_FULL`. Bit 1 `FIFO_EMPTY`. Bit 2 `FIN`: terminó el archivo. |
| `0x0C` | `CLK_DIV` | R/W | Divisor para generar BCLK. |

## Diseño

- Diagramas de bloques y de flujo: [`diagramas/`](diagramas/README.md)
- Estados previstos: Contador de bits (0–7) que genera BCLK/LRCLK, registro de desplazamiento de 8 bits y FIFO de muestras.

## Tareas iniciales del grupo (I2S_1)

1. Diseñar una solución que implemente el protocolo I2S y reproduzca la información de archivos .WAV.
2. Encontrar los archivos .WAV que se usarán en el inicio y en el menú del juego.

## Plan de verificación (checkpoint 3)

Cada prueba del testbench imprime `PASS` o `FAIL` y declara estímulo, resultado esperado y criterio de aprobación.

1. Escribir la muestra 0xA5 y verificar la serialización en SDATA respecto a LRCLK y BCLK.
2. Verificar la frecuencia de LRCLK con el divisor configurado.
3. Caso límite: FIFO vacía al terminar el archivo → `FIN=1` y salida en 0.

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
