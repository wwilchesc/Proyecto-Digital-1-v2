# Diagramas — Display (panel LED / framebuffer)

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

```mermaid
flowchart TD
    A[Reset] --> B[Limpiar framebuffer]
    B --> C{¿El Grupo K escribió un frame nuevo?}
    C -- No --> D[Refrescar panel con el frame actual]
    C -- Sí --> E[Tomar el framebuffer actualizado] --> D
    D --> C
```

## Máquina de estados

Contador de filas y columnas que recorre el framebuffer y la máquina de envío al panel (según el tipo de panel).

El diagrama ASM detallado se agrega aquí en el checkpoint 2.
