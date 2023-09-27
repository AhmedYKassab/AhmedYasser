

#include "../../Lib/STD_TYPES.h"
#include "../DIO0/DIO_config.h"
#include "../DIO0/DIO_priv.h"

void DIO_vidSetPinDirection(u8 Copy_u8GroupID, u8 Copy_u8PinID, u8 Copy_u8Direction)
{
	if (Copy_u8GroupID <= DIO_GROUP_D && Copy_u8PinID <= DIO_PIN_7
			&& Copy_u8Direction <= DIO_OUTPUT)
	{
        switch(Copy_u8GroupID)
        {
            case DIO_GROUP_A:
                if (Copy_u8Direction == DIO_INPUT)
                    DDRA &=~ (DIO_BIT_MASK<<Copy_u8PinID);
                else
                    DDRA |= (DIO_BIT_MASK<<Copy_u8PinID);
            break;

            case DIO_GROUP_B:
                if (Copy_u8Direction == DIO_INPUT)
                    DDRB &=~ (DIO_BIT_MASK<<Copy_u8PinID);
                else
                    DDRB |= (DIO_BIT_MASK<<Copy_u8PinID);
            break;

            case DIO_GROUP_C:
                if (Copy_u8Direction == DIO_INPUT)
                    DDRC &=~ (DIO_BIT_MASK<<Copy_u8PinID);
                else
                    DDRC |= (DIO_BIT_MASK<<Copy_u8PinID);
            break;

            case DIO_GROUP_D:
                if (Copy_u8Direction == DIO_INPUT)
                    DDRD &=~ (DIO_BIT_MASK<<Copy_u8PinID);
                else
                    DDRD |= (DIO_BIT_MASK<<Copy_u8PinID);
            break;

        }
	}

}

void DIO_vidSetPinValue(u8 Copy_u8GroupID, u8 Copy_u8PinID, u8 Copy_u8Value)
{
    if (Copy_u8GroupID <= DIO_GROUP_D && Copy_u8PinID <= DIO_PIN_7
			&& Copy_u8Value <= DIO_HIGH)
	{
        switch(Copy_u8GroupID)
        {
            case DIO_GROUP_A:
                if (Copy_u8Value == DIO_LOW)
                    PORTA &=~ (DIO_BIT_MASK<<Copy_u8PinID);
                else
                    PORTA |= (DIO_BIT_MASK<<Copy_u8PinID);
            break;

            case DIO_GROUP_B:
                if (Copy_u8Value == DIO_LOW)
                    PORTB &=~ (DIO_BIT_MASK<<Copy_u8PinID);
                else
                    PORTB |= (DIO_BIT_MASK<<Copy_u8PinID);
            break;

            case DIO_GROUP_C:
                if (Copy_u8Value == DIO_LOW)
                    PORTC &=~ (DIO_BIT_MASK<<Copy_u8PinID);
                else
                    PORTC |= (DIO_BIT_MASK<<Copy_u8PinID);
            break;

            case DIO_GROUP_D:
                if (Copy_u8Value == DIO_LOW)
                    PORTD &=~ (DIO_BIT_MASK<<Copy_u8PinID);
                else
                    PORTD |= (DIO_BIT_MASK<<Copy_u8PinID);
            break;

        }
	}

}

void DIO_vidTogglePinValue(u8 Copy_u8GroupID, u8 Copy_u8PinID)
{
    if (Copy_u8GroupID <= DIO_GROUP_D && Copy_u8PinID <= DIO_PIN_7)
	{
        switch(Copy_u8GroupID)
        {
            case DIO_GROUP_A:
                PORTA ^= (DIO_BIT_MASK<<Copy_u8PinID);
            break;

            case DIO_GROUP_B:
                PORTB ^= (DIO_BIT_MASK<<Copy_u8PinID);
            break;

            case DIO_GROUP_C:
                PORTC ^= (DIO_BIT_MASK<<Copy_u8PinID);
            break;

            case DIO_GROUP_D:
                PORTD ^= (DIO_BIT_MASK<<Copy_u8PinID);
            break;

        }
	}
}

u8 DIO_u8GetPinValue(u8 Copy_u8GroupID, u8 Copy_u8PinID)
{
    u8 Local_u8PinValue = 0xff;
    if (Copy_u8GroupID <= DIO_GROUP_D && Copy_u8PinID <= DIO_PIN_7)
	{
        switch(Copy_u8GroupID)
        {
            case DIO_GROUP_A:
                Local_u8PinValue = ((PINA>>Copy_u8PinID)&DIO_BIT_MASK);
            break;

            case DIO_GROUP_B:
                Local_u8PinValue = ((PINB>>Copy_u8PinID)&DIO_BIT_MASK);
            break;

            case DIO_GROUP_C:
                Local_u8PinValue = ((PINC>>Copy_u8PinID)&DIO_BIT_MASK);
            break;

            case DIO_GROUP_D:
                Local_u8PinValue = ((PIND>>Copy_u8PinID)&DIO_BIT_MASK);
            break;

        }
	}
    return Local_u8PinValue;
}



