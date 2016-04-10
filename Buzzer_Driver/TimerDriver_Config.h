/*
 * TimerDriver_Config.h
 *
 *  Created on: ???/???/????
 *      Author: lenovo
 */

#ifndef TIMERDRIVER_CONFIG_H_
#define TIMERDRIVER_CONFIG_H_

/*
 * Comment!: Defining Timer's clock value
 * It can take PRESCALLER_INIT_VAL = NO_CLK which means timer is not working
 * PRESCALLER_INIT_VAL = CLKCPU
 * PRESCALLER_INIT_VAL = CLKCPU_BY_8
 * PRESCALLER_INIT_VAL = CLKCPU_BY_64
 * PRESCALLER_INIT_VAL = CLKCPU_BY_256
 * PRESCALLER_INIT_VAL = CLKCPU_BY_1024
 * PRESCALLER_INIT_VAL = EXTERNAL_RISING_EDGE
 * PRESCALLER_INIT_VAL = EXTERNAL_FALLING_EDGE
 */
#define PRESCALLER_INIT_VAL                                     CLKCPU_BY_256

/*Comment!:
 * Defining Timer's working mode, It can take
 * NORMAL_MODE, PWM_PHASE_CORRECT, COMPARE_MATCH, FAST_PWM
 */
#define WAVEFORM_GENERATION_MODE                     NORMAL_MODE

/*Comment!: Timer's initial value */
#define TIMER_INIT_VAL                 0b00000000

#endif /* TIMERDRIVER_CONFIG_H_ */
