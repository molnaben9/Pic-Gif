#include <stdio.h>
#include <unistd.h>

#include "shared.h"
#include "utils.h"
#include "dynamic.h"


void read_file(Image *img, char filename[]){

    FILE *file_ptr;

    file_ptr = fopen(filename, "r");

    if(file_ptr == NULL) {printf("Sikertelen file-beolvasas. file: %s",filename); return;}

    fscanf(file_ptr,"%d",&img->oszlop);
    if(img->oszlop > PIC_SIZE){
        printf("Hibas kep meret, a kep szelessege maximum %d lehet",PIC_SIZE);
        fclose(file_ptr);
        return;
    }

    
    fscanf(file_ptr,"%d",&img->sor);

    if(img->sor > PIC_SIZE){
        printf("Hibas kep meret, a kep magassaga maximum %d lehet",PIC_SIZE);
        fclose(file_ptr);
        return;
    }

    initMatrixIn(img);
    printf("Memoria a matrixnak sikeresen lefoglalva.\n");

    fillMatrixIn(img, file_ptr);
    printf("%s tartalma sikeresen beolvasva.\n",filename);
    sleep(1);

    fclose(file_ptr);

}

