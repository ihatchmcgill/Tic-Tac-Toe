#include<time.h>
#include<cstdlib>
#include"grid.h"

grid::grid(){ //fill new grid with blank spots in constructor
  for(int i = 0; i < 3;i++){
    vector<char> currRow;
    for(int j = 0; j < 3; j++){
      currRow.push_back('_');
    }
    theGrid.push_back(currRow);
  }
}

grid::~grid(){}


void grid::printGrid(){
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      cout << theGrid[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

bool grid::playerMove(int r, int c){
  //check for collision
  if(theGrid[r - 1][c - 1] != '_'){
    return false;
  }
  else{
    theGrid[r-1][c-1] = 'X';
    printGrid();
    return true;
  } 
}
void grid::computerMove(){
  bool placed = false;
  srand(time(0));
  while(!placed){
    int row = rand() % 3;
    int col = rand() % 3;
    //cout << row << ", " << col << endl;
    if(theGrid[row][col] == '_'){
      theGrid[row][col] = 'O';
      placed = true;
    }
  }
  printGrid();
}

bool grid::checkRight(){
  char symbol;
  int count;
  for(int i = 0; i < 3; i++){
    count = 1;
    symbol = theGrid[i][0];   
    for(int j = 1; j < 3; j++){
      if(symbol == theGrid[i][j] && symbol != '_'){
        count++;
        if(count == 3){
          return true;
        }
      }
    }
  }
  return false;
}

bool grid::checkDown(){
  char symbol;
  int count;
  for(int j = 0; j < 3; j++){
    count = 1;
    symbol = theGrid[0][j];   
    for(int i = 1; i < 3; i++){
      if(symbol == theGrid[i][j] && symbol != '_'){
        count++;
        if(count == 3){
          return true;
        }
      }
    }
  }
  return false;
}

bool grid::checkDiag(){
  char symbol = theGrid[0][0];
  int count = 1;
  int i = 1;
  int j = 1;
  while(i < 3){
    if(symbol == theGrid[i][j] && symbol != '_'){
      count++;
    }
    i++;
    j++;
  if(count == 3){
      return true;
    }
  }

  symbol = theGrid[2][0];
  count = 1;
  i = 1;
  j = 1;
  while(j < 3){
    if(symbol == theGrid[i][j] && symbol != '_'){
      count++;
    }
    i--;
    j++;
  if(count == 3){
      return true;
    }
  }

}

bool grid::checkWinner(int numMoves){
  if(numMoves >= 9){
    return true;
  }
  if(checkRight()){
    return true;
  }
  if(checkDown()){
    return true;
  }
  if(checkDiag()){
    return true;
  }

}


