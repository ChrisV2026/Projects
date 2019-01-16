#include <stdio.h>
#include <math.h>
#include "genealg.h"

double comp_distance(const PIXEL *A, const PIXEL *B, int image_size)
{
    double fab = 0, d = 0;
    int i, r1, r2, r3;
    for (i = 0; i < image_size; i++ )
    {
      r1 = (A[i].r - B[i].r);
      r2 = (A[i].g - B[i].g);
      r3 = (A[i].b - B[i].b);
      d+= r1 * r1 + r2 * r2 + r3 * r3;
      //d += (A[i].r - B[i].r) * (A[i].r - B[i].r) + (A[i].g - B[i].g) * (A[i].g - B[i].g) + (A[i].b - B[i].b) * (A[i].b - B[i].b);
    }
    fab = sqrt(d);
    return fab;
}

void comp_fitness_population(const PIXEL *image, Individual *individual, int population_size)
{
    int dim = individual[0].image.width * individual[0].image.height, i;
    for (i = 0; i < population_size; i++)
    {
      individual[i].fitness = comp_distance(image, individual[i].image.data, dim);
    }
}
