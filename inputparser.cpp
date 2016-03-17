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
void InputParser::parseOperandInput1(std::string operand)
{
	setOperand1(stof(operand));
}

//Parse the operands that the user input
void InputParser::parseOperandInput2(std::string operand)
{
	setOperand2(stof(operand));
}

//Parse the operator that the user input
void InputParser::parseOperatorInput(std::string operation)
{
	setOperator(operation[0]);
}