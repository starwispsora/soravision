#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;

String folder = "/Users/sora/Desktop/soravision/opencv/data/";

int main()
{
    //<matrix operation3 : roi>
    Mat img1 = imread(folder + "lena.bmp");
    Rect rc(220, 120, 200, 200); 
    Mat img2 = img1(rc); // shallow copy, roi
    Mat img3 = img1(rc).clone();  // deep copy, new image
   
    img2 = ~img2; //invert
    img1.setTo(Scalar(0, 255, 255), img2); //setTo yellow

    //imshow("img1", img1);
    cv::imwrite("output111.jpg", img1);
    cv::imwrite("output222.jpg", img2);
    cv::imwrite("output333.jpg", img3);  
    //waitKey(0);

    retu