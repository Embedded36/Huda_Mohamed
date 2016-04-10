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

/*Comment!: Prescaler Indices */
#define PRESCALER_CPUCLK                                         0
#define PRESCALER_CPUCLK_8                                     1
#define PRESCALER_CPUCLK_64                                   2
#define PRESCALER_CPUCLK_256                                 3
#define PRESCALER_CPUCLK_1024                                4

/*Comment!: possible values for timer's working modes */
#define NORMAL_MODE                                                 0
#define PWM_PHASE_CORRECT                                     1
#define COMPARE_MATCH                                             2
#define FAST_PWM                                                        3
#define MC_WORKING_FREQ_KHZ                               4000
#define MC_WORKING_FREQ_MHZ                               4

extern void TimerDrive_voidInit(void);
extern void TimerInterrupt_SetFn(void (*Ptr_Fn)(void));
extern void TimerDriver_voidOverFlowEnable(void);
extern void TimerDriver_voidOverFlowDisable(void);
extern void InputCaptureInterrupt_SetFn(void (*Ptr_Fn)(void));
extern void TimerDriver_voidInputCompareEnable(void);
extern void TimerDriver_voidInputCompareDisable(void);
extern u8 Timer_u8SetTimeMsec(u8 Copy_u8Time_msec);
extern u8 Timer_u8SetTimeUsec(u16 Copy_u8Time_usec);
void Timer_voidSetPrescaler(u8 Copy_u8PrescallerIndex);


#endif /* TIMERDRIVER_INTERFACE_H_ */
