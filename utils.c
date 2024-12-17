   #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "dynamic.h"
#include "shared.h"
#include "fileio.h"

void color_print(Color color){
    switch (color){
        case FEKETE:
            printf("%s ", BG_BLACK);
            break;
        case PIROS:
            printf("%s ", BG_RED);
            break;
        case ZOLD:
            printf("%s ", BG_GREEN);
            break;
        case SARGA:
            printf("%s ", BG_YELLOW);
            break;
        case KEK:
            printf("%s ", BG_BLUE);
            break;
        case MAGENTA:
            printf("%s ", BG_MAGENTA);
            break;
        case CIAN:
            printf("%s ", BG_CYAN);
            break;
        case FEHER:
            printf("%s ", BG_WHITE);
            break;
    }
    printf("%s", RESET);
}


void fillMatrixIn(Image *img, FILE *inputstream){

    for(int j = 0; j < img->sor; j++){
            for(int k = 0; k < img->oszlop; k++){
                fscanf(inputstream, "%d", &img->color[j][k]);
            }
        }
}

void printImg(Image *img){
    for(int i=0; i < img->sor; i++){
        for(int j=0; j< img->oszlop; j++){
            color_print(img->color[i][j]);
        }
        printf("\n");
    }
}


void image_print(Image *img, char filename[]){
    printf("%s%s",TERMINAL_CLEAR, TERMINAL_HOME);
    read_file(img, filename);
    sleep(5);
    printf("%s%s",TERMINAL_CLEAR, TERMINAL_HOME);
    printf("Beolvasott kep:\n");
    printImg(img);
    sleep(3);
    printf("%s%s",TERMINAL_CLEAR, TERMINAL_HOME);
    freeTheMatrixIn(img);
    printf("Kepnek lefoglalt matrix helye sikeresen felszabaditva.\n");
    sleep(2);

}


void genFileNames(Gif *gif, char *filename){
    char fextention[] = ".bg\0";
    size_t l = strlen(filename);

    for(int i=0; i < GIF_IMGS; i++){
        strncat(filename,fextention,3);
        char num = i + '0';
        strncat(filename,&num,1);
        strcpy(&gif->input_files[i][0], filename );
        filename[l] = '\0';            //Reseteli a filenevet, hogy a következő ciklusban hozzáadható legyen az extension
    }
    
}



void print_gif(Gif *gif){
    char filename[BUFFER];


    if(fgets(filename,BUFFER,stdin) == NULL){
        printf("Sikertelen filenevbeolvasas\n");
        return;
    }

    
    int filenamelength = 0;
    while(filename[filenamelength] != '\n') filenamelength++;
    filename[filenamelength] = '\0';


    genFileNames(gif, filename);
    
    for(int i=0; i < GIF_IMGS; i++){
        /*
        FILE* inputstream = fopen(&gif->input_files[i][0], "r");
        if(inputstream == NULL){printf("Sikertelen file stream letrehozas: %s",filename); return;}
        */
        read_file(&gif->images[i], gif->input_files[i]);
        printf("File %s beolvasva.\n", gif->input_files[i]);
    }
    printf("%s%s",TERMINAL_CLEAR, TERMINAL_HOME);
    printf("Minden file sikeresen beolvasva\n");
    printf("Gif lejatszasa:\n");
    sleep(4);

    for(int i=0; i < GIF_IMGS; i++){
        printf("%s%s",TERMINAL_CLEAR, TERMINAL_HOME);
        printImg(&gif->images[i]);
        printf("%s%s",TERMINAL_CLEAR, TERMINAL_HOME);
        
        sleep(1);

    }
    printf("%s%s",TERMINAL_CLEAR, TERMINAL_HOME);
    for(int i=0; i < GIF_IMGS; i++){
        freeTheMatrixIn(&gif->images[i]);
    }
    printf("Matrixoknak lefoglalt hely sikeresen felszabaditva.\n");
    sleep(1);
    printf("%s%s",TERMINAL_CLEAR, TERMINAL_HOME);
    printf("Viszlat!\n");
    sleep(1);


}




