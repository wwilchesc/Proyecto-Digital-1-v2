# SPI-RAM

> **Estado: especificación preliminar (checkpoint 1).** Los registros y diagramas pueden cambiar en el checkpoint 2 (ASM). Todo cambio que afecte a otros equipos se acuerda por *issue* en el repositorio general.

| | |
|---|---|
| **Equipo responsable** | Grupo 2 — Memoria externa SPI |
| **Responsable del RTL** | G2-A (ver [`planificacion/equipos.md`](../../planificacion/equipos.md)) |
| **Región de memoria** | `0x410000 – 0x41FFFF` |
| **Archivo RTL** | `cores/spiram/rtl/perip_spiram.v` |

## Función

Leer y escribir una memoria RAM externa por SPI para guardar datos del juego que no caben en la BRAM (niveles, sprites, buffers).

## Protocolo

SPI modo 0 (CPOL=0, CPHA=0), 8 bits por transferencia. Chip de referencia: SRAM serial tipo 23LC1024 (128 KB). Comandos: `0x03` READ, `0x02` WRITE, `0x01` WRMR (modo secuencial). Dirección de 24 bits.

**Pines externos:** `spi_sck`, `spi_mosi`, `spi_miso`, `ram_cs_n`.

## Interfaz con el bus (igual para todos los periféricos)

```verilog
module perip_spiram (
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

Direcciones relativas a `0x410000`. Todos los registros son de 32 bits.

| Desplazamiento | Nombre | Acceso | Descripción |
|---|---|---|---|
| `0x00` | `CONTROL` | R/W | Bit 0 `START`: inicia la operación. Bit 1 `RW`: 0 = leer, 1 = escribir. |
| `0x04` | `ADDR` | R/W | Dirección de 24 bits dentro de la SPI-RAM. |
| `0x08` | `WDATA` | R/W | Byte a escribir (bits 7:0). |
| `0x0C` | `RDATA` | R | Byte leído (bits 7:0). |
| `0x10` | `STATUS` | R | Bit 0 `BUSY`: transferencia en curso. Bit 1 `DONE`: terminó la última operación. |
| `0x14` | `CLK_DIV` | R/W | Divisor del reloj SPI (f_sck = f_clk / (2·(CLK_DIV+1))). |

## Diseño

- Diagramas de bloques y de flujo: [`diagramas/`](diagramas/README.md)
- Estados previstos: `IDLE`, `CMD`, `ADDR`, `DATA`, `DONE`. Datapath: registro de desplazamiento de 8 bits + contador de bits + divisor de reloj.

## Plan de verificación (checkpoint 3)

Cada prueba del testbench imprime `PASS` o `FAIL` y declara estímulo, resultado esperado y criterio de aprobación.

1. Escribir 0xA5 en la dirección 0x000010 y leerla de vuelta con un modelo SPI de la memoria en el testbench.
2. Verificar la trama exacta: comando, 3 bytes de dirección y dato en MOSI.
3. Caso límite: dirección máxima 0x01FFFF; escritura con `BUSY=1` debe ignorarse.

## Firmware previsto

Funciones del driver en `firmware/`: `spiram_write(addr, byte)`, `spiram_read(addr)`, `spiram_test()` (patrón de escritura/lectura para la prueba de arranque).

## Avance

| Checkpoint | Entregable | Estado |
|---|---|---|
| 1 | Flowchart + registros CSR | 🟡 en desarrollo (este documento) |
| 2 | ASM del datapath y del control | ⚪ pendiente |
| 3 | RTL + testbench (`make sim`) | ⚪ pendiente |
| 4 | Integración en la FPGA | ⚪ pendiente |
| 5 | Demo final | ⚪ pendiente |
