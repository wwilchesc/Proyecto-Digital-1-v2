# Cronograma del proyecto

> **Fechas tentativas.** Se ajustan al calendario académico y a lo que indique el profesor. El seguimiento diario se hace en el **GitHub Project**; esta tabla es la línea base del plan.

Campos: los mismos que pide el enunciado. *Responsable* usa los códigos de [`equipos.md`](equipos.md). *Estado*: Pendiente · En desarrollo · Bloqueada · Terminada.

## Checkpoints

| # | Checkpoint | Inicio | Entrega |
|---|---|---|---|
| 1 | Flowchart + especificación CSR | 2026-10-05 | 2026-10-16 |
| 2 | ASM | 2026-10-19 | 2026-10-30 |
| 3 | RTL simulado | 2026-11-03 | 2026-11-20 |
| 4 | Integración en hardware | 2026-11-23 | 2026-12-04 |
| 5 | Demo final | 2026-12-07 | 2026-12-11 |

## Checkpoint 1 — Flowchart + especificación CSR

| ID | Tarea | Responsable | Inicio | Entrega | Dependencias | Estado | Evidencia |
|---|---|---|---|---|---|---|---|
| T-00-01 | Crear el repositorio general, el GitHub Project y los repos de cada grupo | G1-A | 2026-10-05 | 2026-10-07 | Ninguna | En desarrollo | Enlace al Project y a los repos |
| T-00-02 | Completar nombres y usuarios en `equipos.md` | G1-C | 2026-10-05 | 2026-10-07 | Ninguna | En desarrollo | Commit en `planificacion/equipos.md` |
| T-G1-01 | Especificar el decodificador de direcciones y el mux de lectura (flowchart + tabla de `cs`) | G1-A | 2026-10-05 | 2026-10-16 | Ninguna | En desarrollo | `diagramas/README.md`, `interfaces/README.md` |
| T-G1-05 | Flowchart y registros CSR del UART | G1-B | 2026-10-05 | 2026-10-16 | Ninguna | En desarrollo | `cores/uart/README.md` y `cores/uart/diagramas/` |
| T-G2-05 | Flowchart y registros CSR del SPI-RAM | G2-A | 2026-10-05 | 2026-10-16 | Ninguna | En desarrollo | `cores/spiram/README.md` y `cores/spiram/diagramas/` |
| T-G2-11 | Flowchart y registros CSR del SPI-Flash | G2-B | 2026-10-05 | 2026-10-16 | Ninguna | En desarrollo | `cores/spi_flash/README.md` y `cores/spi_flash/diagramas/` |
| T-G3-05 | Flowchart y registros CSR del teclado PS/2 | G3-A | 2026-10-05 | 2026-10-16 | Ninguna | En desarrollo | `cores/ps2_keyboard/README.md` y `cores/ps2_keyboard/diagramas/` |
| T-G3-11 | Flowchart y registros CSR del mouse PS/2 | G3-B | 2026-10-05 | 2026-10-16 | Ninguna | En desarrollo | `cores/ps2_mouse/README.md` y `cores/ps2_mouse/diagramas/` |
| T-G4-05 | Flowchart y registros CSR del control NES | G4-A | 2026-10-05 | 2026-10-16 | Ninguna | En desarrollo | `cores/nes_ctrl/README.md` y `cores/nes_ctrl/diagramas/` |
| T-G5-05 | Flowchart y registros CSR del I2C | G5-A | 2026-10-05 | 2026-10-16 | Ninguna | En desarrollo | `cores/i2c/README.md` y `cores/i2c/diagramas/` |
| T-G6-05 | Flowchart y registros CSR del I2S | G6-A | 2026-10-05 | 2026-10-16 | Ninguna | En desarrollo | `cores/i2s/README.md` y `cores/i2s/diagramas/` |

## Checkpoint 2 — ASM

