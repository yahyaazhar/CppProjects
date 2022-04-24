#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// global variables
int row, colm;
char gam[3][3] = { { '1', '2', '3' }, { '4', '5', '6' }, { '7', '8', '9' } };
char turn = 'X';
bool draw = false;

// prototypes 
void board();
void player1();
void player2();
bool game_over();

int main()
{

	while (game_over())
	{
		board();
		player1();
		game_over();

	}

	if (turn == 'X' && draw == false)
	{
		cout << "PLAYER 2 [O] Wins!\n";
	}
	else if (turn == 'O' && draw == false)
	{
		cout << "PLAYER 1 [1] Wins!\n";
	}
	else
	{
		cout << "DRAW!\n";
	}
}
void board()   // display board
{
	system("cls");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << gam[i][j] << " : ";
		}
		cout << endl << "-----------" << endl;
	}

}

void player1() // gameplay
{
	int choice;

	if (turn == 'X')
	{
		cout << "PLAYER 1 TURN [X]: ";
	}
	if (turn == 'O')
	{
		cout << "PLAYER 2 TURN [O]: ";
	}

	cin >> choice;

	switch (choice)
	{

	case  1: row = 0; colm = 0;
		break;
	case 2: row = 0; colm = 1;
		break;
	case  3: row = 0; colm = 2;
		break;
	case 4: row = 1; colm = 0;
		break;
	case  5: row = 1; colm = 1;
		break;
	case 6: row = 1; colm = 2;
		break;
	case  7: row = 2; colm = 0;
		break;
	case 8: row = 2; colm = 1;
		break;
	case  9: row = 2; colm = 2;
		break;

	default: cout << "INVALID COICE: " << endl;
		break;

	}
	if (turn == 'X' && gam[row][colm] != 'X' && gam[row][colm] != 'O')
	{
		gam[row][colm] = 'X';
		turn = 'O';
	}
	else if (turn == 'O' && gam[row][colm] != 'X' && gam[row][colm] != 'O')
	{
		gam[row][colm] = 'O';
		turn = 'X';
	}
	else
	{
		cout << "BOX IS ALREADY TAKEN! CHOOSE ANY OTHER BOXXX\n";
		player1();
	}
}

bool game_over()     // for final result
{  // for winner
	for (int i = 0; i < 3; i++)
	{

		if (gam[i][0] == gam[i][1] && gam[i][0] == gam[i][2] || gam[0][i] == gam[1][i] && gam[0][i] == gam[2][i])

			return false;
	}
	// for diagonals
	if (gam[0][0] == gam[1][1] && gam[0][0] == gam[2][2])
	{
		return false;
	}
	if (gam[0][2] == gam[1][1] && gam[0][2] == gam[2][0])
	{
		return false;
		}
	// if any box not filled
	for (int i = 0; i < 3; i++)
	{

		for (int j = 0; j < 3; j++)
		{
			if (gam[i][j] != 'X' && gam[i][j] != 'O')
				return true;
		}
	}
	// draw
    draw = true;
	return false;

}