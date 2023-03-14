// 길이가 10인 배열을 선언하고, 총 10개의 정수를 입력받는다.
// 단, 입력받은 숫자가 홀수면 배열의 앞부터, 짝수면 뒤에서부터 채워나간다.
// 그리고 배열을 출력하기.

#include <iostream>

using namespace std;

int main()
{
	char num[10];
	cout << "정수 10개를 입력하세요." << endl;
	for (int i = 0; i < 10; i++)
	{
		cin >> num[i];
	}

	for (int i = 0; i < 10; i++)
	{
		if (num[i] % 2 == 1)
		{
			continue;
		}
	}

}