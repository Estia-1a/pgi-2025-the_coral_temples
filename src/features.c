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

void stat_report(char *source_path) {
    unsigned char *data;
    int width, height, channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    FILE *fichier = fopen("C:\\Users\\louis.foucher--jube\\OneDrive - ESTIA\\Bureau\\Nouveau dossier\\Projet genie informatique\\pgi-2025-the_coral_temples\\stat_report.txt", "w");
    if (!fichier) {
        perror("Erreur création fichier");
        return;
    }
    printf("Fichier ouvert avec succes !\n");


    fprintf(fichier, "max_pixel\n");
    fprintf(fichier, "min_pixel\n");
    fprintf(fichier, "max_component_R\n");
    fprintf(fichier, "max_component_G\n");
    fprintf(fichier, "max_component_B\n");
    fprintf(fichier, "min_component_R\n");
    fprintf(fichier, "min_component_G\n");
    fprintf(fichier, "min_component_B\n");

    fprintf(fichier, "max_pixel\n", max_pixel(*source_path));
    //fprintf(fichier, "min_pixel\n", min_pixel);
    //fprintf(fichier, "max_component_R\n", max_component R);
    //(fichier, "max_component_G\n", max_component G);
    //fprintf(fichier, "max_component_B\n", max_component B);
    //fprintf(fichier, "min_component_R\n", max_component R);
    //printf(fichier, "min_component_G\n", max_component G);
    //fprintf(fichier, "min_component_B\n", max_component B);

    fclose(fichier);
}



