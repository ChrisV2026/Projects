#include <stdio.h>
#include "linkedlist.h"

int main()
{
  int n = 10, m = 10;

  HBnodePtr L = createHBlist(n,m);

  printf("HB list\n");
  printHBlist(L);
  printf("\n");

  printf("SL list\n");
  SLnodePtr P = flattenList(L);
  printSLlist(P);
  printf("\n");

  freeSLlist(P);
  freeHBlist(L);
  return 0;
}
