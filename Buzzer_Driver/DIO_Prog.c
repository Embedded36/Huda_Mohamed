/*
 * DIO_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: lenovo
 */


#include"types.h"
#include"DIO_Interface.h"
#include"DIO_Private.h"
#include"DIO_Config.h"
//#include"delay.h"

/*Comment!: Array hold addresses of all output registers */
static u8* const DIO_u8ArrOutRegAdds[u8OUTPUTREGS_NUM] = {DIO_u8OutReg0Name,DIO_u8OutReg1Name,DIO_u8OutReg2Name,DIO_u8OutReg3Name};

/*Comment!: Array hold addresses of all input registers */
static u8* const DIO_u8ArrInputRegAdds[u8INPUTREGS_NUM] = {DIO_u8InputReg0Name,DIO_u8InputReg1Name,DIO_u8InputReg2Name,DIO_u8InputReg3Name};

/*Comment!: Array hold addresses of all direction registers */
static u8* const DIO_u8ArrDirRegAdds[u8DDRREGS_NUM] = {DIO_u8PORT0DirName,DIO_u8PORT1DirName,DIO_u8PORT2DirName,DIO_u8PORT3DirName};

/*Comment!: Mask Array for setting and clearing specific bits*/
const static u8 DIO_u8SetClrBit[2][8] = {{u8ZERO},{SETBIT0,SETBIT1,SETBIT2,SETBIT3,SETBIT4,SETBIT5,SETBIT6,SETBIT7}};

const static u8 DIO_u8ClrBit[8] = {CLRBIT0,CLRBIT1,CLRBIT2,CLRBIT3,CLRBIT4,CLRBIT5,CLRBIT6,CLRBIT7};
const static u8 DIO_u8SetBit[8] = {SETBIT0,SETBIT1,SETBIT2,SETBIT3,SETBIT4,SETBIT5,SETBIT6,SETBIT7};

/*Comment!: Initialization Function Body*/
extern void DIO_voidInit(void)
{
	/*Comment!: DIO_u8PORT0DirName represent the real name of your microC Direction Register , DDR for AVR family */
	/*Comment!: DIO_u8PORTADIR represent initial value for each port direction */
	*DIO_u8PORT0DirName = DIO_u8PORTADIR;
	*DIO_u8PORT1DirName = DIO_u8PORTBDIR;
	*DIO_u8PORT2DirName = DIO_u8PORTCDIR;
	*DIO_u8PORT3DirName = DIO_u8PORTDDIR;

	/*Comment!: DIO_u8OutReg0Name represent the real name of your microC output Register , PORT for AVR family */
	/*Comment!: DIO_u8PORTAVAL represent initial value for each output port */

	/*Comment!: reset the register output pins before writing on*/
	*DIO_u8OutReg0Name &= (~DIO_u8PORTADIR);
	*DIO_u8OutReg0Name |=(DIO_u8PORTAVAL & DIO_u8PORTADIR);

	*DIO_u8OutReg1Name &= (~DIO_u8PORTBDIR);
	*DIO_u8OutReg1Name |=(DIO_u8PORTBVAL & DIO_u8PORTBDIR);

	*DIO_u8OutReg2Name &= (~DIO_u8PORTCDIR);
	*DIO_u8OutReg2Name |=(DIO_u8PORTCVAL & DIO_u8PORTCDIR);

	*DIO_u8OutReg3Name &= (~DIO_u8PORTDDIR);
	*DIO_u8OutReg3Name |=(DIO_u8PORTDVAL & DIO_u8PORTDDIR);
}

/*Comment!: Read Port Direction */
extern u8 DIO_u8ReadPortDir(u8 Copy_u8PortIdx,u8* Copy_u8PtrtoDir)
{
	/*Comment!: local_u8funcDoneRightFlag is a flag define the function finished right or not
	 * and is initialized with True state, if the user enter index out of boundires it will give him a false return
	 */
	u8 local_u8funcDoneRightFlag = u8TRUE;
	/*Comment!: Copy_u8PortIdx is port index, ex: in atmega32 MC there're 4 ports,
	 *  so u'll have 4 indices from 0 to 3
	 */
	if(Copy_u8PortIdx < u8DDRREGS_NUM)
	{
		*Copy_u8PtrtoDir = *(DIO_u8ArrDirRegAdds[Copy_u8PortIdx]);
	}
	else
	{
		local_u8funcDoneRightFlag = u8FALSE;
	}
	return local_u8funcDoneRightFlag;

}

/*Comment!: Write Port Direction */
extern u8 DIO_u8WritePortDir(u8 Copy_u8PortIdx,u8 Copy_u8PortDir)
{
	/*Comment!: local_u8funcDoneRightFlag is a flag define the function finshed right or not
	 * and is initialized with True state, if the user enter index out of boundires it will give him a false return
	 */
	u8 local_u8funcDoneRightFlag = u8TRUE;
	/*Comment!: Copy_u8PortIdx is port index, ex: in atmega32 MC there're 4 ports,
	 *  so u'll have 4 indices from 0 to 3
	 */
	if(Copy_u8PortIdx < u8DDRREGS_NUM)
	{
		*(DIO_u8ArrDirRegAdds[Copy_u8PortIdx]) = Copy_u8PortDir;
	}
	else
	{
		local_u8funcDoneRightFlag = u8FALSE;
	}
	return local_u8funcDoneRightFlag;
}

