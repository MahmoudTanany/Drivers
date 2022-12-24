/*********************************/
/*   Author  : Mahmoud Tanany    */
/*   Version : 1.1               */
/*   Date    : December 20, 2020 */
/*********************************/


#ifndef _MUART_INTERFACE_H_
#define _MUART_INTERFACE_H_

void MUART_init(u32 CLK, u32 baud);
void MUART_Tx(u8 data);
u8	 MUART_Rx(void);
void MUART_Tx_string(u8 data[]);
void MUART_Rx_string(u8 *data, u8 TerminatingCharacter);

#endif
