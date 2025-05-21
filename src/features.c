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


void tenth_pixel(char *source_path) {
    unsigned char *data;
    int width, heigth, c;

    if (read_image_data(source_path, &data, &width, &heigth, &c) == 0 && width >= 10) {
        int i = 9 * c;
        printf("tenth_pixel: %d, %d, %d\n", data[i], data[i + 1], data[i + 2]);
        free(data);
    }
}

