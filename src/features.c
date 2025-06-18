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

void min_component(char *source_path, char component) {
    unsigned char *data=NULL;
    int width, height, channel_count;
    read_image_data(source_path, &data, &width, &height, &channel_count);

    /*intialisation de la valeur min et de x y min*/
    int min_value = 256;
    int min_x = 0, min_y = 0;

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
         
            /*comparaison de la valeur min pour trouver la plus grande et on garde le x et y*/
            if (value < min_value) {
                min_value = value;
                min_x = x;
                min_y = y;
            }
        }
    }
        
    printf("min_component %c (%d, %d): %d\n", component, min_x, min_y, min_value);
    free_image_data(data);
}

void min_pixel(char *source_path){
    unsigned char *data = NULL;
    int width, height, channel_count;
    read_image_data(source_path, &data, &width, &height, &channel_count);

    int min_sum = 256*3;
    int min_r = 0, min_g = 0, min_b = 0;
    int min_x = 0, min_y = 0;
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            int index = (y * width + x) * channel_count;
            int r = data[index];
            int g = data[index + 1];
            int b = data[index + 2];
            int sum = r + g + b;
            if (sum < min_sum){
                min_sum = sum;
                min_r = r;
                min_g = g;
                min_b = b;
                min_x = x;
                min_y = y;
            }
        }
    }
    printf("min_pixel (%d, %d): %d, %d, %d\n", min_x, min_y, min_r, min_g, min_b);
    free_image_data(data);
}

void max_pixel(char *source_path){
    unsigned char *data = NULL;
    int width, height, channel_count;
    read_image_data(source_path, &data, &width, &height, &channel_count);

    int max_sum = -1;
    int max_r = 0, max_g = 0, max_b = 0;
    int max_x = 0, max_y = 0;
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            int index = (y * width + x) * channel_count;
            int r = data[index];
            int g = data[index + 1];
            int b = data[index + 2];
            int sum = r + g + b;
            if (sum > max_sum){
                max_sum = sum;
                max_r = r;
                max_g = g;
                max_b = b;
                max_x = x;
                max_y = y;
            }
        }
    }
    printf("max_pixel (%d, %d): %d, %d, %d\n", max_x, max_y, max_r, max_g, max_b);
    free_image_data(data);
}

void color_red(char *source_path){
    unsigned char *data = NULL;
    int width, height, channel_count;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for (int i = 0; i < width * height; i++){
        int index = i * channel_count;
        data[index+1] = 0;
        data[index+2] = 0;
    }
    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}

void color_green(char *source_path){
    unsigned char *data = NULL;
    int width, height, channel_count;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for (int i = 0; i < width * height; i++){
        int index = i * channel_count;
        data[index] = 0;
        data[index+2] = 0;
    }
    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}

void color_blue(char *source_path){
    unsigned char *data = NULL;
    int width, height, channel_count;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for (int i = 0; i < width * height; i++){
        int index = i * channel_count;
        data[index] = 0;
        data[index+1] = 0;
    }
    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}

void rotate_cw(char *source_path){
    unsigned char *data = NULL;
    int width, height, channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);
    
    int new_width = height;
    int new_height = width;

    unsigned char *data_rotate = malloc(width * height * channel_count);

    for (int y = 0; y<height; y++){
        for (int x = 0; x<width; x++){
            int index = (y*width + x) * channel_count;
            int new_x = height - 1 - y;
            int new_y = x;
            int new_index = (new_y * new_width + new_x)*channel_count;
            for (int i = 0; i < channel_count; i++){
                data_rotate[new_index + i] = data[index + i];
            }
        }
    }
    write_image_data("image_out.bmp", data_rotate, new_width, new_height);
    free_image_data(data);
    // free(data_rotate);
}

void color_gray(char *source_path){
    unsigned char *data = NULL;
    int width, height, channel_count;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for (int i = 0; i < width * height; i++){
        int index = i * channel_count;
        float gray = (data[index] + data[index+1] + data[index+2])/3;
        data[index] = gray;
        data[index+1] = gray;
        data[index+2] = gray;
    }
    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}

void color_gray_luminance(char *source_path){
    unsigned char *data = NULL;
    int width, height, channel_count;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for (int i = 0; i < width * height; i++){
        int index = i * channel_count;
        float gray = (0.21*data[index]) + (0.72*data[index+1]) + (0.07*data[index+2]);
        data[index] = gray;
        data[index+1] = gray;
        data[index+2] = gray;
    }
    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
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

    // fprintf(fichier, "max_pixel\n", max_pixel(*source_path));
    //fprintf(fichier, "min_pixel\n", min_pixel);
    //fprintf(fichier, "max_component_R\n", max_component R);
    //(fichier, "max_component_G\n", max_component G);
    //fprintf(fichier, "max_component_B\n", max_component B);
    //fprintf(fichier, "min_component_R\n", max_component R);
    //printf(fichier, "min_component_G\n", max_component G);
    //fprintf(fichier, "min_component_B\n", max_component B);

    fclose(fichier);
}