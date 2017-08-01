/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if (n < 0) 
    {
        return false;
    }
    int start = 0;
    int end = n - 1;
    int m = (end + start) / 2;
    int c = n;
    do
    {
        //printf("%i\n", m);
      if (values[m] == value)
      {
          //printf("found!\n");
          return true;
      }
      else if (values[m] > value)
      {
          //printf("m is greater than!\n");
          end = m - 1;
          m = (end + start) / 2;
          c = c / 2;
      }
      else if (values[m] < value)
      {
          //printf("m is lower than!\n");
          start = m + 1;
          m = (start + end) / 2;
          c = c / 2;
      }
    }
    while(c > 0);
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n - (i + 1); j++)
        {
            if (values[j] > values[j + 1])
            {
                //printf("%i, %i\n",values[j], values[j + 1]);
                int x = values[j];
                values[j] = values[j + 1];
                values[j + 1] = x;
            }
        }
    }
    //printf("%i, %i, %i, %i, %i\n", values[0], values[1], values[2], values[3], values[4]);
    return;
}
