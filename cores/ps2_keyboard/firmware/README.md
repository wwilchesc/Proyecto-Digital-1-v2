# Firmware — Teclado PS/2

Pendiente (checkpoint 3–4). Driver en C que accede a los registros de [`../README.md`](../README.md).

Funciones previstas: `kbd_available()`, `kbd_read_scancode()`, `kbd_get_key()` (traduce scan codes a teclas del juego: flechas, espacio, enter).

Las direcciones base se toman de [`interfaces/memory_map.h`](../../../interfaces/memory_map.h).
