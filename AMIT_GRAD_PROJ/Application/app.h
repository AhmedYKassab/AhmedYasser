


#ifndef APP_H_
#define APP_H_



#include "../HAL/LED/LED_interface.h"
#include "../HAL/Button/Button_interface.h"
#include "../HAL/7 Segment/Seven_Segment.h"
#include "../HAL/EEPROM/EEPROM_interface.h"
#include "../HAL/Heater/Heater_int.h"
#include "../MCAL/Interrupt/interrupt.h"
#include "../MCAL/Timer/timer.h"
#include "../HAL/Temp Sensor/LM35.h"





#define OFF 0
#define ON 1
#define SETT 2
#define ADDRESS 0X0301
#define INITIAL_SET_TEMP 60
#define SET_NUM_OVERFLOWS 4
#define ON_NUM_OVERFLOWS 2
#define SET_INTIAL_VALUE 12
#define READ_VALUE 61
#define SIZE 10





void APP_init();
void APP_start();



#endif /* APP_H_ */
