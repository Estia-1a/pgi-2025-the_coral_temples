#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !");
}

void dimension (char *source_path){
    unsigned char *data = NULL;
    int width, height, channels, res;
    
    res = read_image_data(source_path, &data, &width, &height, &channels);

    if (res == 0){
        printf("Erreur lors de l'execution de la fonction: read_image_data(), SORTIE : %d\n", res);
        /*printf("data : %hhn\n", data);*/
    }
    printf("dimension : %d, %d\n", width, height);
}
void first_pixel(char *source_path) {
    unsigned char *data;
    int width, height, channel_count;
    read_image_data(source_path, &data, &width, &height, &channel_count);

    int r, g, b;
    r = data[0];
    g = data[1];
    b = data[2];

    printf("first_pixel: %d, %d, %d\n",r, g, b);

}
void min_pixel(char *source_path){
    unsigned char *data = NULL;
    int width, height, channel_count;
    read_image_data(source_path, &data, &width, &height, &channel_count);

    int min_sum = 256*3;
    int min_r = 0, min_g = 0, min_b = 0;
    int min_x = 0, min_y = 0;
    
}