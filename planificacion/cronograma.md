# Cronograma del proyecto

> **Fechas tentativas.** Se ajustan al calendario académico. El seguimiento diario se hace en el **GitHub Project**; esta tabla es la línea base del plan.

*Responsable*: grupo de [`equipos.md`](equipos.md); dentro del grupo, la persona se asigna en el *issue* de cada tarea. *Estado*: Pendiente · En desarrollo · Bloqueada · Terminada.

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
| T-00-01 | Crear el GitHub Project y los repositorios de cada grupo | Grupo A | 2026-10-05 | 2026-10-07 | Ninguna | En desarrollo | Enlace al Project y a los repos |
| T-00-02 | Completar integrantes en `equipos.md` | Todos | 2026-10-05 | 2026-10-07 | Ninguna | En desarrollo | Commit en `planificacion/equipos.md` |
| T-A-01 | Especificar decodificador de direcciones, mux de lectura y BRAM | Grupo A | 2026-10-05 | 2026-10-16 | Ninguna | En desarrollo | `diagramas/README.md` §2, `interfaces/README.md` |
| T-B-01 | Flowchart y registros CSR del UART | Grupo B | 2026-10-05 | 2026-10-16 | Ninguna | En desarrollo | `cores/uart/README.md` y `cores/uart/diagramas/` |
| T-C-01 | Flowchart y registros CSR del SPI-RAM | Grupo C | 2026-10-05 | 2026-10-16 | Ninguna | En desarrollo | `cores/spiram/README.md` y `cores/spiram/diagramas/` |
| T-D-01 | Flowchart y registros CSR del SPI-Flash | Grupo D | 2026-10-05 | 2026-10-16 | Ninguna | En desarrollo | `cores/spi_flash/README.md` y `cores/spi_flash/diagramas/` |
| T-E-01 | Flowchart y registros CSR del teclado PS/2 | Grupo E | 2026-10-05 | 2026-10-16 | Ninguna | En desarrollo | `cores/ps2_keyboard/README.md` y `cores/ps2_keyboard/diagramas/` |
| T-F-01 | Flowchart y registros CSR del mouse PS/2 | Grupo F | 2026-10-05 | 2026-10-16 | Ninguna | En desarrollo | `cores/ps2_mouse/README.md` y `cores/ps2_mouse/diagramas/` |
| T-G-01 | Flowchart y registros CSR del control NES | Grupo G | 2026-10-05 | 2026-10-16 | Ninguna | En desarrollo | `cores/nes_ctrl/README.md` y `cores/nes_ctrl/diagramas/` |
| T-H-01 | Flowchart y registros CSR del I2C | Grupo H | 2026-10-05 | 2026-10-16 | Ninguna | En desarrollo | `cores/i2c/README.md` y `cores/i2c/diagramas/` |
| T-I-01 | Flowchart y registros CSR del I2S | Grupo I | 2026-10-05 | 2026-10-16 | Ninguna | En desarrollo | `cores/i2s/README.md` y `cores/i2s/diagramas/` |
| T-J-01 | Flowchart y registros CSR del display | Grupo J | 2026-10-05 | 2026-10-16 | Ninguna | En desarrollo | `cores/display/README.md` y `cores/display/diagramas/` |
| T-L-01 | Flowchart y registros CSR del indicadores LED | Grupo L | 2026-10-05 | 2026-10-16 | Ninguna | En desarrollo | `cores/indicadores/README.md` y `cores/indicadores/diagramas/` |
| T-K-01 | Diagramas de flujo del sistema, menú y juego; definir el comando común con E, F y G | Grupo K | 2026-10-05 | 2026-10-16 | Ninguna | En desarrollo | `diagramas/Diagrama_de_Flujo.drawio`, `firmware/README.md` |

## Checkpoint 2 — ASM

