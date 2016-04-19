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
	cout << endl;

	//Parse the operation and perform the operation
	InputParser parseIn;
	parseIn.parseOperandInput1(operand1);
	parseIn.parseOperandInput2(operand2);
	parseIn.parseOperatorInput(operation);

	cout << "Operand1: " << parseIn.getOperand1() << " Operand2: " << parseIn.getOperand2() << " Operator: " << parseIn.getOperator() << endl;
	
	//Perform whatever necessary calculations or comparisons
	Calculation calculate;

	//Print the operands in binary form
	calculate.printToBinary(parseIn.getOperand1());
	calculate.printToBinary(parseIn.getOperand2());
	
	float calcResult;
	bool compResult;
	
	if(parseIn.getOperator() == '<' || parseIn.getOperator() == '>' || parseIn.getOperator() == '=')
	{
		compResult = calculate.compareCalculation(parseIn.getOperand1(), parseIn.getOperand2(), parseIn.getOperator());
		if(compResult == true)
			cout << "Operand 1: " << parseIn.getOperand1() << " is " << parseIn.getOperator() << " operand 2: " << parseIn.getOperand2() << endl;
		else
			cout << "Operand 1: " << parseIn.getOperand1() << " is not " << parseIn.getOperator() << " operand 2: " << parseIn.getOperand2() << endl;		
	}
	else if(parseIn.getOperator() == 'I')
	{
		int intResult = parseIn.getOperand1();
		cout << "The result is: " << intResult << endl;
		calculate.printToBinary(intResult);
	}
	else if(parseIn.getOperator() == 'F')
	{
		int intOp = parseIn.getOperand1();
		calculate.printToBinary(intOp);
		cout << "The result is: " << parseIn.getOperand1() << endl;
		calculate.printToBinary(parseIn.getOperand1());
	}
	else
	{
		calcResult = calculate.floatCalculation(parseIn.getOperand1(), parseIn.getOperand2(), parseIn.getOperator());
		cout << "The result is: " << calcResult << endl;
		calculate.printToBinary(calcResult);
	}

	return 1;
} 
