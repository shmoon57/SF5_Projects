// 프로젝트 2. 타임어택 끝말잇기 게임 240522
/*
1) 제한시간 30초 동안 플레이어는 끝말잇기 규칙에 따라 단어를 입력
2) 제한시간이 종료되면 게임을 종료시키고 입력한 단어의 개수를 출력
3) 단 한번 입력된 단어는 입력하지 못하게 하기

예외처리
1) 잘못된 입력
2) 중복 선택

*/

#include <iostream>
#include <string>
#include <vector>
#include <ctime> // 타임어택 위한 라이브러리

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::cin;

void PrintVector(vector<string>& arr);
bool CheckDuplication(vector<string>& arr, string input);

int main()
{
	string word;
	int elasped_time = 0; // 경과시간 변수
	int count = 0; // 끝말잇기 성공한 횟수를 의미하는 변수

	// 벡터 선언 및 초기화
	vector<string> Word_relay = { "moon" };
	cout << "끝말잇기 게임을 시작합니다 ! " << endl << endl;
	cout << "초기 단어 : moon " << endl;

	// 타임 체크 시작
	clock_t Start_time = clock();

	while (elasped_time < 30)
	{
		cout << "다음 단어를 입력하세요 : ";
		cin >> word;
		cout << endl;

		// 경과 시간 계산
		clock_t End_time = clock();
		elasped_time = (End_time - Start_time) / CLOCKS_PER_SEC;

		// 예외 1 : 끝말잇기 규칙 위배되는 경우
		if (Word_relay.back().back() != word.front())
		{
			cout << "잘못된 입력입니다." << endl;
			continue;
		}

		// 예외 2 : 중복단어 입력한 경우 
		if (CheckDuplication(Word_relay, word))
		{
			cout << "중복된 단어입니다." << endl;
			continue;
		}

		// 입력한 단어를 벡터에 추가
		Word_relay.push_back(word);

		count++;

		PrintVector(Word_relay);
		cout << endl;

	}

	cout << "타임오버!" << endl << endl;

	cout << "게임 종료!" << endl << "총 입력한 단어 개수 : " << count << endl;

	return 0;
}


// 벡터 내용 출력 함수
void PrintVector(vector<string>& arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr.at(i) << "->";
	}
}

// for문 이용해 사용자 입력시 중복되는거 있으면 true 출력
bool CheckDuplication(vector<string>& arr, string input)
{
	for (string word : arr)
	{

		if (word == input)
		{
			return true;
		}
	}

	return false;
}
