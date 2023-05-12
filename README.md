# Atmega328P Embedded-C programming on ArduinoUNO Board
Here we are demonstrating some Embedded C practice codes that can be tried on Arduino Uno hardware as well as tinkercad simulator online.Follow the guide DIY.

## Initial Setup
This is a step-by-step guide for compiling embedded C code for the ATMEGA328P microcontroller using arm-gcc and loading it onto an Arduino UNO board. Use of Ubuntu is recomended.I'm using Windows11 WSL.

Set up Windows Subsystem for Linux (WSL)
Open the Microsoft Store and search for "Ubuntu" or another Linux distribution of your choice.
Install the distribution and launch it.
Follow the prompts to create a username and password. For more information visit this [link](https://learn.microsoft.com/en-us/windows/wsl/install).

### Install necessary packages
Open a terminal window and enter the following command to update the package list: 

```bash
sudo apt-get update
```

Install the arm-gcc toolchain using the following command: 
```bash
sudo apt-get install gcc-arm-none-eabi
```
Install the avrdude tool to upload the compiled code onto the Arduino board: 
```bash
sudo apt-get install avrdude
```
## Code Compile and load
To compile the code run fllowing commands in project directory.
```
avr-gcc -Wall -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o main.o main.c
```
```
avr-gcc -mmcu=atmega328p -o main.elf main.o
```
```
avr-objcopy -O ihex -R .eeprom main.elf main.hex
```
Before loading the code make sure the Arduino is connected to WSL. follow the steps given in the [video](https://youtu.be/TtnIdm6It00).

To load the code on arduino board run following command.
```
sudo avrdude -p atmega328p -c arduino -P /dev/ttyACM0 -U flash:w:main.hex
```