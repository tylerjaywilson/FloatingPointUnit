#ifndef CALCULATION_HPP
#define CALCULATION_HPP

class Calculation
{
	int *operandBits;
	char operation;

	public:
		Calculation();	//Default Constructor
		void printToBinary(float);	//convert the float to binary
		void printToBinary(int);	//convert the int to binary
		float floatCalculation(float, float, char);
		bool compareCalculation(float, float, char);
};

#endif