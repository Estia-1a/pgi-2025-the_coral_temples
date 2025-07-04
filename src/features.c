#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>

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
    
    if (!read_image_data(source_path, &data, &width, &height, &channel_count)){
        printf("Erreur lors de la lecture de l'image.\n");
        return;
    }
 
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
    if (!read_image_data(source_path, &data, &width, &height, &channel_count)){
        printf("Erreur lors de la lecture de l'image.\n");
        return;
    }

    int r, g, b;
    r = data[0];
    g = data[1];
    b = data[2];

    printf("first_pixel: %d, %d, %d\n",r, g, b);

}
void max_component(char *source_path, char component) {
    unsigned char *data=NULL;
    int width, height, channel_count;
    if (!read_image_data(source_path, &data, &width, &height, &channel_count)){
        printf("Erreur lors de la lecture de l'image.\n");
        return;
    }

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
    if (!read_image_data(source_path, &data, &width, &height, &channel_count)){
        printf("Erreur lors de la lecture de l'image.\n");
        return;
    }

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
    if (!read_image_data(source_path, &data, &width, &height, &channel_count)){
        printf("Erreur lors de la lecture de l'image.\n");
        return;
    }

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
    if (!read_image_data(source_path, &data, &width, &height, &channel_count)){
        printf("Erreur lors de la lecture de l'image.\n");
        return;
    }

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
    if (!read_image_data(source_path, &data, &width, &height, &channel_count)){
        printf("Erreur lors de la lecture de l'image.\n");
        return;
    }
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
    if (!read_image_data(source_path, &data, &width, &height, &channel_count)){
        printf("Erreur lors de la lecture de l'image.\n");
        return;
    }
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
    if (!read_image_data(source_path, &data, &width, &height, &channel_count)){
        printf("Erreur lors de la lecture de l'image.\n");
        return;
    }
    for (int i = 0; i < width * height; i++){
        int index = i * channel_count;
        data[index] = 0;
        data[index+1] = 0;
    }
    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}

