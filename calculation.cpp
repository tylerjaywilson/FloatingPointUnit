/* This class converts the float result value into a binary
form that can be compared with the Verilog simulation model
*/
#include <bitset>
#include "calculation.hpp" 
#include <iostream>
#include <math.h>

using namespace std;

Calculation::Calculation()
{
	operandBits = 0;
	operation = '+';
}

/* Print the desired float in binary form */
void Calculation::printToBinary(float operand)
{	
	cout << "\nBinary representation of " << operand << ": ";
	int bit = 0;	

	int *bits = reinterpret_cast<int*>(&operand); // use reinterpret_cast function
	for (int k = 31; k >=0; k--) // for loop to print out binary pattern
	{
		bit = ((*bits>> k)&(0x1)); // get the copied bit value shift right k times, then AND with a 1.
		cout << bit; // print the bit.
	}
	cout << endl << endl;

	operandBits = bits;
}

/* Perform the necessary operation of the two float values and return the result */
float Calculation::floatCalculation(float op1, float op2, char operate)
{
	float result = 0;

	switch(operate)
	{
		case '+':
			result = op1 + op2;
			break;
		case '-':
			result = op1 - op2;
			break;
		case '*':
			result = op1 * op2;
			break;
		case '/':
			result = op1 / op2;
			break;
		case '2':
			result = sqrt(op1);
			break;
		default:
			cout << "Error in operator input!" << endl;
	}
	return result;
}

//Do a comparison operation to determine if the input comparison holds true. Return true or false.
bool Calculation::compareCalculation(float op1, float op2, char operate)
{
	switch(operate)
	{
		case '<':
			if(op1 < op2)
				return true;
			else
				return false;
			break;
		case '>':
			if(op1 > op2)
				return true;
			else
				return false;
			break;
		case '=':
			if(op1 == op2)
				return true;
			else
				return false;
			break;
		default:
			cout << "Error in operator input!" << endl;
	}
}