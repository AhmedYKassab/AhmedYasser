

#ifndef BUTTON_INTERFACE_H_
#define BUTTON_INTERFACE_H_



#include "../../MCAL/DIO0/DIO_int.h"

#define PULL_UP 0
#define PULL_DOWN 1


void button_init(u8 PORTID,u8 PINID,u8 mode);
u8 button_state(u8 PORTID,u8 PINID);


#endif /* BUTTON_INTERFACE_H_ */
