#include"types.h"
#include"TimerDriver_Interface.h"
#include"TimerDriver_Config.h"
#include"TimerDriver_Private.h"

#define  ISR(vector, ...)            \
    void vector (void) __attribute__ ((signal,used,externally_visible)) __VA_ARGS__; \
    void vector (void)

void (*TimerPtr_Fn)(void);

extern void TimerDrive_voidInit(void)
{
	*TIMER0_CONTROL_REG  = TIMER0_CONTROL_REG_INIT_VAL;
	/*Comment! Enable Global Interrupt */
    __asm__("SEI");
	/*Comment! Enable Timer0 overflow Interrupt */
    *TIMER_INTERRUPT_MASK_REG = SETBIT0;
}

extern void TimerInterrupt_SetFn(void (*Ptr_Fn)(void))
{
	TimerPtr_Fn = Ptr_Fn;
}

ISR(__vector_11)
{
	/*Comment!: Running User Interrupt Service Routine */
	TimerPtr_Fn();
}
