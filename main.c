#include <stdio.h>

#include "shared.h"
#include "utils.h"

int main(){
    
    Image img;
    Gif gif;
    
    printf("Az input.txt-ben szereplo kep: \n");
    image_print(&img, "input.txt");

    printf("Mi a fileok kozos neve?(filekiterjesztes nelkul (input) )\n");
    print_gif(&gif);

    


    return 0;
}