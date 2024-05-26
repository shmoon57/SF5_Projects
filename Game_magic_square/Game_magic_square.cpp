// 프로젝트 4. 마방진 만들기 240524
/*
규칙
1) 1은 첫 행의 가운데
2) 우상단으로 갈 수록 숫자가 1씩 늘어남
3) 우상단으로 이동하는 도중 이미 칸 채워져있을경우 바로 아래칸에 숫자 채워짐
4) 첫번째 행에서 우상단으로 이동할 때는 마지막 행의 다음열로 이동
5) 마지막 열에서 우상단으로 이동할 때는 첫번째 열의 이전 행으로 이동한다
6) 첫번째 행의 마지막 열에서는 우상단으로 이동하는 것이 아니라 바로 아래칸으로 이동
*/

#include <iostream>

using std::cin;
using std::cout;
using std::cout;
using std::endl;

int main()
{
	int odd_num;
	bool odd_check = false;
	cout << "-----------------마방진 출력---------------------" << endl << endl;

	// 예외 처리 - 홀수 입력 했을때
	while (!odd_check)
	{
		cout << "마방진의 행 혹은 열의 수를 홀수로 입력해주세요 : ";
		cin >> odd_num;
		if (odd_num % 2 == 1 && odd_num > 2)
		{
			odd_check = true;
			break;
		}
		else
		{
			cout << "잘못 입력하셨습니다! 다시 입력해주세요" << endl;
		}
	}

	// 동적 배열
	int** arr = new int* [odd_num];

	for (int i = 0; i < odd_num; i++)
	{
		arr[i] = new int[odd_num];
	}

	// 모든 값(value)을 0으로 초기화 -> 할 필요는 없노
	for (int i = 0; i < odd_num; i++)
	{
		for (int j = 0; j < odd_num; j++)
		{
			arr[i][j] = 0;
		}
	}

	// 동적 배열 할당
	// 1) 1은 첫 행의 가운데
	int i = 0;
	int j = odd_num / 2;
 	

	for (int value = 1; value <= odd_num * odd_num; value++) 
	{

		// 15 -> 16 갈때 
		if (i < 0 && j == odd_num)
		{
			i = 1; 
			j = odd_num - 1 ;  
		}
		
		else
		{
			// 1 -> 2 갈때
			if (i < 0)
			{
				i = odd_num - 1;
			}

			// 3 -> 4 갈때
			else if (j == odd_num)
			{
				j = 0;
			}
		}

		// 조건 아닐경우 : continue loop 끝으로 
		if (!(arr[i][j] == 0))
		{
			i = i + 2;
			j = j - 1;

			continue;
		}

		else
		{
			arr[i][j] = value;
		} 
		
			// 우상단 규칙 기본
			i--;
			j++;
		}


	// 배열 값 출력
	for (int i = 0; i < odd_num; i++)
	{
		for (int j = 0; j < odd_num; j++)
		{
			cout << " " << arr[i][j];
		}
		cout << endl;
	}

	// 동적 배열 해제
	for (int i = 0; i < odd_num; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;



	return 0;
}


