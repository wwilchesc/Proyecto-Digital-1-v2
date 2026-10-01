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

## Diagrama de flujo

> El diagrama de flujo corresponde a la hoja **«E Keyboard»** de [`diagramas/Diagrama_de_Flujo.drawio`](../../../diagramas/Diagrama_de_Flujo.drawio).

```mermaid
flowchart TD
    A([Conexión]) --> B([Espera de un cambio de estado])
    B --> C{¿Dato diferente de cero?}
    C -- No --> B
    C -- Sí --> D([Recibimiento de datos])
    D -- entrar en ciclo --> E[Transporte de la señal y traducción por medio del driver]
    E -- registro de 8 bits --> F{¿El valor pertenece a la lista relevante?}
    F -- Sí --> G([Conversión de datos al formato legible por la lógica del sistema])
    G --> H([Dato retenido, disponible])
    H --> I([Paso al siguiente loop de lectura de señales])
    F -- No --> I
    I --> B
```

## Máquina de estados

`IDLE`, `DATA` (contador 0–7), `PARITY`, `STOP`. Datapath: sincronizador de 2 flip-flops, filtro del reloj PS/2, registro de desplazamiento, FIFO de 8–16 posiciones.

El diagrama ASM detallado se agrega aquí en el checkpoint 2.
