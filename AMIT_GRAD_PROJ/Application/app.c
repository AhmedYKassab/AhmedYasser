
#include "app.h"

static void OFF_STATE(void);

static void ON_STATE(void);
static f32 TempSense(void);
static void SETT_STATE(void);

static void SevenSegmentBlink(void);

u8 state = OFF;  
u8 prevState = 0 ;
u8 timerFlag = 0;
u8 counterFlag = 0;
f32 currentTemp = 0;
u8 setTemp = INITIAL_SET_TEMP;




void APP_init(void)
{
	button_init(DIO_GROUP_D,DIO_PIN_2,PULL_UP); /*Up Button*/
	button_init(DIO_GROUP_D,DIO_PIN_3,PULL_UP); /*Down Button*/
	button_init(DIO_GROUP_B,DIO_PIN_2,PULL_UP); /*ON|OFF Button*/
	interrupt_init(EX_INT0,FALLING_MODE);  /*Up Button as Interrupt 0*/
	interrupt_init(EX_INT1,FALLING_MODE);  /*Down Button as Interrupt 1*/
	interrupt_init(EX_INT2,FALLING_MODE);  /*ON|OFF Button as Interrupt 2*/
	
	
	timer0_init(OVERFLOW_MODE);
	timer0_interrupt(OVERFLOW_MODE);
	
	Seven_segment_init(A,LSB); 
	Seven_segment_init(B,MSB);
	

	EEPROM_init();
 	EEPROM_WRITE(ADDRESS,setTemp);
 	_delay_ms(10);
	
	HEAT_INIT();
	COOL_INIT();
	State_led_INIT();

	LM35_init(A,ADC7);
	
	
}




void APP_start(void)
{

	while(1)
	{
		switch (state)
		{
			case OFF:
			OFF_STATE();
			break;

			case ON:
			ON_STATE();
			break;

			case SETT:
			SETT_STATE();
			break;

			default:
			state = OFF;  
			break;
		}
	}
}





static void OFF_STATE(void)
{

	interrupt_disable(EX_INT0);
	interrupt_disable(EX_INT1);
	prevState = OFF;

	HEAT_STOP();
	COOL_STOP();
	State_led_stop();
	Seven_segment_disable(UNIT);
	Seven_segment_disable(TENS);
}






static void ON_STATE(void)
{
	u8 savedTemp = 0;

	interrupt_enable(EX_INT0);
	interrupt_enable(EX_INT1);

	if (prevState == OFF)
	{
		EEPROM_READ(ADDRESS,&savedTemp);
	}
	else
	{
		savedTemp = setTemp;
	}
	prevState = ON;
	f32 temp = 0;

	temp = TempSense();
	SevenSegmentWriteFloat(DIO_GROUP_A,LSB,temp);
	SevenSegmentWriteFloat(DIO_GROUP_B,MSB,temp);

	if ((temp - savedTemp) > 5)
	{
		HEAT_STOP();
		COOL_START();
	}
	else if ((savedTemp - temp) > 5)
	{
		COOL_STOP();
		HEAT_START();
	}
	else
	{
		COOL_STOP();
		HEAT_STOP();
		State_led_stop();
	}

	if (getState()==HEAT_ON)
	{
		State_led_tog();
	}
	else if (getState()==COOL_ON)
	{
		State_led_start();
	}
	else
	{

	}
}




static f32 TempSense(void)
{
	f32 temp = 0 ;
	f32 readings[SIZE];
	u8 i = 0;

	for (i = 0 ; i < SIZE ; i++)
	{
		timer0_start(PRE256);
		timer0_intial_val(READ_VALUE);
		while(timerFlag != ON_NUM_OVERFLOWS);
		readings[i] = currentTemp;
		timer0_stop();
		timerFlag = 0; 
	}

	for (i = 0 ; i < SIZE ; i++)
	{
		temp = temp + readings[i];
	}
	temp = temp / SIZE ;

	return temp;
}











static void SETT_STATE(void)
{
	u8 temp = 0 ;
	while(1)
	{
		EEPROM_READ(ADDRESS,&temp);
		if (temp == setTemp)
		{
			counterFlag++;
		}
		else
		{

		}

		if (counterFlag > 5)
		{
			break;
		}
		else
		{

			timer0_start(PRE1024);
			timer0_intial_val(SET_INTIAL_VALUE);
			EEPROM_WRITE(ADDRESS,setTemp);
			SevenSegmentBlink();
			while(timerFlag != SET_NUM_OVERFLOWS);
			timer0_stop();
			timerFlag = 0;
		}
	}

	state = ON;
}





static void SevenSegmentBlink(void)
{

	static u8 prev = 0;

	if (prev == 1)
	{
		Seven_segment_disable(UNIT);
		Seven_segment_disable(TENS);
		prev = 0 ;
	}
	else
	{
		SevenSegmentWriteFloat(A,LSB,setTemp);
		SevenSegmentWriteFloat(B,MSB,setTemp);
		prev = 1 ;
	}
}







ISR (EXT_INT0_VECT)
{

	if (state != SETT)
	{
		state = SETT;
	}
	else
	{
		if (setTemp >= 75)
		{
			setTemp = 75 ;
		}
		else
		{
			setTemp = setTemp + 5 ;
		}
	}

	timerFlag = 0;
	counterFlag = 0;
}





ISR (EXT_INT1_VECT)
{

	if (state != SETT)
	{
		state = SETT;
	}
	else
	{

		if (setTemp <= 35)
		{
			setTemp = 35 ;
		}
		else
		{
			setTemp = setTemp - 5 ;
		}
	}

	timerFlag = 0;
	counterFlag = 0;
}






ISR (EXT_INT2_VECT)
{

	if (state == OFF)
	{
		state = ON;
	}
	else if (state == ON)
	{
		state = OFF;
	}
	else
	{

	}
}







ISR(TIMER0_OVF_vect)
{
	timerFlag++;
	if (state == ON)
	{
		if (timerFlag == 2)
		{
			currentTemp = LM35_Read(ADC7);
		}
	}
}


