# ATmega328P 16x2 LCD Interface
This is a simple example code for interfacing a 16x2 LCD with an ATmega328P microcontroller. The code uses 4-bit mode for sending data and control signals to the LCD. The code initializes the LCD, prints "Hello There!" on the first row and "Aaryan" on the second row.

### Hardware Requirements
1. ATmega328P Microcontroller
2. 16x2 LCD Module
3. Potentiometer (10KΩ)
4. Breadboard
5. Jumper Wires
6. Resistor (220Ω)

### Circuit Diagram
The following is the circuit diagram for the LCD interface. The potentiometer is used to adjust the contrast of the LCD.

### Code Description
The code uses the following pins for interfacing the LCD:

PB0: RS (Register Select)
PB1: RW (Read/Write)
PB2: EN (Enable)
PD4-PD7: D4-D7 Data pins (4-bit mode)
The lcd_Init() function initializes the LCD in 4-bit mode with 2 rows and 5x8 dot matrix. The lcd_cmd() function sends a command to the LCD. The lcd_data() function sends data to the LCD. The lcd_puts() function sends a string to the LCD.

In the main() function, the LCD is initialized and "Hello There!" is printed on the first row using lcd_puts() function. The cursor is then moved to the second row using lcd_cmd(0xC0) and "Aaryan" is printed on the second row using lcd_puts() function.

### Running the Code
Connect the circuit as shown in the circuit diagram.
Connect the Arduino UNO to your computer.
refer [Code Compile and Load](https://github.com/AaryanAshok/ArduinoUNOEmbeddedC/blob/main/README.md) Section for further details.