#include <iostream>
#include "Calculator.h"

void Calculator::Result()
{
	cout << "��� : "<< result << endl;
}

void Plus::Result()
{
	result = input1 + input2;
	cout << "��� : " << result << endl;
}

void Minus::Result()
{
	result = input1 - input2;
	cout << "��� : " << result << endl;
}

void Mulifle::Result()
{
	result = input1 * input2;
	cout << "��� : " << result << endl;
}

void Divided::Result()
{
	// ���� ó�� �ʿ�
	result = input1 / input2;
	cout << "��� : " << result << endl;
}