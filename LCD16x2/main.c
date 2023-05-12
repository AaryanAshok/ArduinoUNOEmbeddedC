#include <avr/io.h>
#include <util/delay.h>

// Define the control and data ports and their corresponding DDRs
#define LCD_CTRL_PORT PORTB
#define LCD_DATA_PORT PORTD
#define LCD_CTRL_DDR DDRB
#define LCD_DATA_DDR DDRD

// Define the control pins
#define LCD_EN PB2
#define LCD_RW PB1
#define LCD_RS PB0

// Function to send command to LCD
void lcd_cmd(unsigned char cmd)
{
    LCD_CTRL_PORT &= ~(1 << LCD_RS);                       // RS low for command mode
    LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | (cmd & 0xF0); // Send upper 4 bits of command
    LCD_CTRL_PORT |= (1 << LCD_EN);                        // Enable high
    _delay_ms(2);
    LCD_CTRL_PORT &= ~(1 << LCD_EN); // Enable low
    _delay_ms(50);

    LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | ((cmd & 0x0F) << 4); // Send lower 4 bits of command
    LCD_CTRL_PORT |= (1 << LCD_EN);                               // Enable high
    _delay_ms(2);
    LCD_CTRL_PORT &= ~(1 << LCD_EN); // Enable low
    _delay_ms(2);
}

void lcd_Init()
{
    LCD_CTRL_DDR |= 0b00000111; // PortB pin 0,1,2 as output
    LCD_DATA_DDR |= 0b11110000; // PORTD pin 7,6,5,4 as output
    _delay_ms(20);
    lcd_cmd(0x02); // Initialize to 4-bit mode
    lcd_cmd(0x28); // 2 lines, 5x8 matrix
    lcd_cmd(0x0C); // Display on, cursor off
    lcd_cmd(0x06); // Increment cursor, no shift
    lcd_cmd(0x01); // Clear display
    _delay_ms(2);
}

// Function to send data to LCD
void lcd_data(uint8_t data)
{
    LCD_CTRL_PORT |= (1 << LCD_RS);                         // RS high for data mode
    LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | (data & 0xF0); // Send upper 4 bits of data
    LCD_CTRL_PORT |= (1 << LCD_EN);                         // Enable high
    _delay_ms(2);
    LCD_CTRL_PORT &= ~(1 << LCD_EN); // Enable low
    _delay_ms(50);
    LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | ((data & 0x0F) << 4); // Send lower 4 bits of data
    LCD_CTRL_PORT |= (1 << LCD_EN);                                // Enable high
    _delay_ms(2);
    LCD_CTRL_PORT &= ~(1 << LCD_EN); // Enable low
    _delay_ms(2);
}

// Function to print a string on the LCD
void lcd_puts(char *str)
{
    while (*str != 0)
    {
        lcd_data(*str); // Send each character of the string
        str++;
    }
}

int main()
{
    lcd_Init();
    lcd_puts("Hello There!");
    lcd_cmd(0xC0);
    lcd_puts("Aaryan");
    while (1)
    {
    }
    return 0;
}
