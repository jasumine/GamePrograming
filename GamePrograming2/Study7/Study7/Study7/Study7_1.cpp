#pragma warning(disable:4996) // 4996������ ����
#include<iostream>
using namespace std;

// #1
// �����͸� ����ؼ� strlen�� �����غ���
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
// ���ڿ� ���� abc def abc // 1)������, 2)�迭
void StrCpy(char* dest, char* src)
{	
	int i = Strlen(dest);
	for (int j = 0; j<Strlen(src); j++)
	{
		dest[i + j] = src[j];
	}

}
// #3
// ���ڸ� ���� �̾��ִ� �Լ�. abc def abcdef // �迭 pointer
void StrCat(char* str1, char* str2)
{

}

// #4
// 3�� ���̵��� �ϰ�����źи� // ���� �������, ������ũ�� 1 ���ʹ��ڿ� ũ�� -1, ������ 0
// a>b,	a<b,	a=b // abc abf ��� -1�� ��ȯ
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
	cout << len << endl;// 5�� ������

	StrCpy(b, a); // b�� a�� ���� �ִ´�.
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