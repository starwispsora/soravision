#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    String folder = "/Users/sora/Desktop/soravision/opencv/data/";
    Scalar white = Scalar(255, 255, 255);
    Scalar red = Scalar(0, 0, 255);
    Mat img(400, 600, CV_8UC3, white);

    Point pt1(30, 40); // Define the point

    // Draw a small circle at pt1 to represent the point
    int radius = 5; // Radius of the dot
    int thickness = -1; // Thickness: -1 means the circle will be filled
    circle(img, pt1, radius, red, thickness);

    // Show the image with the point
    imshow("Image with Point", img);
    waitKey(0);
    destroyAllWindows();

    return 0;
}
