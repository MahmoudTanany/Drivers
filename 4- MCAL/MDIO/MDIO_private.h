/*********************************/
/*   Author  : Mahmoud Tanany    */
/*   Version : 1.1               */
/*   Date    : December 20, 2020 */
/*********************************/



#ifndef _MDIO_PRIVATE_H_
#define _MDIO_PRIVATE_H_

typedef struct
{
	u8 PIN;
	u8 DDR;
	u8 PORT;
}GPIO_type;

#define GPIOD ((volatile GPIO_type *)0x30)
#define GPIOC ((volatile GPIO_type *)0x33)
#define GPIOB ((volatile GPIO_type *)0x36)
#define GPIOA ((volatile GPIO_type *)0x39)

// #define *((volatile u8*)0x3B) PORTA
// #define *((volatile u8*)0x3A) DDRA
// #define *((volatile u8*)0x39) PINA

#endif
