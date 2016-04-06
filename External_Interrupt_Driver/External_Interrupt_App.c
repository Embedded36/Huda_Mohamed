#include"types.h"
#include"DIO_Interface.h"
#include"KeyPad_Driver_Interface.h"
#include"External_Interrupt_Interface.h"
#include"TimerDriver_Interface.h"
#include"delay.h"

#define        LED0_PIN_IDX                                                     21
#define        LED1_PIN_IDX                                                     22
#define        LED2_PIN_IDX                                                     23

static const u8 External_Interrupt_Components_u8Leds_Pins[3] = {LED0_PIN_IDX,LED1_PIN_IDX,LED2_PIN_IDX};
static u8 External_Interrupt_Components_u8LedState[3] = {0, 0, 0};
static u8 CurrentServedLed = 3;
static u8 Overflow_u8Counter = 0;
static 	u8 LED_ON_OFF = 2;
static u8 LED_OffBlank = 0;


void INT0_ISR_APP(void );
void Timer0_OverflowAPP(void );


void main(void)
{
	u8 KeyPadVal = 16;
	DIO_voidInit();
	KeyPad_voidInit();
	ExternalInterrup_voidInit();
	TimerDrive_voidInit();
	SetISR(INT0_ISR_APP);
	TimerInterrupt_SetFn(Timer0_OverflowAPP);
while(1)
{
	Keypad_u8Read(&KeyPadVal);
	switch(KeyPadVal)
	{
	case 1:
		CurrentServedLed = 0;
		break;
		////////////////////////////////////////////////
	case 2:
		CurrentServedLed = 1;
		break;
		///////////////////////////////////////////////
	case 3:
		CurrentServedLed = 2;
		break;
	default:
		break;
	}
	if(LED_OffBlank == 1)
	{
		if(LED_ON_OFF == 1)
		{
			  DIO_u8WritePin(External_Interrupt_Components_u8Leds_Pins[CurrentServedLed], 1);
		}
		else if(LED_ON_OFF == 0)
		{
			  DIO_u8WritePin(External_Interrupt_Components_u8Leds_Pins[CurrentServedLed], 0);
		}
		else{}
	}
	else{}

} /* Comment!: End of while loop */
} /* Comment!: End of main function */

void INT0_ISR_APP(void )

{
	LED_OffBlank = !LED_OffBlank;
	if(LED_OffBlank == 0)
    {
	      DIO_u8WritePin(External_Interrupt_Components_u8Leds_Pins[CurrentServedLed], 0);
    }
    else if(LED_OffBlank == 1)
    {
    	Overflow_u8Counter = 0;
    }
}
void Timer0_OverflowAPP(void )
{
	if( (LED_OffBlank == 1) && (Overflow_u8Counter < 5))
	{
		Overflow_u8Counter++;
	}
	if((LED_OffBlank == 1) && (Overflow_u8Counter == 4))
	{
		//External_Interrupt_Components_u8LedState[CurrentServedLed] = 1;
		LED_ON_OFF = !LED_ON_OFF;
		Overflow_u8Counter = 0;
	}

}
