# Diagramas — I2C (EEPROM de puntajes)

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
    A[Reset: SCL=1, SDA=1] --> B{¿Orden en CONTROL?}
    B -- START --> C[SDA baja con SCL alto]
    B -- WRITE --> D[Enviar 8 bits y leer ACK]
    B -- READ --> E[Leer 8 bits y enviar ACK/NACK]
    B -- STOP --> F[SDA sube con SCL alto]
    B -- Ninguna --> B
    C --> G[DONE=1]
    D --> G
    E --> G
    F --> G
    G --> B
```

## Máquina de estados

`IDLE`, `START`, `BIT` (contador 0–7), `ACK`, `STOP`, cada uno dividido en fases del reloj SCL. El firmware arma la secuencia completa de la EEPROM con estas órdenes básicas.

El diagrama ASM detallado se agrega aquí en el checkpoint 2.
