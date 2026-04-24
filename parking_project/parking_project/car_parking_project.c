
#include "ultrasonic_sensor.h"
#include "lcd.h"
#include "buzzer.h"
#include "led.h"
#include <util/delay.h>
#include <avr/io.h>

int main(void)
{
    uint16 distance = 0;   // variable to store distance value from ultrasonic sensor

    /* Initialize drivers */
    LCD_init();       // initialize the LCD
    LEDS_init();      // initialize all LEDs
    Buzzer_init();    // initialize buzzer
    Ultrasonic_init();// initialize ultrasonic sensor

    SREG |= (1<<7);   // enable global interrupts

    while (1)
    {
        // get distance reading from ultrasonic sensor
        distance = Ultrasonic_readDistance();

        /* case 1: object is very close (<= 5 cm) */
        if (distance <= 5)
        {
            LCD_moveCursor(0,0);
            LCD_displayString("STOP!     ");  // warning message on LCD

            Buzzer_on();  // turn buzzer ON

            // flash all LEDs continuously
            LED_on(LED_RED);
            LED_on(LED_GREEN);
            LED_on(LED_BLUE);
            _delay_ms(200);
            LED_off(LED_RED);
            LED_off(LED_GREEN);
            LED_off(LED_BLUE);
            _delay_ms(200);
        }
        else
        {
            // otherwise display the distance normally
            LCD_moveCursor(0,0);
            LCD_displayString("Dist=");
            LCD_intgerToString(distance);
            LCD_displayString(" cm   ");

            Buzzer_off();  // buzzer OFF

            /* LED indication depending on distance range */
            if (distance >= 6 && distance <= 10)
            {
                // all LEDs ON
                LED_on(LED_RED);
                LED_on(LED_GREEN);
                LED_on(LED_BLUE);
            }
            else if (distance >= 11 && distance <= 15)
            {
                // red + green ON, blue OFF
                LED_on(LED_RED);
                LED_on(LED_GREEN);
                LED_off(LED_BLUE);
            }
            else if (distance >= 16 && distance <= 20)
            {
                // only red ON
                LED_on(LED_RED);
                LED_off(LED_GREEN);
                LED_off(LED_BLUE);
            }
            else
            {
                // all LEDs OFF (safe zone)
                LED_off(LED_RED);
                LED_off(LED_GREEN);
                LED_off(LED_BLUE);
            }

        }
    }
}
