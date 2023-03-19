#include <iostream>

using namespace std;

int Strlen(const char* str)
{
	// 포인터를 사용해서 strlen을 구현해보기
	// str[i]번째가 \0이면, 길이는 i-1임. 
	int i = 0;
	while (str[i] != '\0') // i번째가 \0이 아닐떄까지, i는 길이
	{
		i++;
	}
	return  i;

}

// 문자열 복사 abc def abc // 1)포인터, 2)배열
char* StrCpy(char* dest, char* src) 
{
	for (int i = 0; i < sizeof(src); i++)
	{
		dest[i] = src[i]; 
		if (src[i] == '\0')
		{
			dest[i] = '\0';
			continue;
		}
	}
	return dest;

	/*
	1) 포인터
	char *ret = dest; // dest의 주소를 저장
	while(*src !='\0') // src의 값이 \0이 아닐때까지 진행
	{
	*dest = *src;
	*dest++ = *src++; // [i]가 계속 늘어나면서 정보를 넘겨주고있음.
	}
	*dest = '\0'; // 마지막에 null값을 넘겨준다.
	return ret; // dest[0]의 주소값을 가지고 있어서 ret을 반환
	
	2) 배열
	int i = 0;
	while(src[i] != '\0')
	{
	dest[i] = src[i];
	i++
	}
	dest[i] = '\0';

	*/
}

// 문자를 서로 이어주는 함수. abc def abcdef // 배열 pointer
char* StrCat(char* dest, char* src) //dest 뒤에 \0를 지우고 src를 붙이는 방식
{
	// dest의 \0이 나올때부터, src의 크기만큼
	int n = 0;
	while (dest[n] != '\0')
	{
		n++;
	}
	// int n = Strlen(dest);

	for (int i = 0; i < sizeof(src); i++)
	{
		dest[n + i] = src[i];
	}
	// dest[n+i] = '\0';
	/*
	1) 배열
	while(src[i] != '\0')
	{
	dest[len+i] = src[i];
	i++;
	}
	dest[len+i] = '\0';


	2) 포인터
	char *ret = dest;

	while(*dest != '\0') dest++;
	while(*src != '\0') *dest++ = *src++;

	*dest = '\0';
	*/

	return dest;
}

// 3개 난이도가 하고싶은신분만 // 사전 순서대로, 앞쪽이크면 1 뒤쪽문자열 크면 -1, 같으면 0
int StrCmp(char* a, char* b) // a>b,	a<b,	a=b // abc abf 라면 -1을 반환
{
	int i = 0;
	while (a[i] != '\0' || b[i] != '0')
	{
		if (a[i] > b[i]) return 1;
		else if (a[i] < b[i]) return -1;
		else if (a[i] == b[i]) return 0;
		i++;
	}

}


#pragma warning(disable:4996) // 4996에러를 무시

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

	cout << StrCmp(a, b) <<endl;
}
