#include <iostream>
#include <string>

using namespace std;
// ����� ���� - ��� ����� ���� �˻�

int n;

int main()
{
	cin >> n;
	int i = 665;

	for (;; i++)
	{
		// i�� ���ڷ� �ٲ㼭 666�� ã�´�.  npos�� ã�� ���ߴٴ� ������ !=�̸� ã�Ҵٴ� ��
		if (to_string(i).find("666") != string::npos)
			n--;

		if (n == 0)
			break;
	}
	cout << i << endl;
}