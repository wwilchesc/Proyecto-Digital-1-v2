# Periféricos

| Carpeta | Módulo | Grupo | Estado |
|---|---|---|---|
| [`blink`](blink/README.md) | Ejemplo guía (profesor) | referencia | ✅ completo, `make sim` en PASS |
| [`uart`](uart/README.md) | UART de diagnóstico | B | 🟡 checkpoint 1 |
| [`spiram`](spiram/README.md) | SPI-RAM | C | 🟡 checkpoint 1 |
| [`spi_flash`](spi_flash/README.md) | SPI-Flash | D | 🟡 checkpoint 1 |
| [`ps2_keyboard`](ps2_keyboard/README.md) | Teclado PS/2 | E | 🟡 checkpoint 1 |
| [`ps2_mouse`](ps2_mouse/README.md) | Mouse PS/2 | F | 🟡 checkpoint 1 |
| [`nes_ctrl`](nes_ctrl/README.md) | Control NES | G | 🟡 checkpoint 1 |
| [`i2c`](i2c/README.md) | I2C (EEPROM de puntajes) | H | 🟡 checkpoint 1 |
| [`i2s`](i2s/README.md) | I2S (audio) | I | 🟡 checkpoint 1 |
| [`display`](display/README.md) | Display (panel LED / framebuffer) | J | 🟡 checkpoint 1 |
| [`indicadores`](indicadores/README.md) | Pantallas RGB e indicadores LED de puerto | L | 🟡 checkpoint 1 |

Cada carpeta sigue la estructura del ejemplo `blink`: `README.md` (especificación), `diagramas/`, `rtl/` y `firmware/`. El bus y el SoC (Grupo A) y el software de juegos (Grupo K, en [`firmware/`](../firmware/README.md)) no son periféricos y no tienen carpeta aquí.
