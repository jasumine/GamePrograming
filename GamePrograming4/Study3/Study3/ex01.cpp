/* 숙제
괄호문제.
(), () 올바른 괄호
)( ,(()( 올바르지 않은 괄호

문자열 s () () true
		(())() true
		)()(  false
		(()(  false

push push 하다가  ( ) <- 한쌍이 만나면 pop 해주는 방식으로...
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
		{ // 끝에 2개를 비교해서 만들어보기~
			if (s.top() == ')') // 마지막이 ) 라면
			{
				char right = s.top(); // rihgt에 ) 를 담고
				s.pop(); // 지우고
				char left = s.top();
				if (left == '(') // 만약 left가 ( 라면
				{
					s.pop(); // ( )  가 맞아서. left가 속해있는 top을 지워준다.
				}
				else
				{
					s.push(right); // 아니라면 다시 right를 넣어서 원래대로 돌린다.
				}
			}
		}

		if (s.size() == 0)
		{
			cout << "true" << endl;
		}
	}
}