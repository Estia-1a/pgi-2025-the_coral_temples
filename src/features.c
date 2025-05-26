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
    int width;
    int height;
    int channels;
    if (read_image_data(source_path, &data, &width, &height, &channels)==0){
        printf("Erreur lors de l'execution de la fonction: read_image_data()\n");
    }
    else{
        printf("dimension : %d, %d\n", width, height);
    }
}