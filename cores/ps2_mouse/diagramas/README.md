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

## Diagrama de flujo

> El diagrama de flujo corresponde a la hoja **«F-Mouse»** de [`diagramas/Diagrama_de_Flujo.drawio`](../../../diagramas/Diagrama_de_Flujo.drawio).

```mermaid
flowchart TD
    A([Setup del ratón]) --> B([Establecer conexión: reset])
    B --> C{¿Autotest del mouse superado?}
    C -- No --> B
    C -- Sí --> D[Establecer frecuencia de muestreo]
    D --> E[Frecuencia input 1] --> F[Frecuencia input 2] --> G[Frecuencia input 3]
    G --> H[Solicitar ID]
    H --> I{¿ID recibido de Microsoft?}
    I -- No --> B
    I -- Sí --> J[Establecer resolución] --> K[Introducir resolución]
    K --> L[Establecer escala] --> M[Establecer frec. muestreo] --> N[Introducir frec. muestreo]
    N --> O[Habilitación]
    O --> P([LECTURA de paquetes])
```

## Máquina de estados

Transmisión host→dispositivo: `INHIBIT`, `REQ`, `SEND`, `WAIT_ACK`. Recepción: se reutiliza el receptor PS/2 del teclado + contador de bytes del paquete (0–2).

El diagrama ASM detallado se agrega aquí en el checkpoint 2.
