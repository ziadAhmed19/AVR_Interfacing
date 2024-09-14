Author: Ziad Ahmed Hassan El-Banna

Email: ziadwizard612@gmail.com
## Electric_Watrer_Heating_System.c

This code controls an electric water heater system using an AVR microcontroller.

### Functionality

- Controls heating and cooling elements based on a desired temperature set by the user.
- Reads temperature from an LM35 sensor and stores the average in a buffer.
- Allows user to adjust desired temperature with buttons (up and down).
- Toggles system on/off with another button.
- Saves the desired temperature to EEPROM memory when turned off.

### Hardware Used

- AVR Microcontroller (ATMEGA32A)
- Seven Segment Display
- LM35 Temperature Sensor
- Three buttons (On/Off, Up, Down)
- Heating Element
- Cooling Element
- Heating Element LED
- Cooling Element LED
-  EEPROM memory
- 2x 555 Timers ICs
- 5x 10K ohm Resistors
- 2x 68K ohm Resistors
- 4x 10nF Capacitors 
- 7408 2 Input AND Gate IC
- 7404 1 Input NOT Gate IC
- 7447 7-Segment Display Driver IC
- 2-Channel Relay Module 5Volts Control
- 2x DC motors

## Code Explanation: Electric_Watrer_Heating_System.c

# Purpose:
This code controls an electric water heater system using an AVR microcontroller. It regulates the water temperature based on a user-set desired temperature, reads and averages temperature readings from an LM35 sensor, and provides user control via buttons.

-Key Components and Functionality:-

1. Initialization:
   - Initializes peripherals like seven segment display, analog-to-digital converter (ADC), and external interrupts.
   - Sets pin directions for buttons, heating, and cooling elements.

2. -Global Variables:-
   - `gState_flag1` and `gState_flag2`: Flags to indicate the system's on/off state.
   - `i`: Counter for the temperature reading buffer.
   - `Desired_Temperature`: The desired temperature set by the user.
   - `Meaned_Actual_Temperature`: The average of the last 10 temperature readings.
   - `Actual_Temperature_Matrix`: A buffer to store the last 10 temperature readings.

3. -Main Loop:-
   - Continuously checks the system state flags:
     - -On-State:-
       - Displays the desired temperature on the seven-segment display.
     - -Off-State:-
       - Disables the seven-segment display.
       - Reads temperature every 100ms using the ADC.
       - Compares the average temperature with the desired temperature:
         - If the average is below the desired temperature, activates the heating element.
         - If the average is above the desired temperature, activates the cooling element.

4. -Interrupt Service Routines (ISRs):-
   - -INT0_vect (On/Off button):- Toggles the system state flags.
   - -INT1_vect (Up button):- Increments the desired temperature if it's below 75°C.
   - -INT2_vect (Down button):- Decrements the desired temperature if it's above 35°C.
   - -ADC_vect (LM35 sensor):- Reads the ADC value, converts it to temperature, stores it in the buffer, and calculates the average temperature.

5. -EEPROM Storage:-
   - Saves the desired temperature to EEPROM memory when the system is turned off.

-Overall Flow:-
1. The system initializes and enters the main loop.
2. The user sets the desired temperature using the buttons.
3. The system reads the temperature from the LM35 sensor and calculates the average.
4. The system compares the average temperature with the desired temperature and activates the heating or cooling element accordingly.
5. The system continues this process until the user turns it off.
