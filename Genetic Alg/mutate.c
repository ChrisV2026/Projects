#include <stdio.h>
#include "genealg.h"
#include <stdlib.h>
#include <time.h>

void mutate(Individual *individual, double rate)
{
  int num, i, chosen = 0, dim;;
  dim = individual[0].image.width * individual[0].image.height;
  num = (int)(rate/100 * dim);
  for (i = 0; i < num; i++)
  {
    chosen = rand() % (dim);
    individual->image.data[chosen].r = rand() % (individual->image.max_color+1);
    individual->image.data[chosen].g = rand() % (individual->image.max_color+1);
    individual->image.data[chosen].b = rand() % (individual->image.max_color+1);
  }
}

void mutate_population(Individual *individual, int population_size, double rate)
{
  Individual *i;
  for (i = (individual+population_size/4); i < (individual + population_size); i++)
    mutate(i, rate);
}
