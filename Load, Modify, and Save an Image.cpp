#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
using namespace cv;
using namespace std;

int main(int argc, char** argv){
	String imageName("../images/002.jpg"); // set image path,(default)
	Mat image;
	image = imread(imageName, IMREAD_COLOR); // Read the file
	Mat gray_image;
	cvtColor(image, gray_image, COLOR_BGR2GRAY);
	imwrite("../images/gray_002.jpg", gray_image);
	if (image.empty()){
		cout << "Could not open or find the image" << endl;
		return -1;
	}
	namedWindow(imageName, WINDOW_AUTOSIZE);
	namedWindow("Gray image", WINDOW_AUTOSIZE);
	imshow(imageName, image);
	imshow("Gray image", gray_image);
	waitKey(0); // Wait for a keystroke in the window
	return 0;
}