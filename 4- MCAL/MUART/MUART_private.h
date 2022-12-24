/*********************************/
/*   Author  : Mahmoud Tanany    */
/*   Version : 1.0               */
/*   Date    : December 24, 2020 */
/*********************************/

#ifndef _MUART_PRIVATE_H_
#define _MUART_PRIVATE_H_

#define UDR   *((volatile u8*)0x2C)
#define UCSRA *((volatile u8*)0x2B)
#define UCSRB *((volatile u8*)0x2A)
#define UBRRL *((volatile u8*)0x29)
#define UCSRC *((volatile u8*)0x40)
#define UBRRH *((volatile u8*)0x40)



#endif
