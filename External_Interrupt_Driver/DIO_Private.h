/*
 * DIO_Private.h
 *
 *  Created on: ???/???/????
 *      Author: lenovo
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

/*Comment!: Defining Boalean One/Zero */
#define u8ONE  1
#define u8ZERO 0

/*Comment!: Number of input ports Regs */
#define u8INPUTREGS_NUM 		 4
/*Comment!: Number of output ports Regs */
#define u8OUTPUTREGS_NUM	 4
/*Comment!: Number of direction ports Regs */
#define u8DDRREGS_NUM		     4
/*Comment!: I/O registers size */
#define DIO_u8REGSIZE				 8
/*Comment!: I/O Pins number */
#define DIO_u8PINSNUM			 32

#define REG_IS_OUTPUT 			0b11111111
#define REG_IS_INPUT				0b00000000
/*Comment!: Implementing Concatenation and Concatenation helper */
#define conc(x7,x6,x5,x4,x3,x2,x1,x0) conchelper(x7,x6,x5,x4,x3,x2,x1,x0)
#define conchelper(y7,y6,y5,y4,y3,y2,y1,y0) 0b##y7##y6##y5##y4##y3##y2##y1##y0

/*Comment!: Initialization function PreProcessor */
/*Comment!: Direction Preprocessor Initialization */
#define DIO_u8PORTADIR conc(DIO_u8PIN7_INITDIR,DIO_u8PIN6_INITDIR, \
							DIO_u8PIN5_INITDIR,DIO_u8PIN4_INITDIR, \
							DIO_u8PIN3_INITDIR,DIO_u8PIN2_INITDIR, \
							DIO_u8PIN1_INITDIR,DIO_u8PIN0_INITDIR)
#define DIO_u8PORTBDIR conc(DIO_u8PIN15_INITDIR,DIO_u8PIN14_INITDIR, \
							DIO_u8PIN13_INITDIR,DIO_u8PIN12_INITDIR, \
							DIO_u8PIN11_INITDIR,DIO_u8PIN10_INITDIR, \
							DIO_u8PIN9_INITDIR,DIO_u8PIN8_INITDIR)
#define DIO_u8PORTCDIR conc(DIO_u8PIN23_INITDIR,DIO_u8PIN22_INITDIR, \
							DIO_u8PIN21_INITDIR,DIO_u8PIN20_INITDIR, \
							DIO_u8PIN19_INITDIR,DIO_u8PIN18_INITDIR, \
							DIO_u8PIN17_INITDIR,DIO_u8PIN16_INITDIR)
#define DIO_u8PORTDDIR conc(DIO_u8PIN31_INITDIR,DIO_u8PIN30_INITDIR, \
							DIO_u8PIN29_INITDIR,DIO_u8PIN28_INITDIR, \
							DIO_u8PIN27_INITDIR,DIO_u8PIN26_INITDIR, \
							DIO_u8PIN25_INITDIR,DIO_u8PIN24_INITDIR)

/*Comment!: Port Values Preprocessor Initialization */
#define DIO_u8PORTAVAL conc(DIO_u8PIN7_INITVAL,DIO_u8PIN6_INITVAL, \
							DIO_u8PIN5_INITVAL,DIO_u8PIN4_INITVAL, \
							DIO_u8PIN3_INITVAL,DIO_u8PIN2_INITVAL, \
							DIO_u8PIN1_INITVAL,DIO_u8PIN0_INITVAL)
#define DIO_u8PORTBVAL conc(DIO_u8PIN15_INITVAL,DIO_u8PIN14_INITVAL, \
							DIO_u8PIN13_INITVAL,DIO_u8PIN12_INITVAL, \
							DIO_u8PIN11_INITVAL,DIO_u8PIN10_INITVAL, \
							DIO_u8PIN9_INITVAL,DIO_u8PIN8_INITVAL)
#define DIO_u8PORTCVAL conc(DIO_u8PIN23_INITVAL,DIO_u8PIN22_INITVAL, \
							DIO_u8PIN21_INITVAL,DIO_u8PIN20_INITVAL, \
							DIO_u8PIN19_INITVAL,DIO_u8PIN18_INITVAL, \
							DIO_u8PIN17_INITVAL,DIO_u8PIN16_INITVAL)
#define DIO_u8PORTDVAL conc(DIO_u8PIN31_INITVAL,DIO_u8PIN30_INITVAL, \
							DIO_u8PIN29_INITVAL,DIO_u8PIN28_INITVAL, \
							DIO_u8PIN27_INITVAL,DIO_u8PIN26_INITVAL, \
							DIO_u8PIN25_INITVAL,DIO_u8PIN24_INITVAL)

/*Comment!: Output Regs names according to each microController */
#define DIO_u8OutReg0Name ((volatile u8*)(0x3B))
#define DIO_u8OutReg1Name ((volatile u8*)(0x38))
#define DIO_u8OutReg2Name ((volatile u8*)(0x35))
#define DIO_u8OutReg3Name ((volatile u8*)(0x32))

/*Comment!: Input Regs names according to each microController */
#define DIO_u8InputReg0Name ((volatile u8*)(0x39))
#define DIO_u8InputReg1Name ((volatile u8*)(0x36))
#define DIO_u8InputReg2Name ((volatile u8*)(0x33))
#define DIO_u8InputReg3Name ((volatile u8*)(0x30))

/*Comment!: Ports directions names according to each microController */
#define DIO_u8PORT0DirName ((volatile u8*)(0x3A))
#define DIO_u8PORT1DirName ((volatile u8*)(0x37))
#define DIO_u8PORT2DirName ((volatile u8*)(0x34))
#define DIO_u8PORT3DirName ((volatile u8*)(0x31))


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


#endif /* DIO_PRIVATE_H_ */