/*Comment!: Read Port Value */
extern u8 DIO_u8ReadPortVal(u8 Copy_u8PortIdx,u8* Copy_u8Ptrtoval)

{
	/*Comment!: local_u8funcDoneRightFlag is a flag define the function finshed right or not
	 * and is initialized with True state, if the user enter index out of boundires it will give him a false return
	 */
	u8 local_u8funcDoneRightFlag = u8TRUE;
	/*Comment!: Copy_u8PortIdx is port index, ex: in atmega32 MC there're 4 ports,
	 *  so u'll have 4 indices from 0 to 3
	 */
	if((Copy_u8PortIdx < u8INPUTREGS_NUM) || (*DIO_u8ArrDirRegAdds[Copy_u8PortIdx] == REG_IS_INPUT) )
	{
		*Copy_u8Ptrtoval = *(DIO_u8ArrInputRegAdds[Copy_u8PortIdx]);
	}
	else
	{
		local_u8funcDoneRightFlag = u8FALSE;
	}

	return local_u8funcDoneRightFlag;
}

/*Comment!: Write Port Value */
extern u8 DIO_u8WritePort(u8 Copy_u8PortIdx, u8 copy_u8PortVal)
{
	/*Comment!: local_u8funcDoneRightFlag is a flag define the function finshed right or not
	 * and is initialized with True state, if the user enter index out of boundires it will give him a false return
	 */
	u8 local_u8funcDoneRightFlag = u8TRUE;
	/*Comment!: Copy_u8PortIdx is port index, ex: in atmega32 MC there're 4 ports,
	 *  so u'll have 4 indices from 0 to 3
	 */
	if((Copy_u8PortIdx < u8OUTPUTREGS_NUM) || (*DIO_u8ArrDirRegAdds[Copy_u8PortIdx] == REG_IS_OUTPUT))
	{
		*(DIO_u8ArrOutRegAdds[Copy_u8PortIdx]) = copy_u8PortVal;
	}
	else
	{
		local_u8funcDoneRightFlag = u8FALSE;
	}
	return local_u8funcDoneRightFlag;
}

/*Comment!: Read Pin Direction */
extern u8 DIO_ReadPinDir(u8 Copy_u8PinIdx, u8* Copy_u8PtrtoDir)
{
	/*Comment!: local_u8funcDoneRightFlag is a flag define the function finshed right or not
	 * and is initialized with True state, if the user enter index out of boundires it will give him a false return
	 */
	u8 local_u8funcDoneRightFlag = u8TRUE;
	/*Comment!: local_u8PortIdx represent the port index */
	/*Comment!: local_u8PinIdx represent the pin index for that port, ex at Atmega32 PORTA0 to PORTA7*/
	u8 local_u8PortIdx,local_u8PinIdx;

	if(Copy_u8PinIdx < DIO_u8PINSNUM)
	{
		local_u8PortIdx = Copy_u8PinIdx / DIO_u8REGSIZE;
		local_u8PinIdx = Copy_u8PinIdx % DIO_u8REGSIZE;
		*Copy_u8PtrtoDir = ((*(DIO_u8ArrDirRegAdds[local_u8PortIdx])) & DIO_u8SetBit[local_u8PinIdx])  >> (local_u8PinIdx);
	}
	else
	{
		local_u8funcDoneRightFlag = u8FALSE;
	}
	return local_u8funcDoneRightFlag;
}

/*Comment!: Read Pin Value */
extern u8 DIO_u8ReadPinVal(u8 Copy_u8PinIdx, u8* Copy_u8PtrToVal)
{

	/*Comment!: local_u8funcDoneRightFlag is a flag define the function finshed right or not
	 * and is initialized with True state, if the user enter index out of boundires it will give him a false return
	 */
	u8 local_u8funcDoneRightFlag = u8TRUE;
	/*Comment!: local_u8PortIdx represent the port index */
	u8 local_u8PortIdx = Copy_u8PinIdx / DIO_u8REGSIZE;
	/*Comment!: local_u8PinIdx represent the pin index for that port, ex at Atmega32 PORTA0 to PORTA7 */
	u8 local_u8PinIdx = Copy_u8PinIdx % DIO_u8REGSIZE;

	/*Comment!: local_u8PinDir is the current pin direction */
	u8 local_u8PinDir = (*DIO_u8ArrDirRegAdds[local_u8PortIdx] & (DIO_u8SetBit[local_u8PinIdx])) >> (local_u8PinIdx);

	if((local_u8PortIdx < u8INPUTREGS_NUM) && (local_u8PinDir == u8ZERO) )
	{
	*Copy_u8PtrToVal = ((*(DIO_u8ArrInputRegAdds[local_u8PortIdx])) & (DIO_u8SetBit[local_u8PinIdx])) >> (local_u8PinIdx);
	}
	else
	{
		local_u8funcDoneRightFlag = u8FALSE;
	}

	return local_u8funcDoneRightFlag;
}

