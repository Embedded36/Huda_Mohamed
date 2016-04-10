#include"types.h"
#include"TimerDriver_Interface.h"
#include"TimerDriver_Config.h"
#include"TimerDriver_Private.h"
//handle set time fn
#define  ISR(vector, ...)            \
    void vector (void) __attribute__ ((signal,used,externally_visible)) __VA_ARGS__; \
    void vector (void)

void (*TimerPtr_Fn)(void);
void (*InputCompare_PtrFn)(void);

extern void TimerDrive_voidInit(void)
{
	/*Comment!: Timer waveform generation mode and pre scaler value */
	*TIMER0_CONTROL_REG  = TIMER0_CONTROL_REG_INIT_VAL;
}

extern void TimerInterrupt_SetFn(void (*Ptr_Fn)(void))
{
	TimerPtr_Fn = Ptr_Fn;
}
extern void InputCaptureInterrupt_SetFn(void (*Ptr_Fn)(void))
{
	InputCompare_PtrFn = Ptr_Fn;
}

ISR(__vector_11)
{
	/*Comment!: Running User Interrupt Service Routine */
	TimerPtr_Fn();
}
ISR(__vector_10)
{
	/*Comment!: Running User Interrupt Service Routine */
	InputCompare_PtrFn();
}
extern void TimerDriver_voidOverFlowDisable(void)
{
	/*Comment! Disable global Interrupt */
	__asm__("CLI");
	/*Comment! Disable Timer0 overflow Interrupt */
	*TIMER_INTERRUPT_MASK_REG &= CLRBIT0;
}
extern void TimerDriver_voidOverFlowEnable(void)
{
	/*Comment! Enable Global Interrupt */
	__asm__("SEI");
	/*Comment! Enable Timer0 overflow Interrupt */
	*TIMER_INTERRUPT_MASK_REG |= SETBIT0;
}
extern void TimerDriver_voidInputCompareEnable(void)
{
	/*Comment! Enable Global Interrupt */
	__asm__("SEI");
	/*Comment! Enable Timer0 Output Compare Interrupt */
	*TIMER_INTERRUPT_MASK_REG |= SETBIT1;
}
extern void TimerDriver_voidInputCompareDisable(void)
{
	/*Comment! Disable global Interrupt */
	__asm__("CLI");
	/*Comment! Disable Timer0 Output Compare Interrupt */
	*TIMER_INTERRUPT_MASK_REG &= CLRBIT1;
}
extern u8 Timer_u8SetTime(u8 Copy_u8Time_msec)
{
	u8 local_u8fnDoneRight = u8OK;
	u8 local_u8Prescaller_BinVal = (*TIMER0_CONTROL_REG) &(0b00000111);
	u16 local_u8Prescaller_Val;
	u8 local_u8CountsNum;
	switch(local_u8Prescaller_BinVal)
	{
	case 1:
		local_u8Prescaller_Val = 1;
		break;
	case 2:
		local_u8Prescaller_Val = 8;
		break;
	case 3:
		local_u8Prescaller_Val = 64;
		break;
	case 4:
		local_u8Prescaller_Val = 256;
		break;
	case 5:
		local_u8Prescaller_Val = 1024;
		break;
	default:
		local_u8fnDoneRight = u8ERROR;
		break;
	}
	local_u8CountsNum = (local_u8fnDoneRight) * (MC_WORKING_FREQ_HZ * Copy_u8Time_msec) / (local_u8Prescaller_Val);
	*TIMER0_COMPARE_REG = local_u8CountsNum;
	return local_u8fnDoneRight;
}
