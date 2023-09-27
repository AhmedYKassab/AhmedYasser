
#include "Heater_int.h"





void HEAT_INIT(void)
{
	DIO_vidSetPinDirection(HEAT_PORT, HEAT_PIN, DIO_OUTPUT);
}
void HEAT_START(void)
{
	DIO_vidSetPinValue(HEAT_PORT, HEAT_PIN, DIO_HIGH);
}
void HEAT_STOP(void)
{
	DIO_vidSetPinValue(HEAT_PORT, HEAT_PIN, DIO_LOW);
}

void COOL_INIT(void)
{
	DIO_vidSetPinDirection(COOL_PORT, COOL_PIN, DIO_OUTPUT);
}
void COOL_START(void)
{
	DIO_vidSetPinValue(COOL_PORT, COOL_PIN, DIO_HIGH);
}
void COOL_STOP(void)
{
	DIO_vidSetPinValue(COOL_PORT, COOL_PIN, DIO_LOW);
}

void State_led_INIT(void)
{
	DIO_vidSetPinDirection(STATE_LED_PORT, STATE_LED_PORT, DIO_OUTPUT);
}
void State_led_start(void)
{
	DIO_vidSetPinValue(STATE_LED_PORT, STATE_LED_PIN, DIO_HIGH);
}
void State_led_stop(void)
{
	DIO_vidSetPinValue(STATE_LED_PORT, STATE_LED_PIN, DIO_LOW);
}

void State_led_tog(void)
{
	DIO_vidSetPinValue(STATE_LED_PORT, STATE_LED_PIN, DIO_HIGH);
	_delay_ms(1000);
	DIO_vidSetPinValue(STATE_LED_PORT, STATE_LED_PIN, DIO_LOW);
}


u8 getState(void)
{
	if (DIO_u8GetPinValue(HEAT_PORT, HEAT_PIN)==DIO_HIGH)
	{
		return HEAT_ON;
	}
	else if (DIO_u8GetPinValue(COOL_PORT, COOL_PIN)==DIO_HIGH)
	{
		return COOL_ON;
	}
	else
	{
		return BOTH_OFF;
	}
}

