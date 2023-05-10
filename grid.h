#ifndef GRID_H
#define GRID_H
#include<vector>
#include<string>
#include<iostream>

using namespace std;

class grid {
  public:
  vector<vector<char>> theGrid;
  grid();
  ~grid();

  void printGrid();
  bool playerMove(int r, int c);
  void computerMove();
  bool checkWinner(int numMoves);
  bool checkRight();
  bool checkDown();
  bool checkDiag();


};

#endif