/*!
   \file ReadWrite.h
   \brief the methods to read and write to a file
   \author Christopher Vishnu
   \date 13th/April/2019
*/
#ifndef A4_READ_WRITE_H
#define A4_READ_WRITE_H

#include <string>
#include <stdio.h>
#include <cstdio>
#include <iostream>

using namespace std;

/*!
   \brief defining a constant for the SIZE of the grid so that only the constant needs to be
   modified to change the size of the grids
*/
#define SIZE 10

/*!
   \brief Class for the methods of reading and writing to a file for the game grids
   \details Writes the current state of the board taken in as a string to a text file and reads a start state of the board
*/
class ReadWrite{
  private:
    char* file_name;

  public:
    /*!
       \brief Constructor to the Class creating an object specific to the file you are reading from and writing to.
       \param file_name is the name of the file taken in as an array of characters
       \post sets state variable to the name of the file
    */
    ReadWrite(char* file_name);

    /*!
       \brief method to write a string representing the state of the grid to a file
       \param str is the string representation of the game grid
    */
    void writeGrid(string str);

    /*!
       \brief method to read the grid from the inputed file and modify an array that is passed in
       \param grid[][] a 2D array of size SIZE which is a constant defined in the module
    */
    void readGrid(bool grid[][SIZE]);

};

#endif
