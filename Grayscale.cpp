/*
	convert image rgb to bgr
	RBG to GBR
*/
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>
using namespace cv;
using namespace std;


int main(int argc, char** argv) {





	cv::Mat img = cv::imread("../images/002.jpg", cv::IMREAD_COLOR);

	int width = img.cols;
	int height = img.rows;
	//printf("%d %d\n", height, width);
	cv::Mat out = cv::Mat::zeros(height, width, CV_8UC1);
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			//printf("%d %d\n", j, i);
			out.at<uchar>(j, i) = (int)((float)img.at<cv::Vec3b>(j, i)[0] * 0.0722 + \
				(float)img.at<cv::Vec3b>(j, i)[1] * 0.7152 + \
				(float)img.at<cv::Vec3b>(j, i)[2] * 0.2126);

			
		}
	}

	//cv::imwrite("out.jpg", out);
	cv::imshow("answer", out);
	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;





}
