#include<iostream>
using namespace std;
#include<vector>
#include<queue>

int main()
{
	int n = 7;
	int k = 3;
	vector<int> enemy{ 4,2,4,5,3,3,3,1 };

	priority_queue<int, vector<int>, greater<int>> pq;

	int sum = 0;
	int round = 0;

	for (int i = 0; i < enemy.size(); i++)
	{
		int e = enemy[i]; 
		pq.push(e); // pq ���� �ּҰ��� top���� ������ ����
		if (pq.size() > k) // �н��Ǻ��� Ŀ�� clear
		{
			sum += pq.top(); // ���� �������� sum�� �ְ�
			pq.pop();	// ���� ���� ���� pop -> pq���� ū ���鸸 ����. pass������ ó������
		}
		if (sum > n) // ���� �������� �������� n���� ũ�ٸ� 
		{
			round = i; // �ش� ���� ���������� Ŭ���� �Ѱ�.
			break; // +) sum�̶� n�� ���ٸ� �ش����� clear�Ѱ����� �����ϱ⶧��!
		}
		else // enemy�� �н��Ǻ��� ������ round�� enemy�� ũ�� || enemy�� ��簪�� ��ģ�� ���� n�� ũ�ٸ� ������ ����. round = enemy.size();
		{
			round = enemy.size();
		}
	}
	cout << round << endl;
}