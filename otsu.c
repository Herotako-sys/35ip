#include "header.h"
#include <math.h>

int calculateOtsuThreshold(unsigned char image[HEIGHT][WIDTH][3]) {
    int histogram[256] = { 0 };
    int total = HEIGHT * WIDTH;
    float sum = 0;
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            unsigned char green = image[y][x][1]; // 緑色成分
            histogram[green]++;
            sum += green;
        }
    }

    float sumB = 0;
    int wB = 0;
    int wF = 0;
    float SE = 0;
    float SE_B = 0;
    float SE_F = 0;
    float vB = 0;
    float vF = 0;
    float rMax = 0;
    int thresh = 0;

    //画像全体の画素値の平均と分散
    float mean = sum / total;
    float MSE = 0;
    for (int t = 0; t < 256; t++) {
		MSE += (t - mean) * (t - mean) * histogram[t];
        SE += t * t * histogram[t];
	}
    float variance = MSE / total;

    for (int t = 0; t < 256; t++) {
        //背景、前景の画素等パラメータ計算
        wB += histogram[t];
        if (wB == 0) continue;
        wF = total - wB;
        if (wF == 0) break;

        sumB += (float)(t * histogram[t]);
        float uB = sumB / wB;
        float uF = (sum - sumB) / wF;

        SE_B += t * t * histogram[t];

        vB = SE_B / wB - uB * uB;
        vF = (SE - SE_B) / wF - uF * uF;

        float vw = sqrt((wB * vB + wF * vF) /(wB + wF));
        float vz = sqrt((wB * (uB - mean) * (uB - mean) + wF * (uF - mean) * (uF - mean))
            / (wB + wF));

        float separation = vz / vw;
        if (separation > rMax) {
            rMax = separation;
            thresh = t;
        }
    }

    printf("Threshold: %d, rMax: %f \n", thresh, rMax);

    return thresh;
}

