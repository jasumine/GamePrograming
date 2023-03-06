#include <iostream>
#include <string>

using namespace std;

int main()
{
	/*
	string str;
	getline(cin, str);

	string find;
	string replace;

	cout << "찾을 단어 : ";
	getline(cin, find);
	cout << "대체할 단어 : ";
	getline(cin, replace);

	int startIndex = 0;
	int findIndex = str.find(find, startIndex); // find 단어를 startIndex위치부터 찾아서 findIndex에 넣는다
	str.replace(findIndex, find.length(), replace); // findIndex의 위치부터 find의 길이에 replace단어를 넣는다.
	cout << str << endl;
	*/

	string str;
	cout << "문자열을 입력. ";
	getline(cin, str);

	int length = str.length();

	for (int i = 0; i < str.length(); i++) // 길이만큼 ㄷㄷ
	{
		string first = str.substr(0, 1); // 앞글자
		string last = str.substr(1, length - 1); // 앞글자 빼고 나머지 길이만큼
		str = last + first; // 뒷글자 + 앞글자

		cout << str << endl;
	}

}