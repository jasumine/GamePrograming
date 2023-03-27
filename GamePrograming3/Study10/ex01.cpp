/*#1.vector를 사용하여 숫자를 입력받고,그숫자를 벡터에 삽입한뒤
벡터에 있는 수의 평균값을 출력하는 프로그램을 작성하자.
0을 입력하면 프로그램은 종료된다.
*/
#include <iostream>
#include <vector>
using namespace  std;


float average(vector<int> v)
{
	float average = 0;
	int v_size = v.size();
	for (auto it = v.begin(); it < v.end(); it++)
	{
		average += *it;
	}
	return average / v_size;
}

int main()
{
	vector<int> numbers;

	while (1)
	{
		cout << "숫자를 입력하세요.";
		int number;
		cin >> number;
		if (number == 0)
		{
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		}
		numbers.push_back(number);
		for (vector<int>::iterator it = numbers.begin(); it < numbers.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
		cout << "평균 : " << average(numbers) << endl;
	}
}

