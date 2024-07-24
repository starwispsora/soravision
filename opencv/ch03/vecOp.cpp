#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

String folder = "/workspaces/soravision/opencv/data/";

int main()
{
    //<vector>
    Vec3b p1, p2(0, 0, 225); // p1= blue, p2= red
    p1[0] = 255;
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;

    //<scalar>
    Scalar gray = 128; // similar to vec1b
    cout << "gray: " << gray << endl;   
    Scalar yellow(0, 255, 255); // similar to vec3b
    cout << "yellow: " << yellow << endl;

    //<coulor>
    Mat img1(400, 400, CV_8UC3, yellow);
    Mat img2(400, 400, CV_8UC1, gray);  
    Mat img3(400, 400, CV_8UC3, p2);
    Mat img4(400, 400, CV_8UC3, Scalar(255, 0, 0)); // blue

    //imshow("img1", img1);
    imwrite("output11111.jpg", img1);
    imwrite("output22222.jpg", img2);
    imwrite("output33333.jpg", img3);
    imwrite("output44444.jpg", img4);

    return 0;
}