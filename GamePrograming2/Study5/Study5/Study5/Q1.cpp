// 길이가 10인 배열, 10개의 정수 입력받아서, 홀수와 짝수를 나누어 출력하는 프로그램
// 10개의 배열은 main에서 받고, 배열내에 존재하는 홀수만 출력하는 함수,
// 배열내에 짝수만 출력하는 함수를 정의해서 두 함수를 호출

#include <iostream>
#include <string>

using namespace std;

void zero(int numbers[]) // 짝수 출력 함수
{
	for (int i = 0; i < 10; i++)
	{
		if (numbers[i] % 2 == 0)
		{
			cout << "짝수 : " << numbers[i] << ",";
		}
	}
}

void one(int numbers[]) // 홀수 출력 함수
{
	for (int i = 0; i < 10; i++)
	{
		if (numbers[i] % 2 == 1)
		{
			cout << "홀수 : " << numbers[i] << " ,";
		}
	}
}

int main()
{
	int numbers[10];
	cout << "정수 10개를 입력 하세요." << endl;
	for (int i = 0; i < 10; i++)
	{
		cin >> numbers[i];
	}
	zero(numbers);
	one(numbers);
}