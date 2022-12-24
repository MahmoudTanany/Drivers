/*********************************/
/*   Author  : Mahmoud Tanany    */
/*   Version : 1.1               */
/*   Date    : December 20, 2020 */
/*********************************/


#ifndef _MDIO_INTERFACE_H_
#define _MDIO_INTERFACE_H_

#define MDIO_PORTA 	77 //Magic Numbers
#define MDIO_PORTB 	64 
#define MDIO_PORTC 	12 
#define MDIO_PORTD 	17  


#define MDIO_HIGH	1
#define MDIO_LOW	0

#define MDIO_INPUT	0
#define MDIO_OUTPUT	1

void MDIO_SetPortDirection(u8 port, u8 direction);		//DDR
void MDIO_SetPortValue(u8 port, u8 value); 				//PORT
u8 	 MDIO_GetPortValue(u8 port);						//PIN

void MDIO_SetPinDirection(u8 port, u8 pin, u8 direction);
void MDIO_SetPinValue(u8 port, u8 pin, u8 value);
u8   MDIO_GetPinValue(u8 port, u8 pin);

#endif

