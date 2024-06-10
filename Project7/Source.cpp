#include <iostream>
#include <iomanip>
using namespace std;

#define SIZE 3

void displayscreen(char[][3]); //function prototype to display the grid
bool validate(char[][3]); //function prototype to check for the win condition.

int main() {
	bool valid; //check for valid input
	char grid[SIZE][SIZE] = { {' ',' ',' '}, {' ',' ',' '} ,{' ',' ',' '}};
	int userinput, counter=0; //get user input and check and check for the game round.
	bool endgame = false;
	int col, row;
	while (counter!=9 && !endgame) { //check for two condition whether the game draw or either player won the game early
		valid = true;
		displayscreen(grid);
		cout << "Player " << counter%2+1 << " please key in the desire position by using numpad position:";
		cin >> userinput;
		row = (9 - userinput) / 3;
		col = (userinput - 1) % 3;
		if (userinput > 0 && userinput < 10 && grid[row][col] == ' ') {
			if (counter % 2 == 0)
				grid[row][col] = 'X';
			else
				grid[row][col] = 'O';
			}
		else
			valid = false;

		endgame = validate(grid);

		if (!valid) {
			cout << "Please key in an appropriate Value." << endl;
			system("PAUSE");
		}
		else
			counter++;
		system("CLS");
	}
	displayscreen(grid);
	if (endgame)
		cout << "Game End, the winner is Player " << --counter % 2 + 1 << endl;
	else
		cout << "Game End, no one win this match!";
}

void displayscreen( char grid[3][SIZE]) {
	cout << "|-----------Tic Tac Toe-------------|" << endl;
	cout << "|-----------------------------------|" << endl; //36 words
	for (int i = 0; i < SIZE; i++) {
		cout << "|";
		for (int j = 0; j < SIZE; j++) {
			cout << "     " << grid[i][j] << "     |";
		}
		cout << endl ;

	}
	cout << "|-----------------------------------|" << endl;
}

bool validate(char grid[][3]) {
	for (int i = 0; i < SIZE; i++) { 
		//Check for horizontal line
		if ((grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][2] != ' ') || (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[2][i] != ' '))
			return true;
	}
	//Check for diagonal line
	if ((grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]&& grid[2][2] != ' ' )|| (grid[2][0] == grid[1][1] && grid[1][1] == grid[2][0] && grid[2][0] != ' '))
		return true;
	else
		return false;

	}