# Firmware — SPI-Flash

Pendiente (checkpoint 3–4). Driver en C que accede a los registros de [`../README.md`](../README.md).

Funciones previstas: `flash_read_id()`, `flash_read(addr, buf, n)`, `flash_write_page(addr, buf, n)`, `flash_erase_sector(addr)`.

Las direcciones base se toman de [`interfaces/memory_map.h`](../../../interfaces/memory_map.h).
