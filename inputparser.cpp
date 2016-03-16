/* This class parses the input operation that the user would like to perform
and prepares for quick and easy computation of the input operators
and operands
*/

#include <string>
#include <stdint.h>
#include <stdio.h>
#include "inputparser.hpp" 

//Default Constructor
InputParser::InputParser()
{
	operand1 = 0.0;
	operand2 = 0.0;
	numOperands = 2;
	operation = '+';
} 

//Get and set functions for the operands and operator
void InputParser::setOperand1(float op1)
{
	operand1 = op1;
}
void InputParser::setOperand2(float op2)
{
	operand2 = op2;
}
void InputParser::setOperator(char operation_t)
{
	operation = operation_t;
}
float InputParser::getOperand1(void)
{
	return operand1;
}
float InputParser::getOperand2(void)
{
	return operand2;
}
char InputParser::getOperator(void)
{
	return operation;
}

//Parse the operands that the user input
void InputParser::parseOperandInput(std::string operands)
{
	char operand1[50];
	char operand2[50];

	int count1 = 0;
	int count2 = 0;
	while(operands[count1] != 0x20)
	{
		operand1[count1] = operands[count1];
		count1++;
	}

	count1++;
	while(operands[count2] != 0x00)
	{
		operand2[count2] = operands[count1];
		count1++;
		count2++;
	}

	double op1, op2;
	op1 = atof(operand1);
	op2 = atof(operand2);

	printf("Op1: %c%c%c%c", operand1[0], operand1[2], operand1[3],operand1[4]);
	printf("HERE: %d, %d", op1, op2);
	setOperand1(atof(operand1));
	setOperand2(atof(operand2));
}

//Parse the operator that the user input
void InputParser::parseOperatorInput(std::string operation)
{
	setOperator(operation[0]);
}