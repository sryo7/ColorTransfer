// colortransfer.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include<iostream>
//#include<opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>


void Trackbar(int val);

using namespace cv;

IplImage* img;
//トラックバーの関数から操作するためにグローバル関数に置く


int main(int argc,char *argv[]) {

	img = cvLoadImage("C:/Users/僚/Pictures/opencv/arimura.png");
	
	namedWindow("RGBchanger", CV_WINDOW_AUTOSIZE);
	cvShowImage("RGBchanger", img);
	cvCreateTrackbar("Move it", "RGBchanger", 0, 2, Trackbar);
	waitKey(0);
	return 0;
}

uchar p[3];
int x, y;

void Trackbar(int val) {
	for (y = 0; y < img->height; y++) {
		for (x = 0; x < img->width; x++) {
			p[0] = img->imageData[img->widthStep * y + x * 3];        // B
			p[1] = img->imageData[img->widthStep * y + x * 3 + 1];    // G
			p[2] = img->imageData[img->widthStep * y + x * 3 + 2];    // R
			img->imageData[img->widthStep * y + x * 3] = p[1];
			img->imageData[img->widthStep * y + x * 3 + 1] = p[2];
			img->imageData[img->widthStep * y + x * 3 + 2] = p[0];
		}
	}

	cvShowImage("RGBchangerbar", img);
	cvSaveImage("Barimura.png", img);
}

