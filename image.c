#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void loadImage(unsigned char image[HEIGHT][WIDTH][3], const char* filename)
{
	FILE* fp = fopen(filename, "rb");
	if (fp == NULL) {
		fprintf(stderr, "ファイルを開けませんでした。\n");
		exit(1);
	}

	char buffer[1024];

	fgets(buffer, sizeof(buffer), fp);
	fgets(buffer, sizeof(buffer), fp);
	fgets(buffer, sizeof(buffer), fp);

	fread(image, sizeof(unsigned char), HEIGHT * WIDTH * 3, fp);

	fclose(fp);
}

void saveImage(unsigned char image[HEIGHT][WIDTH][3], const char* filename)
{
	FILE* fp = fopen(filename, "wb");
	if (fp == NULL) {
		fprintf(stderr, "ファイルを開けませんでした。\n");
		exit(1);
	}

	fprintf(fp, "P6\n");
	fprintf(fp, "%d %d\n", WIDTH, HEIGHT);
	fprintf(fp, "255\n");

	fwrite(image, sizeof(unsigned char), HEIGHT * WIDTH * 3, fp);

	fclose(fp);
}
