#include "buzzer.h"
#include "gpio.h"

/***************************************************
 * Description : Initialize the buzzer to be off

 ***************************************************/
void Buzzer_init(void){

    GPIO_setupPinDirection(BUZZER_portID, BUZZER__PinID, PIN_OUTPUT);
    GPIO_writePin(BUZZER_portID, BUZZER__PinID, LOGIC_LOW);
}


/***************************************************
 * Description : Turn on the buzzer
 ***************************************************/
void Buzzer_on(void){
	GPIO_writePin(BUZZER_portID,BUZZER__PinID,LOGIC_HIGH);

}

/***************************************************
 * Description : Turn off the buzzer
 ***************************************************/
void Buzzer_off(void){

	GPIO_writePin(BUZZER_portID,BUZZER__PinID,LOGIC_LOW);

}

