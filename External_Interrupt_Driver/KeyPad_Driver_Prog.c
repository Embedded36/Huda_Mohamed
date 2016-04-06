/*
 * KeyPad_Driver_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: lenovo
 */
#include"types.h"
#include"DIO_Interface.h"
#include"KeyPad_Driver_Config.h"
#include"KeyPad_Driver_Interface.h"
#include"delay.h"
static const u8 KeyPad_u8StateArr[4][4] ={{ACTIVE,OFF,OFF,OFF},{OFF,ACTIVE,OFF,OFF},
																	{OFF,OFF,ACTIVE,OFF},{OFF,OFF,OFF,ACTIVE}};
static const u8 KeyPad_u8SWITCHMap[4][4] = {{KEYPAD_SWITCH1_IDX,KEYPAD_SWITCH2_IDX,KEYPAD_SWITCH3_IDX,
		KEYPAD_SWITCH4_IDX}, {KEYPAD_SWITCH5_IDX,KEYPAD_SWITCH6_IDX,KEYPAD_SWITCH7_IDX,
				KEYPAD_SWITCH8_IDX},{KEYPAD_SWITCH9_IDX,KEYPAD_SWITCH10_IDX,KEYPAD_SWITCH11_IDX,
						KEYPAD_SWITCH12_IDX},{KEYPAD_SWITCH13_IDX,KEYPAD_SWITCH14_IDX,KEYPAD_SWITCH15_IDX,
								KEYPAD_SWITCH16_IDX}};
void KeyPad_voidInit(void)
{
	 DIO_u8WritePin(KEYPAD_ROW1,OFF);
	 DIO_u8WritePin(KEYPAD_ROW2,OFF);
	 DIO_u8WritePin(KEYPAD_ROW3,OFF);
	 DIO_u8WritePin(KEYPAD_ROW4,OFF);
}

u8 Keypad_u8Read(u8* Copy_u8SwitchNo)
{
	u8 local_u8funcDoneRightFlag = u8OK;
	u8 local_u8ActiveRows = 0;
	u8 local_u8Col1Val;
	u8 local_u8Col2Val;
	u8 local_u8Col3Val;
	u8 local_u8Col4Val;
    u8 local_testVal;
	u8 local_u8Counter;
	for(local_u8Counter = 0; local_u8Counter <4; local_u8Counter++)
	{
	DIO_u8WritePin(KEYPAD_ROW1,KeyPad_u8StateArr[local_u8Counter][KEYPAD_ROW_IDX1]);
	DIO_u8WritePin(KEYPAD_ROW2,KeyPad_u8StateArr[local_u8Counter][KEYPAD_ROW_IDX2]);
	DIO_u8WritePin(KEYPAD_ROW3,KeyPad_u8StateArr[local_u8Counter][KEYPAD_ROW_IDX3]);
	DIO_u8WritePin(KEYPAD_ROW4,KeyPad_u8StateArr[local_u8Counter][KEYPAD_ROW_IDX4]);

	DIO_u8ReadPinVal(KEYPAD_COL1,&local_u8Col1Val);
	DIO_u8ReadPinVal(KEYPAD_COL2,&local_u8Col2Val);
	DIO_u8ReadPinVal(KEYPAD_COL3,&local_u8Col3Val);
	DIO_u8ReadPinVal(KEYPAD_COL4,&local_u8Col4Val);
	local_testVal = (!local_u8Col1Val)*(!local_u8Col2Val)*(local_u8Col3Val ^ local_u8Col4Val) +   \
			(!local_u8Col3Val)*(!local_u8Col4Val)*(local_u8Col1Val ^ local_u8Col2Val);
	if(local_testVal == 1)
	{
	local_u8ActiveRows |= local_u8Col1Val;
	local_u8ActiveRows |= local_u8Col2Val << 1;
	local_u8ActiveRows |= local_u8Col3Val << 2;
	local_u8ActiveRows |= local_u8Col4Val << 3;
	switch(local_u8ActiveRows)
	{
	case 1:
			*Copy_u8SwitchNo = KeyPad_u8SWITCHMap[local_u8Counter][KEYPAD_COL_IDX1];
			break;
	case 2:
			*Copy_u8SwitchNo = KeyPad_u8SWITCHMap[local_u8Counter][KEYPAD_COL_IDX2];
		break;
	case 4:
			*Copy_u8SwitchNo = KeyPad_u8SWITCHMap[local_u8Counter][KEYPAD_COL_IDX3];
		break;
	case 8:
			*Copy_u8SwitchNo = KeyPad_u8SWITCHMap[local_u8Counter][KEYPAD_COL_IDX4];
	        break;
	default:
		local_u8funcDoneRightFlag = u8ERROR;
		break;
	}         //end of switch case
	} //end of if
	}    //end of for
	return local_u8funcDoneRightFlag;
}

