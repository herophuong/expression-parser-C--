/*
 * ominus.cpp
 *
 *  Created on: 03-01-2012
 *      Author: herop-kde
 */

#include "functions.hpp"

/************************************************
 * 												*
 *       OPERATOR OVERLOADING: MINUS			*
 * 												*
 ************************************************/
big_num big_num::operator-(big_num op2)
{
	big_num temp;
	int index1, index2;
	int carry = 0;

	/*CONSIDER DIFFERENT SITUATIONS*/
	//If the minuend is negative, change minus to plus
	if (op2.sign == -1)
	{
		return (*this + op2);
	//If not but the subtrahend is negative, also change minus
	//to plus with the result is also negative
	} else {
		if (sign == -1)
		{
			op2.sign = -1;
			temp = op2 + *this;
			return temp;
		}
	}
	//Now, if the subtrahend is smaller than the minuend,
	//we swap their position and return the negative result of the new operation
	if (abs_compare(*this, op2) == -1)
	{
		temp = op2 - *this;
		temp.sign = -1;
		return temp;
	}

	/*DOING THE SUBSTRACTION*/
	//Make the index for subtrahend and minuend
	index1 = number.length() - 1;
	index2 = op2.number.length() - 1;
	//Subtract digit by digit from right to left until there's no digit of minuend left
	for ( ;index2 != -1; index1--, index2--)
	{
		if (number.at(index1) >= op2.number.at(index2))
		{
			carry += number.at(index1) - op2.number.at(index2);
			temp.number.insert(0,1,D2C(carry));
			carry = 0;
		}
		else
		{
			carry += 10 + number.at(index1) - op2.number.at(index2);
			temp.number.insert(0,1,D2C(carry%10));
			carry = -1;
		}
	}
	//Now put the other digits of subtrahend into the result
	while (index1 >= 0)
	{
		if (carry == -1)	//Do not forget the carry phase
		{
			if (number.at(index1) != 0)
			{
				temp.number.insert(0,1,carry+number.at(index1));
				carry = 0;
			}
			else
			{
				temp.number.insert(0,1,'9');
				carry = -1;
			}
		} else {
			temp.number.insert(0,1,number.at(index1));
		}
		index1--;
	}
	//Remove redundant zero digits at the left side
	while (temp.number.at(0) == '0' && temp.number.length() > 1)
		temp.number.erase(0,1);
	return temp;
}
