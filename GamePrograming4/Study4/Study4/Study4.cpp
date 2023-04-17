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

// -> main내에서 하지않고 bool 함수를 써서 만들어보기.
/*
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
					s.pop(); // ( )  가 맞아서. left가 속해있는 top을 지워준다.
				else
					s.push(right); // 아니라면 다시 right를 넣어서 원래대로 돌린다.
			}
		}
		if (s.size() == 0)
			cout << "true" << endl;
	}
}
*/

bool solution(string s)
{
	bool answer = true;
	stack<char> stk;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
			stk.push('(');
		else // )가 들어온 순간 (를 빼면 굳이 )를 넣지 않아도 빠지는것.
		{
			if (!stk.empty() && stk.top() == '(') // 비어있지 않고, top이 ( 라면 (를꺼내면 됨.
				stk.pop();
			else // 아니라면 )가 들어온 경우이고, 쌍이 아니여서 )를 넣어준다.
				stk.push(')');
		}
	}
	if (stk.empty()) //for를 돌렸을때 다 지워졌으면, 알맞은 쌍이 있는것.
		return true;
	else return false;
}

int main()
{
	string s;
	cin >> s;
	bool answer = solution(s);


}