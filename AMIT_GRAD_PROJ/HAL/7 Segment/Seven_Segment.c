

#include "Seven_Segment.h"



void Seven_segment_enable(u8 Segment)
{
	if (Segment == TENS)
	{

		DIO_vidSetPinDirection(DIO_GROUP_B, DIO_PIN_3, DIO_OUTPUT);
		DIO_vidSetPinValue(DIO_GROUP_B, DIO_PIN_3, DIO_HIGH);

	}
	else if (Segment == UNIT)
	{

		DIO_vidSetPinDirection(DIO_GROUP_B, DIO_PIN_1, DIO_OUTPUT);
		DIO_vidSetPinValue(DIO_GROUP_B, DIO_PIN_1, DIO_HIGH);

	}
}


void Seven_segment_disable(u8 Segment)
{
	if (Segment == TENS)
	{

		DIO_vidSetPinDirection(DIO_GROUP_B, DIO_PIN_3, DIO_OUTPUT);
		DIO_vidSetPinValue(DIO_GROUP_B, DIO_PIN_3, DIO_LOW);

	}
	else if (Segment == UNIT)
	{
		DIO_vidSetPinDirection(DIO_GROUP_B, DIO_PIN_1, DIO_OUTPUT);
		DIO_vidSetPinValue(DIO_GROUP_B, DIO_PIN_1, DIO_LOW);
	}
}



void Seven_segment_init(u8 PORTID,u8 type)
{
  if(type == MSB)
  {
	  DIO_vidSetPinDirection(PORTID, DIO_PIN_4, DIO_OUTPUT);
	  DIO_vidSetPinDirection(PORTID, DIO_PIN_5, DIO_OUTPUT);
	  DIO_vidSetPinDirection(PORTID, DIO_PIN_6, DIO_OUTPUT);
	  DIO_vidSetPinDirection(PORTID, DIO_PIN_7, DIO_OUTPUT);
  }
  else if (type == LSB)
  {
	  DIO_vidSetPinDirection(PORTID, DIO_PIN_0, DIO_OUTPUT);
	DIO_vidSetPinDirection(PORTID, DIO_PIN_1, DIO_OUTPUT);
    DIO_vidSetPinDirection(PORTID, DIO_PIN_2, DIO_OUTPUT);
	DIO_vidSetPinDirection(PORTID, DIO_PIN_3, DIO_OUTPUT);
  }
  else
  {

  }
}



void Write_Seven_segment(u8 PORTID,u8 type, u8 num)
{
	if(type == MSB)
	{
		switch(PORTID)
				{
				case DIO_GROUP_A:
					PORTA=(PORTA & 0x0F) | (num<<4);
					break;
				case DIO_GROUP_B:
					PORTB=(PORTB & 0x0F) | (num<<4);
					break;
				case DIO_GROUP_C:
					PORTC=(PORTC & 0x0F) | (num<<4);
					break;
				case DIO_GROUP_D:
					PORTD=(PORTD & 0x0F) | (num<<4);
					break;
				default:
					break;
				}
	}
	else if (type == LSB)
	{
		switch(PORTID)
		{
		case DIO_GROUP_A:
			PORTA=(PORTID & 0xF0) | (num & 0x0F);
			break;
		case DIO_GROUP_B:
			PORTB=(PORTID & 0xF0) | (num & 0x0F);
			break;
		case DIO_GROUP_C:
			PORTC=(PORTID & 0xF0) | (num & 0x0F);
			break;
		case DIO_GROUP_D:
			PORTD=(PORTID & 0xF0) | (num & 0x0F);
			break;
		default:
			break;
		}
	}
}



u8 Read_Seven_segment(u8 PORTID,u8 type)
{
	u8 Bits = 0;
	if(type == MSB)
	{
		Bits = ((PORTID & 0xF0)>>4);
	}
	else if (type == LSB)
	{
		Bits = (PORTID & 0x0F);
	}
	return Bits ;
}


void BothSevenSegmentWrite(u8 PORTID,u8 type,u8 val)
{
	u8 tens,ones;
	if (val <= 99)
	{
		tens = val / 10 ;
		ones = val%10;
		for (u8 i = 0 ; i <= 10 ; i++)
		{
			Seven_segment_disable(TENS);
			Seven_segment_enable(UNIT);
			Write_Seven_segment(PORTID,type,ones);
			_delay_ms(5);
			Seven_segment_disable(UNIT);
			Seven_segment_enable(TENS);
			Write_Seven_segment(PORTID,type,tens);
			_delay_ms(5);
		}
	}
	else
	{

	}
}

void BothSevenSegmentWriteFloat(u8 PORTID,u8 type,u32 val)
{
	u8 tens,ones;
	if (val <= 99)
	{
		tens = val / 10 ;
		ones = val%10;
		for (u8 i = 0 ; i <= 10 ; i++)
		{
			Seven_segment_disable(TENS);
			Seven_segment_enable(UNIT);
			Write_Seven_segment(PORTID,type,ones);
			_delay_ms(5);
			Seven_segment_disable(UNIT);
			Seven_segment_enable(TENS);
			Write_Seven_segment(PORTID,type,tens);
			_delay_ms(5);
		}
	}
	else
	{

	}
}

void SevenSegmentWriteFloat(u8 PORTID,u8 type,u32 val)
{
	u8 tens,ones;
	if (val <= 99)
	{
		tens = val / 10 ;
		ones = val%10;
		Seven_segment_enable(UNIT);
		Seven_segment_enable(TENS);
		if (type == MSB)
		{
			Write_Seven_segment(B,MSB,ones);
		}
		else if (type == LSB)
		{
			Write_Seven_segment(A,LSB,tens);
		}
	}
	else
	{

	}
}




