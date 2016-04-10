/*
 * External_Interrupt_Private.h
 *
 *  Created on: ???/???/????
 *      Author: lenovo
 */

#ifndef EXTERNAL_INTERRUPT_PRIVATE_H_
#define EXTERNAL_INTERRUPT_PRIVATE_H_

/*Comment!: Setting physical sense control bits for INT0 */
#if INTERRUPT0_SENSE_CONTROL == LOW_LEVEL
       #define INT0_SC0                  0
       #define INT0_SC1                  0
#elif INTERRUPT0_SENSE_CONTROL == LOGICAL_CHANGE
      #define INT0_SC0                  1
       #define INT0_SC1                  0
#elif INTERRUPT0_SENSE_CONTROL == FALLING_EDGE
      #define INT0_SC0                  0
       #define INT0_SC1                  1
#elif INTERRUPT0_SENSE_CONTROL == RAISING_EDGE
      #define INT0_SC0                  1
       #define INT0_SC1                  1
#endif

/*Comment!: Setting physical sense control bits for INT1 */
#if INTERRUPT1_SENSE_CONTROL == LOW_LEVEL
       #define INT1_SC0                  0
       #define INT1_SC1                  0
#elif INTERRUPT1_SENSE_CONTROL == LOGICAL_CHANGE
      #define INT1_SC0                  1
       #define INT1_SC1                  0
#elif INTERRUPT1_SENSE_CONTROL == FALLING_EDGE
      #define INT1_SC0                  0
       #define INT1_SC1                  1
#elif INTERRUPT1_SENSE_CONTROL == RAISING_EDGE
      #define INT1_SC0                  1
       #define INT1_SC1                  1
#endif

/*Comment!: Setting physical sense control bits for INT2 */
#if INTERRUPT2_SENSE_CONTROL == RAISING_EDGE
      #define INT2_SC                  1
#elif INTERRUPT2_SENSE_CONTROL == FALLING_EDGE
      #define INT2_SC                  0
#endif

/*Comment!: RESERVED_VAL represents bits that are reserved in your MC,
 *                 DONT_CARE  represents bits that you don't care about'em in that driver
 */
#define RESERVED_VAL                0
#define DONT_CARE                     0

/*Comment!: Defining pointer to physical registers you'll use in Interrupt Driver */
#define MCU_CONTROL_REG                                              ((volatile u8*)(0x55))
#define MCU_CONTROL_STATUS_REG                              ((volatile u8*)(0x54))
#define GENERAL_INTERRUPT_CONTROL_REG                  ((volatile u8*)(0x5B))
#define STATUS_REG                                                        ((volatile u8*)(0x5F))

/*Comment!: Implementing Concatenation and Concatenation helper */
#define conc(x7,x6,x5,x4,x3,x2,x1,x0) conchelper(x7,x6,x5,x4,x3,x2,x1,x0)
#define conchelper(y7,y6,y5,y4,y3,y2,y1,y0) 0b##y7##y6##y5##y4##y3##y2##y1##y0

/*
 * Comment!: Setting physical registers according to user configurations,
 * these will be called in the driver initialize function
 */
#define MCU_CONTROL_REG_INIT_VAL    conc(DONT_CARE, DONT_CARE, DONT_CARE, DONT_CARE,  \
		INT1_SC1, INT1_SC0, INT0_SC1, INT0_SC0)

#define MCU_CONTROL_STATUS_REG_INIT_VAL    conc(DONT_CARE, INT2_SC, RESERVED_VAL, DONT_CARE, \
		DONT_CARE, DONT_CARE, DONT_CARE, DONT_CARE)

#endif /* EXTERNAL_INTERRUPT_PRIVATE_H_ */
