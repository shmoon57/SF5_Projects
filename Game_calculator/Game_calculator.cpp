/*
240528 프로젝트 6 클래스 복습 (계산기 만들기)

클래스 상속 정적 멤버, 업캐스팅, 가상 함수를 사용하여 사칙연산 수행하는 계산기 만들기
(Y: 계속, AC: 초기화, Exit: 종료)

상속 -> 사칙연산
가상 함수, 업캐스팅 -> 결과 알려주는 함수
정적 멤버 -> 결과 값(result) 알려주기
*/

#include <iostream>
#include "Calculator.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

// static 변수 초기화
float Calculator::result = 0;

int main()
{
	float input1;
	float input2;
	char oper;
	string progress;

	bool correct_progress = false;

	cout << "사칙 연산 계산기 " << endl << endl;

	while (true)
	{
		// Progress = "AC" 입력시 여기서 시작
		cout << "숫자를 입력해주세요 : ";
		cin >> input1;
		Calculator::result = input1;
		while (true)
		{
			// Progress = "Y" 입력시 여기서 시작
			bool correct_progress = false;
			cout << "연산자를 입력해주세요 : ";
			cin >> oper;

			// 업캐스팅 선언
			Calculator* c;

			cout << "숫자를 입력해주세요 : ";
			cin >> input2;

			// 조건(연산자)에 따른 동적 할당
			switch (oper)
			{
			case '+':
				c = new Plus(Calculator::result, input2);
				break;

			case '-':
				c = new Minus(Calculator::result, input2);
				break;

			case '*':
				c = new Mulifle(Calculator::result, input2);
				break;

			case '/':
				c = new Divided(Calculator::result, input2);
				break;

			default:
				cout << "잘못된 연산자입니다" << endl;
				continue;
			}

			cout << "----------------------------------------------" << endl;
			// 동적 바인딩
			c->Result();
			// 동적할당 해제
			delete c;
			cout << endl;

			while (!correct_progress)
			{
				cout << "연산을 계속 진행하겠습니까? (Y: 계속, AC: 초기화, Exit: 종료) ";
				cin >> progress;

				if (progress == "Exit" || progress == "Y" || progress == "AC")
				{
					correct_progress = true;
					break;
				}

				// 예외 처리(잘못된 입력)
				else
				{
					cout << "잘못된 입력입니다! 다시 입력해주세요" << endl;
				}
			}


			// 연산 종료
			if (progress == "Exit")
			{
				break;
			}

			// 결과 연산 지속 
			else if (progress == "Y")
			{
				input1 = Calculator::result;
				continue;
			}

			// 연산 초기화
			else if (progress == "AC")
			{
				Calculator::result = 0;
				cout << "초기화 되었습니다! " << endl;
				break;
			}
		}

		if (progress == "Exit")
		{
			break;
		}

	}


	cout << "계산을 종료합니다" << endl;


	return 0;

}

