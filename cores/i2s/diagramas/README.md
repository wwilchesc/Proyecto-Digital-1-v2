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

## Diagrama de flujo (preliminar)

```mermaid
flowchart TD
    A[Reset] --> B{¿ENABLE?}
    B -- No --> B
    B -- Sí --> C{¿MODE?}
    C -- FIFO --> D{¿FIFO vacía?}
    D -- Sí --> E[Enviar 0, UNDERRUN=1]
    D -- No --> F[Tomar muestra de la FIFO]
    C -- Tono --> G[Generar muestra cuadrada]
    E --> H[Serializar canal izquierdo, LRCLK=0]
    F --> H
    G --> H
    H --> I[Serializar canal derecho, LRCLK=1]
    I --> B
```

## Máquina de estados

Contador de bits (0–31) que genera BCLK/LRCLK; registro de desplazamiento de 32 bits; FIFO de muestras; generador de tono opcional.

El diagrama ASM detallado se agrega aquí en el checkpoint 2.
