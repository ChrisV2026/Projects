#include <stdio.h>
#include "genealg.h"
#include <stdlib.h>
#include <time.h>

static int cmpd(const void * a, const void * b)
{
  Individual *ai = (Individual *)a;
  Individual *bi = (Individual *)b;
  if (ai->fitness > bi->fitness)
    return 1;
  else if(ai ->fitness < bi->fitness)
    return (- 1);
  else
    return 0;
}

PPM_IMAGE *evolve_image(const PPM_IMAGE *image, int num_generations, int population_size, double rate)
{
  int i;
  srand(time(NULL));
  PPM_IMAGE *new = malloc(sizeof(PPM_IMAGE));
  Individual *ind = generate_population(population_size, image->width, image->height, image->max_color);
  comp_fitness_population(image->data, ind, population_size);
  qsort(ind, population_size, sizeof(Individual), cmpd);
  for (i = 1; i <= num_generations; i++)
  {
    crossover(ind, population_size);
    mutate_population(ind, population_size, rate);
    comp_fitness_population(image->data, ind, population_size);
    qsort(ind, population_size, sizeof(Individual), cmpd);
    //printf("Gen %d ..... %.10e\n", i, ind[0].fitness);
  }

  new->width = ind[0].image.width;
  new->height = ind[0].image.height;
  new->max_color = ind[0].image.max_color;
  new->data = malloc(sizeof(PIXEL)*new->width * new->height);

  for (i = 0; i < new->width * new->height; i++)
    new->data[i] = ind[0].image.data[i];

  for (i = 0; i < population_size; i++)
  {
    free(ind[i].image.data);
  }
  free(ind);
  return new;
}

void free_image(PPM_IMAGE *p)
{
  free(p->data);
  free(p);
}
