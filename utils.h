#ifndef UTILS_H
#define UTILS_H

#include "shared.h"

void color_print(Color color);

void printImg(Image *img);

void image_print(Image *img, char filename[]);

void print_gif(Gif *gif);

void fillMatrixIn(Image *img, FILE *inputstream);

void genFilenames(Gif *gif, char *filename);

#endif