#include <iostream>
#include "Calculator.h"

void Calculator::Result()
{
	cout << "결과 : "<< result << endl;
}

void Plus::Result()
{
	result = input1 + input2;
	cout << "결과 : " << result << endl;
}

void Minus::Result()
{
	result = input1 - input2;
	cout << "결과 : " << result << endl;
}

void Mulifle::Result()
{
	result = input1 * input2;
	cout << "결과 : " << result << endl;
}

void Divided::Result()
{
	// 예외 처리 필요
	result = input1 / input2;
	cout << "결과 : " << result << endl;
}