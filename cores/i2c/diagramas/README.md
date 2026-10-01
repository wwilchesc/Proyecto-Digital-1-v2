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

## Diagrama de flujo

> El diagrama de flujo corresponde a la hoja **«H.1 Protocolo I^2C»** de [`diagramas/Diagrama_de_Flujo.drawio`](../../../diagramas/Diagrama_de_Flujo.drawio).

```mermaid
flowchart TD
    A([Comprobación de elementos al encender]) --> B[Condición de START I2C]
    B --> C[Enviar dirección a elementos]
    C --> D{¿Existe dirección?}
    D -- No --> E[Abortar] --> F[Indicador de código de error]
    D -- Sí --> G[Enviar byte de datos]
    G --> H[Comprobación byte por byte]
    H --> I{¿Información recibida correctamente?}
    I -- No --> E
    I -- Sí --> J([Condición STOP])
    J --> K{¿Faltan componentes?}
    K -- Sí --> G
    K -- No --> L{¿Todos responden OK?}
    L -- No --> M[Saltar condición y código de error]
    L -- Sí --> N[Pantalla de inicio]
```

## Máquina de estados

`IDLE`, `START`, `BIT` (contador 0–7), `ACK`, `STOP`, cada uno dividido en fases del reloj SCL. El firmware arma la secuencia completa de la EEPROM con estas órdenes básicas.

El diagrama ASM detallado se agrega aquí en el checkpoint 2.
