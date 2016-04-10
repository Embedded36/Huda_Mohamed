/*
 * KeyPad_Driver_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: lenovo
 */

#ifndef KEYPAD_DRIVER_INTERFACE_H_
#define KEYPAD_DRIVER_INTERFACE_H_

#define KEYPAD_SWITCH1_IDX                     0
#define KEYPAD_SWITCH2_IDX                     1
#define KEYPAD_SWITCH3_IDX                     2
#define KEYPAD_SWITCH4_IDX                     3
#define KEYPAD_SWITCH5_IDX                     4
#define KEYPAD_SWITCH6_IDX                     5
#define KEYPAD_SWITCH7_IDX                     6
#define KEYPAD_SWITCH8_IDX                     7
#define KEYPAD_SWITCH9_IDX                     8
#define KEYPAD_SWITCH10_IDX                    9
#define KEYPAD_SWITCH11_IDX                    10
#define KEYPAD_SWITCH12_IDX                    11
#define KEYPAD_SWITCH13_IDX                    12
#define KEYPAD_SWITCH14_IDX                    13
#define KEYPAD_SWITCH15_IDX                    14
#define KEYPAD_SWITCH16_IDX                    15

#define KEYPAD_ROW_IDX1                             0
#define KEYPAD_ROW_IDX2                             1
#define KEYPAD_ROW_IDX3                             2
#define KEYPAD_ROW_IDX4                             3

#define KEYPAD_COL_IDX1                             0
#define KEYPAD_COL_IDX2                             1
#define KEYPAD_COL_IDX3                             2
#define KEYPAD_COL_IDX4                             3


#define ACTIVE                                                  1
#define OFF                                                        0

void KeyPad_voidInit(void);
u8 Keypad_u8Read(u8* Copy_u8SwitchNo);
//u8 KeyPad_u8On(void);
//u8 KeyPad_u8ff(void);


#endif /* KEYPAD_DRIVER_INTERFACE_H_ */
