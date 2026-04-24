

#ifndef LED_H_
#define LED_H_
#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
 typedef enum {
	 LED_RED,
	 LED_GREEN,
	 LED_BLUE,
	  } LED_ID;

	 typedef enum {
		 LED_POSITIVE_LOGIC, /* LED ON = High, OFF = Low */
		 LED_NEGATIVE_LOGIC /* LED ON = Low, OFF = High */
	 } LED_Logic;
# define RED_LED_PORT   PORTC_ID
# define RED_LED_PIN   PIN0_ID

# define BLUE_LED_PORT   PORTC_ID
# define BLUE_LED_PIN   PIN2_ID

# define GREEN_LED_PORT   PORTC_ID
# define GREEN_LED_PIN   PIN1_ID




#define LED_LOGIC_TYPE  LED_POSITIVE_LOGIC




/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for  Initializes all Leds (red, green, blue) pins direction.
   Turn off all the Leds
 */
void LEDS_init (void );
/*
 * Description :
 * Function responsible for  Turns on the specified LED
 */
void LED_on (LED_ID id);
/*
 * Description :
 * Function responsible for  Turns off the specified LED
 */
void LED_off (LED_ID id);




#endif
