#include "header.h"

void binarizeImage(unsigned char image[HEIGHT][WIDTH][3], int threshold) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // 緑色(G)成分が閾値を超えているかチェック
            if (image[y][x][1] > threshold) {
                // ピクセルを白に設定
                image[y][x][0] = 255;
                image[y][x][1] = 255;
                image[y][x][2] = 255;
            }
            else {
                // ピクセルを黒に設定
                image[y][x][0] = 0;
                image[y][x][1] = 0;
                image[y][x][2] = 0;
            }
        }
    }
}

