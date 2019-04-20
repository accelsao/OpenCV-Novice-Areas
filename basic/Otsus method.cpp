/*
	Otsus method
	time complexity: O(hw)
	one image 1024*768*256 ~ 1e9
*/
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
using namespace cv;
using namespace std;

const char window_name[] = "Otsu's Method";

int main(int argc, char** argv) {

	Mat img = cv::imread("../images/002.jpg", cv::IMREAD_COLOR);
	if (img.empty()) {
		puts("No Image!");
		return -1;
	}
	Mat gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);

	double w0, w1;
	double m0, m1;
	double max_sb = 0, sb = 0;
	int height = img.rows;
	int width = img.cols;
	int threshold;
	for (int t = 0;t < 256;t++) {
		w0 = w1 = m0 = m1 = 0;
		for (int i = 0;i < height;i++) {
			for (int j = 0;j < width;j++) {
				int val = (int)(gray.at<uchar>(i, j));
				if (val < t) {
					w0 ++;
					m0 += val;
				}
				else {
					w1++;
					m1 += val;
				}
			}
		}
		//printf("%lf %lf\n", m0, m1);
		m0 /= w0;
		m1 /= w1;
		w0 /= (height * width);
		w1 /= (height * width);
		sb = w0 * w1 * pow(m0 - m1, 2);
		if (sb > max_sb) {
			max_sb = sb;
			threshold = t;
		}
	}

	for (int i = 0;i < height;i++) {
		for (int j = 0;j < width;j++) {
			gray.at<uchar>(i, j) = (int)gray.at<uchar>(i, j) < threshold ? 0 : 255;
		}
	}

	namedWindow(window_name, WINDOW_AUTOSIZE);
	imshow(window_name, gray);
	waitKey(0);
	destroyAllWindows();
	return 0;
}