| ID | Tarea | Responsable | Inicio | Entrega | Dependencias | Estado | Evidencia |
|---|---|---|---|---|---|---|---|
| T-A-02 | ASM del decodificador y del mux | Grupo A | 2026-10-19 | 2026-10-30 | T-A-01 | Pendiente | ASM en `diagramas/` |
| T-B-02 | ASM del datapath y del control del UART | Grupo B | 2026-10-19 | 2026-10-30 | T-B-01 | Pendiente | ASM en `cores/uart/diagramas/` |
| T-C-02 | ASM del datapath y del control del SPI-RAM | Grupo C | 2026-10-19 | 2026-10-30 | T-C-01 | Pendiente | ASM en `cores/spiram/diagramas/` |
| T-D-02 | ASM del datapath y del control del SPI-Flash | Grupo D | 2026-10-19 | 2026-10-30 | T-D-01 | Pendiente | ASM en `cores/spi_flash/diagramas/` |
| T-E-02 | ASM del datapath y del control del teclado PS/2 | Grupo E | 2026-10-19 | 2026-10-30 | T-E-01 | Pendiente | ASM en `cores/ps2_keyboard/diagramas/` |
| T-F-02 | ASM del datapath y del control del mouse PS/2 | Grupo F | 2026-10-19 | 2026-10-30 | T-F-01 | Pendiente | ASM en `cores/ps2_mouse/diagramas/` |
| T-G-02 | ASM del datapath y del control del control NES | Grupo G | 2026-10-19 | 2026-10-30 | T-G-01 | Pendiente | ASM en `cores/nes_ctrl/diagramas/` |
| T-H-02 | ASM del datapath y del control del I2C | Grupo H | 2026-10-19 | 2026-10-30 | T-H-01 | Pendiente | ASM en `cores/i2c/diagramas/` |
| T-I-02 | ASM del datapath y del control del I2S | Grupo I | 2026-10-19 | 2026-10-30 | T-I-01 | Pendiente | ASM en `cores/i2s/diagramas/` |
| T-J-02 | ASM del datapath y del control del display | Grupo J | 2026-10-19 | 2026-10-30 | T-J-01 | Pendiente | ASM en `cores/display/diagramas/` |
| T-L-02 | ASM del datapath y del control del indicadores LED | Grupo L | 2026-10-19 | 2026-10-30 | T-L-01 | Pendiente | ASM en `cores/indicadores/diagramas/` |
| T-K-02 | Flujo de compilación del firmware (`firmware.hex` para la BRAM) con el Grupo A | Grupo K | 2026-10-19 | 2026-10-30 | Ninguna | Pendiente | Instrucciones en `firmware/README.md` |

## Checkpoint 3 — RTL simulado

