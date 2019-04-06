/*
	Simple linear blender (dst = a * src1 + b * src2)

*/
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
using namespace cv;
using namespace std;

int main() {

	double alpha = 0.5;
	double beta;
	double input;

	Mat src1, src2, dst;
	cout << " Simple Linear Blender " << endl;
	cout << "-----------------------" << endl;
	cout << " Enter alpha [0.0-1.0]: ";
	cin >> input;
	// We use the alpha provided by the user if it is between 0 and 1
	if (input >= 0 && input <= 1) {
		alpha = input;
	}
	//![load]
	// Read images ( both have to be of the same size and type )
	src1 = imread( "../images/001.jpg" );
	src2 = imread( "../images/002.jpg" );
	//![load]

	if (src1.empty()) { cout << "Error loading src1" << endl; return -1; }
	if (src2.empty()) { cout << "Error loading src2" << endl; return -1; }
	//![blend_images]
	beta = (1.0 - alpha);
	addWeighted(src1, alpha, src2, beta, 0., dst);
	dst = alpha * src1 + beta * src2;
	//![blend_images]
	//![display]
	imshow("Linear Blend", dst);
	waitKey(0);
	imwrite("../images/blend.jpg", dst);
	//![display]
}
