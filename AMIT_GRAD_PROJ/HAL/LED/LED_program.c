

#include "LED_interface.h"



void LED_init(u8 PORTID,u8 PINID)
{
	DIO_vidSetPinDirection(PORTID, PINID, DIO_OUTPUT);
}



void LED_on(u8 PORTID,u8 PINID)
{
	DIO_vidSetPinValue(PORTID, PINID, DIO_HIGH);
}



void LED_off(u8 PORTID,u8 PINID)
{
	DIO_vidSetPinValue(PORTID, PINID, DIO_LOW);
}



void LED_toggle(u8 PORTID,u8 PINID)
{
	if(DIO_u8GetPinValue(PORTID, PINID)==DIO_HIGH)
	{
		LED_off(PORTID, PINID);
	}
	else if(DIO_u8GetPinValue(PORTID, PINID)==DIO_LOW)
	{
		LED_on(PORTID, PINID);
	}
	else
	{

	}
}
