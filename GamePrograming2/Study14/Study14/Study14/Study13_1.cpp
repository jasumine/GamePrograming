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

	cout << "ã�� �ܾ� : ";
	getline(cin, find);
	cout << "��ü�� �ܾ� : ";
	getline(cin, replace);

	int startIndex = 0;
	int findIndex = str.find(find, startIndex); // find �ܾ startIndex��ġ���� ã�Ƽ� findIndex�� �ִ´�
	str.replace(findIndex, find.length(), replace); // findIndex�� ��ġ���� find�� ���̿� replace�ܾ �ִ´�.
	cout << str << endl;
	*/

	string str;
	cout << "���ڿ��� �Է�. ";
	getline(cin, str);

	int length = str.length();

	for (int i = 0; i < str.length(); i++) // ���̸�ŭ ����
	{
		string first = str.substr(0, 1); // �ձ���
		string last = str.substr(1, length - 1); // �ձ��� ���� ������ ���̸�ŭ
		str = last + first; // �ޱ��� + �ձ���

		cout << str << endl;
	}

}