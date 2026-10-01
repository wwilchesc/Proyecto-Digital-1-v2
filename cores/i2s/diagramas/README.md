# Diagramas — I2S (audio)

## Diagrama de bloques

```mermaid
flowchart LR
    BUS[Bus CSR<br/>d_in, cs, addr, rd, wr] --> REGS[Registros CSR]
    REGS --> CTRL[Unidad de control<br/>FSM]
    CTRL <--> DP[Datapath<br/>desplazamiento, contadores]
    DP <--> PINS[Pines externos]
    DP --> REGS
    REGS --> DOUT[d_out]
```

## Diagrama de flujo

> El diagrama de flujo corresponde a la hoja **«I2S»** de [`diagramas/Diagrama_de_Flujo.drawio`](../../../diagramas/Diagrama_de_Flujo.drawio).

```mermaid
flowchart TD
    A([Inicio]) --> B([Leer archivo .wav]) --> C([Leer metadatos])
    C --> D{¿Es mono?}
    D -- Sí --> F([Leer datos de audio])
    D -- No --> E([Bloqueo de gestión de estéreo]) --> F
    F --> G([Ignorar uno de los canales])
    G --> H([Esperar un pulso de BCLK])
    H --> I([Cambiar de estado LRCLK])
    I --> J(["Enviar 8 bits al DAC (1 bit por cada pulso de BCLK)"])
    J --> K([Reproducir audio])
    K --> L{¿El archivo terminó?}
    L -- No --> F
    L -- Sí --> M([Finalizar reproducción]) --> N([Fin])
```

## Máquina de estados

Contador de bits (0–7) que genera BCLK/LRCLK, registro de desplazamiento de 8 bits y FIFO de muestras.

El diagrama ASM detallado se agrega aquí en el checkpoint 2.
