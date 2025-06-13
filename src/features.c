#include <estia-image.h>
#include <stdio.h>
#include <string.h>
#include "features.h"
#include "utils.h"
#include <stdlib.h>


/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !");
}

void tenth_pixel(char *source_path) {
    unsigned char *data;
    int width, height, channels;

    read_image_data(source_path, &data, &width, &height, &channels);

    int i = 9 * channels;
    printf("tenth_pixel: %d, %d, %d\n", data[i], data[i + 1], data[i + 2]);

    data[i]     = 255;
    data[i + 1] = 0;
    data[i + 2] = 0;

    write_image_data(source_path, data, width, height);

    free(data);
}

