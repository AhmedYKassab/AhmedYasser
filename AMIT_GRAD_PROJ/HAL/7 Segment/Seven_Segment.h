

#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_



#include "../../MCAL/DIO0/DIO_int.h"
#include "../../MCAL/DIO0/DIO_config.h"
#include <util/delay.h>


#define MSB 1
#define LSB 0


#define TENS 1
#define UNIT 0



void Seven_segment_enable(u8 Segment);

void Seven_segment_disable(u8 Segment);

void Seven_segment_init(u8 PORTID,u8 type);

void Write_Seven_segment(u8 PORTID,u8 type, u8 num);

u8 Read_Seven_segment(u8 PORTID,u8 type);

void BothSevenSegmentWrite(u8 PORTID,u8 type,u8 val);

void BothSevenSegmentWriteFloat(u8 PORTID,u8 type,u32 val);
void SevenSegmentWriteFloat(u8 PORTID,u8 type,u32 val);


#endif /* SEVEN_SEGMENT_H_ */
