#ifndef _INPUT_PARSER_HPP
#define _INPUT_PARSER_HPP

class InputParser
{
	float operand1, operand2;
	int numOperands;
	char operation;

	public:
		InputParser();	//Default Constructor
		void parseOperandInput1(std::string);
		void parseOperandInput2(std::string);
		void parseOperatorInput(std::string);
		void setOperand1(float);
		void setOperand2(float);
		void setOperator(char);
		float getOperand1(void);
		float getOperand2(void);
		char getOperator(void);
};

#endif