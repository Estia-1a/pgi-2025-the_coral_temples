#include <stdlib.h>
#include "utils.h"

pixelRGB *get_pixel(unsigned char *data, const unsigned int width, const unsigned int height,
                    const unsigned int n, const unsigned int x, const unsigned int y) {
    if (!data || x >= width || y >= height) {
        return NULL;
    }

    int index = (y * width + x) * n;
    pixelRGB *p = malloc(sizeof(pixelRGB));
    if (!p) return NULL;

    p->R = data[index];
    p->G = data[index + 1];
    p->B = data[index + 2];

    return p;
}