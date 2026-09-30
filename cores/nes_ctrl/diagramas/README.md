# Diagramas — Control NES

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
    B -- Sí --> C[Esperar POLL_DIV ciclos]
    C --> D[Pulso LATCH]
    D --> E[Leer bit de DATA]
    E --> F[Pulso CLK]
    F --> G{¿8 bits leídos?}
    G -- No --> E
    G -- Sí --> H[Invertir y guardar en BUTTONS_P1/P2]
    H --> B
```

## Máquina de estados

`IDLE`, `LATCH`, `READ`, `SHIFT`, `DONE`. Datapath: divisor de tiempo, contador de bits (0–7), dos registros de desplazamiento.

El diagrama ASM detallado se agrega aquí en el checkpoint 2.
