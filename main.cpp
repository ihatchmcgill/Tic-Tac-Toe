#include "grid.h"
#include <ostream>

using namespace std;

bool checkCoor(char i) {
	if (i == '1' || i == '2' || i == '3') {
		return true;
	} else {
    cout << "Sorry that is not a valid input. Please select 1, 2, or 3" << endl;
		return false;
	}
}

void playerTurn(grid &theGrid) {
	bool validRow = false;
	bool validCol = false;

	char row;
	while (!validRow) {
		cout << "Please select a row to place an 'X' (1 - 3 from top to "
				"bottom): ";
		cin >> row;
		if (checkCoor(row)) {
			validRow = true;
		}
	}
	cout << "You have selected ROW: " << row << endl;
	char col;
	while (!validCol) {
		cout << "Please select a column to place an 'X' (1 - 3 from left to "
				"right): ";
		cin >> col;
		if (checkCoor(col)) {
			validCol = true;
		}
	}
	cout << "You have selected COLUMN: " << col << endl;
	int r = (int)row - 48;
	int c = (int)col - 48;

	while (!theGrid.playerMove(r, c)) {
		cout << "Sorry, you cannot overwrite an existing 'X' or 'O'" << endl;
		validRow = false;
		validCol = false;
		while (!validRow) {
			cout << "Please select a row to place an 'X' (1 - 3 from top to "
					"bottom): ";
			cin >> row;
			if (checkCoor(row)) {
				validRow = true;
			}
		}
		cout << "You have selected ROW: " << row << endl;
		while (!validCol) {
			cout << "Please select a column to place an 'X' (1 - 3 from left "
					"to right): ";
			cin >> col;
			if (checkCoor(col)) {
				validCol = true;
			}
		}
		r = (int)row - 48;
		c = (int)col - 48;
	}
}
void computerTurn(grid &theGrid) {
	cout << "Computer placing an 'O'..." << endl;
	theGrid.computerMove();
}

int startGame(grid &theGrid) {
	char input;
	bool started = false;
	cout << "Welcome to Tic Tac Toe!" << endl;
	while (!started) {
		cout << "Select 1 if you'd like to go first, or 2 for the computer to "
				"go first: ";
		cin >> input;
		if (input == '1') {
			started = true;
			playerTurn(theGrid);
			return 0;
		} else if (input == '2') {
			started = true;
			computerTurn(theGrid);
			return 1;
		} else {
			cout << "Sorry, that is not valid input" << endl;
		}
	}
}

int main() {
  bool playAgain = true;;
  char input;
  while(playAgain){
    playAgain = true;
    int numMoves = 1;
	  grid myGrid;
	  //myGrid.printGrid();
	  int whoStarted =
		  startGame(myGrid); // 0 if player started, 1 if computer started

	  while (!myGrid.checkWinner(numMoves)) {
		  if (whoStarted == 0) {
			  computerTurn(myGrid);
        numMoves++;
        if(myGrid.checkWinner(numMoves)){
          break;
        }
			  playerTurn(myGrid);
        numMoves++;
		  } 
      else {
			  playerTurn(myGrid);
        numMoves++;
        if(myGrid.checkWinner(numMoves)){
          break;
        }
			  computerTurn(myGrid);
        numMoves++;
		  }
	  }
  cout << "GAME OVER. Would you like to play again? (Y/N): ";
  cin >> input;
  while(input != 'Y'  && input != 'N'){
      cout << "Sorry that is not valid input. Would you like to play again? (Y/N): ";
      cin >> input;
    }
  if(input == 'N'){
    cout << "Thanks for playing!" << endl;
    return 0;
    }
  }
  return 0;
}