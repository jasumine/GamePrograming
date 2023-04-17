/*
0111010 = 1111(4글자) = 100(4)

01110 = 111(3글자) = 11(3)
11= 11(2글자) = 10(2)
10 = 1 = 1
-> 0은 3번 없어졌다. 변환을 총 3번함. 

원본		0을 제거한 숫자 
1111111 = 1111111 = 111(7) -> 7글자
111	=	111		= 11(3) -> 3글자
11	=	11		= 10(2) 
10	=	1		= 1 (1)

총 4번 변환, 제거된 0은 1개
*/

#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <string>
using namespace std;

string bitset(int num)
{ 
	// num == 10
	list<int> r;
	int top = num / 2; // 5
	r.push_back(num % 2); // 0
	while (top < 1)
	{
		r.push_front(top % 2); 
		// 1 --> top 2 / r 1
		// 2 --> top 1 / r 0
	}
	
	string bit;
	int count=0;
	for (auto it = r.begin(); it != r.end(); it++)
	{
		bit[count] = *it;
		count++;
	}
	return bit;
}


int main()
{
	string number;
	cin >> number;

	// temp에 1만 들어가도록 넣기.
	string temp;
	int tempsize = 0;
	int count = 0;
	int zeroCount = 0;
	while (tempsize != 1)
	{
		int tempsize = 0;
		for (int i = 0; i < number.size(); i++)
		{
			if (number[i] == '1')
			{
				temp.append(1, number[i]);
				tempsize++;
			}
			else zeroCount++;

		}
		temp = bitset(tempsize);
		count++;
	}
	cout << "변환 : " << count << " 없어진 0의 개수 : " << zeroCount;

}