
#include "TWI_interface.h"

void TWI_Init(void)
{
    TWBR = 0x02;
	TWSR = 0x00;
    TWAR = 0b00000010;
    TWCR = (1<<TWEN);
}

void TWI_Start(void)
{
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while(BIT_IS_CLEAR(TWCR,TWINT));
}

void TWI_Stop(void)
{
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

void TWI_Write(unsigned char data)
{
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while(BIT_IS_CLEAR(TWCR,TWINT));
}

unsigned char TWI_Read_With_ACK(void)
{
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    while(BIT_IS_CLEAR(TWCR,TWINT));
    return TWDR;
}

unsigned char TWI_Read_With_NACK(void)
{
    TWCR = (1 << TWINT) | (1 << TWEN);
    while(BIT_IS_CLEAR(TWCR,TWINT));
    return TWDR;
}

unsigned char TWI_Get_Status(void)
{
	unsigned char status;
    status = TWSR & 0xF8;
    return status;
}
