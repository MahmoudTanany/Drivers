/*********************************/
/*   Author  : Mahmoud Tanany    */
/*   Version : 1.1               */
/*   Date    : December 20, 2020 */
/*********************************/

#ifndef _LBIT_MATH_H_
#define _LBIT_MATH_H_

#define SET_BIT(REG, BIT) 		REG |= (1<<BIT)
#define CLEAR_BIT(REG, BIT)		REG &=~(1<<BIT)
#define TOGGLE_BIT(REG, BIT)	REG ^= (1<<BIT)
#define GET_BIT(REG,BIT)		(REG>>BIT)&1

#endif