


#include "timer.h"



void timer0_init(u8 mode)
{

	switch(mode)
	{

		case OVERFLOW_MODE:
		CLR_BIT(TCCR0,3);
		CLR_BIT(TCCR0,6);
		break;

		case CTC_MODE:
		SET_BIT(TCCR0,3);
		CLR_BIT(TCCR0,6);
		break;

		case FAST_PWM_MODE:
		SET_BIT(TCCR0,3);
		SET_BIT(TCCR0,6);
		break;

		case PWM_PHASE_CORRECT_MODE:
		CLR_BIT(TCCR0,3);
		SET_BIT(TCCR0,6);
		break;

		default:
		break;	
	}
	TCNT0 = 0;

}


void timer0_start(u8 prescaler)
{

	switch (prescaler)
	{

		case NO_PRE:
		SET_BIT(TCCR0,0);
		CLR_BIT(TCCR0,1);
		CLR_BIT(TCCR0,2);
		break; 

		case PRE8:
		CLR_BIT(TCCR0,0);
		SET_BIT(TCCR0,1);
		CLR_BIT(TCCR0,2);
		break;

		case PRE64:
		SET_BIT(TCCR0,0);
		SET_BIT(TCCR0,1);
		CLR_BIT(TCCR0,2);
		break;

		case PRE256:
		CLR_BIT(TCCR0,0);
		CLR_BIT(TCCR0,1);
		SET_BIT(TCCR0,2);
		break;

		case PRE1024:
		SET_BIT(TCCR0,0);
		CLR_BIT(TCCR0,1);
		SET_BIT(TCCR0,2);
		break;

		default:
		break;
	}

}



void timer0_intial_val(u8 initialval)
{
	TCNT0 = initialval;
}



void timer0_stop(void)
{
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
}



void counter0_start(u8 mode)
{
	switch(mode)
	{

		case EX_FALL:
		CLR_BIT(TCCR0,0);
		SET_BIT(TCCR0,1);
		SET_BIT(TCCR0,2);
		break;

		case EX_RIS:
		SET_BIT(TCCR0,0);
		SET_BIT(TCCR0,1);
		SET_BIT(TCCR0,2);
		break;

		default:
		break;
	}
}


void timer0_wait_for_flag(u8 flag)
{

	switch(flag)
	{

		case OVERFLOW_FLAG:
		while(!GET_BIT(TIFR,0));
		SET_BIT(TIFR,0);
		break;

		case OUT_COMPARE_FLAG:
		while(!GET_BIT(TIFR,1));
		SET_BIT(TIFR,1);
		break;

		default:
		break;
	}

}



void timer0_status(u8 *val)
{
	*val = TCNT0;
}


void timer0_interrupt(u8 mode)
{
	switch(mode)
	{
		case OVERFLOW_MODE:
		SET_BIT(TIMSK,0);
		break;
		case CTC_MODE:
		SET_BIT(TIMSK,1);
		break;
		default:
		break;
	} 
}



void delay(u8 pre,u8 OverflowNumber)
{

	u8 count = 0;
	timer0_start(pre);
	while (count < OverflowNumber)
	{
		timer0_wait_for_flag(OVERFLOW_FLAG);
		count++;
	}
	timer0_stop();
}