| ID | Tarea | Responsable | Inicio | Entrega | Dependencias | Estado | Evidencia |
|---|---|---|---|---|---|---|---|
| T-A-03 | RTL de BRAM, decodificador, mux y top `SOC.v` + testbench | Grupo A | 2026-11-03 | 2026-11-20 | T-A-02 | Pendiente | `make sim` en PASS, PR |
| T-B-03 | RTL del UART | Grupo B | 2026-11-03 | 2026-11-20 | T-B-02 | Pendiente | `cores/uart/rtl/`, PR |
| T-B-04 | Testbench automático del UART (casos normales, límite y error) | Grupo B | 2026-11-03 | 2026-11-20 | T-B-02 | Pendiente | `make sim` en PASS + `.gtkw` y capturas interpretadas |
| T-B-05 | Driver C y programa de prueba del UART | Grupo B | 2026-11-03 | 2026-11-20 | T-B-01 | Pendiente | `cores/uart/firmware/` |
| T-C-03 | RTL del SPI-RAM | Grupo C | 2026-11-03 | 2026-11-20 | T-C-02 | Pendiente | `cores/spiram/rtl/`, PR |
| T-C-04 | Testbench automático del SPI-RAM (casos normales, límite y error) | Grupo C | 2026-11-03 | 2026-11-20 | T-C-02 | Pendiente | `make sim` en PASS + `.gtkw` y capturas interpretadas |
| T-C-05 | Driver C y programa de prueba del SPI-RAM | Grupo C | 2026-11-03 | 2026-11-20 | T-C-01 | Pendiente | `cores/spiram/firmware/` |
| T-D-03 | RTL del SPI-Flash | Grupo D | 2026-11-03 | 2026-11-20 | T-D-02 | Pendiente | `cores/spi_flash/rtl/`, PR |
| T-D-04 | Testbench automático del SPI-Flash (casos normales, límite y error) | Grupo D | 2026-11-03 | 2026-11-20 | T-D-02 | Pendiente | `make sim` en PASS + `.gtkw` y capturas interpretadas |
| T-D-05 | Driver C y programa de prueba del SPI-Flash | Grupo D | 2026-11-03 | 2026-11-20 | T-D-01 | Pendiente | `cores/spi_flash/firmware/` |
| T-E-03 | RTL del teclado PS/2 | Grupo E | 2026-11-03 | 2026-11-20 | T-E-02 | Pendiente | `cores/ps2_keyboard/rtl/`, PR |
| T-E-04 | Testbench automático del teclado PS/2 (casos normales, límite y error) | Grupo E | 2026-11-03 | 2026-11-20 | T-E-02 | Pendiente | `make sim` en PASS + `.gtkw` y capturas interpretadas |
| T-E-05 | Driver C y programa de prueba del teclado PS/2 | Grupo E | 2026-11-03 | 2026-11-20 | T-E-01 | Pendiente | `cores/ps2_keyboard/firmware/` |
| T-F-03 | RTL del mouse PS/2 | Grupo F | 2026-11-03 | 2026-11-20 | T-F-02 | Pendiente | `cores/ps2_mouse/rtl/`, PR |
| T-F-04 | Testbench automático del mouse PS/2 (casos normales, límite y error) | Grupo F | 2026-11-03 | 2026-11-20 | T-F-02 | Pendiente | `make sim` en PASS + `.gtkw` y capturas interpretadas |
| T-F-05 | Driver C y programa de prueba del mouse PS/2 | Grupo F | 2026-11-03 | 2026-11-20 | T-F-01 | Pendiente | `cores/ps2_mouse/firmware/` |
| T-G-03 | RTL del control NES | Grupo G | 2026-11-03 | 2026-11-20 | T-G-02 | Pendiente | `cores/nes_ctrl/rtl/`, PR |
| T-G-04 | Testbench automático del control NES (casos normales, límite y error) | Grupo G | 2026-11-03 | 2026-11-20 | T-G-02 | Pendiente | `make sim` en PASS + `.gtkw` y capturas interpretadas |
| T-G-05 | Driver C y programa de prueba del control NES | Grupo G | 2026-11-03 | 2026-11-20 | T-G-01 | Pendiente | `cores/nes_ctrl/firmware/` |
| T-H-03 | RTL del I2C | Grupo H | 2026-11-03 | 2026-11-20 | T-H-02 | Pendiente | `cores/i2c/rtl/`, PR |
| T-H-04 | Testbench automático del I2C (casos normales, límite y error) | Grupo H | 2026-11-03 | 2026-11-20 | T-H-02 | Pendiente | `make sim` en PASS + `.gtkw` y capturas interpretadas |
| T-H-05 | Driver C y programa de prueba del I2C | Grupo H | 2026-11-03 | 2026-11-20 | T-H-01 | Pendiente | `cores/i2c/firmware/` |
| T-I-03 | RTL del I2S | Grupo I | 2026-11-03 | 2026-11-20 | T-I-02 | Pendiente | `cores/i2s/rtl/`, PR |
| T-I-04 | Testbench automático del I2S (casos normales, límite y error) | Grupo I | 2026-11-03 | 2026-11-20 | T-I-02 | Pendiente | `make sim` en PASS + `.gtkw` y capturas interpretadas |
| T-I-05 | Driver C y programa de prueba del I2S | Grupo I | 2026-11-03 | 2026-11-20 | T-I-01 | Pendiente | `cores/i2s/firmware/` |
| T-J-03 | RTL del display | Grupo J | 2026-11-03 | 2026-11-20 | T-J-02 | Pendiente | `cores/display/rtl/`, PR |
| T-J-04 | Testbench automático del display (casos normales, límite y error) | Grupo J | 2026-11-03 | 2026-11-20 | T-J-02 | Pendiente | `make sim` en PASS + `.gtkw` y capturas interpretadas |
| T-J-05 | Driver C y programa de prueba del display | Grupo J | 2026-11-03 | 2026-11-20 | T-J-01 | Pendiente | `cores/display/firmware/` |
| T-L-03 | RTL del indicadores LED | Grupo L | 2026-11-03 | 2026-11-20 | T-L-02 | Pendiente | `cores/indicadores/rtl/`, PR |
| T-L-04 | Testbench automático del indicadores LED (casos normales, límite y error) | Grupo L | 2026-11-03 | 2026-11-20 | T-L-02 | Pendiente | `make sim` en PASS + `.gtkw` y capturas interpretadas |
| T-L-05 | Driver C y programa de prueba del indicadores LED | Grupo L | 2026-11-03 | 2026-11-20 | T-L-01 | Pendiente | `cores/indicadores/firmware/` |
| T-K-03 | Autotest de arranque y checksum del menú (Fase 1) | Grupo K | 2026-11-03 | 2026-11-20 | T-K-02 | Pendiente | `firmware/selftest/`, log UART |
| T-K-04 | Menú, submenú, modo demo y validación de controles (Fases 2 y 3) | Grupo K | 2026-11-03 | 2026-11-20 | T-K-01 | Pendiente | `firmware/menu/` |
| T-K-05 | Bucle del juego: vidas, colisiones, puntaje, pausa y hot-plug (Fase 4) | Grupo K | 2026-11-03 | 2026-11-20 | T-K-01 | Pendiente | `firmware/juego/` |

