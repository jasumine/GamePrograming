/*#1.vector�� ����Ͽ� ���ڸ� �Է¹ް�,�׼��ڸ� ���Ϳ� �����ѵ�
���Ϳ� �ִ� ���� ��հ��� ����ϴ� ���α׷��� �ۼ�����.
0�� �Է��ϸ� ���α׷��� ����ȴ�.
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
		cout << "���ڸ� �Է��ϼ���.";
		int number;
		cin >> number;
		if (number == 0)
		{
			cout << "���α׷��� �����մϴ�." << endl;
			return 0;
		}
		numbers.push_back(number);
		for (vector<int>::iterator it = numbers.begin(); it < numbers.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
		cout << "��� : " << average(numbers) << endl;
	}
}

