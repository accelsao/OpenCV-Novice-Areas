/*
	convert image bgr to rgb
*/
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>
using namespace cv;
using namespace std;


int main(int argc, char** argv) {
	String imageName("../images/002.jpg");
	Mat src, dst;
	src = imread(imageName, IMREAD_COLOR);
	if (src.empty()) {
		cout << "Could not open or find the image" << endl;
		return -1;
	}
	int width = src.rows;
	int height = src.cols;
	
	dst = src.clone();
	
	for (int i = 0;i < width;i++) {
		for (int j = 0;j < height;j++) {
			uchar red = dst.at<Vec3b>(i, j)[0];//b(0),g(1),r(2)
			dst.at<Vec3b>(i, j)[0] = src.at<Vec3b>(i, j)[2];
			dst.at<Vec3b>(i, j)[2] = red;
			//printf("%d %d\n", i, j);
		}
	}
	namedWindow(imageName, WINDOW_AUTOSIZE);
	imshow(imageName, dst);
	waitKey(0);
	destroyAllWindows();
	return 0;
}
