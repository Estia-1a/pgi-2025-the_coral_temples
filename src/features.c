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

void tenth_pixel(char *source_path){
    unsigned char *data = NULL;
    int width, height, channel_count;
    
    read_image_data(source_path, &data, &width, &height, &channel_count);
 
    int r, g, b;
    r = data[27];
    g = data[28];
    b = data[29];
 
    printf("tenth_pixel: %d, %d, %d\n",r, g, b);
 
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
void max_component(char *source_path, char component) {
    unsigned char *data=NULL;
    int width, height, channel_count;
    read_image_data(source_path, &data, &width, &height, &channel_count);

    /*intialisation de la valeur max et de x y max*/
    int max_value = -1;
    int max_x = 0, max_y = 0;

    /*Ce bloc permet de choisir quelle composante comparer.*/
    int component_index;
    if (component == 'R') component_index = 0;
    else if (component == 'G') component_index = 1;
    else if (component == 'B') component_index = 2;
    else {
        printf("Composante invalide. Utilisez R, G ou B.\n");
        return;
    }

    // component_index = 0;
    /*parcour de l'image en y et x */
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * channel_count;
            int value = data[index + component_index];
         
            /*comparaison de la valeur max pour trouver la plus grande et on garde le x et y*/
            if (value > max_value) {
                max_value = value;
                max_x = x;
                max_y = y;
            }
        }
    }
        
printf("max_component %c (%d, %d): %d\n", component, max_x, max_y, max_value);
    free_image_data(data);
}
