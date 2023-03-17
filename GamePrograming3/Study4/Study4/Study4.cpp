#include <iostream>
using namespace std;
#include <iomanip>

const int MAX = 100;
int board[MAX][MAX] = {};
int N;

void PrintBorad()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << setfill('0') << setw(2) << board[i][j] << " ";
		}
		cout << endl;
	}
}

void setField(int n)
{
	int number = 1;
	int x = 0, y = 0;
	int countX = 0, countY = 0;
	int countN = n;
	int corner = 0;
	int saveX = 0;
	int saveY = 0;


	while (number <= n * n)
	{
		int MaxN = n - (n - countN);
		if (countX > 1) countX = 1;
		if (countY > 1) countY = 1;
		

		switch (corner % 4)
		{
		case 0: // → (y증가)
			for (y+countY; (y + countY) < MaxN-1; y++)
			{
				board[x - countX][y + countY] = number;
				number++;
			}
			saveY = y + countY;
			countX++;
			corner++;
			break;
		case 1: // ↓ (x 증가)

			for (x+countX; (x + countX)< MaxN-1; x++)
			{
				board[x + countX][y + countY] = number;
				number++;
			}
			countY++;
			corner++;
			break;
		case 2: // ← (y감소)
			for (y-countY; (y-countY)> MaxN-1; y--)
			{
				board[x + countX][y - countY] = number;
				number++;
			}
			corner++;
			countN--;
			break;
		case 3: // ↑ (x감소)
			for (x-countX; (x-countX)> MaxN; x--)
			{
				board[x - countX][y - countY] = number;
				number++;
			}
			corner++;
			break;
		}
	}
}


int main()
{
	cin >> N;
	setField(N);
	PrintBorad();

	
}