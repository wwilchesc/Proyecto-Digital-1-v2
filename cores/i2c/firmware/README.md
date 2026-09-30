# Firmware — I2C (EEPROM de puntajes)

Pendiente (checkpoint 3–4). Driver en C que accede a los registros de [`../README.md`](../README.md).

Funciones previstas: `i2c_start()`, `i2c_write(byte)`, `i2c_read(ack)`, `i2c_stop()`, `eeprom_write(addr, byte)`, `eeprom_read(addr)`, `score_save()`, `score_load()`.

Las direcciones base se toman de [`interfaces/memory_map.h`](../../../interfaces/memory_map.h).
