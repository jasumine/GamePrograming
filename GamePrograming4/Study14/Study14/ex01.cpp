#include <iostream>
#include <string>

using namespace std;
// 브루토 포스 - 모든 경우의 수를 검사

int n;

int main()
{
	cin >> n;
	int i = 665;

	for (;; i++)
	{
		// i를 문자로 바꿔서 666을 찾는다.  npos는 찾지 못했다는 뜻으로 !=이면 찾았다는 뜻
		if (to_string(i).find("666") != string::npos)
			n--;

		if (n == 0)
			break;
	}
	cout << i << endl;
}