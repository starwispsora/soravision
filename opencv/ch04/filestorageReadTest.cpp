#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;
String folder = "/Users/sora/Desktop/soravision/opencv/data/";
Mat img;

int main()
{
    FileStorage fs;
    String name;

    fs.open(folder + "myData.json", FileStorage::READ);
    if (!fs.isOpened())
    {
        cerr << "File open failed!" << endl;
        return 1;
    }
    fs["name"] >> name; 
    fs["mat1"] >> img; 
    fs.release();

    cout << name << endl;
    imshow("img", img);
    waitKey(0);

    return 0;
}
