/* This class converts the float result value into a binary
form that can be compared with the Verilog simulation model
*/
#include <bitset>
#include "binaryconvert.hpp" 
#include <iostream>

using namespace std;

BinaryConvert::BinaryConvert()
{
	operandBits = 0;
}

void BinaryConvert::printToBinary(float operand)
{	
	cout << "Binary representation of " << operand << ": ";
	int bit = 0;	

	int *bits = reinterpret_cast<int*>(&operand); // use reinterpret_cast function
	for (int k = 31; k >=0; k--) // for loop to print out binary pattern
	{
		bit = ((*bits>> k)&(0x1)); // get the copied bit value shift right k times, then AND with a 1.
		cout << bit; // print the bit.
	}
	cout << endl;

	operandBits = bits;
}