## Checkpoint 4 — Integración en hardware

| ID | Tarea | Responsable | Inicio | Entrega | Dependencias | Estado | Evidencia |
|---|---|---|---|---|---|---|---|
| T-A-04 | Probar el SoC en la FPGA con el ejemplo `blink_test` | Grupo A | 2026-11-23 | 2026-12-04 | T-A-03, T-K-02 | Pendiente | LED parpadeando en la FPGA |
| T-B-06 | Prueba del UART en la FPGA dentro del SoC y PR al repositorio general | Grupo B | 2026-11-23 | 2026-12-04 | T-B-04, T-A-03 | Pendiente | Video/foto + salida UART, PR aceptado |
| T-C-06 | Prueba del SPI-RAM en la FPGA dentro del SoC y PR al repositorio general | Grupo C | 2026-11-23 | 2026-12-04 | T-C-04, T-A-03 | Pendiente | Video/foto + salida UART, PR aceptado |
| T-D-06 | Prueba del SPI-Flash en la FPGA dentro del SoC y PR al repositorio general | Grupo D | 2026-11-23 | 2026-12-04 | T-D-04, T-A-03 | Pendiente | Video/foto + salida UART, PR aceptado |
| T-E-06 | Prueba del teclado PS/2 en la FPGA dentro del SoC y PR al repositorio general | Grupo E | 2026-11-23 | 2026-12-04 | T-E-04, T-A-03 | Pendiente | Video/foto + salida UART, PR aceptado |
| T-F-06 | Prueba del mouse PS/2 en la FPGA dentro del SoC y PR al repositorio general | Grupo F | 2026-11-23 | 2026-12-04 | T-F-04, T-A-03 | Pendiente | Video/foto + salida UART, PR aceptado |
| T-G-06 | Prueba del control NES en la FPGA dentro del SoC y PR al repositorio general | Grupo G | 2026-11-23 | 2026-12-04 | T-G-04, T-A-03 | Pendiente | Video/foto + salida UART, PR aceptado |
| T-H-06 | Prueba del I2C en la FPGA dentro del SoC y PR al repositorio general | Grupo H | 2026-11-23 | 2026-12-04 | T-H-04, T-A-03 | Pendiente | Video/foto + salida UART, PR aceptado |
| T-I-06 | Prueba del I2S en la FPGA dentro del SoC y PR al repositorio general | Grupo I | 2026-11-23 | 2026-12-04 | T-I-04, T-A-03 | Pendiente | Video/foto + salida UART, PR aceptado |
| T-J-06 | Prueba del display en la FPGA dentro del SoC y PR al repositorio general | Grupo J | 2026-11-23 | 2026-12-04 | T-J-04, T-A-03 | Pendiente | Video/foto + salida UART, PR aceptado |
| T-L-06 | Prueba del indicadores LED en la FPGA dentro del SoC y PR al repositorio general | Grupo L | 2026-11-23 | 2026-12-04 | T-L-04, T-A-03 | Pendiente | Video/foto + salida UART, PR aceptado |
| T-K-06 | Integrar sonidos (I), puntajes top 5 (H), display (J) e indicadores (L) | Grupo K | 2026-11-23 | 2026-12-04 | T-K-05, T-H-06, T-I-06, T-J-06, T-L-06 | Pendiente | Video del juego en la FPGA |

## Checkpoint 5 — Demo final

| ID | Tarea | Responsable | Inicio | Entrega | Dependencias | Estado | Evidencia |
|---|---|---|---|---|---|---|---|
| T-ALL-01 | Integración de todos los módulos y ensayo de la demo | Todos (coordina A) | 2026-12-07 | 2026-12-11 | Todas las tareas del checkpoint 4 | Pendiente | Video de la demo |
| T-ALL-02 | Documentación final | Todos | 2026-12-07 | 2026-12-11 | T-ALL-01 | Pendiente | README actualizados |
