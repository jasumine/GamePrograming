#include <iostream>
using namespace std;

int N, M, J;

int main()
{
	cin >> N >> M >> J;
	int cnt = 0;

	int start = 1, end = M; // 1~M���� �ٱ����� ũ��.

	while (J--) // J(����ǰ���)�� 0�� �ɶ�����.
	{
		int x; // ��� ��ġ
		cin >> x;
		
		bool flag = true;

		while (flag)
		{
			if (start <= x && x <= end) // x �� start�� end ���̿� ����. = �ٱ��� ũ��ȿ� �ִ�.
			{
				flag = false; // �������� �ʴ´�.
			}
			else if (start > x) // start�� x�� ��ġ���� ���� �ִٸ�, <<���� �Űܾ���.
			{
				start--; 
				end--;	// <<���� �Űܾ��ؼ� -- 
				cnt++; // ������ ī��Ʈ�� ++
			}
			else // �� ���� ��쿣 >>���� �ű��.
			{
				start++; 
				end++;
				cnt++;
			}
		}
	}
	cout << cnt;
}