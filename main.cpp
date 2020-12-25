#include <iostream>
#include"histogram.h"
#include <fstream>
#include <string>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void rgb2gray(Mat src,int row,int col,Mat &gray) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			int b = src.at<Vec3b>(i, j)[0];
			int g = src.at<Vec3b>(i, j)[1];
			int r = src.at<Vec3b>(i, j)[2];
			int Gray = (r * 299 + g * 587 + b * 114 + 500) / 1000;
			gray.at<uchar>(i, j) = Gray;
		}
	}
}

int main() {
	Mat src = imread("D:/1.jpg");
	int row = src.rows;
	int col = src.cols;
	Mat gray(row, col, CV_8UC1);
	if (src.channels() == 3) {
		rgb2gray(src, row, col, gray);
	}
	cout << "请输入灰度区间数：" << endl;
	double interval_num;
	cin >> interval_num;
	vector<int> gray_value_num(interval_num);

	histogram h1;
	h1.set_interval_num(interval_num);
	int value_num = 0;

	for (int m = 0; m < row; m++) {
		for (int n = 0; n < col; n++) {
			int gray_value = gray.at<uchar>(m, n);
			for (int i = 0; i < interval_num; i++) {
				if (gray_value > i*h1.get_interval_min() && gray_value < (i + 1)*h1.get_interval_min()) {
					value_num++;
					gray_value_num[i] = gray_value_num[i] + value_num;
					value_num = 0;
				}
			}
		}
	}

	for (int k = 0; k < interval_num; k++) {
		cout << k * h1.get_interval_min() <<"~"<< (k + 1)*h1.get_interval_min();
		for (int m = 0; m < gray_value_num[k]/100; m++) {
			cout << "*";
		}
		cout<<" "<<endl;
	}

	imshow("gray", gray);
	imshow("rgb", src);
	waitKey(0);
	return 0;
}