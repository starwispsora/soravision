#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;

String folder = "/workspaces/soravision/opencv/data/";

int main()
{
    // <matrix operation1 : constructor>
    Mat img1;
    img1 = Scalar(10,  0,  0);
    Mat img2(400, 600, CV_8UC1); //p79
    //Mat img3(400, 600, CV_8UC3); //how to change this to blue
    Mat img3(400, 600, CV_8UC3, Scalar(255, 0, 0));
    Mat img4(Size(500, 500), CV_8UC3); 
    Mat img5(300, 400, CV_8UC1, Scalar(0));
    Mat img6(300, 400, CV_8UC1, Scalar(255));

    //cv::imshow("image", img2); 
    //cv::waitKey(0); 
    cv::imwrite("output2.jpg", img2); 
    cv::imwrite("output3.png", img3);
    cv::imwrite("output4.bmp", img4);
    cv::imwrite("output5.jpg", img5);
    cv::imwrite("output6.jpg", img6);

    return 0;
}