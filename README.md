# Proyecto Digital 1 — Consola de videojuegos retro sobre FPGA

> **Versión preliminar (checkpoint 1).** Este repositorio organiza **qué vamos a construir** y **cómo nos dividimos el trabajo**. Las especificaciones de registros, los diagramas y las fechas son propuestas que se irán refinando en cada checkpoint.
>
> Guía del curso: [cicamargoba/digital_UN — 2026_1](https://github.com/cicamargoba/digital_UN/tree/main/2026_1)

## 1. Qué vamos a hacer

Una **consola de videojuegos retro** en una FPGA:

- Un procesador **RISC-V (femtorv32, RV32I)** que ejecuta el software de juegos escrito en **C**. El procesador se usa como **caja negra**: no lo diseñamos ni lo modificamos.
- Un **panel de LEDs** como pantalla, manejado por un framebuffer, más pantallas RGB laterales y un LED indicador por puerto.
- **Periféricos** en **Verilog**: teclado y mouse PS/2, control NES, memorias SPI-RAM y SPI-Flash, EEPROM I2C para los puntajes, audio I2S y UART para diagnóstico.

El procesador se comunica con cada periférico mediante **registros mapeados en memoria (CSR)**: el software escribe o lee una dirección y el hardware responde. Todo el curso construye **una sola consola compartida**: cada grupo es dueño de un módulo y al final todos se integran sobre el mismo bus.

## 2. Cómo funciona la consola

El flujo completo está en [`diagramas/`](diagramas/README.md#3-diagrama-de-flujo-general) (fuente: [`Diagrama_de_Flujo.drawio`](diagramas/Diagrama_de_Flujo.drawio)). En resumen, tiene cuatro fases:

| Fase | Qué pasa | Grupos |
|---|---|---|
| **1. Arranque y diagnóstico** | Carga el bootloader de la BRAM, inicia UART y bus, hace un autotest de SPI-RAM y SPI-Flash y verifica el checksum del menú. Si algo falla, muestra el error y lo registra por UART | A, B, C, D, J, K |
| **2. Gestión de periféricos** | Escanea los 2 puertos, identifica si hay teclado, mouse o control NES y enciende el LED RGB del puerto | E, F, G, L |
| **3. Navegación y selección** | Muestra los paneles de juegos (Single / Multi-Local), maneja el modo demo por inactividad y valida que haya suficientes controles | J, K |
| **4. Ejecución** | Carga el juego a RAM y lo ejecuta, reproduce sonidos y pausa el juego si se desconecta un control | C, D, I, K |

## 3. Metodología

Seguimos el flujo **top-down** del curso: **flowchart → ASM → RTL → hardware**. Cada módulo pasa por los mismos checkpoints:

| # | Checkpoint | Entregable |
|---|---|---|
| 1 | Flowchart + especificación CSR | `cores/<p>/README.md` y `cores/<p>/diagramas/` |
| 2 | ASM | Diagrama ASM del datapath y del control |
| 3 | RTL simulado | `rtl/*.v`, testbench automático, `make sim` en PASS, `.gtkw` |
| 4 | Integración en hardware | Módulo funcionando en la FPGA dentro del SoC compartido |
| 5 | Demo final | Consola completa jugando |

## 4. Arquitectura

![Diagrama de bloques del SoC](./diagrama_soc_digital1_v3.svg)

El **decodificador de direcciones** genera `cs0`–`cs9` a partir de `mem_addr`. Todos los periféricos tienen el mismo contrato de puertos (`d_in`, `cs`, `addr`, `rd`, `wr`, `d_out`) y un **mux** lleva el `d_out` del periférico seleccionado a `mem_rdata`.

Más detalle: [`diagramas/`](diagramas/README.md) (bloques, flujo general y relación entre módulos) e [`interfaces/`](interfaces/README.md) (contrato de puertos y convenciones CSR).

## 5. Mapa de memoria

| Rango | Módulo | Grupo | Carpeta |
|---|---|---|---|
| `0x000000 – 0x3FFFFF` | BRAM (arranque / firmware) | A | — |
| `0x400000 – 0x40FFFF` | UART (diagnóstico) | B | [`cores/uart`](cores/uart/README.md) |
| `0x410000 – 0x41FFFF` | SPI-RAM | C | [`cores/spiram`](cores/spiram/README.md) |
| `0x420000 – 0x42FFFF` | SPI-Flash | D | [`cores/spi_flash`](cores/spi_flash/README.md) |
| `0x430000 – 0x43FFFF` | Teclado PS/2 | E | [`cores/ps2_keyboard`](cores/ps2_keyboard/README.md) |
| `0x440000 – 0x44FFFF` | Mouse PS/2 | F | [`cores/ps2_mouse`](cores/ps2_mouse/README.md) |
| `0x450000 – 0x45FFFF` | Control NES | G | [`cores/nes_ctrl`](cores/nes_ctrl/README.md) |
| `0x460000 – 0x46FFFF` | I2C (EEPROM / puntajes) | H | [`cores/i2c`](cores/i2c/README.md) |
| `0x470000 – 0x47FFFF` | I2S (audio) | I | [`cores/i2s`](cores/i2s/README.md) |
| `0x480000 – 0x4FFFFF` | Display (framebuffer, 512 KB) | J | [`cores/display`](cores/display/README.md) |
| `0x500000` | `blink` (ejemplo guía) | referencia | [`cores/blink`](cores/blink/README.md) |
| por asignar (propuesta `0x510000`) | Pantallas RGB e indicadores LED | L | [`cores/indicadores`](cores/indicadores/README.md) |

El software de juegos (Grupo K) vive en la BRAM. Las direcciones en C están en [`interfaces/memory_map.h`](interfaces/memory_map.h).

## 6. División del trabajo

Un grupo por módulo, con las mismas letras del diagrama de flujo:

| Grupo | Módulo |
|---|---|
| **A** | BRAM, bus y SoC (decodificador, mux, top) |
| **B** | UART |
| **C** | SPI-RAM |
| **D** | SPI-Flash |
| **E** | Teclado PS/2 |
| **F** | Mouse PS/2 |
| **G** | Control NES |
| **H** | I2C (EEPROM de puntajes) |
| **I** | I2S (audio) |
| **J** | Display |
| **K** | Software de juegos |
| **L** | Pantallas RGB e indicadores LED de puerto |

Integrantes y dependencias: [`planificacion/equipos.md`](planificacion/equipos.md). Tareas con fechas, dependencias y evidencias: [`planificacion/cronograma.md`](planificacion/cronograma.md).

## 7. Planificación y seguimiento

- Cada tarea se crea como **issue** con el formulario [`tarea.yml`](.github/ISSUE_TEMPLATE/tarea.yml). El formulario pide equipo, responsable, fechas, dependencias, criterios de aceptación y evidencia.
- Todos los issues se agregan al **GitHub Project** general, con una vista de tabla (seguimiento) y otra de roadmap (cronograma). La configuración está en [`planificacion/README.md`](planificacion/README.md).
- Una tarea se cierra solo cuando hay **evidencia verificable**: un PR, una simulación en PASS, formas de onda o un video en la FPGA.

### Repositorio general y repositorios de grupo

Este es el **repositorio general**: contiene la arquitectura, las interfaces, el mapa de memoria, los diagramas y la integración.

1. Cada grupo crea **su propio repositorio** a partir de esta estructura y trabaja en su carpeta.
2. Los cambios comunes (mapa de memoria, interfaces, diagramas) se hacen aquí y los grupos los traen a su repo.
3. Cuando un módulo pasa `make sim` y se prueba en la FPGA, el grupo abre un **pull request** hacia este repositorio. El Grupo A lo revisa y lo integra.

## 8. Estructura del repositorio

```
.github/ISSUE_TEMPLATE/tarea.yml   formulario para crear tareas
planificacion/                     GitHub Projects, equipos y cronograma
diagramas/                         flujo general, bloques y relación entre módulos
    Diagrama_de_Flujo.drawio       fuente de todos los diagramas de flujo
interfaces/                        contrato de puertos, convenciones CSR y memory_map.h
cores/                             un directorio por periférico
    <periferico>/
        README.md                  función, protocolo, registros CSR, plan de pruebas
        diagramas/                 bloques, flujo, estados / ASM
        rtl/                       Verilog, testbench, Makefile, .gtkw
        firmware/                  driver en C
    blink/                         ejemplo guía completo del profesor
firmware/                          software de juegos (Grupo K) y programas de prueba
diagrama_soc_digital1_v3.svg       diagrama de bloques del SoC
```

## 9. Cómo probar el ejemplo guía

Requisitos: [Icarus Verilog](https://bleyer.org/icarus/) y [GTKWave](https://gtkwave.sourceforge.net/) (en Windows vienen juntos en el instalador de Icarus) y `make`.

```bash
cd cores/blink/rtl
make sim      # compila y corre el testbench; debe imprimir PASS
make wave     # abre las formas de onda en GTKWave
```
