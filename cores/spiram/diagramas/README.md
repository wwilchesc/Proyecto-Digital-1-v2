# Diagramas — SPI-RAM

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
    A[Reset: CS_N=1] --> B{¿CONTROL.START?}
    B -- No --> B
    B -- Sí --> C[BUSY=1, CS_N=0]
    C --> D[Enviar comando 0x03 o 0x02]
    D --> E[Enviar dirección de 24 bits]
    E --> F{¿RW?}
    F -- Escribir --> G[Enviar WDATA]
    F -- Leer --> H[Recibir byte en RDATA]
    G --> I[CS_N=1, BUSY=0, DONE=1]
    H --> I
    I --> B
```

## Máquina de estados

`IDLE`, `CMD`, `ADDR`, `DATA`, `DONE`. Datapath: registro de desplazamiento de 8 bits + contador de bits + divisor de reloj.

El diagrama ASM detallado se agrega aquí en el checkpoint 2.
