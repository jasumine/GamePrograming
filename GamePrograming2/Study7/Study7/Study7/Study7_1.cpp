#pragma warning(disable:4996) // 4996에러를 무시
#include<iostream>
using namespace std;

// #1
// 포인터를 사용해서 strlen을 구현해보기
int Strlen(char* str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}

// #2
// 문자열 복사 abc def abc // 1)포인터, 2)배열
void StrCpy(char* dest, char* src)
{	
	int i = Strlen(dest);
	for (int j = 0; j<Strlen(src); j++)
	{
		dest[i + j] = src[j];
	}

}
// #3
// 문자를 서로 이어주는 함수. abc def abcdef // 배열 pointer
void StrCat(char* str1, char* str2)
{

}

// #4
// 3개 난이도가 하고싶은신분만 // 사전 순서대로, 앞쪽이크면 1 뒤쪽문자열 크면 -1, 같으면 0
// a>b,	a<b,	a=b // abc abf 라면 -1을 반환
int StrCmp(char* str1, char* str2)
{
	int value = 0;
	return value;
}



int main()
{
	const int SIZE = 100;

	char a[SIZE] = "Hello"; //[H][e][l][l][o][\0] [] []
	char b[SIZE];

	int len = Strlen(a); // string length
	cout << len << endl;// 5가 나오게

	StrCpy(b, a); // b에 a의 값을 넣는다.
	for (int i = 0; i < Strlen(b); i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;

	StrCat(b, a);
	for (int i = 0; i < Strlen(b); i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;

	cout << StrCmp(a, b) << endl;
}