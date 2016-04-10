/*
 * delay.h
 *
 *  Created on: ???/???/????
 *      Author: lenovo
 */
#ifndef DELAY_H_
#define DELAY_H_
#include"delay_config.h"
/*Comment!: assume compare instruction takes 1 cycle */
/*Comment!: assume increment instruction takes 1 cycle*/
/*Comment!: NOP instruction takes 1 cycle */
#define Delay(DELAY_INMSEC) 		do{ \
								u32 u32Counter = 0; \
								for (u32Counter = ((DELAY_INMSEC*MC_CLK)/20000);u32Counter>0; u32Counter--) \
								{ \
								__asm__("NOP");\
								} \
								} \
								while(0)


#endif /* DELAY_H_ */

