#pragma once
#include<iostream>
#include<vector>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

class histogram {
public:
	histogram() { value_num = 0;}
	void set_interval_num(int a) { interval_num = a; }
	int get_interval_min() { return ceil(255 / interval_num); }
	void get_histogram(Mat,int,int);

	void draw_histogram();
private:
	int interval_num;
	int interval_min;
	int value_num;
	
};