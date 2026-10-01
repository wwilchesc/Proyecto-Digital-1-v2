# SPI-Flash

> **Estado: especificación preliminar (checkpoint 1).** Los registros y diagramas pueden cambiar en el checkpoint 2 (ASM). Todo cambio que afecte a otros equipos se acuerda por *issue* en el repositorio general.

| | |
|---|---|
| **Equipo responsable** | Grupo D — SPI-Flash (assets, íconos y binarios) (ver [`planificacion/equipos.md`](../../planificacion/equipos.md)) |
| **Región de memoria** | `0x420000 – 0x42FFFF` |
| **Archivo RTL** | `cores/spi_flash/rtl/perip_spiflash.v` |

## Función

Leer datos no volátiles del juego (gráficos, niveles, sonidos) almacenados en la memoria Flash SPI de la tarjeta.

## Protocolo

SPI modo 0. Chip de referencia: familia W25Qxx. Comandos: `0x03` READ, `0x06` WRITE ENABLE, `0x02` PAGE PROGRAM, `0x20` SECTOR ERASE, `0x05` READ STATUS, `0x9F` JEDEC ID.

**Pines externos:** `spi_sck`, `spi_mosi`, `spi_miso`, `flash_cs_n` (se comparte el bus SPI con la SPI-RAM si la placa lo exige; a definir con los Grupos A y C).

## Interfaz con el bus (igual para todos los periféricos)

```verilog
module perip_spiflash (
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
| `0x00` | `CONTROL` | R/W | Bit 0 `START`. Bits 15:8 `CMD`: comando SPI a enviar. |
| `0x04` | `ADDR` | R/W | Dirección de 24 bits. |
| `0x08` | `WDATA` | R/W | Byte a programar. |
| `0x0C` | `RDATA` | R | Byte leído / registro de estado / byte del JEDEC ID. |
| `0x10` | `STATUS` | R | Bit 0 `BUSY` (del periférico). Bit 1 `DONE`. |
| `0x14` | `CLK_DIV` | R/W | Divisor del reloj SPI. |

## Diseño

- Diagramas de bloques y de flujo: [`diagramas/`](diagramas/README.md)
- Estados previstos: `IDLE`, `CMD`, `ADDR`, `DATA`, `DONE`. Puede reutilizar el maestro SPI del Grupo C (misma base de RTL que la SPI-RAM).

## Plan de verificación (checkpoint 3)

Cada prueba del testbench imprime `PASS` o `FAIL` y declara estímulo, resultado esperado y criterio de aprobación.

1. Leer el JEDEC ID (`0x9F`) desde un modelo de Flash en el testbench.
2. Secuencia WREN → PAGE PROGRAM → READ y comparar el dato.
3. Caso de error: programar sin WREN no debe cambiar el contenido del modelo.

## Firmware previsto

Funciones del driver en `firmware/`: `flash_read_id()`, `flash_read(addr, buf, n)`, `flash_write_page(addr, buf, n)`, `flash_erase_sector(addr)`.

## Avance

| Checkpoint | Entregable | Estado |
|---|---|---|
| 1 | Flowchart + registros CSR | 🟡 en desarrollo (este documento) |
| 2 | ASM del datapath y del control | ⚪ pendiente |
| 3 | RTL + testbench (`make sim`) | ⚪ pendiente |
| 4 | Integración en la FPGA | ⚪ pendiente |
| 5 | Demo final | ⚪ pendiente |
