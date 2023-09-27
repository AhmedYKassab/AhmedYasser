
#include "EEPROM_interface.h"

void EEPROM_init(void)
{
	TWI_Init();
}

void EEPROM_WRITE(u16 Address ,u8 Data)
{
	 TWI_Start();
	 TWI_Write((unsigned char)(0xA0 | ((Address & 0x0700)>>7)));
	 TWI_Write((unsigned char)(Address));
	 TWI_Write(Data);
	 TWI_Stop();
}

void EEPROM_READ(u16 Address ,u8 *Data)
{
	 TWI_Start();
	 TWI_Write((unsigned char)((0xA0) | ((Address & 0x0700)>>7)));
	 TWI_Write((unsigned char)(Address));
	 TWI_Start();

     TWI_Write((unsigned char)((0xA0) | ((Address & 0x0700)>>7) | 1));

	 *Data = TWI_Read_With_NACK();

	   TWI_Stop();
}
