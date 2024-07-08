#include <stdio.h>
#include <stdlib.h>>
#include "header.h"

void generateHistogram(const char* inputFile, const char* outputFile) {
    unsigned char image[HEIGHT][WIDTH][3];
    loadImage(image, inputFile);

    int histogram[3][256] = { 0 };

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            for (int c = 0; c < 3; c++) {
                histogram[c][image[y][x][c]]++;
            }
        }
    }

    FILE* outFp = fopen(outputFile, "w");
    if (outFp == NULL) {
        fprintf(stderr, "ファイルを開けませんでした: %s\n", outputFile);
        exit(1);
    }

    fprintf(outFp, "Color,Value,Count\n");
    for (int c = 0; c < 3; c++) {
        char color = (c == 0) ? 'R' : (c == 1) ? 'G' : 'B';
        for (int i = 0; i < 256; i++) {
            fprintf(outFp, "%c,%d,%d\n", color, i, histogram[c][i]);
        }
    }

    fclose(outFp);
}
