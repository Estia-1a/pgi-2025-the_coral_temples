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

    /*FILE *file = fopen(source_path, "rb");

    if (file == NULL) {
        printf("Le fichier n'existe pas ou est inaccessible : %s\n", source_path);
        return;
    }
    fclose(file);
    printf("Le fichier existe : %s\n", source_path);*/

    unsigned char *data = NULL;
    int width, height, channels, res;
    
    res = read_image_data(source_path, &data, &width, &height, &channels);

    if (data==NULL){
        printf("Erreur lors de l'execution de la fonction: read_image_data(), SORTIE : %d\n", res);
        /*printf("data : %hhn\n", data);*/
        return;
    }
    printf("dimension : %d, %d\n", width, height);
}