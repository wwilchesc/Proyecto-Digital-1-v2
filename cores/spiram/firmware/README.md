# Firmware — SPI-RAM

Pendiente (checkpoint 3–4). Driver en C que accede a los registros de [`../README.md`](../README.md).

Funciones previstas: `spiram_write(addr, byte)`, `spiram_read(addr)`, `spiram_test()` (patrón de escritura/lectura para la prueba de arranque).

Las direcciones base se toman de [`interfaces/memory_map.h`](../../../interfaces/memory_map.h).
