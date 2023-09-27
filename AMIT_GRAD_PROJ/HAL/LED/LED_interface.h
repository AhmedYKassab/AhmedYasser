

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_



#include "../../MCAL/DIO0/DIO_int.h"



void LED_init(u8 PORTID,u8 PINID);


void LED_on(u8 PORTID,u8 PINID);


void LED_off(u8 PORTID,u8 PINID);


void LED_toggle(u8 PORTID,u8 PINID);



#endif /* LED_INTERFACE_H_ */
