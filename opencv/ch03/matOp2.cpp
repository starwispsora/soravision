#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;

String folder = "/Users/sora/Desktop/soravision/opencv/data/";

int main()
{
    //<Matrix Operation2 : clone, copyTo)
    Mat img1 = imread(folder + "lena.bmp");
    Mat img2 = img1;
    Mat img3;
    img3 = img1;

    Mat img4 = img1.clone();
    Mat img5;
    img1.copyTo(img5);

    img1.setTo(Scalar(0, 255, 255)); //blue green red

    //imshow("img1", img1);
    //imshow("img2", img2);
    //imshow("img3", img3);
    //imshow("img4", img4);
    //imshow("img5", img5);
    cv::imwrite("output11.jpg", img1);
    cv::imwrite("output22.jpg", img2);   
    cv::imwrite("output33.jpg", img3);  
    cv::imwrite("output44.jpg", img4);
    cv::imwrite("output55.jpg", img5);
    //waitKey(0);

    return 0;
}