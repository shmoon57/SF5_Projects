// 프로젝트 5 야구게임 240525
/*
1) 사용자는 1부터 9까지 중 3개의 숫자를 뽑아 컴퓨터가 랜덤으로 뽑은 숫자 3개와 비교(중복 X)
숫자의 자리가 같으면 모두 strike
자리는 다르지만 3개의 숫자 중 포함되어 있으면 ball

*/

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

#define Vec_SIZE 3

using namespace std;

// 중복 체크 함수 
bool CheckDuplication(vector<int>& pick, int num, int size);
// 컴퓨터 pick 벡터 만드는 함수
void MakeComVector(vector<int>& pick);
// 유저 pick 벡터 만드는 부울 함수 false -> 게임 종료
bool MakeUserVector(vector<int>& pick);

int main()
{
	// 게임 종료 부울 변수
	bool isfinish = false;

	// 유저 및 컴퓨터가 선택한 빈 벡터 생성
	vector<int> user;
	vector<int> com;

	int loop_count = 0;

	cout << "----- 야구게임을 시작합니다! ----- " << endl << endl;

	while (!isfinish)
	{
		// 컴퓨터 pick 벡터 초기화 (완료)
		srand(time(NULL));

		// 컴퓨터가 선택한 벡터 초기화
		com.clear();
		MakeComVector(com);

		cout << "1 ~ 9 사이의 숫자 3개를 입력하세요 (이외의 숫자 : 종료) " << endl;

		// 유저가 선택한 벡터 초기화
		user.clear();

		if (!MakeUserVector(user))
		{
			cout << "게임을 종료하였습니다." << endl;
			break;
		}

		// 스트, 볼 갯수 초기화
		int count_strike = 0;
		int count_ball = 0;

		// 숫자와 자리가 같은 경우 스트라이크 1 추가
		for (int i = 0; i < Vec_SIZE; i++)
		{
			if (user.at(i) == com.at(i))
			{
				count_strike++;
			}
		}

		// 모든 인덱스 값들 비교하여 같은 경우 볼 1 추가(스트라이크 개수 포함됨)
		for (int i = 0; i < Vec_SIZE; i++)
		{
			for (int j = 0; j < Vec_SIZE; j++)
			{
				if (user.at(i) == com.at(j))
				{
					count_ball++;
				}
			}
		}

		// 스트라이크 갯수 만큼 차감
		if (count_strike != 0)
		{
			count_ball -= count_strike;
		}

		cout << "Strike : " << count_strike << "         Ball : " << count_ball << endl << endl;

		// 루프 1번 돌때 카운트 추가
		loop_count++;

		// 조건 3 스트라이크 -> 게임 종료
		if (count_strike == 3)
		{
			cout << loop_count << "번 만에 맞췄습니다." << endl;

			isfinish = true;
		}


	}

	return 0;
}

	void MakeComVector(vector<int>&pick)
{
	for (int i = 0; i < Vec_SIZE; i++)
	{
		while (true)
		{
			int com_num = rand() % 9 + 1;
			// 컴퓨터 pick 벡터 초기화
			pick.push_back(com_num);

			// 중복 없으면 빠져나오기
			if (!CheckDuplication(pick, com_num, i))
			{
				break;
			}
			// 중복있으면 벡터 값 빼기
			pick.pop_back();
		}
	}
}
	// 유저 벡터 만드는 부울 함수 
bool MakeUserVector(vector<int>& pick)
{
	int num;

	for (int i = 0; i < Vec_SIZE; i++)
	{
		while (true)
		{
			// 사용자가 선택할 숫자 입력
			cin >> num;

			// 1 ~ 9 숫자 이외 입력시 false -> main 문에서 게임종료
			if (num < 1 || num > 9)
			{
				return false;
			}

			// 중복 없을시 push_back
			if (!CheckDuplication(pick, num, i))
			{
				pick.push_back(num);
				break;
			}

			// 중복있으면 벡터 값 빼기
			else
			{
				cout << "중복된 값을 입력하셨습니다. 다시 입력해주세요! " << endl;
			}
			
		}
	}
	// 정상으로 만들어진 경우 true 출력
	return true;
}


// for문 이용해 벡터 값이 중복될시 true 출력
bool CheckDuplication(vector<int>& pick, int num, int size)
{
	for (int i = 0; i < size; i++)
	{
	
		if (pick.at(i) == num)
		{
			return true;
		}
	}

	return false;
}

