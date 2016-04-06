/*
 * TimerDriver_Private.h
 *
 *  Created on: ???/???/????
 *      Author: lenovo
 */

#ifndef TIMERDRIVER_PRIVATE_H_
#define TIMERDRIVER_PRIVATE_H_

/*Comment!: setting physical values for timer's clock according to user's configurations */
#if PRESCALLER_INIT_VAL == NO_CLK
      #define CLK_SELECT2    0
      #define CLK_SELECT1     0
      #define CLK_SELECT0     0
#elif PRESCALLER_INIT_VAL == CLKCPU
      #define CLK_SELECT2     0
      #define CLK_SELECT1      0
      #define CLK_SELECT0      1
#elif PRESCALLER_INIT_VAL == CLKCPU_BY_8
      #define CLK_SELECT2      0
      #define CLK_SELECT1       1
      #define CLK_SELECT0      0
#elif PRESCALLER_INIT_VAL == CLKCPU_BY_64
      #define CLK_SELECT2       0
      #define CLK_SELECT1        1
      #define CLK_SELECT0        1
#elif PRESCALLER_INIT_VAL == CLKCPU_BY_256
      #define CLK_SELECT2       1
      #define CLK_SELECT1        0
      #define CLK_SELECT0        0
#elif PRESCALLER_INIT_VAL == CLKCPU_BY_1024
      #define CLK_SELECT2        1
      #define CLK_SELECT1        0
      #define CLK_SELECT0        1
#elif PRESCALLER_INIT_VAL == EXTERNAL_FALLING_EDGE
      #define CLK_SELECT2        1
      #define CLK_SELECT1         1
      #define CLK_SELECT0        0
#elif PRESCALLER_INIT_VAL == EXTERNAL_RISING_EDGE
      #define CLK_SELECT2        1
      #define CLK_SELECT1         1
      #define CLK_SELECT0         1
#endif

/*Comment!: setting physical values for timer's working mode according to user's configurations */
#if WAVEFORM_GENERATION_MODE == NORMAL_MODE
       #define WAVE_SEL1           0
       #define WAVE_SEL0          0
#elif WAVEFORM_GENERATION_MODE == PWM_PHASE_CORRECT
        #define WAVE_SEL1          0
        #define WAVE_SEL0          1
#elif WAVEFORM_GENERATION_MODE == COMPARE_MATCH
          #define WAVE_SEL1         1
          #define WAVE_SEL0        0
#elif WAVEFORM_GENERATION_MODE == FAST_PWM
          #define WAVE_SEL1         1
          #define WAVE_SEL0         1
#endif

/*
 * Comment!: These bits are related to Timer Control Register, but I didn't know Their usage yet,
 * so I'll set them by zeros till I know
 */

#define FORCE_OUT_COMPARE                      0
#define COMPARE_OUT1                                 0
#define COMPARE_OUT0                                 0

/*Comment!: Implementing Concatenation and Concatenation helper */
#define conc(x7,x6,x5,x4,x3,x2,x1,x0)     conchelper(x7,x6,x5,x4,x3,x2,x1,x0)
#define conchelper(y7,y6,y5,y4,y3,y2,y1,y0)   0b##y7##y6##y5##y4##y3##y2##y1##y0

/*Comment!: Timer peripheral's physical registers */
#define TIMER0_CONTROL_REG              ((volatile u8*)(0x53))
#define TIMER0_DATA_REG                     ((volatile u8*)(0x52))
#define TIMER0_COMPARE_REG               ((volatile u8*)(0x5C))
#define TIMER_INTERRUPT_MASK_REG  ((volatile u8*)(0x59))
#define TIMER_INTERRUPT_FLAG_REG   ((volatile u8*)(0x58))

#define TIMER0_CONTROL_REG_INIT_VAL     conc(FORCE_OUT_COMPARE, WAVE_SEL0,    \
	                                              COMPARE_OUT1, COMPARE_OUT0, WAVE_SEL1,   \
	                	                          CLK_SELECT2, CLK_SELECT1, CLK_SELECT0)

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
#endif /* TIMERDRIVER_PRIVATE_H_ */
