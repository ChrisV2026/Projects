#include <stdio.h>
#include <stdbool.h>

int linsolve(int n, double A[], double b[], double x[])
{
    int pos, i, j, k, count;
    double multifactor, divfactor;
    bool zerorow = true, zerocol = true, found = false;

    pos = 0;

    //checks for rows and coloumns of zeros
    for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
      {
        if (A[i*n + j] != 0)
          zerorow = false;
        if (A[j*n + i] != 0)
          zerocol = false;
        if ((!zerorow) && (!zerocol))
          break;
      }

      if (zerorow || zerocol)
        return 0;

      else if (i != (n - 1))
      {
        zerorow = true;
        zerocol = true;
      }
    }

    //goes down the list row by row to perform the row reduction steps to every row
    for (i = 0; i < n; i++)
    {
      //searches for the first non-zero entry in the row
      while(!found)
      {
        if (A[i*n + pos] == 0)
          pos++;
        else
          break;
      }

      //this is the factor to get the proper entry to 1
      divfactor = A[i*n + pos];
      //divides the b value by this number as well
      b[i] /= divfactor;

      //divides the rest of the row by this number
      for (j = 0; j < n; j++)
      {
        A[i*n + j] /= divfactor;
      }

      //subtracts the rest of the rows by a factor of the ith row
      for (k = 0; k < n; k++)
      {
        if (k == i)
          continue;

        //this is the factor to get the coloumns above and below the ones to go to 0
        multifactor = A[k*n + pos];
        b[k] -= b[i] * multifactor;

        //subtracts all entries by the above entry*the factor
        for (j = 0; j < n; j++)
        {
          A[k*n + j] -= multifactor * A[i*n + j];

          //increments a counter to check if the row is all 0s
          if (A[k*n + j] == 0)
            count++;
        }

        //checks if the number of 0s is the same as the number of entries
        if (count == n)
          return 0;

        //reinitalizes the counter
        else
          count = 0;
      }

      pos = 0;
    }

    for (j = 0; j<n; j++)
      x[j] = b[j];

    return 1;
}
