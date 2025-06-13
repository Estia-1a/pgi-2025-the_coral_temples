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