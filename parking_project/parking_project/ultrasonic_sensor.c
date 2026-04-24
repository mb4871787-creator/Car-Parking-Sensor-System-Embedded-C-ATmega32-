#include "ultrasonic_sensor.h"
#include "icu.h"
#include "gpio.h"
#include "std_types.h"
#include "common_macros.h"
#include <util/delay.h>


 uint16 g_distance;
 uint16 g_time;
 uint8 g_edges_counter;



void Ultrasonic_init(void){

	ICU_ConfigType icu_type = {F_CPU_8, RAISING};

	ICU_init(&icu_type);
	/*call back by passing the address of the edge processing function
	 *  (name of the function = address of the function )*/
	ICU_setCallBack(Ultrasonic_edgeProcessing);
	/* setup the direction of the trigger to be output pin */
	GPIO_setupPinDirection(ULTRASONIC_TRIGGER_PORTID,ULTRASONIC_TRIGGER_PINID,PIN_OUTPUT);
}


void Ultrasonic_Trigger(void) {
	GPIO_writePin(ULTRASONIC_TRIGGER_PORTID,ULTRASONIC_TRIGGER_PINID,LOGIC_HIGH);
		/*delay for sending signal*/
		_delay_us(10);
		/*give the trigger logic low (0) to stop send signal */
		GPIO_writePin(ULTRASONIC_TRIGGER_PORTID,ULTRASONIC_TRIGGER_PINID,LOGIC_LOW);
}

uint16 Ultrasonic_readDistance(void){
	/* Send the trigger pulse by using the Ultrasonic_Trigger
function. */
	Ultrasonic_Trigger ();
	if(g_edges_counter==2){ //raising & falling -> 1 cycle
			g_edges_counter=0; //reset the counter of the edges
			//g_distance = (g_time*0.01715);
			g_distance = g_time / 116;
			}
			return (g_distance+1);

}

void Ultrasonic_edgeProcessing(void){
	g_edges_counter++;
	if(g_edges_counter==1){
		/*clear the timer register to start the timer when the rising edge is detected*/
		ICU_clearTimerValue();
		/*change the edge select to the falling edge to know the time of the pulse*/
		ICU_setEdgeDetectionType(FALLING);
	}
	/*this condition will be true when the falling edge is detected*/
	else if(g_edges_counter==2){
		/*we will read the input capture register and save it inside the g_timeHigh*/
		g_time =  ICU_getInputCaptureValue ();

		/*clear the input capture register to start detect again*/
		ICU_clearTimerValue();

		/*To start detecting from the rising edge*/
		ICU_setEdgeDetectionType(RAISING);
	}
}
