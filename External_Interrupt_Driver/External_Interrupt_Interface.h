/*
 * External_Interrupt_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: lenovo
 */

#ifndef EXTERNAL_INTERRUPT_INTERFACE_H_
#define EXTERNAL_INTERRUPT_INTERFACE_H_

/*Comment!: Possible values for interrupt sense control */
#define RAISING_EDGE                                 0
#define FALLING_EDGE                                  1
#define LOGICAL_CHANGE                             2
#define LOW_LEVEL                                        3

/*Comment!: Mask for clearing specific bits*/
#define CLRBIT0 0b11111110
#define CLRBIT1 0b11111101
#define CLRBIT2 0b11111011
#define CLRBIT3 0b11110111
#define CLRBIT4 0b11101111
#define CLRBIT5 0b11011111
#define CLRBIT6 0b10111111
#define CLRBIT7 0b01111111

/*Comment!: Mask for setting specific bits*/
#define SETBIT0 0b00000001
#define SETBIT1 0b00000010
#define SETBIT2 0b00000100
#define SETBIT3 0b00001000
#define SETBIT4 0b00010000
#define SETBIT5 0b00100000
#define SETBIT6 0b01000000
#define SETBIT7 0b10000000

/*Comment!: Interface APIs for External Interrupts Driver */
extern void ExternalInterrup_voidInit(void);
extern void SetISR(void (*ptrFn)(void));

#endif /* EXTERNAL_INTERRUPT_INTERFACE_H_ */
