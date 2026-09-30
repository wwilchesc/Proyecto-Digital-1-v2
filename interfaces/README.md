# Interfaces compartidas

Todo lo que comparten los periféricos. Solo se cambia por acuerdo en un *issue* del repositorio general.

## 1. Contrato de puertos de un periférico

Todos los periféricos exponen el mismo contrato, igual que el ejemplo [`cores/blink`](../cores/blink/rtl/perip_blink.v):

| Puerto | Dirección | Ancho | Descripción |
|---|---|---|---|
| `clk` | entrada | 1 | Reloj del sistema |
| `rst` | entrada | 1 | Reset síncrono, activo en alto |
| `d_in` | entrada | 32 | Dato que escribe la CPU |
| `cs` | entrada | 1 | Selección del periférico (desde el decodificador) |
| `addr` | entrada | N | Desplazamiento local dentro de la ventana (la base ya viene restada) |
| `rd` | entrada | 1 | Lectura |
| `wr` | entrada | 1 | Escritura |
| `d_out` | salida | 32 | Dato leído. Debe ser `0` cuando `cs && rd` no está activo |
| *pines* | — | — | Señales externas del protocolo (ver el README de cada periférico) |

## 2. Convenciones de registros CSR

- Todos los registros son de **32 bits**, alineados a 4 bytes (`0x00`, `0x04`, `0x08`…).
- Registro `0x00`: casi siempre `CONTROL` (bit 0 = habilitar/iniciar) o el dato principal.
- Hay un registro `STATUS` de solo lectura con bits `BUSY`/`VALID`/`DONE` y banderas de error.
- Los bits no usados se leen como 0 y se ignoran al escribir.
- Acceso: `R` solo lectura, `W` solo escritura, `R/W` lectura y escritura.

## 3. Mapa de memoria

Tabla en el [README principal](../README.md#4-mapa-de-memoria) y en C en [`memory_map.h`](memory_map.h).

## 4. Pines y restricciones

- La asignación de pines de la FPGA y el archivo de restricciones los consolida G1 a medida que cada grupo define sus pines externos.
- Las entradas asíncronas (PS/2, NES, UART RX, I2C SDA) pasan por un **sincronizador de 2 flip-flops** antes de usarse.
- Las líneas de colector abierto (PS/2, I2C) se manejan como `assign pin = oe ? 1'b0 : 1'bz;`.
