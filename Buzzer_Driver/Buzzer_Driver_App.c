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
	u8 BuzzerApp_PulseWidth_msec = 0;
	DIO_voidInit();
	KeyPad_voidInit();
	TimerDrive_voidInit();
	TimerDriver_voidInputCompareEnable();
	InputCaptureInterrupt_SetFn(AppFn_voidTimerOutCompareInterpt);
	while(1)
	{
		Keypad_u8Read(&BuzzerApp_u8KeyPadSwitchNo);
		switch(BuzzerApp_u8KeyPadSwitchNo)
		{
		case 0:
			BuzzerApp_PulseWidth_msec = 9;
            break;
		case 1:
			BuzzerApp_PulseWidth_msec = 10;
			break;
		case 2:
			BuzzerApp_PulseWidth_msec = 12;
			break;
		case 3:
			BuzzerApp_PulseWidth_msec = 17;
			break;
		case 4:
			BuzzerApp_PulseWidth_msec = 23;
			break;
		case 5:
			BuzzerApp_PulseWidth_msec = 28;
			break;
		case 6:
			BuzzerApp_PulseWidth_msec = 35;
			break;
		case 7:
			BuzzerApp_PulseWidth_msec = 43;
			break;
		case 8:
			BuzzerApp_PulseWidth_msec = 51;
			break;
		case 9:
			BuzzerApp_PulseWidth_msec = 50;
			break;
		case 10:
			BuzzerApp_PulseWidth_msec = 56;
			break;
		case 11:
			BuzzerApp_PulseWidth_msec = 64;
			break;
		default:
			break;
		}
		Timer_u8SetTime(BuzzerApp_PulseWidth_msec);
		DIO_u8WritePin(u8BuzzerHighPin, BuzzerApp_PinOffOn);

	}
}
void AppFn_voidTimerOutCompareInterpt(void)
{
	BuzzerApp_PinOffOn = !BuzzerApp_PinOffOn;
}