| ID | Tarea | Responsable | Inicio | Entrega | Dependencias | Estado | Evidencia |
|---|---|---|---|---|---|---|---|
| T-G1-02 | ASM del decodificador y del mux | G1-A | 2026-10-19 | 2026-10-30 | T-G1-01 | Pendiente | Diagrama ASM en `diagramas/` |
| T-G1-04 | Flujo de compilación del firmware (`firmware.hex` para la BRAM) con el ejemplo `blink_test` | G1-C | 2026-10-19 | 2026-10-30 | Ninguna | Pendiente | Instrucciones en `firmware/README.md` y LED parpadeando en la FPGA |
| T-G1-06 | ASM del datapath y del control del UART | G1-B | 2026-10-19 | 2026-10-30 | T-G1-05 | Pendiente | ASM en `cores/uart/diagramas/` |
| T-G2-06 | ASM del datapath y del control del SPI-RAM | G2-A | 2026-10-19 | 2026-10-30 | T-G2-05 | Pendiente | ASM en `cores/spiram/diagramas/` |
| T-G2-12 | ASM del datapath y del control del SPI-Flash | G2-B | 2026-10-19 | 2026-10-30 | T-G2-11 | Pendiente | ASM en `cores/spi_flash/diagramas/` |
| T-G3-06 | ASM del datapath y del control del teclado PS/2 | G3-A | 2026-10-19 | 2026-10-30 | T-G3-05 | Pendiente | ASM en `cores/ps2_keyboard/diagramas/` |
| T-G3-12 | ASM del datapath y del control del mouse PS/2 | G3-B | 2026-10-19 | 2026-10-30 | T-G3-11 | Pendiente | ASM en `cores/ps2_mouse/diagramas/` |
| T-G4-06 | ASM del datapath y del control del control NES | G4-A | 2026-10-19 | 2026-10-30 | T-G4-05 | Pendiente | ASM en `cores/nes_ctrl/diagramas/` |
| T-G5-06 | ASM del datapath y del control del I2C | G5-A | 2026-10-19 | 2026-10-30 | T-G5-05 | Pendiente | ASM en `cores/i2c/diagramas/` |
| T-G6-06 | ASM del datapath y del control del I2S | G6-A | 2026-10-19 | 2026-10-30 | T-G6-05 | Pendiente | ASM en `cores/i2s/diagramas/` |

## Checkpoint 3 — RTL simulado

