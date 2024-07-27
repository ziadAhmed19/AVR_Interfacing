#Description:

- This file contains the implementation of UART (Universal Asynchronous Receiver/Transmitter) communication functions for ATmega32A.
- It provides functions for initializing the UART module, transmitting and receiving data, as well as handling 9-bit data transmission and reception.

#Functions:

* uart_init(uint32_t BAUD, Parity parity, Mode_Of_Operation mod, Stop_Bit bit, Data_Size packet_size, Clock_Polarity polarity):
    - Initializes the UART module with the specified parameters: baud rate, parity, mode of operation, stop bits, data size, and clock polarity.

* uart_Transmit(uint8_t data):
    - Transmits the given 8-bit data over the UART.

* uart_Transmit_Plus(uint8_t data):
    - Transmits the given 9-bit data over the UART.

* uart_Receive(void):
    - Receives and returns an 8-bit data from the UART.

* uart_Receive_Plus(void):
    - Receives and returns a 9-bit data from the UART.

* uart_Flush(void):
    - Flushes the UART receive buffer by reading and discarding any available data.

#Resources:
8-bit AVR Microcontroller with 32KBytes In-System Programmable Flash DataSheet


#Usage:

1. Include the "UART_Interface.h" header file in your main program.
2. Call the `uart_init` function to configure the UART module according to your requirements.
3. Use `uart_Transmit` or `uart_Transmit_Plus` to send data over the UART.
4. Use `uart_Receive` or `uart_Receive_Plus` to receive data from the UART.
5. Use `uart_Flush` if necessary to clear the receive buffer.

#Author:

ziadAhmed19