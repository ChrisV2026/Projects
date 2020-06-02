#include <string>
#include <stdio.h>
#include <cstdio>
#include <iostream>
#include "../include/GameGrid.h"
#include "../include/ReadWrite.h"


int main(){
  char n[] = "src/grid2.txt";
  ReadWrite file(n);
  GameGrid g("src/grid.txt");
  g.time_travel(1);
  g.show_board();
  g.time_travel(1);
  g.show_board();
  file.writeGrid(g.toString());
  GameGrid g2("src/grid2.txt");
  g2.time_travel(1);
  g2.show_board();
  return 0;
}
