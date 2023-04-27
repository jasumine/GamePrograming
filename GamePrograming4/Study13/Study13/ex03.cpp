#include <iostream>
using namespace std;

// 10의 갯수 2*5 =10
//			1 2 3 4 5 6 7 8 9 10 = 10!
//2의배수	  1   1   1   1    1 =8개
//				  1		  1
//                1       1

int main()
{
	int a;

	int line;
	cin >> line;
	for (int i = 0; i < line; i++)
	{
		cin >> a;

		int ret2 = 0, ret5 = 0;

		// 2*5인 10의 배수를 구하기위해 2를 구하느것 보다 5의 배수의 값을 구하는게 훨씬 빠르닷
		/*for (int j = 2; j < a; j *=2)
		{
			ret2 += a / j;
		}*/
		for (int j = 5; j <= a; j *= 5)
		{
			ret5 += a / j;
		}

		cout << ret5 << "\n";
	}

}