#ifndef SHARED_H
#define SHARED_H

#define PIC_SIZE 30
#define BUFFER 256
#define GIF_IMGS 10


#define RESET "\033[0m"
#define BG_BLACK "\033[40m"
#define BG_RED "\033[41m"
#define BG_GREEN "\033[42m"
#define BG_YELLOW "\033[43m"
#define BG_BLUE "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN "\033[46m"
#define BG_WHITE "\033[47m"


#define TERMINAL_CLEAR "\033[2J"
#define TERMINAL_HOME "\033[2H"


typedef enum{
    FEKETE,
    PIROS,
    ZOLD,
    SARGA,
    KEK,
    MAGENTA,
    CIAN,
    FEHER
} Color;

typedef struct{
    int** color;
    int oszlop;
    int sor;
} Image;

typedef struct{
    Image images[GIF_IMGS];
    char input_files[GIF_IMGS][BUFFER];
} Gif;


#endif