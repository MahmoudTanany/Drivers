/*********************************/
/*   Author  : Kanzy Amr         */
/*   Version : 1.0               */
/*   Date    : December 25, 2020 */
/*********************************/

#include "LBIT_math.h"
#include "LSTD_types.h"
#include "MDIO_interface.h"

#include "HLCD_interface.h"

#include <util/delay.h>


void HLCD_init(void)
{

	MDIO_SetPortDirection(HLCD_DATAPORT,0xFF);  //Make LCD port direction as o/p
	MDIO_SetPinDirection(HLCD_CMDPORT,HLCD_RS,MDIO_OUTPUT);
	MDIO_SetPinDirection(HLCD_CMDPORT,HLCD_RW,MDIO_OUTPUT);
	MDIO_SetPinDirection(HLCD_CMDPORT,HLCD_EN,MDIO_OUTPUT);
	HLCD_send_cmd(0x38); 
	HLCD_send_cmd(0x05); 
	_delay_ms(1);
	HLCD_send_cmd(0x0F);
	HLCD_send_cmd(0x01); 
	_delay_ms(2);
}
void HLCD_send_cmd(u8 data)
{
	MDIO_SetPinValue(HLCD_CMDPORT,HLCD_RS,MDIO_LOW);
	MDIO_SetPinValue(HLCD_CMDPORT,HLCD_RW,MDIO_LOW);
	MDIO_SetPortValue(HLCD_DATAPORT,data);
	MDIO_SetPinValue(HLCD_CMDPORT,HLCD_EN,MDIO_LOW);
	MDIO_SetPinValue(HLCD_CMDPORT,HLCD_EN,MDIO_HIGH);
	_delay_us(10);
	MDIO_SetPinValue(HLCD_CMDPORT,HLCD_EN,MDIO_LOW);
}
void HLCD_send_data(u8 data)
{
	MDIO_SetPinValue(HLCD_CMDPORT,HLCD_RS,MDIO_HIGH);
	MDIO_SetPinValue(HLCD_CMDPORT,HLCD_RW,MDIO_LOW);
	MDIO_SetPortValue(HLCD_DATAPORT,data);
	MDIO_SetPinValue(HLCD_CMDPORT,HLCD_EN,MDIO_LOW);
	MDIO_SetPinValue(HLCD_CMDPORT,HLCD_EN,MDIO_HIGH);
	_delay_us(1);
	MDIO_SetPinValue(HLCD_CMDPORT,HLCD_EN,MDIO_LOW);
}

void HLCD_send_data_string(u8 data[])
{
	int i=0;
	while(data[i]!='\0')
	{
		HLCD_send_data(data[i]);
		i++;
	}	//Transmit data


}

