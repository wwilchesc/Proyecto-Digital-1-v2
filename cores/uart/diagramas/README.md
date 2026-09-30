# Diagramas — UART (depuración)

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
    A[Reset] --> B[Reposo: TX en 1]
    B --> C{¿Escritura en TX_DATA?}
    C -- Sí --> D[TX_BUSY=1, enviar bit de inicio]
    D --> E[Enviar 8 bits, LSB primero]
    E --> F[Bit de parada, TX_BUSY=0]
    F --> B
    C -- No --> G{¿Flanco de bajada en RX?}
    G -- Sí --> H[Muestrear en la mitad de cada bit]
    H --> I[Guardar byte, RX_VALID=1]
    I --> B
    G -- No --> B
```

## Máquina de estados

`IDLE`, `START`, `DATA` (contador de 8 bits), `STOP` — una máquina para TX y otra para RX.

El diagrama ASM detallado se agrega aquí en el checkpoint 2.
