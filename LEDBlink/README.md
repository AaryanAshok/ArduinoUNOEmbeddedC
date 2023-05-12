# ATMEGA328P LED Blink Program on Arduino UNO Using EmbeddedC

This is a simple program for blinking an LED connected to an ATMEGA328P microcontroller. This program can be used as a starting point for learning embedded programming with the ATMEGA328P microcontroller. This program is written in EmbeddedC and can be dumped on Arduino UNO.

## Hardware Requirements
1. ATMEGA328P microcontroller

## Code Explanation
The code uses the AVR-GCC library to control the ATMEGA328P microcontroller's I/O pins. The program initializes the DDRB register as an output port and sets the value of PORTB register to toggle the LED connected to PB5. The delay function is used to control the speed of the LED blinking.

## Running the Program
### Tinkercad link:
Visit [TinkerCAD](https://www.tinkercad.com/things/7cqUnSutyBN) to try simulation of the following program.
### Hardware:
Please refer [Code Compile and Load](https://github.com/AaryanAshok/ArduinoUNOEmbeddedC/blob/main/README.md) Section.
