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

## Diagrama de flujo

> El diagrama de flujo corresponde a la hoja **«Controlador NES»** de [`diagramas/Diagrama_de_Flujo.drawio`](../../../diagramas/Diagrama_de_Flujo.drawio).

```mermaid
flowchart TD
    A([Leer mando NES]) --> B[LATCH = HIGH] --> C[Esperar 12 µs] --> D[LATCH = LOW]
    D --> E[Leer pin DATA] --> F["Guardar en registro_temp[0]"] --> G[i = 1]
    G --> H{i ≤ 7}
    H -- Sí --> I[CLOCK = HIGH] --> J[Esperar 6 µs] --> K[CLOCK = LOW] --> L[Esperar 6 µs]
    L --> M[Leer pin DATA] --> N["Guardar en registro_temp[i]"] --> O[i = i + 1] --> H
    H -- No --> P["Invertir bits: byte = ~registro_temp"]
    P --> Q[Escribir byte en MMIO 0x450000]
    Q --> R["'Dato listo' en 0x450008"]
    R --> S([Byte listo para la CPU])
    S --> T[Esperar temporizador de 16.6 ms, 60 Hz] --> A
```

## Máquina de estados

`IDLE`, `LATCH` (12 µs), `READ`, `CLK_HIGH` (6 µs), `CLK_LOW` (6 µs), `STORE`, `WAIT_60HZ`. Datapath: contador de tiempo, contador de bits `i` (0–7), registro `registro_temp` de 8 bits.

El diagrama ASM detallado se agrega aquí en el checkpoint 2.
