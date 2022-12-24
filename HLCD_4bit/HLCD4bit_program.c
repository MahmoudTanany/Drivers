/*********************************/
/*   Author  : Kanzy Amr         */
/*   Version : 1.0               */
/*   Date    : December 25, 2020 */
/*********************************/

#include "LBIT_math.h"
#include "LSTD_types.h"
#include "MDIO_interface.h"

#include "HLCD4bit_interface.h"

#include <util/delay.h>


void HLCD_init(void)
{
	_delay_ms(20);
	MDIO_SetPortDirection(HLCD_DATAPORT,0xFF); // output
	MDIO_SetPinValue(MDIO_PORTA, 3, MDIO_HIGH); //Buzzer OFF (AMIT Kit)
	MDIO_SetPinDirection(HLCD_CMDPORT,HLCD_RS,MDIO_OUTPUT); 
	MDIO_SetPinDirection(HLCD_CMDPORT,HLCD_RW,MDIO_OUTPUT);
	MDIO_SetPinDirection(HLCD_CMDPORT,HLCD_EN,MDIO_OUTPUT);
	HLCD_send_cmd(0x02);
	_delay_us(50);
	HLCD_send_cmd(0x28); // fn set , 4 bit mode
	_delay_us(50);
	HLCD_send_cmd(0x01); // entry mode set
	_delay_us(50);
	HLCD_send_cmd(0x06); // Display on/off
	_delay_us(50);
	HLCD_send_cmd(0x0C); // clear display
	_delay_ms(20);
}
// void HLCD_4bit(u8 data)
// {
// 	u8 data1;
// 	data = data & 0xF0; //mask lower nibble because PA4-PA7 pins are used. 
// 	HLCD_CMDPORT(data1); // send to LCD
// 	data1 = ((data<<4) & 0xF0); //shift 4-bit and mask
// 	HLCD_CMDPORT(data1); // send to LCD
// }
void HLCD_send_cmd(u8 data)
{	
	u8 data1;
	//data = data & 0x0F; //mask higher 4 bits because PA4-PA7 pins are used. 
	data1 = ((data<<4)); //shift 4-bit and mask
	MDIO_SetPinValue(HLCD_CMDPORT,HLCD_RS,MDIO_LOW);
	MDIO_SetPinValue(HLCD_CMDPORT,HLCD_RW,MDIO_LOW);
	MDIO_SetPortValue(HLCD_DATAPORT,data);
	MDIO_SetPinValue(HLCD_CMDPORT,HLCD_EN,MDIO_LOW);
	MDIO_SetPinValue(HLCD_CMDPORT,HLCD_EN,MDIO_HIGH);
	_delay_us(1);
	MDIO_SetPinValue(HLCD_CMDPORT,HLCD_EN,MDIO_LOW);
	_delay_ms(1);
	MDIO_SetPortValue(HLCD_DATAPORT,data1);
	MDIO_SetPinValue(HLCD_CMDPORT,HLCD_EN,MDIO_LOW);
	MDIO_SetPinValue(HLCD_CMDPORT,HLCD_EN,MDIO_HIGH);
	_delay_us(1);
	MDIO_SetPinValue(HLCD_CMDPORT,HLCD_EN,MDIO_LOW);
	_delay_ms(1);
}
void HLCD_send_data(u8 data)
{
	u8 data1;
	//data = data & 0x0F; //mask higher 4 bits because PA4-PA7 pins are used. 
	data1 = ((data<<4)); //shift 4-bit and mask
	MDIO_SetPinValue(HLCD_CMDPORT,HLCD_RS,MDIO_HIGH);
	MDIO_SetPinValue(HLCD_CMDPORT,HLCD_RW,MDIO_LOW);
	MDIO_SetPortValue(HLCD_DATAPORT,data);
	MDIO_SetPinValue(HLCD_CMDPORT,HLCD_EN,MDIO_LOW);
	MDIO_SetPinValue(HLCD_CMDPORT,HLCD_EN,MDIO_HIGH);
	_delay_us(1);
	MDIO_SetPinValue(HLCD_CMDPORT,HLCD_EN,MDIO_LOW);
	_delay_ms(1);
	MDIO_SetPortValue(HLCD_DATAPORT,data1);
	MDIO_SetPinValue(HLCD_CMDPORT,HLCD_EN,MDIO_LOW);
	MDIO_SetPinValue(HLCD_CMDPORT,HLCD_EN,MDIO_HIGH);
	_delay_us(1);
	MDIO_SetPinValue(HLCD_CMDPORT,HLCD_EN,MDIO_LOW);
	_delay_ms(1);
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

