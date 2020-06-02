#include <stdio.h>
#include <cstdio>
#include <string>
#include <iostream>
#include <stdexcept>
#include "../include/ReadWrite.h"

#define SIZE 10

using namespace std;

ReadWrite::ReadWrite(char * file_name){
  this->file_name = file_name;
}


void ReadWrite::writeGrid(string str){
  FILE * fp = fopen(this->file_name, "w");
  fprintf(fp, "%s", str.c_str());
  fclose(fp);
}

void ReadWrite::readGrid(bool grid[][SIZE]){
  FILE * fp = fopen(this->file_name, "r");
  if (fp == NULL)
    throw invalid_argument("File Not Found");
  unsigned int temp;
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      fscanf(fp, "%u,  ", &temp);
      if (temp > 1)
        throw invalid_argument("Colony must either be 1 or 0");
      grid[i][j] = temp;
    }
  }
  fclose(fp);
}
