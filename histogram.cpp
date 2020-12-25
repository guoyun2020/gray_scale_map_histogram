#include"histogram.h"
//
//void histogram::get_histogram(Mat gray,int row,int col) {
//	for (int m = 0; m < row; m++) {
//		for (int n = 0; n < col; n++) {
//			int gray_value = gray.at<uchar>(m, n);
//			for (int i = 0; i < interval_num; i++) {
//				if (gray_value > i*interval_min && gray_value < (i + 1)*interval_min) {
//					value_num++;
//					gray_value_num[i] = gray_value_num[i] + value_num;
//					value_num = 0;
//				}
//			}
//		}
//	}
//
//}
//
//void histogram::draw_histogram() {
//
//}