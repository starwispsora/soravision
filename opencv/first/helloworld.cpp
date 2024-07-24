#include "opencv2/opencv.hpp"
#include <iostream>
#include <string>

std::string folder = "/Users/sora/Desktop/soravision/opencv/data/";

int main()
{
    std::cout << "hello, world" << std::endl;
    cv::Mat img;
    img = cv::imread(folder + "lena.bmp");
    cv::imshow("image", img);
    cv::waitKey(0);

    //cv::imwrite("output.jpg", img);
    //std::cout << "Image saved to output.jpg" << std::endl;
    return 0;
}