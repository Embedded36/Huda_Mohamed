#include"types.h"
#include"External_Interrupt_Interface.h"
#include"External_Interrupt_Config.h"
#include"External_Interrupt_Private.h"


#define  ISR(vector, ...)            \
    void vector (void) __attribute__ ((signal,used,externally_visible)) __VA_ARGS__; \
    void vector (void)

//enable interrupt and global interrupt
static void (*PtrToISRFn)(void);

extern void ExternalInterrup_voidInit(void)
{
	*MCU_CONTROL_REG = MCU_CONTROL_REG_INIT_VAL;
	*MCU_CONTROL_STATUS_REG = MCU_CONTROL_STATUS_REG_INIT_VAL;

	/*Comment! Enable Global Interrupt */
	//*STATUS_REG |= (SETBIT7);
     __asm__("SEI");
	/*Comment!: Enable Interrupt0 */
	*GENERAL_INTERRUPT_CONTROL_REG |= SETBIT6;
}
extern void SetISR(void (*ptrFn)(void))
{
	PtrToISRFn = ptrFn;
}

ISR(__vector_1)
{
	/*Comment!: Running User Interrupt Service Routine */
	PtrToISRFn();
}

