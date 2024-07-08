#include <stdio.h>
#include <stdlib.h>
#include "header.h"

//int main(int argc, char** argv)
//{
//	if (argc != 3) {
//		fprintf(stderr, "Usage: %s <input> <output>\n", argv[0]);
//		exit(1);
//	}
//
//	unsigned char image[HEIGHT][WIDTH][3];
//	loadImage(image, argv[1]);
//	saveImage(image, argv[2]);
//
//	return 0;
//}



//課題5 差分生成
//int main(int argc, char** argv)
//{
//	if (argc != 4) {
//		fprintf(stderr, "Usage: %s <current> <background> <output>\n", argv[0]);
//		exit(1);
//	}
//
//	unsigned char currentImage[HEIGHT][WIDTH][3];
//	unsigned char backgroundImage[HEIGHT][WIDTH][3];
//	unsigned char resultImage[HEIGHT][WIDTH][3];
//
//	loadImage(currentImage, argv[1]);
//	loadImage(backgroundImage, argv[2]);
//	subtractImages(currentImage, backgroundImage, resultImage);
//	saveImage(resultImage, argv[3]);
//
//	return 0;
//}

//課題5 差分ヒストグラム化
//int main(int argc, char** argv)
//{
//	if (argc != 3)
//	{
//		fprintf(stderr, "Usage: %s <input> <csv>\n", argv[0]);
//		exit(1);
//	}
//
//	generateHistogram(argv[1], argv[2]);
//
//	return 0;
//}

//課題6 二値化
//int main(int argc, char** argv) {
//    if (argc != 4) {
//        fprintf(stderr, "Usage: %s <inputFile> <threshold> <outputFile>\n", argv[0]);
//        exit(1);
//    }
//
//    int threshold = atoi(argv[2]);
//    unsigned char image[HEIGHT][WIDTH][3];
//    loadImage(image, argv[1]);
//    binarizeImage(image, threshold);
//    saveImage(image, argv[3]);
//
//    return 0;
//}

//課題7 判別分析法
//int main(int argc, char** argv) {
//    if (argc != 3) {
//        fprintf(stderr, "Usage: %s <inputFile> <outputFile>\n", argv[0]);
//        exit(1);
//    }
//
//    unsigned char image[HEIGHT][WIDTH][3];
//    loadImage(image, argv[1]);
//    int threshold = calculateOtsuThreshold(image);
//    binarizeImage(image, threshold);
//    saveImage(image, argv[2]);
//
//    return 0;
//}

//課題8 ノイズ除去
int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s <binary_image> <iterations> <output_filename>\n", argv[0]);
        return 1;
    }

    unsigned char image[HEIGHT][WIDTH][CHANNELS];
    int iterations = atoi(argv[2]);

    loadImage(image, argv[1]);
    opening(image, iterations);
    closing(image, iterations);
    saveImage(image, argv[3]);

    return 0;
}
