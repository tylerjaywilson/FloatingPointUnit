/* Project: Floating Point Unit Execution: Golden Model for VLSI Design
Authors: Tyler Wilson and Michael Schena

This project allows the user to add, subtract, multiply, and divide floating point numbers.
This project allows the user to verify that the floating point unit created in Verilog
matches the output of this program.
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include "binaryconvert.hpp"
#include "inputparser.hpp"

using namespace std;

int main()
{
	cout << "\nFloating Point Calculator and Binary Respresentation \n\n";
	string operands;		//Operands 
	string operation;		//Operator

	cout << "Enter your operands seperated by a space (i.e. 5.2 14.41): \n";
	getline(cin, operands);
	cout << "\nEnter your operator(i.e. +): \n\n";
	getline(cin, operands);
	
	//Parse the operation and perform the operation
	InputParser parseIn;

	parseIn.parseOperandInput(operands);
	parseIn.parseOperatorInput(operation);

	printf("Operand 1: %d Operator: %c Operand 2: %d \n", parseIn.getOperand1(), parseIn.getOperator(), parseIn.getOperand2());


	return 1;
} 