| ID | Tarea | Responsable | Inicio | Entrega | Dependencias | Estado | Evidencia |
|---|---|---|---|---|---|---|---|
| T-G1-03 | RTL del decodificador, mux y top `SOC.v` + testbench con periféricos simulados | G1-A | 2026-11-03 | 2026-11-20 | T-G1-02 | Pendiente | `make sim` en PASS, PR |
| T-G1-07 | RTL del UART | G1-B | 2026-11-03 | 2026-11-20 | T-G1-06 | Pendiente | `cores/uart/rtl/`, PR |
| T-G1-08 | Testbench automático del UART (casos normales, límite y error) | G1-B | 2026-11-03 | 2026-11-20 | T-G1-06 | Pendiente | `make sim` en PASS + `.gtkw` y capturas interpretadas |
| T-G1-09 | Driver C y programa de prueba del UART | G1-B | 2026-11-03 | 2026-11-20 | T-G1-05 | Pendiente | `cores/uart/firmware/` |
| T-G2-07 | RTL del SPI-RAM | G2-A | 2026-11-03 | 2026-11-20 | T-G2-06 | Pendiente | `cores/spiram/rtl/`, PR |
| T-G2-08 | Testbench automático del SPI-RAM (casos normales, límite y error) | G2-C | 2026-11-03 | 2026-11-20 | T-G2-06 | Pendiente | `make sim` en PASS + `.gtkw` y capturas interpretadas |
| T-G2-09 | Driver C y programa de prueba del SPI-RAM | G2-C | 2026-11-03 | 2026-11-20 | T-G2-05 | Pendiente | `cores/spiram/firmware/` |
| T-G2-13 | RTL del SPI-Flash | G2-B | 2026-11-03 | 2026-11-20 | T-G2-12 | Pendiente | `cores/spi_flash/rtl/`, PR |
| T-G2-14 | Testbench automático del SPI-Flash (casos normales, límite y error) | G2-C | 2026-11-03 | 2026-11-20 | T-G2-12 | Pendiente | `make sim` en PASS + `.gtkw` y capturas interpretadas |
| T-G2-15 | Driver C y programa de prueba del SPI-Flash | G2-C | 2026-11-03 | 2026-11-20 | T-G2-11 | Pendiente | `cores/spi_flash/firmware/` |
| T-G3-07 | RTL del teclado PS/2 | G3-A | 2026-11-03 | 2026-11-20 | T-G3-06 | Pendiente | `cores/ps2_keyboard/rtl/`, PR |
| T-G3-08 | Testbench automático del teclado PS/2 (casos normales, límite y error) | G3-C | 2026-11-03 | 2026-11-20 | T-G3-06 | Pendiente | `make sim` en PASS + `.gtkw` y capturas interpretadas |
| T-G3-09 | Driver C y programa de prueba del teclado PS/2 | G3-C | 2026-11-03 | 2026-11-20 | T-G3-05 | Pendiente | `cores/ps2_keyboard/firmware/` |
| T-G3-13 | RTL del mouse PS/2 | G3-B | 2026-11-03 | 2026-11-20 | T-G3-12 | Pendiente | `cores/ps2_mouse/rtl/`, PR |
| T-G3-14 | Testbench automático del mouse PS/2 (casos normales, límite y error) | G3-C | 2026-11-03 | 2026-11-20 | T-G3-12 | Pendiente | `make sim` en PASS + `.gtkw` y capturas interpretadas |
| T-G3-15 | Driver C y programa de prueba del mouse PS/2 | G3-C | 2026-11-03 | 2026-11-20 | T-G3-11 | Pendiente | `cores/ps2_mouse/firmware/` |
| T-G4-07 | RTL del control NES | G4-A | 2026-11-03 | 2026-11-20 | T-G4-06 | Pendiente | `cores/nes_ctrl/rtl/`, PR |
| T-G4-08 | Testbench automático del control NES (casos normales, límite y error) | G4-B | 2026-11-03 | 2026-11-20 | T-G4-06 | Pendiente | `make sim` en PASS + `.gtkw` y capturas interpretadas |
| T-G4-09 | Driver C y programa de prueba del control NES | G4-B | 2026-11-03 | 2026-11-20 | T-G4-05 | Pendiente | `cores/nes_ctrl/firmware/` |
| T-G5-07 | RTL del I2C | G5-A | 2026-11-03 | 2026-11-20 | T-G5-06 | Pendiente | `cores/i2c/rtl/`, PR |
| T-G5-08 | Testbench automático del I2C (casos normales, límite y error) | G5-B | 2026-11-03 | 2026-11-20 | T-G5-06 | Pendiente | `make sim` en PASS + `.gtkw` y capturas interpretadas |
| T-G5-09 | Driver C y programa de prueba del I2C | G5-C | 2026-11-03 | 2026-11-20 | T-G5-05 | Pendiente | `cores/i2c/firmware/` |
| T-G6-07 | RTL del I2S | G6-A | 2026-11-03 | 2026-11-20 | T-G6-06 | Pendiente | `cores/i2s/rtl/`, PR |
| T-G6-08 | Testbench automático del I2S (casos normales, límite y error) | G6-B | 2026-11-03 | 2026-11-20 | T-G6-06 | Pendiente | `make sim` en PASS + `.gtkw` y capturas interpretadas |
| T-G6-09 | Driver C y programa de prueba del I2S | G6-C | 2026-11-03 | 2026-11-20 | T-G6-05 | Pendiente | `cores/i2s/firmware/` |

