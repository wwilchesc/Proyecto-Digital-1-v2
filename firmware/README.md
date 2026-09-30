# Firmware de integración

Aquí van el **juego** y los programas en C que usan varios periféricos a la vez. El driver de cada periférico **no** va aquí, sino en `cores/<periferico>/firmware/`.

| Carpeta | Contenido | Responsable |
|---|---|---|
| `blink_test/` | Ejemplo del profesor: usa el driver de `blink` | referencia |
| `selftest/` *(pendiente)* | Autoprueba de arranque: prueba cada periférico e informa por UART | G1-C |
| `juego/` *(pendiente)* | Juego sobre el núcleo suministrado (andamiaje), con entradas PS/2/NES, puntajes I2C y sonido I2S | todos, coordina G1 |

## Flujo previsto del firmware

```mermaid
flowchart TD
    A[Encendido: CPU ejecuta desde BRAM] --> B[uart_init: mensaje de arranque]
    B --> C[Autoprueba: SPI-RAM, SPI-Flash, EEPROM, NES, PS/2]
    C --> D{¿Falla algún periférico?}
    D -- Sí --> E[Reportar por UART y seguir sin ese periférico]
    D -- No --> F[Cargar puntajes altos desde EEPROM I2C]
    E --> F
    F --> G[Menú en el panel LED]
    G --> H{¿Start en NES o Enter en teclado?}
    H -- No --> G
    H -- Sí --> I[Bucle del juego]
    I --> J[Leer entradas: NES, teclado, mouse]
    J --> K[Actualizar estado del juego]
    K --> L[Dibujar en el framebuffer]
    L --> M[Sonido por I2S]
    M --> N{¿Fin de la partida?}
    N -- No --> I
    N -- Sí --> O[Guardar puntaje en EEPROM]
    O --> G
```

La forma de compilar a `firmware.hex` (cargado en la BRAM con `$readmemh`) la documenta G1 en la tarea `T-G1-04`.
