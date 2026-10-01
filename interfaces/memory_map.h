/* Mapa de memoria de la consola — Digital 1
 * Fuente: README.md (sección 4). Cualquier cambio se acuerda en el repositorio general.
 */
#ifndef MEMORY_MAP_H
#define MEMORY_MAP_H

#include <stdint.h>

#define BRAM_BASE        0x000000u   /* 0x000000 - 0x3FFFFF  arranque / firmware  A */
#define UART_BASE        0x400000u   /* 0x400000 - 0x40FFFF  B                      */
#define SPIRAM_BASE      0x410000u   /* 0x410000 - 0x41FFFF  C                      */
#define SPIFLASH_BASE    0x420000u   /* 0x420000 - 0x42FFFF  D                      */
#define PS2KBD_BASE      0x430000u   /* 0x430000 - 0x43FFFF  E                      */
#define PS2MOUSE_BASE    0x440000u   /* 0x440000 - 0x44FFFF  F                      */
#define NES_BASE         0x450000u   /* 0x450000 - 0x45FFFF  G                      */
#define I2C_BASE         0x460000u   /* 0x460000 - 0x46FFFF  H                      */
#define I2S_BASE         0x470000u   /* 0x470000 - 0x47FFFF  I                      */
#define DISPLAY_BASE     0x480000u   /* 0x480000 - 0x4FFFFF  framebuffer (512 KB) J */
#define BLINK_BASE       0x500000u   /* ejemplo guía                                */
#define INDICADORES_BASE 0x510000u   /* POR ASIGNAR (propuesta)  L                 */

/* Acceso a un registro CSR de 32 bits: REG32(UART_BASE + 0x08) */
#define REG32(addr) (*(volatile uint32_t *)(addr))

#endif /* MEMORY_MAP_H */
