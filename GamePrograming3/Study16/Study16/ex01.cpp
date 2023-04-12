#include <iostream>
using namespace std;

int N, M, J;

int main()
{
	cin >> N >> M >> J;
	int cnt = 0;

	int start = 1, end = M; // 1~M까지 바구니의 크기.

	while (J--) // J(사과의개수)가 0이 될때까지.
	{
		int x; // 사과 위치
		cin >> x;
		
		bool flag = true;

		while (flag)
		{
			if (start <= x && x <= end) // x 는 start와 end 사이에 있음. = 바구니 크기안에 있다.
			{
				flag = false; // 움직이지 않는다.
			}
			else if (start > x) // start가 x의 위치보다 높이 있다면, <<으로 옮겨야함.
			{
				start--; 
				end--;	// <<으로 옮겨야해서 -- 
				cnt++; // 움직인 카운트는 ++
			}
			else // 이 외의 경우엔 >>으로 옮긴다.
			{
				start++; 
				end++;
				cnt++;
			}
		}
	}
	cout << cnt;
}