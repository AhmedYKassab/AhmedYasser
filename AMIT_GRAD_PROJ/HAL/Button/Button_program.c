

#include "Button_interface.h"



void button_init(u8 PORTID,u8 PINID,u8 mode)
{
	if (mode == PULL_UP)
	{
DIO_vidSetPinDirection(PORTID, PINID, DIO_INPUT);
DIO_vidSetPinValue(PORTID, PINID, DIO_PULL_UP);

	}
	else if (mode == PULL_DOWN)
	{
		DIO_vidSetPinDirection(PORTID, PINID, DIO_INPUT);
		DIO_vidSetPinValue(PORTID, PINID, DIO_FLOAT);
	}
	else
	{

	}
	
}



u8 button_state(u8 PORTID,u8 PINID)
{
	return DIO_u8GetPinValue(PORTID, PINID);

}
