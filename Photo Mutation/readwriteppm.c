#include <stdio.h>
#include <stdlib.h>
#include "genealg.h"

PPM_IMAGE *read_ppm(const char *file_name)
{
    PPM_IMAGE *image = malloc(sizeof(PPM_IMAGE));
    FILE *fp = fopen(file_name, "r");
    int count = 0, dim = 0;
    fscanf(fp, "%*[^\n]\n");     ///scaning and not saving the first line the P3 line
    fscanf(fp, "%d %d", &image->width, &image->height);
    fscanf(fp, "%d", &image->max_color);

    dim = image->width * image->height;
    image->data = malloc(sizeof(PIXEL)*dim);
    while (fscanf(fp, "%hhu %hhu %hhu", &image->data[count].r, &image->data[count].g, &image->data[count].b) != EOF)
      count++;
    fclose(fp);
    return image;
}

void write_ppm(const char *file_name, const PPM_IMAGE *image)
{
    FILE *fp = fopen(file_name, "w");
    int i;
    fprintf(fp, "P3\n%d %d\n%d\n", image->width, image->height, image->max_color);
    for (i = 0; i < image->height*image->width; i++)
      fprintf(fp, "%hhu %hhu %hhu ", image->data[i].r, image->data[i].g, image->data[i].b);
    fclose(fp);
}


// int main()
// {
//   PPM_IMAGE *p = read_ppm("mcmaster.ppm");
//   char n[9] = "file.ppm";
//   write_ppm(n, p);
//
//   free(p);
//   return 0;
// }
