/*********************************/
/*   Author  : Mahmoud Tanany    */
/*   Version : 1.1               */
/*   Date    : December 20, 2020 */
/*********************************/


#include "LSTD_types.h"
#include "LBIT_math.h"

#include "MUART_private.h"
#include "MUART_interface.h"

void MUART_init(u32 CLK, u32 baud)
{
	u16 UBRR = ((CLK)/(16*baud));
	UBRRL = (u8)UBRR;
	UBRRH = (u8)(UBRR>>8);

//	 UBRRL = 103;		 //Setting baud rate to 9600 (Old)
//	UBRRL = 8;		 //Setting baud rate to 115200 (Old)

	CLEAR_BIT(UCSRB, 2); //Set char size to 8-bits (Bit UCSZ2)
	UCSRC = 0x86;		 //Char Size 8-bits (Bits UCSZ0:1) & Parity disabled & Stop bits 1
	UCSRB |= (3<<3);	 //Enable Tx & Rx
}

void MUART_Tx(u8 data)
{
	while(0==(GET_BIT(UCSRA,5)));	//Polling on UDRE bit
	UDR=data;
	while(0==(GET_BIT(UCSRA,6)));	//Polling on TXC Flag
}
void MUART_Tx_string(u8 data[])
{
	int i=0;
	while(data[i]!='\0')
	{
		MUART_Tx(data[i]);
		i++;
	}	//Transmit data

}

u8	 MUART_Rx(void)
{
	u8 data;
	while(0==(GET_BIT(UCSRA,7)));
	data = UDR;
//	while(1==(GET_BIT(UCSRA,7)));
	return data;
}

/*u8	 MUART_Rx_string(u8 length)
{
	int i=0;
	u8 data[length]=MUART_Rx();
	while(data[i]!='&')
	{
		i++;
		data[i] = MUART_Rx();
	}	//Transmit data
	data[i+1]='\0';
	return data;
}*/

void MUART_Rx_string(u8 *data, u8 TerminatingCharacter)
	
{
	u8 Ch;
	Ch = MUART_Rx();
	*data = Ch;
	data++;
	while (Ch != TerminatingCharacter)
	{
		Ch = MUART_Rx();
		*data = Ch;
		data++;
	}
	data--;
	*data = '\0';
}
