#include"types.h"
#include"DIO_Interface.h"
#include"KeyPad_Driver_Interface.h"
#include"TimerDriver_Interface.h"
#include"External_Interrupt_Interface.h"
#include"Buzzer_Driver_Config.h"

u8 BuzzerApp_PinOffOn =0;
void AppFn_voidTimerOutCompareInterpt(void);

void main(void)
{

	u8 BuzzerApp_u8KeyPadSwitchNo = 16;
	u16 BuzzerApp_PulseWidth_usec = 0;
	//u16 DoReMi_Usec[16] = {4545, 4059, 3822, 3405, 3034, 2863, 2551, 4900, 4700, 4300, 3200,	2400, 2300, 2200, 2100, 2000};
	u16 DoReMi_Usec[16] = {500, 1500, 2500, 3500, 4500, 5500, 6500, 7500, 8500, 9500, 10050, 11050, 12050, 13050, 14050, 15050};
	DIO_voidInit();
	KeyPad_voidInit();
	TimerDrive_voidInit();
	TimerDriver_voidInputCompareEnable();
	InputCaptureInterrupt_SetFn(AppFn_voidTimerOutCompareInterpt);
	while(1)
	{
		Keypad_u8Read(&BuzzerApp_u8KeyPadSwitchNo);
		if((BuzzerApp_u8KeyPadSwitchNo >= 0) && (BuzzerApp_u8KeyPadSwitchNo < 16))
		{
			TimerDriver_voidInputCompareEnable();
		    BuzzerApp_PulseWidth_usec = DoReMi_Usec[BuzzerApp_u8KeyPadSwitchNo];
		}
		else
		{
			TimerDriver_voidInputCompareDisable();
		}
		Timer_u8SetTimeUsec(BuzzerApp_PulseWidth_usec);
		DIO_u8WritePin(u8BuzzerHighPin, BuzzerApp_PinOffOn);

	}
}
void AppFn_voidTimerOutCompareInterpt(void)
{
	BuzzerApp_PinOffOn = !BuzzerApp_PinOffOn;
}
