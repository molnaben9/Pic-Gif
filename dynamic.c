#include <stdio.h>
#include <stdlib.h>

#include "shared.h"

void initMatrixIn(Image *img){
    img->color = (int**)malloc(img->sor * sizeof(int*));
    if(img->color == NULL){printf("Sikertelen memoriafoglalas a matrixnak"); return;}
    for(int i=0; i< img->sor;i++){
        img->color[i] = (int*)malloc(img->oszlop * sizeof(int));
        if(img->color[i] == NULL){
            printf("Sikertelen memoriafoglalas a matrix sorainak");
            for(int j= 0; j < i; j++){
                free(img->color[j]);
            }
            free(img->color);
            return;
        }
    }
    
}

void freeTheMatrixIn(Image *img){
    for(int i=0; i< img->sor; i++){
        free(img->color[i]);
    }
    free(img->color);
    
}