/*Comment!: Write Pin Value */
extern u8 DIO_u8WritePin(u8 Copy_u8PinIdx, u8 copy_u8PinVal)
{
	/*Comment!: copy_u8PinVal is the value that user want to set pin with, It should take zero or one only */
	/*Comment!: local_u8funcDoneRightFlag is a flag define the function finshed right or not
	 * and is initialized with True state, if the user enter index out of boundires it will give him a false return
	 */
	u8 local_u8funcDoneRightFlag = u8TRUE;

	/*Comment!: local_u8PortIdx represent the port index */
	/*Comment!: local_u8PinIdx represent the pin index for that port, ex at Atmega32 PORTA0 to PORTA7 */
	u8 local_u8PortIdx = Copy_u8PinIdx / DIO_u8REGSIZE;
	u8 local_u8PinIdx = Copy_u8PinIdx % DIO_u8REGSIZE;
	/*Comment!: local_u8PinDir is the current pin direction */
	u8 local_u8PinDir = (*DIO_u8ArrDirRegAdds[local_u8PortIdx] & (DIO_u8SetBit[local_u8PinIdx])) >> (local_u8PinIdx);

	if((local_u8PortIdx < u8OUTPUTREGS_NUM) && (local_u8PinDir == u8ONE))
	{
		*DIO_u8ArrOutRegAdds[local_u8PortIdx] &= DIO_u8ClrBit[local_u8PinIdx];
		*DIO_u8ArrOutRegAdds[local_u8PortIdx] |= DIO_u8SetClrBit[copy_u8PinVal][local_u8PinIdx];
	}
	else
	{
		local_u8funcDoneRightFlag = u8FALSE;
	}
	return local_u8funcDoneRightFlag;
}

/*Comment!: Write Pin Direction */
extern u8 DIO_u8WritePinDir(u8 Copy_u8PinIdx,u8 Copy_u8PinDir)
{
	/*Comment!: local_u8funcDoneRightFlag is a flag define the function finshed right or not
	 * and is initialized with True state, if the user enter index out of boundires it will give him a false return
	 */
	u8 local_u8funcDoneRightFlag = u8TRUE;

	/*Comment!: local_u8PortIdx represent the port index */
	/*Comment!: local_u8PinIdx represent the pin index for that port, ex at Atmega32 PORTA0 to PORTA7*/
	u8 local_u8PortIdx,local_u8PinIdx;

	/*Comment!: Copy_u8PinIdx represent the pin index */
	if(Copy_u8PinIdx < DIO_u8PINSNUM)
	{
		local_u8PortIdx = Copy_u8PinIdx / DIO_u8REGSIZE;
		local_u8PinIdx = Copy_u8PinIdx % DIO_u8REGSIZE;
		/*Comment!: Copy_u8PinDir is the value that user want to set pin with, It should take zero or one only */
		*DIO_u8ArrDirRegAdds[local_u8PortIdx] &= DIO_u8ClrBit[local_u8PinIdx];
		*DIO_u8ArrDirRegAdds[local_u8PortIdx] |= DIO_u8SetClrBit[Copy_u8PinDir][local_u8PinIdx];
	}
	else
	{
		local_u8funcDoneRightFlag = u8FALSE;
	}
	return local_u8funcDoneRightFlag;
}

extern u8 DIO_u8ReadPinValOut(u8 Copy_u8PinIdx, u8* Copy_u8PtrToVal)
{

	/*Comment!: local_u8funcDoneRightFlag is a flag define the function finshed right or not
	 * and is initialized with True state, if the user enter index out of boundires it will give him a false return
	 */
	u8 local_u8funcDoneRightFlag = u8TRUE;
	/*Comment!: local_u8PortIdx represent the port index */
	u8 local_u8PortIdx = Copy_u8PinIdx / DIO_u8REGSIZE;
	/*Comment!: local_u8PinIdx represent the pin index for that port, ex at Atmega32 PORTA0 to PORTA7 */
	u8 local_u8PinIdx = Copy_u8PinIdx % DIO_u8REGSIZE;

	/*Comment!: local_u8PinDir is the current pin direction */
	u8 local_u8PinDir = (*DIO_u8ArrDirRegAdds[local_u8PortIdx] & (DIO_u8SetBit[local_u8PinIdx])) >> (local_u8PinIdx);

	if((local_u8PortIdx < u8OUTPUTREGS_NUM) && (local_u8PinDir == u8ONE) )
	{
	*Copy_u8PtrToVal = ((*(DIO_u8ArrOutRegAdds[local_u8PortIdx])) & (DIO_u8SetBit[local_u8PinIdx])) >> (local_u8PinIdx);
	}
	else
	{
		local_u8funcDoneRightFlag = u8FALSE;
	}

	return local_u8funcDoneRightFlag;
}
