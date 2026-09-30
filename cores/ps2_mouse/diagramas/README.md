# Diagramas — Mouse PS/2

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
    A[Reset] --> B{¿CONTROL.INIT?}
    B -- No --> B
    B -- Sí --> C[Host: inhibir reloj ≥100 µs y enviar 0xF4]
    C --> D{¿Recibe 0xFA?}
    D -- No --> E[ERR=1] --> B
    D -- Sí --> F[READY=1]
    F --> G[Recibir byte 1: botones y signos]
    G --> H[Recibir byte 2: ΔX]
    H --> I[Recibir byte 3: ΔY]
    I --> J[Actualizar DX, DY, BUTTONS; NEW_PACKET=1]
    J --> G
```

## Máquina de estados

Transmisión host→dispositivo: `INHIBIT`, `REQ`, `SEND`, `WAIT_ACK`. Recepción: se reutiliza el receptor PS/2 del teclado + contador de bytes del paquete (0–2).

El diagrama ASM detallado se agrega aquí en el checkpoint 2.
