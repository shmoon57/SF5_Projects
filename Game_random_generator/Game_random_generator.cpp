// 프로젝트 3. 랜덤 숫자 맞추기 240523
/*
1) 컴퓨터가 1~25까지 수 중 랜덤으로 6개의 수 지정(중복X)
2) 사용자도 1~25까지의 수 중 랜덤으로 6개 입력(중복X)
3) 두 배열을 비교해서 몇 등인지 출력하기
	//  3-1) 1개도 못맞추면 7등, 1개만 맞추면 6등 , 2개 맞추면 5등
	//  3-2) 6개 맞추면 1등
*/

#include <iostream>
// 난수 생성위한 라이브러리
#include <cstdlib>
#include <ctime>


using std::cout;
using std::cin;
using std::endl;

#define Arr_Size 6

// 중복여부 확인 부울 함수
bool isDuplicate(int size, int arr[], int input);

int main()
{
	// 배열 선언
	int user_pick[6];
	int com_pick[6];
	int user_num;

	cout << "랜덤 숫자 맞추기 게임을 시작합니다 ! " << endl << endl;

	// int com_pick[6] 배열 초기화
	srand(time(NULL));

	for (int i = 0; i < Arr_Size; i++)
	{
		int input;
		// do - while문 활용 
		// 중복 발생시 input 재정의
		do
		{
			// 중복 방지 코드 작성 , 처음 한번은 실행
			input = rand() % 25 + 1;

		} while (isDuplicate(i, com_pick, input));

		com_pick[i] = input;
		// cout << com_pick[i] << endl; - 결과 확인용

	}

	cout << "숫자는 1 ~ 25까지의 숫자만 입력할 수 있습니다" << endl;

	for (int i = 0; i < Arr_Size; i++)
	{
		// do - while문 활용
		// if, if else 조건 발생시 무한 반복 , else 통해 빠져나오기
		do
		{
			cout << i + 1 << "번째 번호를 입력하세요: ";
			cin >> user_num;

			// 1 ~ 25 이외 숫자 입력 시
			if (user_num < 1 || user_num > 25)
			{
				cout << "유효하지 않은 숫자입니다. 1 ~ 25 사이의 숫자를 입력하세요." << endl;
			}

			// 번호가 중복시
			else if (isDuplicate(i, user_pick, user_num))
			{
				cout << "중복된 숫자입니다. 다시 입력해주세요." << endl;
			}

			else
			{
				break;
			}
		} while (true);

		user_pick[i] = user_num;
	}

	cout << endl << "-----------------------------" << endl;
	cout << "당첨번호 공개!" << endl;

	for (int i = 0; i < Arr_Size; i++)
	{
		cout << com_pick[i] << " ";

	}

	cout << endl << endl << "1 ~ 7등까지 결과가 나올 수 있습니다." << endl;

	// 배열 비교 case에 따라 결과 출력 코드 배열
	// 이중 for문 돌며 일치하는 숫자 카운트 
	int match_count = 0;

	for (int i = 0; i < Arr_Size; i++)
	{
		for (int j = 0; j < Arr_Size; j++)
		{
			if (user_pick[i] == com_pick[j])
			{
				match_count++;
			}
		}
	}

	switch (match_count)
	{
	case 0:
		cout << "결과 : 7등입니다!" << endl << endl;
		break;

	case 1:
		cout << "결과 : 6등입니다!" << endl << endl;
		break;

	case 2:
		cout << "결과 : 5등입니다!" << endl << endl;
		break;

	case 3:
		cout << "결과 : 4등입니다!" << endl << endl;
		break;

	case 4:
		cout << "결과 : 3등입니다!" << endl << endl;
		break;

	case 5:
		cout << "결과 : 2등입니다!" << endl << endl;
		break;

	case 6:
		cout << "결과 : 1등입니다!" << endl << endl;
		break;
	}

}


bool isDuplicate(int size, int arr[], int input)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == input)
		{
			return true;
		}
	}

	// 중복이 없는 경우 , i = size = 0 인경우 false 반환
	return false;
}
