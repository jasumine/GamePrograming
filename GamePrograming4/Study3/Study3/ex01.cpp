/* ����
��ȣ����.
(), () �ùٸ� ��ȣ
)( ,(()( �ùٸ��� ���� ��ȣ

���ڿ� s () () true
		(())() true
		)()(  false
		(()(  false

push push �ϴٰ�  ( ) <- �ѽ��� ������ pop ���ִ� �������...
*/
#include<iostream>
using namespace std;
#include<stack>


int main()
{
	stack<char> s;
	
	while (1)
	{
		char str;
		cin >> str;
		s.push(str);

		if (s.size() >= 2)
		{ // ���� 2���� ���ؼ� ������~
			if (s.top() == ')') // �������� ) ���
			{
				char right = s.top(); // rihgt�� ) �� ���
				s.pop(); // �����
				char left = s.top();
				if (left == '(') // ���� left�� ( ���
				{
					s.pop(); // ( )  �� �¾Ƽ�. left�� �����ִ� top�� �����ش�.
				}
				else
				{
					s.push(right); // �ƴ϶�� �ٽ� right�� �־ ������� ������.
				}
			}
		}

		if (s.size() == 0)
		{
			cout << "true" << endl;
		}
	}
}