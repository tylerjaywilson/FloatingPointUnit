/* Project: Floating Point Unit Execution: Golden Model for VLSI Design
Authors: Tyler Wilson and Michael Schena

This project allows the user to add, subtract, multiply, and divide floating point numbers.
This project allows the user to verify that the floating point unit created in Verilog
matches the output of this program.
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <bitset>
#include "calculation.hpp"
#include "inputparser.hpp"

using namespace std;

int main()
{
	cout << "\nFloating Point Calculator and Binary Respresentation \n\n";
	string operand1, operand2;		//Operands 
	string operation;		//Operator
	
	cout << "Enter your 1st operand (i.e. 3.12): \n";
	getline(cin, operand1);
	cout << "Enter your 2nd operand (i.e. -12.276): \n";
	getline(cin, operand2);
	cout << "Enter your operator(i.e. +): \n";
	getline(cin, operation);
	
	//Parse the operation and perform the operation
	InputParser parseIn;
	parseIn.parseOperandInput1(operand1);
	parseIn.parseOperandInput2(operand2);
	parseIn.parseOperatorInput(operation);

	cout << "Operand1: " << parseIn.getOperand1() << " Operand2: " << parseIn.getOperand2() << " Operator: " << parseIn.getOperator() << endl;

	//Perform whatever necessary calculation
	Calculation calculate;
	float result;
	result = calculate.floatCalculation(parseIn.getOperand1(), parseIn.getOperand2(), parseIn.getOperator());
	calculate.printToBinary(result);
	
	return 1;
} 
