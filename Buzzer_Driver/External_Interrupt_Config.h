/*
 * External_Interrupt_Config.h
 *
 *  Created on: ???/???/????
 *      Author: lenovo
 */

#ifndef EXTERNAL_INTERRUPT_CONFIG_H_
#define EXTERNAL_INTERRUPT_CONFIG_H_

/*Comment!: Defining external interrupts sensing control
 * INT0 and INT1 can take these values RAISING_EDGE, FALLING_EDGE, LOGICAL_CHANGE and LOW_LEVEL
 * INT3 can take these values RAISING_EDGE and FALLING_EDGE
 */
#define INTERRUPT0_SENSE_CONTROL                             RAISING_EDGE
#define INTERRUPT1_SENSE_CONTROL                             RAISING_EDGE
#define INTERRUPT2_SENSE_CONTROL                             RAISING_EDGE

#endif /* EXTERNAL_INTERRUPT_CONFIG_H_ */
