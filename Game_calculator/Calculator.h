#pragma once

#include <iostream>

using std::cout;
using std::cin;
using std::endl;


#ifndef Class_Calculator
#define Class_Calculator

class Calculator
{
public:
	Calculator() {}
	// 오버라이딩 할 가상함수(필수) -> 결과 : 값 출력
	virtual void Result() = 0;
	// 정적 멤버 result 선언
	static float result;

protected:
	float input1;
	float input2;
	
};

class Plus : public Calculator
{
public:	
	Plus(float a, float b)
	{
		this->input1 = a;
		this->input2 = b;
	}

	void Result() override;

};

class Minus : public Calculator
{

public:
	Minus(float a, float b)
	{
		this->input1 = a;
		this->input2 = b;
	}

	void Result() override;

};

class Mulifle : public Calculator
{

public:
	Mulifle(float a, float b)
	{
		this->input1 = a;
		this->input2 = b;
	}

	void Result() override;

};

class Divided : public Calculator
{

public:
	Divided(float a, float b)
	{
		this->input1 = a;
		this->input2 = b;
	}

	void Result() override;

};

#endif