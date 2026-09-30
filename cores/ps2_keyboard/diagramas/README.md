# Diagramas — Teclado PS/2

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
    A[Reset] --> B[Sincronizar ps2_clk y detectar flanco de bajada]
    B --> C{¿Bit de inicio = 0?}
    C -- No --> B
    C -- Sí --> D[Leer 8 bits de datos]
    D --> E[Leer paridad y parada]
    E --> F{¿Paridad impar correcta?}
    F -- No --> G[PARITY_ERR=1]
    F -- Sí --> H{¿FIFO llena?}
    H -- Sí --> I[OVERFLOW=1]
    H -- No --> J[Guardar scan code, VALID=1]
    G --> B
    I --> B
    J --> B
```

## Máquina de estados

`IDLE`, `DATA` (contador 0–7), `PARITY`, `STOP`. Datapath: sincronizador de 2 flip-flops, filtro del reloj PS/2, registro de desplazamiento, FIFO de 8–16 posiciones.

El diagrama ASM detallado se agrega aquí en el checkpoint 2.
