
#include "std_types.h"
#include "common_macros.h"
#include "LED.h"
#include "avr/io.h"
#include "gpio.h"



void LEDS_init (void) {
	GPIO_setupPinDirection( RED_LED_PORT, RED_LED_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(BLUE_LED_PORT, BLUE_LED_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(GREEN_LED_PORT, GREEN_LED_PIN, PIN_OUTPUT);

	if (LED_LOGIC_TYPE==LED_POSITIVE_LOGIC){
	GPIO_writePin(RED_LED_PORT, RED_LED_PIN, LOGIC_LOW);
	GPIO_writePin(BLUE_LED_PORT, BLUE_LED_PIN, LOGIC_LOW);
	GPIO_writePin(GREEN_LED_PORT, GREEN_LED_PIN, LOGIC_LOW);

	}
	else {
		GPIO_writePin(RED_LED_PORT, RED_LED_PIN, LOGIC_HIGH);
		GPIO_writePin(BLUE_LED_PORT, BLUE_LED_PIN, LOGIC_HIGH);
		GPIO_writePin(GREEN_LED_PORT, GREEN_LED_PIN, LOGIC_HIGH);

	}

	}


	void LED_on(LED_ID id) {
	    switch (id) {
	    case LED_RED:
	        if (LED_LOGIC_TYPE == LED_POSITIVE_LOGIC) {
	            GPIO_writePin(RED_LED_PORT, RED_LED_PIN, LOGIC_HIGH);
	        }
	        else {
	            GPIO_writePin(RED_LED_PORT, RED_LED_PIN, LOGIC_LOW);
	        }
	        break;

	    case LED_GREEN:
	        if (LED_LOGIC_TYPE == LED_POSITIVE_LOGIC) {
	            GPIO_writePin(GREEN_LED_PORT, GREEN_LED_PIN, LOGIC_HIGH);
	        }
	        else {
	            GPIO_writePin(GREEN_LED_PORT, GREEN_LED_PIN, LOGIC_LOW);
	        }
	        break;

	    case LED_BLUE:
	        if (LED_LOGIC_TYPE == LED_POSITIVE_LOGIC) {
	            GPIO_writePin( BLUE_LED_PORT, BLUE_LED_PIN, LOGIC_HIGH);
	        }
	        else {
	            GPIO_writePin( BLUE_LED_PORT, BLUE_LED_PIN, LOGIC_LOW);
	        }
	        break;
	    }
	}

	void LED_off(LED_ID id) {
	    switch (id) {
	    case LED_RED:
	        if (LED_LOGIC_TYPE == LED_POSITIVE_LOGIC) {
	            GPIO_writePin(RED_LED_PORT, RED_LED_PIN, LOGIC_LOW);
	        }
	        else {
	            GPIO_writePin(RED_LED_PORT, RED_LED_PIN, LOGIC_HIGH);
	        }
	        break;

	    case LED_GREEN:
	        if (LED_LOGIC_TYPE == LED_POSITIVE_LOGIC) {
	            GPIO_writePin(GREEN_LED_PORT, GREEN_LED_PIN, LOGIC_LOW);
	        }
	        else {
	            GPIO_writePin(GREEN_LED_PORT, GREEN_LED_PIN, LOGIC_HIGH);
	        }
	        break;

	    case LED_BLUE:
	        if (LED_LOGIC_TYPE == LED_POSITIVE_LOGIC) {
	            GPIO_writePin( BLUE_LED_PORT,  BLUE_LED_PIN, LOGIC_LOW);
	        }
	        else {
	            GPIO_writePin( BLUE_LED_PORT,  BLUE_LED_PIN, LOGIC_HIGH);
	        }
	        break;
	    }
	}
