#include <string>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include "../include/GameGrid.h"
#include "../include/ReadWrite.h"

using namespace std;
#define SIZE 10


GameGrid::GameGrid(string file_name){
  int n = file_name.length();
  char f[n+1];
  strcpy(f, file_name.c_str());
  ReadWrite file(f);
  file.readGrid(this->board);
}

bool GameGrid::get_boardPos(int ind1, int ind2){
  if(ind1 >= SIZE || ind1 < 0)
    throw out_of_range("Not an index on the board");
  if(ind2 >= SIZE || ind2 < 0)
    throw out_of_range("Not an index on the board");
  return this->board[ind1][ind2];
}

bool GameGrid::is_mutate(int row, int col){
  if(this->board[row][col] == 0)
    return is_revive(row, col);
  else
    return is_dying(row, col);
}

bool GameGrid::is_revive(int row, int col){
  int adj[8][2] = {{row - 1, col}, {row + 1, col}, {row + 1, col - 1}, {row + 1, col + 1},
                    {row - 1, col - 1}, {row - 1, col + 1}, {row, col - 1}, {row, col + 1}};
  unsigned int count = 0;
  for(int i = 0; i < 8; i ++){
    int rowadj = adj[i][0];
    int coladj = adj[i][1];
    if(rowadj < 0 || rowadj >= SIZE)
      continue;
    else if(coladj < 0 || coladj >= SIZE)
      continue;
    else if(this->board[rowadj][coladj])
      count++;
  }
  if(count == 3)
    return true;
  return false;
}

bool GameGrid::is_dying(int row, int col){
  return solid(row, col) || overpop(row, col);
}

bool GameGrid::overpop(int row, int col){
  int adj[8][2] = {{row - 1, col}, {row + 1, col}, {row + 1, col - 1}, {row + 1, col + 1},
                    {row - 1, col - 1}, {row - 1, col + 1}, {row, col - 1}, {row, col + 1}};
  unsigned int count = 0;
  for(int i = 0; i < 8; i ++){
    int rowadj = adj[i][0];
    int coladj = adj[i][1];
    if(rowadj < 0 || rowadj >= SIZE)
      continue;
    else if(coladj < 0 || coladj >= SIZE)
      continue;
    else if(this->board[rowadj][coladj])
      count++;
  }
  if(count >= 4)
    return true;
  return false;
}

bool GameGrid::solid(int row, int col){
  int adj[8][2] = {{row - 1, col}, {row + 1, col}, {row + 1, col - 1}, {row + 1, col + 1},
                    {row - 1, col - 1}, {row - 1, col + 1}, {row, col - 1}, {row, col + 1}};
  unsigned int count = 0;
  for(int i = 0; i < 8; i ++){
    int rowadj = adj[i][0];
    int coladj = adj[i][1];
    if(rowadj < 0 || rowadj >= SIZE)
      continue;
    else if(coladj < 0 || coladj >= SIZE)
      continue;
    else if(this->board[rowadj][coladj])
      count++;
  }
  if(count <= 1)
    return true;
  return false;
}

void GameGrid::next_gen(){
  bool grid[SIZE][SIZE];
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      grid[i][j] = this->board[i][j];
    }
  }

  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      if(is_mutate(i,j))
          grid[i][j] = !grid[i][j];
    }
  }

  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      this->board[i][j] = grid[i][j];
    }
  }
}

void GameGrid::time_travel(int gens){
  if(gens <= 0)
    throw invalid_argument("Must be a number greater than 0");
  for(int i = 0; i < gens; i++)
    next_gen();
  //show_board();
}

void GameGrid::show_board(){
  string rep = "\n  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  \n";
  string dead =  "x_x";
  string alive = "o_o";
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      //rep += " | " + to_string(this->board[i][j]);
      if(this->board[i][j])
        rep += " | " + alive;
      else
        rep += " | " + dead;
    }
    rep+= " | \n";
    //rep += "  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  \n";
  }
  rep += "  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  \n";
  printf("%s", rep.c_str());
}

string GameGrid::toString(){
  string rep = "";
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      rep += to_string(this->board[i][j]);
      if(j < SIZE - 1)
        rep += ", ";
    }
    rep+= "\n";
  }
  return rep;
}
