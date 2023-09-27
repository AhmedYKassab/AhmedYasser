


#ifndef TIMER_H_
#define TIMER_H_

#include "Timer0 register.h"


#define OVERFLOW_MODE 0
#define CTC_MODE 1
#define FAST_PWM_MODE 2
#define PWM_PHASE_CORRECT_MODE 3



#define NO_CLK 0
#define NO_PRE 1
#define PRE8 2
#define PRE64 3
#define PRE256 4
#define PRE1024 5
#define EX_FALL 6
#define EX_RIS 7


#define OVERFLOW_FLAG 0
#define OUT_COMPARE_FLAG 1



  
#define TIMER0_OVF_vect __vector_11


void timer0_init(u8 mode);
void timer0_start(u8 prescaler);
void timer0_intial_val(u8 initialval);
void timer0_stop(void);
void counter0_start(u8 mode);
void timer0_wait_for_flag(u8 flag);
void timer0_status(u8 *val);
void timer0_interrupt(u8 mode);
void delay(u8 pre,u8 OverflowNumber);







#endif /* TIMER_H_ */
