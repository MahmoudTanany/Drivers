/*********************************/
/*   Author  : Mahmoud Tanany    */
/*   Version : 1.1               */
/*   Date    : December 20, 2020 */
/*********************************/


#include "LBIT_math.h"
#include "LSTD_types.h"

#include "MDIO_private.h"
#include "MDIO_interface.h"

void MDIO_SetPortDirection(u8 port,u8 direction)
{
	switch(port)
	{
		case MDIO_PORTA:
		{
			GPIOA -> DDR = direction;
			break;
		}
		case MDIO_PORTB:
		{
			GPIOB -> DDR = direction;
			break;
		}
		case MDIO_PORTC:
		{
			GPIOC -> DDR = direction;
			break;
		}
		case MDIO_PORTD:
		{
			GPIOD -> DDR = direction;
			break;
		}
		default:
		{
			//Report an Error
			break;
		}
	}
}
void MDIO_SetPortValue(u8 port, u8 value)
{
	switch(port)
	{
		case MDIO_PORTA:
		{
			GPIOA -> PORT = value;
			break;
		}
		case MDIO_PORTB:
		{
			GPIOB -> PORT = value;
			break;
		}
		case MDIO_PORTC:
		{
			GPIOC -> PORT = value;
			break;
		}
		case MDIO_PORTD:
		{
			GPIOD -> PORT = value;
			break;
		}
		default:
		{
			//Report an Error
			break;
		}
	}
}
u8  MDIO_GetPortValue(u8 port)
{
	u8 value;
	switch(port)
	{
		case MDIO_PORTA:
		{
			value = GPIOA -> PIN;
			break;
		}
		case MDIO_PORTB:
		{
			value = GPIOB -> PIN;
			break;
		}
		case MDIO_PORTC:
		{
			value = GPIOC -> PIN;
			break;
		}
		case MDIO_PORTD:
		{
			value = GPIOD -> PIN;
			break;
		}
		default:
		{
			//Report and Error
			break;
		}
	}
	return value;
}

void MDIO_SetPinDirection(u8 port, u8 pin, u8 direction)
{
	if(pin>=0 && pin<=7)
	{
		switch(port)
		{
			case MDIO_PORTA:
			{
				if(MDIO_OUTPUT == direction)
				{
					SET_BIT(GPIOA -> DDR, pin);
						
				}
				else if(MDIO_INPUT == direction)
				{
					CLEAR_BIT(GPIOA -> DDR, pin);
				}
				else
				{
					//report error
				}
				break;
			}	
		
			case MDIO_PORTB:
			{
				if(MDIO_OUTPUT == direction)
				{
					SET_BIT(GPIOB ->DDR, pin);
						
				}
				
				else if(MDIO_INPUT == direction)
				{
					CLEAR_BIT(GPIOB -> DDR, pin);
				}	
				else
				{
					//report error
				}
				break;
			}
			case MDIO_PORTC:
			{
				if(MDIO_OUTPUT == direction)
				{
					SET_BIT(GPIOC ->DDR, pin);
						
				}
				
				else if (MDIO_INPUT == direction)
				{
					
					CLEAR_BIT(GPIOC -> DDR, pin);
				}
				else
				{
					//report error
				}
				break;
			}
			
			case MDIO_PORTD:
			{
				if(MDIO_OUTPUT == direction)
				{
					SET_BIT(GPIOD ->DDR, pin);
						
				}
				
				else if (MDIO_INPUT == direction)
				{
					CLEAR_BIT(GPIOD -> DDR, pin);
				}
				else
				{
					//report error
				}
				break;
			}
			default:
			{
					//Report an Error
				break;
			}
		}
	}
	else
	{
		//Report an Error
	}	
}
void MDIO_SetPinValue(u8 port, u8 pin, u8 value)
{
	if(pin>=0 && pin<=7)
	{
		switch(port)
		{
			case MDIO_PORTA:
			{
				if(value == MDIO_HIGH)
				{
					SET_BIT(GPIOA -> PORT, pin);
						
				}
				else if(value == MDIO_LOW)
				{
					CLEAR_BIT(GPIOA -> PORT, pin);
				}
				else
				{
					//report error
				}
				break;
			}	
		
			case MDIO_PORTB:
			{
				if(value == MDIO_HIGH)
				{
					SET_BIT(GPIOB ->PORT, pin);
						
				}
				
				else if(value == MDIO_LOW)
				{
					CLEAR_BIT(GPIOB -> PORT, pin);
				}	
				else
				{
					//report error
				}
				break;
			}
			case MDIO_PORTC:
			{
				if(value == MDIO_HIGH)
				{
					SET_BIT(GPIOC ->PORT, pin);
						
				}
				
				else if (value == MDIO_LOW)
				{
					
					CLEAR_BIT(GPIOC -> PORT, pin);
				}
				else
				{
					//report error
				}
				break;
			}
			
			case MDIO_PORTD:
			{
				if(value == MDIO_HIGH)
				{
					SET_BIT(GPIOD ->PORT, pin);
						
				}
				
				else if (value == MDIO_LOW)
				{
					CLEAR_BIT(GPIOD -> PORT, pin);
				}
				else
				{
					//report error
				}
				break;
			}
			default:
			{
					//Report an Error
				break;
			}
		}
	}
	else
	{
		//Report an Error
	}
}
u8   MDIO_GetPinValue(u8 port, u8 pin)
{
	u8 value;
	
	if(pin >= 0 && pin <=7)
	{
		switch (port)
		{
			case MDIO_PORTA:
			{
				if(1 == (GET_BIT((GPIOA -> PIN),pin)))
				{
					value = MDIO_HIGH;
				}
				else if(0 == (GET_BIT((GPIOA -> PIN),pin)))
				{
					value = MDIO_LOW;
				}
				else
				{
					//report error
				}
				break;
			}
			case MDIO_PORTB:
			{
				if(1 ==(GET_BIT((GPIOB -> PIN),pin)))
				{
					value = MDIO_HIGH;
				}
				else if(0 ==(GET_BIT((GPIOB -> PIN),pin)))
				{
					value = MDIO_LOW;
				}
				else
				{
					//reprt error
				}
			break;
			}
			case MDIO_PORTC:
			{
				if(1 ==(GET_BIT((GPIOC -> PIN),pin)))
				{
					value = MDIO_HIGH;
				}
				else if(0 ==(GET_BIT((GPIOC -> PIN),pin)))
				{
					value = MDIO_LOW;
				}
				else
				{
					//reprt error
				}
			break;
			}
			case MDIO_PORTD:
			{
				if(1 ==(GET_BIT((GPIOD -> PIN),pin)))
				{
					value = MDIO_HIGH;
				}
				else if(0 == (GET_BIT((GPIOD -> PIN),pin)))
				{
					value = MDIO_LOW;
				}
				else
				{
					//reprt error
				}
			break;
			}
			
		}
	}
	else
	{
		//report error
	}
	
	return value;
}
