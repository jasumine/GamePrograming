// 백준 14469번
#include <iostream>
using namespace std;
#include<string>
#include<vector>

int total;

int main()
{
	int cowCount;
	cin >> cowCount;

	vector<int> vcow;
	vector<int> vsec;
	
	for (int i = 0; i < cowCount; i++)
	{
		int cow, sec;
		cin >> cow, sec;
		vcow.push_back(cow);
		vsec.push_back(sec);
	}

	while (cowCount--)
	{
		//망했어요
	}



	cout << total;
}
