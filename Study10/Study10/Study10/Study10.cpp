/*
길이가 4x4인 2차원 배열을 선언한다.

	1	2	3	4	--90도회전-->	13	9	5	1	--90도회전-->	16	15	14	13	--90도회전-->	4	8	12	16
	5	6	7	8					14	10	6	2					12	11	10	9					3	7	11	15
	9	10	11	12					15	11	7	3					8	7	6	5					2	6	10	14
	13	14	15	16					16	12	8	4					4	3	2	1					1	5	9	13

*/

#include <iostream>
#include <iomanip>
using namespace std;

int board[4][4] = {};

void setBoard()
{
	int k = 1;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			board[i][j] = { k };
			k++;
		}
	}
}

void PrintBoard()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			cout << setfill('0')<<setw(2) << board[i][j] << " ";

		cout << '\n';
	}
}

void turnBoard(int board[][4])
{
	int turnBoard[4][4]{};
	for (int i=0; i < 4; i++)
	{
		for (int j =0; j < 4; j++)
		{
			turnBoard[i][j] = board[3-j][i];
			// turnBoard2[j][3-i] = board[i][j]; 
		}
	}
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			board[i][j] = turnBoard[i][j];
		}
	}
}

void oneLineTurn()
{
	for (int i = 0; i < 2; i++)
	{
		int temp01; // 바깥 배열 12개 
		int temp02; // 남은 안쪽배열 4개

		for (int j = i; j < 3 - i; j++)
		{
			temp01 = board[j][3 - i];
			board[j][3 - i] = board[i][j];

			temp02 = board[3 - i][3 - j];
			board[3 - i][3 - j] = temp01;

			temp01 = board[3 - j][i];
			board[3 - j][i] = temp02;

			board[i][j] = temp01;
		}
	}
}

int main()
{	
	setBoard();
	PrintBoard();

	for (int i = 0; i < 4; i++)
	{
		turnBoard(board);
		PrintBoard();
		cout << endl;
	}

}