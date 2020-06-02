#include "../catch/catch.h"
#include "../include/ReadWrite.h"
#include "../include/GameGrid.h"
#include <string>
#include <stdexcept>

#define SIZE 10

using namespace std;

TEST_CASE("test for GameGrid", "[GameGrid]"){
  char n[] = "gridtest.txt";
  ReadWrite f(n);
  GameGrid g("test/testgrid.txt");
  GameGrid g2("test/test3grid.txt");

  SECTION("Game follows proper rules (solitude)"){
    string r1 = "0, 1, 0, 0, 0, 0, 0, 0, 0, 0\n";
    string r2 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    string r3 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    string r4 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    string r5 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    string r6 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    string r7 = "0, 0, 0, 0, 1, 1, 0, 0, 0, 0\n";
    string r8 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    string r9 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    string r10 = "0, 0, 0, 0, 1, 0, 0, 0, 0, 0\n";

    string grid = r1 + r2 + r3 + r4 + r5 + r6 + r7 + r8 + r9 + r10;
    REQUIRE(g.toString() == grid);

    g.time_travel(1);
    r1 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    r2 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    r3 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    r4 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    r5 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    r6 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    r7 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    r8 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    r9 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    r10 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";

    grid = r1 + r2 + r3 + r4 + r5 + r6 + r7 + r8 + r9 + r10;
    REQUIRE(g.toString() == grid);
  }

  SECTION("Game follows proper rules (populate and overpopulation)"){
    g2.time_travel(1);
    string r1 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    string r2 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    string r3 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    string r4 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    string r5 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    string r6 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    string r7 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    string r8 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    string r9 = "0, 0, 0, 1, 1, 1, 0, 0, 0, 0\n";
    string r10 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";

    string grid = r1 + r2 + r3 + r4 + r5 + r6 + r7 + r8 + r9 + r10;
    REQUIRE(g2.toString() == grid);
  }

  SECTION("Gamegrid toString"){
    string r1 = "0, 1, 0, 0, 0, 0, 0, 0, 0, 0\n";
    string r2 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    string r3 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    string r4 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    string r5 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    string r6 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    string r7 = "0, 0, 0, 0, 1, 1, 0, 0, 0, 0\n";
    string r8 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    string r9 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    string r10 = "0, 0, 0, 0, 1, 0, 0, 0, 0, 0\n";

    string grid = r1 + r2 + r3 + r4 + r5 + r6 + r7 + r8 + r9 + r10;
    REQUIRE(g.toString() == grid);
  }

  SECTION("Gamegrid get board position test"){
    for(int i = 0; i < SIZE; i ++){
      for(int j = 0; j < SIZE; j++){
        if(i == 7 && j == 4)
          REQUIRE(g2.get_boardPos(i, j) == 1);
        else if(i == 8 && j== 4)
        REQUIRE(g2.get_boardPos(i, j) == 1);
        else if(i == 9 && j== 4)
          REQUIRE(g2.get_boardPos(i,j) == 1);
        else
          REQUIRE(g2.get_boardPos(i, j) == 0);
      }
    }
  }

  SECTION("Gamegrid get board position test"){
    REQUIRE_THROWS_AS(g.get_boardPos(10,0), out_of_range);
    REQUIRE_THROWS_AS(g.get_boardPos(0,11), out_of_range);
    REQUIRE_THROWS_AS(g.get_boardPos(12,13), out_of_range);
  }
}
