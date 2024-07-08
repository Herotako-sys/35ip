#include "header.h"

void erode(unsigned char src[HEIGHT][WIDTH][CHANNELS], unsigned char dst[HEIGHT][WIDTH][CHANNELS]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            unsigned char min = 255;
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT) {
                        for (int c = 0; c < CHANNELS; c++) {
                            min = src[ny][nx][c] < min ? src[ny][nx][c] : min;
                        }
                    }
                }
            }
            for (int c = 0; c < CHANNELS; c++) {
                dst[y][x][c] = min;
            }
        }
    }
}

void dilate(unsigned char src[HEIGHT][WIDTH][CHANNELS], unsigned char dst[HEIGHT][WIDTH][CHANNELS]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            unsigned char max = 0;
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT) {
                        for (int c = 0; c < CHANNELS; c++) {
                            max = src[ny][nx][c] > max ? src[ny][nx][c] : max;
                        }
                    }
                }
            }
            for (int c = 0; c < CHANNELS; c++) {
                dst[y][x][c] = max;
            }
        }
    }
}

void opening(unsigned char image[HEIGHT][WIDTH][CHANNELS], int iterations) {
    unsigned char temp[HEIGHT][WIDTH][CHANNELS];
    for (int i = 0; i < iterations; i++) {
        erode(image, temp);
        dilate(temp, image);
    }
}

void closing(unsigned char image[HEIGHT][WIDTH][CHANNELS], int iterations) {
    unsigned char temp[HEIGHT][WIDTH][CHANNELS];
    for (int i = 0; i < iterations; i++) {
        dilate(image, temp);
        erode(temp, image);
    }
}
