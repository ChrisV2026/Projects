#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "genealg.h"

PIXEL *generate_random_image(int width, int height, int max_color)
{
  PIXEL *image = malloc(sizeof(PIXEL)*width*height);
  int i;
  for (i = 0; i < height*width; i++)
  {
    image[i].r = rand() % (max_color + 1);
    image[i].g = rand() % (max_color + 1);
    image[i].b = rand() % (max_color + 1);
  }
  return image;
}

Individual *generate_population(int population_size, int width, int height, int max_color)
{
  Individual *ind = malloc(sizeof(Individual)*population_size);
  int i;
  for (i = 0; i < population_size; i++)
  {
    ind[i].image.width = width;
    ind[i].image.height = height;
    ind[i].image.max_color = max_color;
    ind[i].image.data = generate_random_image(width, height, max_color);
  }
  return ind;
}
