#include "StdTypes.h"
#include "Utils.h"

#include "DIO_Interface.h"

#include "KeyPad_Cfg.h"

#include "KeyPad_Interface.h"

void KEYPAD_Init(void)
{
	DIO_WritePin(FIRST_OUPUT,HIGH);
	DIO_WritePin(FIRST_OUPUT+1,HIGH);
	DIO_WritePin(FIRST_OUPUT+2,HIGH);
	DIO_WritePin(FIRST_OUPUT+3,HIGH);
}

u8 KEYPAD_Getkey (void)
{
	u8 r,c,key=NO_KEY;
	
	for(r=0;r<ROWS;r++)
	{
		DIO_WritePin(FIRST_OUPUT+r,LOW);
		for(c=0;c<COLS;c++)
		{
			if(DIO_ReadPin(FIRST_INPUT+c)==LOW)
			{
				key=KeysArray[r][c];
				while(DIO_ReadPin(FIRST_INPUT+c)==LOW);
			}	
		}
		DIO_WritePin(FIRST_OUPUT+r,HIGH);
	}
	return key;
}
