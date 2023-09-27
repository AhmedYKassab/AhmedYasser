

#ifndef HAL_HAL_HEATER_INT_HEATER_INT_H_
#define HAL_HAL_HEATER_INT_HEATER_INT_H_


#include "../../MCAL/DIO0/DIO_int.h"
#include <util/delay.h>
#include "../../Lib/BIT_MATH.h"
#include "../../Lib/STD_TYPES.h"


#define HEAT_PORT        DIO_GROUP_C
#define HEAT_PIN         DIO_PIN_2

#define COOL_PORT        DIO_GROUP_C
#define COOL_PIN         DIO_PIN_3

#define STATE_LED_PORT        DIO_GROUP_C
#define STATE_LED_PIN         DIO_PIN_4

#define BOTH_OFF 0
#define HEAT_ON 1
#define COOL_ON 2
 

void HEAT_INIT(void);
void HEAT_START(void);
void HEAT_STOP(void);

void COOL_INIT(void);
void COOL_START(void);
void COOL_STOP(void);

void State_led_INIT(void);
void State_led_start(void);
void State_led_stop(void);
void State_led_tog(void);
u8 getState(void);


#endif