void color_gray(char *source_path){
    unsigned char *data = NULL;
    int width, height, channel_count;
    if (!read_image_data(source_path, &data, &width, &height, &channel_count)){
        printf("Erreur lors de la lecture de l'image.\n");
        return;
    }
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
    if (!read_image_data(source_path, &data, &width, &height, &channel_count)){
        printf("Erreur lors de la lecture de l'image.\n");
        return;
    }
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

void rotate_cw(char *source_path){
    unsigned char *data = NULL;
    int width, height, channel_count;

    if (!read_image_data(source_path, &data, &width, &height, &channel_count)){
        printf("Erreur lors de la lecture de l'image.\n");
        return;
    }
    
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

void rotate_acw(char *source_path){
    unsigned char *data = NULL;
    int width, height, channel_count;
 
    if (!read_image_data(source_path, &data, &width, &height, &channel_count)){
        printf("Erreur lors de la lecture de l'image.\n");
        return;
    }
   
    int new_width = height;
    int new_height = width;
 
    unsigned char *data_rotate = malloc(width * height * channel_count);
 
    for (int y = 0; y<height; y++){
        for (int x = 0; x<width; x++){
            int index = (y*width + x) * channel_count;
            int new_x = y;
            int new_y = width - 1 - x;
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

void color_invert(char *source_path){
    unsigned char *data = NULL;
    int width, height, channel_count;
 
    if (!read_image_data(source_path, &data, &width, &height, &channel_count)){
        printf("Erreur lors de la lecture de l'image.\n");
        return;
    }
 
    for(int i = 0; i< width * height; i++){
        int index = i * channel_count;
 
        data[index] = 255 - data[index];
        data[index + 1 ] = 255 - data[index + 1];
        data[index + 2 ] = 255 - data[index + 2];
    }
 
    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}

void mirror_horizontal(char *source_path){
    unsigned char *data = NULL;
    int width, height, channel_count;

    if (!read_image_data(source_path, &data, &width, &height, &channel_count)){
        printf("Erreur lors de la lecture de l'image.\n");
        return;
    }
    unsigned char *mirordata = malloc(width * height * channel_count);
    if (!mirordata){
        printf("Erreur d'allocation mémoire.\n");
        free_image_data(data);
        return;
    }
    for (int y = 0; y<height; y++){
        for (int x=0; x<width; x++){
            int index = (y*width+x)*channel_count;
            int new_index = (y * width + (width-1-x))*channel_count;
            for (int i= 0; i< channel_count; i++){
                mirordata[new_index + i] = data[index+i];
            }
        }
    }
    write_image_data("image_out.bmp", mirordata, width, height);
    free_image_data(data);
}

void color_desaturate(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channel_count;
 
    if (!read_image_data(source_path, &data, &width, &height, &channel_count)){
        printf("Erreur lors de la lecture de l'image.\n");
        return;
    }
 
    for (int i = 0; i < width * height; i++) {
        int index = i * channel_count;
 
        unsigned char r = data[index];
        unsigned char g = data[index + 1];
        unsigned char b = data[index + 2];
 
        unsigned char min = r;
        if (g < min) min = g;
        if (b < min) min = b;
 
        unsigned char max = r;
        if (g > max) max = g;
        if (b > max) max = b;
 
        unsigned char new_val = (min + max) / 2;
 
        data[index]     = new_val;
        data[index + 1] = new_val;
        data[index + 2] = new_val;
    }
 
    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}

void mirror_vertical(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channel_count;
 
    if (!read_image_data(source_path, &data, &width, &height, &channel_count)) {
        printf("Erreur lors de la lecture de l'image.\n");
        return;
    }
 
    unsigned char *mirrored_data = malloc(width * height * channel_count);
    if (!mirrored_data) {
        printf("Erreur d'allocation mémoire.\n");
        free_image_data(data);
        return;
    }
 
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int src_index = (y * width + x) * channel_count;
            int dst_index = ((height - 1 - y) * width + x) * channel_count;
 
            for (int c = 0; c < channel_count; c++) {
                mirrored_data[dst_index + c] = data[src_index + c];
            }
        }
    }
 
    write_image_data("image_out.bmp", mirrored_data, width, height);
 
    free_image_data(data);
    free(mirrored_data);
}

void mirror_total(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channel_count;

    if (!read_image_data(source_path, &data, &width, &height, &channel_count)) {
        printf("Erreur lors de la lecture de l'image.\n");
        return;
    }
    unsigned char *mirrored_data = malloc(width * height * channel_count);
    if (!mirrored_data) {
        printf("Erreur d'allocation mémoire.\n");
        free_image_data(data);
        return;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int src_index = (y * width + x) * channel_count;
            int dst_index = ((height - 1 - y) * width + (width - 1 - x)) * channel_count;

            for (int c = 0; c < channel_count; c++) {
                mirrored_data[dst_index + c] = data[src_index + c];
            }
        }
    }

    write_image_data("image_out.bmp", mirrored_data, width, height);

    free_image_data(data);
    free(mirrored_data);

}

void scale_crop(char *source_path, int center_x, int center_y, int crop_width, int crop_height) {
    unsigned char *data = NULL;
    int width, height, channel_count;
 
    read_image_data(source_path, &data, &width, &height, &channel_count);
 
    int x_start = center_x - crop_width / 2;
    int y_start = center_y - crop_height / 2;
 
    if (x_start < 0) x_start = 0;
    if (y_start < 0) y_start = 0;
    if (x_start + crop_width > width) crop_width = width - x_start;
    if (y_start + crop_height > height) crop_height = height - y_start;
 
    unsigned char *cropped = malloc(crop_width * crop_height * channel_count);
 
    for (int y = 0; y < crop_height; y++) {
        for (int x = 0; x < crop_width; x++) {
            int src = ((y_start + y) * width + (x_start + x)) * channel_count;
            int dst = (y * crop_width + x) * channel_count;
 
            for (int c = 0; c < channel_count; c++) {
                cropped[dst + c] = data[src + c];
            }
        }
    }
 
    write_image_data("image_out.bmp", cropped, crop_width, crop_height);
    free_image_data(data);
    free(cropped);
}

void scale_nearest(char *source_path, float scale_factor) {
    unsigned char *data = NULL;
    int width, height, channels;

    if (!read_image_data(source_path, &data, &width, &height, &channels)) {
        printf("Erreur lors de la lecture de l'image.\n");
        return;
    }

    int new_width = (int)(width * scale_factor);
    int new_height = (int)(height * scale_factor);

    if (new_width <= 0 || new_height <= 0) {
        printf("Facteur d'échelle trop petit !\n");
        free_image_data(data);
        return;
    }

    unsigned char *scaled = malloc(new_width * new_height * channels);
    if (!scaled) {
        printf("Erreur d'allocation mémoire.\n");
        free_image_data(data);
        return;
    }

    for (int y = 0; y < new_height; y++) {
        for (int x = 0; x < new_width; x++) {
            int src_x = (int)(x / scale_factor);
            int src_y = (int)(y / scale_factor);
            int src_index = (src_y * width + src_x) * channels;
            int dst_index = (y * new_width + x) * channels;

            for (int c = 0; c < channels; c++) {
                scaled[dst_index + c] = data[src_index + c];
            }
        }
    }

    write_image_data("image_out.bmp", scaled, new_width, new_height);

    free_image_data(data);
    free(scaled);
}

void scale_bilinear(char *source_path, float scale_factor) {
    unsigned char *data = NULL;
    int width, height, channels;

    if (!read_image_data(source_path, &data, &width, &height, &channels)) {
        printf("Erreur lors de la lecture de l'image.\n");
        return;
    }

    int new_width = (int)(width * scale_factor);
    int new_height = (int)(height * scale_factor);

    if (new_width <= 0 || new_height <= 0) {
        printf("Facteur d'échelle trop petit !\n");
        free_image_data(data);
        return;
    }

    unsigned char *scaled = malloc(new_width * new_height * channels);
    if (!scaled) {
        printf("Erreur d'allocation mémoire.\n");
        free_image_data(data);
        return;
    }

    for (int y = 0; y < new_height; y++) {
        for (int x = 0; x < new_width; x++) {
            float gx = x / scale_factor;
            float gy = y / scale_factor;

            int x1 = (int)gx;
            int y1 = (int)gy;
            int x2 = x1 + 1;
            int y2 = y1 + 1;

            if (x2 >= width) x2 = width - 1;
            if (y2 >= height) y2 = height - 1;

            float dx = gx - x1;
            float dy = gy - y1;

            for (int c = 0; c < channels; c++) {
                float Q11 = data[(y1 * width + x1) * channels + c];
                float Q12 = data[(y1 * width + x2) * channels + c];
                float Q21 = data[(y2 * width + x1) * channels + c];
                float Q22 = data[(y2 * width + x2) * channels + c];

                float R1 = Q11 * (1 - dx) + Q12 * dx;
                float R2 = Q21 * (1 - dx) + Q22 * dx;
                float P = R1 * (1 - dy) + R2 * dy;

                int dst_index = (y * new_width + x) * channels + c;
                scaled[dst_index] = (unsigned char)(P);
            }
        }
    }

    write_image_data("image_out.bmp", scaled, new_width, new_height);

    free_image_data(data);
    free(scaled);
}

void second_line(char *source_path) {
    unsigned char *data = NULL;
    int width, height, channels;

    if (!read_image_data(source_path, &data, &width, &height, &channels)) {
        printf("Erreur lors de la lecture de l'image.\n");
        return;
    }

    if (height < 2) {
        printf("Image trop petite : il faut au moins 2 lignes.\n");
        free_image_data(data);
        return;
    }

    int index = width * channels; // (1,0) correspond au premier pixel de la 2e ligne
    int r = data[index];
    int g = data[index + 1];
    int b = data[index + 2];

    printf("second_line: %d, %d, %d\n", r, g, b);

    free_image_data(data);
}

#include "utils.h"

void print_pixel(char *source_path, int x, int y) {
    unsigned char *data = NULL;
    int width, height, channels;

    if (!read_image_data(source_path, &data, &width, &height, &channels)) {
        printf("Erreur lecture image\n");
        return;
    }

    pixelRGB *p = get_pixel(data, width, height, channels, x, y);
    if (!p) {
        printf("Pixel hors image ou erreur\n");
    } else {
        printf("print_pixel (%d, %d): %d, %d, %d\n", x, y, p->R, p->G, p->B);
        free(p);
    }

    free_image_data(data);
}
