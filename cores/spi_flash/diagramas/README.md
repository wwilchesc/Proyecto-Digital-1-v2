# Diagramas — SPI-Flash

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
    A[Reset] --> B{¿CONTROL.START?}
    B -- No --> B
    B -- Sí --> C[CS_N=0, enviar CMD]
    C --> D{¿El comando lleva dirección?}
    D -- Sí --> E[Enviar dirección de 24 bits]
    D -- No --> F
    E --> F{¿Lectura o escritura de dato?}
    F -- Lectura --> G[Recibir byte en RDATA]
    F -- Escritura --> H[Enviar WDATA]
    F -- Ninguno --> I
    G --> I[CS_N=1, DONE=1]
    H --> I
    I --> B
```

## Máquina de estados

`IDLE`, `CMD`, `ADDR`, `DATA`, `DONE`. Puede reutilizar el maestro SPI del Grupo 2 (misma base de RTL que la SPI-RAM).

El diagrama ASM detallado se agrega aquí en el checkpoint 2.
