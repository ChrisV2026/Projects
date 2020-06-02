/*!
   \file ReadWrite.h
   \brief the methods to read and write to a file
   \author Christopher Vishnu
   \date 13th/April/2019
*/

#ifndef A4_GAME_GRID_H
#define A4_GAME_GRID_H

#include <string>
#include <stdio.h>
#include <cstdio>
#include <iostream>
#include "ReadWrite.h"

/*!
   \brief defining a constant for the SIZE of the grid so that only the constant needs to be
   modified to change the size of the grids
*/
#define SIZE 10

using namespace std;

/*!
   \brief Class for the methods for regarding the gamegrid
   \details changing the states of squares in the game grid
*/
class GameGrid{
//already commented some of the functions before I changed them to private and didnt want to remove my hardwork
private:
  bool board[SIZE][SIZE];
  /*!
     \brief A method to determine whether or not some colony needs to change states
     \param row is the row index
     \param col is the column index
     \return returns whether or not the colony needs to change states based on the rules
  */
  bool is_mutate(int row, int col);

  /*!
     \brief A method to determine whether or not a dead colony is going to be populated
     \param row is the row index
     \param col is the column index
     \return returns whether or not the dead colony is going to be populated
  */
  bool is_revive(int row, int col);

  /*!
     \brief A method to determine whether or not alive colony is going to die
     \param row is the row index
     \param col is the column index
     \return returns whether or not the alive colony is going to die
  */
  bool is_dying(int row, int col);

  /*!
     \brief A method to determine whether or not an alive colony is going to die by over population
     \param row is the row index
     \param col is the column index
     \return returns whether or not the colony alive colony is going to die by overpopulation
  */
  bool overpop(int row, int col);

  /*!
     \brief A method to determine whether or not an alive colony is going to die by solitude
     \param row is the row index
     \param col is the column index
     \return returns whether or not the colony alive colony is going to die by solitude
  */
  bool solid(int row, int col);

  /*!
     \brief Method to change the colonies based on the rules to their next state
  */
  void next_gen();


public:
  /*!
     \brief A constructor for the GameGrid which takes in a file to create the board according to the file
     \param file_name the name of the file that has that has the initial game state
  */
  GameGrid(string file_name);

  /*!
     \brief Getter method to return the value at a certain position on the board
     \param ind1 is the row index
     \param ind2 is the column index
     \return returns the bool at the specfic position
  */
  bool get_boardPos(int ind1, int ind2);

  /*!
     \brief Method to call next state a bunch of times based on inputted number of gens
     \param the number of states you would like to go through
  */
  void time_travel(int gens);

  /*!
     \brief Displays the board on the console
  */
  void show_board();

  /*!
     \brief A method to represent the board as a string
     \return returns the string representation fo the board
  */
  string toString();


};

#endif