## Checkpoint 4 — Integración en hardware

| ID | Tarea | Responsable | Inicio | Entrega | Dependencias | Estado | Evidencia |
|---|---|---|---|---|---|---|---|
| T-G1-10 | Prueba del UART en la FPGA dentro del SoC y PR al repositorio general | G1-B | 2026-11-23 | 2026-12-04 | T-G1-08, T-G1-03 | Pendiente | Video/foto + salida UART, PR aceptado |
| T-G2-10 | Prueba del SPI-RAM en la FPGA dentro del SoC y PR al repositorio general | G2-A | 2026-11-23 | 2026-12-04 | T-G2-08, T-G1-03 | Pendiente | Video/foto + salida UART, PR aceptado |
| T-G2-16 | Prueba del SPI-Flash en la FPGA dentro del SoC y PR al repositorio general | G2-B | 2026-11-23 | 2026-12-04 | T-G2-14, T-G1-03 | Pendiente | Video/foto + salida UART, PR aceptado |
| T-G3-10 | Prueba del teclado PS/2 en la FPGA dentro del SoC y PR al repositorio general | G3-A | 2026-11-23 | 2026-12-04 | T-G3-08, T-G1-03 | Pendiente | Video/foto + salida UART, PR aceptado |
| T-G3-16 | Prueba del mouse PS/2 en la FPGA dentro del SoC y PR al repositorio general | G3-B | 2026-11-23 | 2026-12-04 | T-G3-14, T-G1-03 | Pendiente | Video/foto + salida UART, PR aceptado |
| T-G4-10 | Prueba del control NES en la FPGA dentro del SoC y PR al repositorio general | G4-A | 2026-11-23 | 2026-12-04 | T-G4-08, T-G1-03 | Pendiente | Video/foto + salida UART, PR aceptado |
| T-G5-10 | Prueba del I2C en la FPGA dentro del SoC y PR al repositorio general | G5-A | 2026-11-23 | 2026-12-04 | T-G5-08, T-G1-03 | Pendiente | Video/foto + salida UART, PR aceptado |
| T-G6-10 | Prueba del I2S en la FPGA dentro del SoC y PR al repositorio general | G6-A | 2026-11-23 | 2026-12-04 | T-G6-08, T-G1-03 | Pendiente | Video/foto + salida UART, PR aceptado |
| T-G4-20 | Integrar el driver de panel/framebuffer suministrado y mostrar un patrón de prueba | G4-C | 2026-11-23 | 2026-12-04 | T-G1-03 | Pendiente | Foto del panel + PR |
| T-G1-20 | Programa de autoprueba de arranque que ejecuta las pruebas de todos los periféricos e informa por UART | G1-C | 2026-11-23 | 2026-12-04 | Pruebas en FPGA de todos los grupos | Pendiente | Log UART en el PR |
| T-G5-20 | Tabla de puntajes altos en EEPROM (`score_save/load`) | G5-C | 2026-11-23 | 2026-12-04 | T-G5-09 | Pendiente | Puntaje persiste tras apagar |
| T-G6-20 | Efectos de sonido del juego | G6-C | 2026-11-23 | 2026-12-04 | T-G6-09 | Pendiente | Video con audio |

## Checkpoint 5 — Demo final

| ID | Tarea | Responsable | Inicio | Entrega | Dependencias | Estado | Evidencia |
|---|---|---|---|---|---|---|---|
| T-ALL-01 | Integración del juego con todos los periféricos y ensayo de la demo | Todos (coordina G1-A) | 2026-12-07 | 2026-12-11 | Todas las tareas del checkpoint 4 | Pendiente | Video de la demo |
| T-ALL-02 | Documentación final y sustentación | Todos | 2026-12-07 | 2026-12-11 | T-ALL-01 | Pendiente | README actualizados y presentación |
