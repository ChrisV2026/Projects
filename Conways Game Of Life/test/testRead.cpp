#include "../catch/catch.h"
#include "../include/ReadWrite.h"
#include "../include/GameGrid.h"
#include <string>
#include <stdexcept>

#define SIZE 10

using namespace std;

TEST_CASE("test for ReadWrite", "[ReadWrite]"){
  char f1[] = "test/testgrid.txt";
  char f2[] = "test/test2grid.txt";
  ReadWrite pfile(f1);
  ReadWrite imfile(f2);
  bool testgrid[SIZE][SIZE];

  SECTION("Reading an non-existent file"){
    char f3[] = "nogrid.txt";
    ReadWrite nofile(f3);
    REQUIRE_THROWS_AS(nofile.readGrid(testgrid), invalid_argument);
  }

  SECTION("Reading proper file"){
    pfile.readGrid(testgrid);
    for(int i = 0; i < SIZE; i ++){
      for(int j = 0; j < SIZE; j++){
        if(i == 0 && j == 1)
          REQUIRE(testgrid[i][j] == 1);
        else if(i == 6 && j == 4)
          REQUIRE(testgrid[i][j] == 1);
        else if(i == 6 && j== 5)
        REQUIRE(testgrid[i][j] == 1);
        else if(i == 9 && j== 4)
          REQUIRE(testgrid[i][j] == 1);
        else
          REQUIRE(testgrid[i][j] == 0);
      }
    }
  }

  SECTION("Reading a file that is not the proper format"){
    REQUIRE_THROWS_AS(imfile.readGrid(testgrid), invalid_argument);
  }

  SECTION("Writing to a file"){
    char f4[] = "grid.txt";
    ReadWrite file(f4);
    string r1 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    string r2 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    string r3 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    string r4 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    string r5 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    string r6 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    string r7 = "0, 0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    string r8 = "0, 0, 0, 0, 1, 0, 0, 0, 0, 0\n";
    string r9 = "0, 0, 0, 0, 1, 0, 0, 0, 0, 0\n";
    string r10 = "0, 0, 0, 0, 1, 0, 0, 0, 0, 0";

    string grid = r1 + r2 + r3 + r4 + r5 + r6 + r7 + r8 + r9 + r10;
    file.writeGrid(grid);
    file.readGrid(testgrid);
    for(int i = 0; i < SIZE; i ++){
      for(int j = 0; j < SIZE; j++){
        if(i == 7 && j == 4)
          REQUIRE(testgrid[i][j] == 1);
        else if(i == 8 && j== 4)
        REQUIRE(testgrid[i][j] == 1);
        else if(i == 9 && j== 4)
          REQUIRE(testgrid[i][j] == 1);
        else
          REQUIRE(testgrid[i][j] == 0);
      }
    }
  }
}
