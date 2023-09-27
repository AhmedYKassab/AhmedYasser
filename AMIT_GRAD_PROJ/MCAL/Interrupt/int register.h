


#ifndef REGISTER_H_
#define REGISTER_H_

#include "../../Lib/STD_TYPES.h"



#define SREG (*((volatile u8 *)0x5F))
#define MCUCR (*((volatile u8 *)0x55))
#define MCUCSR (*((volatile u8 *)0x54))
#define GICR (*((volatile u8 *)0x5B))
#define GIFR (*((volatile u8 *)0x5A))





#endif /* REGISTER_H_ */
