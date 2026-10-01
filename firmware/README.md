# Software de juegos (Grupo K)

Aquí van el **juego** y los programas en C que usan varios periféricos a la vez. El driver de cada periférico **no** va aquí, sino en `cores/<periferico>/firmware/`.

El Grupo K es el **orquestador central** (ver [relación entre módulos](../diagramas/README.md#4-relación-entre-módulos)): recibe de los Grupos E, F y G el comando común ya traducido (A/B/Start/Select/Pad), lee assets de la Flash (D), usa la SPI-RAM como memoria de trabajo (C), pide sonidos al I2S (I), guarda puntajes por I2C (H), le dice al display qué mostrar (J) y registra errores por UART (B).

| Carpeta | Contenido |
|---|---|
| `blink_test/` | Ejemplo del profesor: usa el driver de `blink` |
| `selftest/` *(pendiente)* | Fase 1: autotest de SPI-RAM y SPI-Flash, checksum del menú, log por UART |
| `menu/` *(pendiente)* | Fases 2 y 3: puertos, menú, submenú, modo demo |
| `juego/` *(pendiente)* | Fase 4: bucle del juego, sonido, hot-plug y puntajes |

El flujo general de las cuatro fases está en [`diagramas/README.md`](../diagramas/README.md#3-diagrama-de-flujo-general). Los diagramas de esta página vienen de [`Diagrama_de_Flujo.drawio`](../diagramas/Diagrama_de_Flujo.drawio).

## 1. Menú y opciones

Hoja **«Software_juegos»**.

```mermaid
flowchart TD
    M[MENÚ] --> DJ[Desplegar juegos]
    DJ --> R1[Leer entrada de periféricos]
    R1 --> B1{¿Botón seleccionado?}
    B1 -- UP --> U1[Mover selección hacia arriba] --> DJ
    B1 -- DOWN --> D1[Mover selección hacia abajo] --> DJ
    B1 -- LEFT --> L1[Mover selección hacia la izquierda] --> DJ
    B1 -- RIGHT --> RR1[Mover selección hacia la derecha] --> DJ
    B1 -- B --> RET1[Retroceder] --> M
    B1 -- A --> SEL[Seleccionar juego preseleccionado]
    SEL --> IJ([Inicio de juego])
    IJ --> SM[Desplegar submenú]
    SM --> R2[Leer entrada de periféricos]
    R2 --> B2{¿Botón seleccionado?}
    B2 -- UP --> U2[Mover selección hacia arriba] --> SM
    B2 -- DOWN --> D2[Mover selección hacia abajo] --> SM
    B2 -- B --> RET2[Retroceder] --> DJ
    B2 -- A --> OPS[Seleccionar opción preseleccionada]
    OPS --> OP{Opciones}
    OP --> SP[Singleplayer]
    OP --> MP[Multiplayer]
    OP --> TU[Tutorial]
    OP --> SC[Scores]
    OP --> EX[Exit]
    EX --> M
    SC --> LS[Lista de scores] --> WB[Esperar a que presionen B] --> OP
    TU --> CT["Mostrar controles con descripción de movimiento (por juego)"] --> WB
    MP --> NC{¿Número de controles adecuado?}
    NC -- NO --> ADV[Mensaje de advertencia] --> WB2[Esperar a que presionen B] --> OP
    NC -- SI --> PS
    SP --> PS["Pantalla: Press Start to play / Press B to go to Menu"]
    PS -- B --> OP
    PS -- Start --> RI[Leer entrada de periféricos]
    RI --> CALC[Calcular posición y estado de sprites]
    RI --> UPD[Actualizar posición y estado de sprites] --> SCR[Actualizar pantalla]
    CALC --> COL{¿Colisión?}
    COL -- No --> ASC[Actualizar score] --> RI
    COL -- Sí --> AC[Acción] --> FIN{¿Fin del juego?}
    FIN -- NO --> ASC
    FIN -- SI --> TOP{¿Score entre los 5 mejores?}
    TOP -- NO --> PS
    TOP -- SI --> GS[Guardar score] --> P5[Pantalla: estás entre los 5 mejores]
    P5 --> TEC[Desplegar teclado] --> GN[Guardar nombre y score] --> PS
```

## 2. Lógica del juego (un frame)

Hojas **«Diagrama General + Diagrama de Juego»** y **«Página-17»**.

```mermaid
flowchart TD
    INI["Inicializar variables: vidas = n, puntos = 0"] --> AS[Cargar assets relacionados al juego]
    AS --> PA{¿Partida activa?}
    PA -- No --> SAL([Salida a menú])
    PA -- Sí --> LE[Leer entrada del periférico activo]
    LE --> SE{¿Select seleccionado?}
    SE -- Sí --> TUT[Ejecutar tutorial] --> PA
    SE -- No --> ST{¿Start seleccionado?}
    ST -- Sí --> PZ["Alternar estado: pausa = !pausa"] --> EP{¿Juego en pausa?}
    EP -- Sí --> LE
    EP -- No --> CP
    ST -- No --> CP[Calcular posición del personaje]
    CP --> MV[Mover objetos/enemigos según velocidad]
    MV --> PW{¿Choca con pared u obstáculo?}
    PW -- Sí --> REV[Revertir posición a frame previo] --> EN
    PW -- No --> EN{¿Choca con enemigo o peligro?}
    EN -- Sí --> V1[Vidas = Vidas - 1] --> SD[Reproducir sonido de daño]
    SD --> RS[Reubicar personaje en respawn] --> VD{¿Vidas ≤ 0?}
    VD -- Sí --> GO["Mostrar 'Game Over'"] --> SAL
    VD -- No --> IT
    EN -- No --> IT{¿Choca con item o punto?}
    IT -- Sí --> DI[Destruir/desactivar item] --> PT[Puntos = Puntos + ValorItem]
    PT --> SR[Reproducir sonido de recompensa] --> WIN{¿Puntuación ≥ Puntuación_Ganar?}
    WIN -- Sí --> GAN["Mostrar '¡Ganaste!'"] --> SAL
    WIN -- No --> REN
    IT -- No --> REN[Renderizar imagen/overlay en pantalla]
    REN --> PA
```

## Compilación

La forma de compilar a `firmware.hex` (cargado en la BRAM con `$readmemh`) la documenta el Grupo A junto con el Grupo K (tarea `T-K-02` del [cronograma](../planificacion/cronograma.md)).
