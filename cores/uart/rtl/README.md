# RTL — UART (depuración)

Pendiente (checkpoint 3). Aquí van, siguiendo el ejemplo [`cores/blink/rtl`](../../blink/rtl/):

- `perip_uart.v` — módulo Verilog sintetizable
- `perip_uart_TB.v` — testbench automático (imprime `PASS`/`FAIL`)
- `perip_uart_TB.gtkw` — señales para GTKWave
- `Makefile` — `make sim` y `make wave`
