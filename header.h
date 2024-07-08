#pragma once	

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 640
#define HEIGHT 480
#define CHANNELS 3

// 現在の画像と背景画像の差分を計算する関数
void subtractImages(unsigned char currentImage[HEIGHT][WIDTH][3], unsigned char backgroundImage[HEIGHT][WIDTH][3], unsigned char resultImage[HEIGHT][WIDTH][3]);

// 画像を読み込む関数
void loadImage(unsigned char image[HEIGHT][WIDTH][3], const char* filename);

// 画像を保存する関数
void saveImage(unsigned char image[HEIGHT][WIDTH][3], const char* filename);

// ヒストグラムを生成する関数
void generateHistogram(const char* inputFile, const char* outputFile);

// 二値化する関数
void binarizeImage(unsigned char image[HEIGHT][WIDTH][3], int theshold);

// 大津の二値化を行う関数
int calculateOtsuThreshold(unsigned char image[HEIGHT][WIDTH][3]);

void erode(unsigned char src[HEIGHT][WIDTH][CHANNELS], unsigned char dst[HEIGHT][WIDTH][CHANNELS]);

void dilate(unsigned char src[HEIGHT][WIDTH][CHANNELS], unsigned char dst[HEIGHT][WIDTH][CHANNELS]);

void opening(unsigned char image[HEIGHT][WIDTH][CHANNELS], int iterations);

void closing(unsigned char image[HEIGHT][WIDTH][CHANNELS], int iterations);
