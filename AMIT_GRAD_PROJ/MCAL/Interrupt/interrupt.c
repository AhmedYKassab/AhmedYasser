


#include "interrupt.h"



void global_interrupt_state(u8 state)
{
	if (state == ENABLE)
	{
		SET_BIT(SREG,7);
	}
	else
	{
		CLR_BIT(SREG,7);
	}

}



void interrupt_init(u8 id,u8 mode)
{

	global_interrupt_state(ENABLE);
	switch(id)
	{

		case EX_INT0:
		if (mode == LOW_MODE)
		{
			CLR_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
			SET_BIT(GICR,6);
		}
		else if (mode == ANY_CHANGE_MODE)
		{
			SET_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
			SET_BIT(GICR,6);
		}
		else if (mode == FALLING_MODE)
		{
			CLR_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
			SET_BIT(GICR,6);
		}
		else if (mode == RISING_MODE)
		{
			SET_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
			SET_BIT(GICR,6);
		}
		else
		{

		}
		break;

		case EX_INT1:
		if (mode == LOW_MODE)
		{
			CLR_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
			SET_BIT(GICR,7);
		}
		else if (mode == ANY_CHANGE_MODE)
		{
			SET_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
			SET_BIT(GICR,7);
		}
		else if (mode == FALLING_MODE)
		{
			CLR_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
			SET_BIT(GICR,7);
		}
		else if (mode == RISING_MODE)
		{
			SET_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
			SET_BIT(GICR,7);
		}
		else
		{

		}
		break;

		case EX_INT2:
		if (mode == FALLING_MODE)
		{
			CLR_BIT(MCUCSR,6);
			SET_BIT(GICR,5);
		}
		else if (mode == RISING_MODE)
		{
			SET_BIT(MCUCSR,6);
			SET_BIT(GICR,5);
		}
		else
		{

		}
		break;

		default:

		break;
	}

}



void interrupt_wait_for_flag(u8 id)
{
	switch(id)
	{

		case EX_INT0:
		while(!GET_BIT(GIFR,6));
		SET_BIT(GIFR,6);
		break;

		case EX_INT1:
		while(!GET_BIT(GIFR,7));
		SET_BIT(GIFR,7);
		break;

		case EX_INT2:
		while(!GET_BIT(GIFR,5));
		SET_BIT(GIFR,5);
		break;

		default:
		break;
	}

}



void interrupt_enable(u8 id)
{

	switch(id)
	{
		case EX_INT0:
		SET_BIT(GICR,6);
		break;

		case EX_INT1:
		SET_BIT(GICR,7);
		break;

		case EX_INT2:
		SET_BIT(GICR,5);
		break;

		default:

		break;
	}

}


void interrupt_disable(u8 id)
{

	switch(id)
	{

		case EX_INT0:
		CLR_BIT(GICR,6);
		break;

		case EX_INT1:
		CLR_BIT(GICR,7);
		break;

		case EX_INT2:
		CLR_BIT(GICR,5);
		break;

		default:
		break;
	}
}
