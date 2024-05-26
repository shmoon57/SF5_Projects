/*
프로젝트 1. 배스킨라빈스 31 게임 240522
서로 최소 1개에서 최대 3개의 연속된 숫자를 말하고 31이라는 숫자를 말하는 사람이 지는 게임.
1) 사용자는 본인이 입력한 숫자만큼.
2) 컴퓨터는 랜덤 숫자만큼.
3) 단 사용자, 컴퓨터 모두 1~3사이의 개수만 가능

개수를 입력
사용자 입력
예외처리) 1-3 사이의 수를 입력하게끔
컴퓨터 - 난수생성
	
31 나올시 게임 종료!

*/

#include <iostream>
// 1 ~ 3 난수 생성위한 라이브러리
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	// 유저가 입력하는 변수 선언
	int user_count;
	// 사용자가 입력한 카운트 변수
	int half_count = 0;
	// 사용자 + 컴퓨터가 입력한 카운트 변수
	int total_count = 0;
	

	cout << "<베스킨 라빈스 31 게임> 시작! " << endl;

	while (1)
	{
		// 1 ~ 3 난수 생성 위한 변수 초기화
		srand(time(NULL));
		int com_ram_num = rand() % 3 + 1;
		

		cout << endl << "개수를 입력하세요 : ";
		cin >> user_count;

		// 1 ~ 3 이외 입력값 예외처리
		if (user_count > 3 || user_count < 1)
		{
			cout << "1 ~ 3 사이의 수만 입력해주세요!" << endl;
			continue;
		}

		// 정상 작동
		else
		{
			cout << endl << "사용자가 부른 숫자" << endl;
			
			for (int i = 0; i < user_count; i++)
			{
				cout << total_count + i + 1 << endl;
			}

			// 사용자가 입력한 시점까지 카운트 누적
			half_count = total_count + user_count;

			// 카운트가 31이상 누적될시 While문 빠져나옴
			if (half_count >= 31)
			{
				cout << "게임 종료! 컴퓨터의 승리입니다" << endl;
				break;
			}

			cout << endl << "컴퓨터가 부른 숫자" << endl;

			for (int i = 0; i < com_ram_num; i++)
			{
				cout << half_count + i + 1 << endl;
				
			}

			// 사용자 + 컴퓨터가 입력한 시점까지 카운트 누적 
			total_count = half_count + com_ram_num;


			// 카운트가 31이상 누적될시 While문 빠져나옴
			if (total_count >= 31)
			{
				cout << "게임 종료! 사용자의 승리입니다" << endl;
				break;
			}

		}
	}

}


