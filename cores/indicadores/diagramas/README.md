# Diagramas — Pantallas RGB e indicadores LED de puerto

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

> El diagrama de flujo corresponde a la hoja **«Matriz led»** de [`diagramas/Diagrama_de_Flujo.drawio`](../../../diagramas/Diagrama_de_Flujo.drawio).

```mermaid
flowchart TD
    A([Solicitud: Activar Indicador]) --> B["Inicialización MAX7219 vía SPI<br/>CS = LOW, enviar Shutdown, Decode, ScanLimit, Intensity, CS = HIGH"]
    B --> C["Carga del mapa de píxeles<br/>patrón ERR o X en buffer de 8x32"]
    C --> D["FASE 1: Mostrar falla<br/>CS = LOW, enviar 64 bits/fila por DIN/CLK, CS = HIGH (latch), esperar 500 ms"]
    D --> E["FASE 2: Apagar pantalla<br/>CS = LOW, enviar 0x00 a todas las filas, CS = HIGH (latch), esperar 500 ms"]
    E --> F{"¿El error persiste?"}
    F -- Sí --> D
    F -- No --> G["Limpiar pantalla<br/>datos = 0x00, CS = HIGH"]
    G --> H([Retornar al flujo principal])
```

## Máquina de estados

`INIT`, `LOAD`, `SHOW` (500 ms), `OFF` (500 ms), `CLEAR`. Datapath: maestro SPI de 16 bits, buffer de 8×32 y temporizador de 500 ms.

El diagrama ASM detallado se agrega aquí en el checkpoint 2.
