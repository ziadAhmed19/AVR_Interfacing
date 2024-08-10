# SPI Library for AVR Microcontrollers

## Overview
This SPI (Serial Peripheral Interface) library is designed for AVR microcontrollers, specifically targeting the ATmega32. The library provides a simple interface for initializing and using SPI communication in both Master and Slave modes. It supports various configurations such as data order, clock polarity, clock phase, and interrupt settings. The library allows for transmitting and receiving data as well as strings over the SPI bus.

## Features
- **Master and Slave Modes**: Support for both Master and Slave configurations.
- **Configurable Data Order**: Choose between MSB-first or LSB-first data transmission.
- **Clock Polarity and Phase Control**: Configure clock polarity and phase to match the needs of your peripheral devices.
- **Interrupt Handling**: Enable or disable SPI interrupts for non-blocking communication.
- **String Transmission**: Send and receive strings via SPI with simple function calls.

## File Structure
- **SPI_Program.c**: Contains the implementation of SPI functions, including initialization, data transmission, and reception.
- **SPI_Interface.h**: Header file declaring the functions and enumerations used in the library (not included in the provided code snippet but assumed to exist).

## Usage

### Initialization
#### Master Initialization
To initialize the microcontroller as an SPI Master:

SPI_Master_Init(MSB, LeadingEdge_Sample_Rising_TrailingEdge_Setup_Falling, Fosc_16, Interruput_Enabled);

- **Data Order**: `MSB` (Most Significant Bit first) or `LSB` (Least Significant Bit first).
- **SPI Mode**: Clock polarity and phase (e.g., `LeadingEdge_Sample_Rising_TrailingEdge_Setup_Falling`).
- **Clock Rate**: Choose from `Fosc_4`, `Fosc_16`, `Fosc_64`, `Fosc_128`, or their doubled-speed versions.
- **Interrupt**: `Interruput_Enabled` or `Interruput_Disabled`.

#### Slave Initialization
To initialize the microcontroller as an SPI Slave:

SPI_Slave_Init(MSB, Interruput_Enabled);

- **Data Order**: `MSB` or `LSB`.
- **Interrupt**: `Interruput_Enabled` or `Interruput_Disabled`.

### Data Transmission and Reception
#### Master Transmit
To transmit a single byte of data as a master:
```c
SPI_Master_Transmit(0x55);
```

To transmit a string of data as a master:

SPI_Master_Transmit_String((uint8_t*)"Hello, Slave!");


#### Master Receive
To receive a single byte of data as a master:

uint8_t data = SPI_Master_Receive();


#### Slave Receive
To receive a single byte of data as a slave:

uint8_t data = SPI_SLave_Receive();


#### Slave Transmit
To transmit a single byte of data as a slave:

SPI_Slave_Transmit(0xAA);


To transmit a string of data as a slave:

SPI_Slave_Transmit_String((uint8_t*)"Hello, Master!");


### Slave Selection Control (Master Only)
To select or deselect a slave device:

SPI_Master_SS(Slave_One, Select); // Selects the first slave
SPI_Master_SS(Slave_One, DeSelect); // Deselects the first slave

- **SlaveAddress**: Specify which slave to select or deselect (e.g., `Slave_One`).
- **Selection_State**: `Select` or `DeSelect`.

## Example Usage
Here’s a basic example of how you might use the library in your `main.c` file:


#include "SPI_Interface.h"

int main(void) {
    // Initialize SPI as Master
    SPI_Master_Init(MSB, LeadingEdge_Sample_Rising_TrailingEdge_Setup_Falling, Fosc_16, Interruput_Enabled);

    // Select the slave
    SPI_Master_SS(Slave_One, Select);

    // Transmit a string
    SPI_Master_Transmit_String((uint8_t*)"Hello, Slave!");

    // Receive a response
    uint8_t response = SPI_Master_Receive();

    // Deselect the slave
    SPI_Master_SS(Slave_One, DeSelect);

    while (1) {
        // Main loop
    }
}


## License
This SPI library is released under the MIT License. Feel free to modify and use it in your projects.

## Acknowledgments
Thanks to the AVR community for providing extensive resources and documentation that made this project possible.
