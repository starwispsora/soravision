#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;
String folder = "/Users/sora/Desktop/soravision/opencv/data/";

int main()
{
    Mat img(400, 600, CV_8UC3, Scalar(255, 255, 255)); //white colored image
    Point pt1(30, 30), pt2(200, 200); //line start and end point, tilted line
    int a = 0;
    while(true){
        img = Scalar(255, 255, 255); //initialize image with white color
        pt1.x +=a; //move start point
        pt2.x +=a; //move end point
        line(img, pt1, pt2, Scalar(255, 0, 0), 3, LINE_AA); //draw line
         //imshow("img", img);
        imwrite("line.jpg", img); 
        if (waitKey(30) == 27)
            break;
    }

    
    return 0;
}