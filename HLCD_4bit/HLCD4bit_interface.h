/*********************************/
/*   Author  : Kanzy Amr         */
/*   Version : 1.0               */
/*   Date    : December 25, 2020 */
/*********************************/

#ifndef _HLCD_INTERFACE_H_
#define _HLCD_INTERFACE_H_

#define HLCD_DATAPORT	MDIO_PORTA
#define HLCD_CMDPORT	MDIO_PORTB

#define HLCD_EN			3
#define HLCD_RW			2
#define HLCD_RS			1

void HLCD_init(void);
void HLCD_send_cmd(u8 data);
void HLCD_send_data(u8 data);
void HLCD_send_data_string(u8 data[]);

#endif
