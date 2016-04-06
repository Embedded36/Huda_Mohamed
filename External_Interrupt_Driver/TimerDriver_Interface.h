/*
 * TimerDriver_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: lenovo
 */

#ifndef TIMERDRIVER_INTERFACE_H_
#define TIMERDRIVER_INTERFACE_H_

/*Comment!: possible values for timer's clock */
#define NO_CLK                                                            0
#define CLKCPU                                                             1
#define CLKCPU_BY_8                                                   2
#define CLKCPU_BY_64                                                 3
#define CLKCPU_BY_256                                               4
#define CLKCPU_BY_1024                                              5
#define EXTERNAL_FALLING_EDGE                              6
#define EXTERNAL_RISING_EDGE                                7

/*Comment!: possible values for timer's working modes */
#define NORMAL_MODE                                                 0
#define PWM_PHASE_CORRECT                                     1
#define COMPARE_MATCH                                             2
#define FAST_PWM                                                        3

extern void TimerDrive_voidInit(void);
extern void TimerInterrupt_SetFn(void (*Ptr_Fn)(void));

#endif /* TIMERDRIVER_INTERFACE_H_ */
