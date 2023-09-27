


#ifndef INTERRUPT_H_
#define INTERRUPT_H_


#include "../../Lib/BIT_MATH.h"
#include "int register.h"




#define EX_INT0 0
#define EX_INT1 1
#define EX_INT2 2


#define DISABLE 0
#define ENABLE 1


#define LOW_MODE 0
#define ANY_CHANGE_MODE 1
#define FALLING_MODE 2
#define RISING_MODE 3



#define EXT_INT0_VECT __vector_1
#define EXT_INT1_VECT __vector_2
#define EXT_INT2_VECT __vector_3

#define ISR(INT_VECT) void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)




void global_interrupt_state(u8 state);
void interrupt_init(u8 id,u8 mode);
void interrupt_wait_for_flag(u8 id);
void interrupt_enable(u8 id);
void interrupt_disable(u8 id);


#endif /* INTERRUPT_H_ */
