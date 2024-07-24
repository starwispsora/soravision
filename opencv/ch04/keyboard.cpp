#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;
String folder = "/workspaces/soravision/opencv/data/";
cv::Mat img2; //<<<<<<<<<<<
int img; //<<<<<<<<<<<

int main() //p143, p146, p150, p151 +add textbook code
{
    Scalar white = Scalar(255, 255, 255);
    Scalar yellow = Scalar(0, 255, 255);
    Scalar blue = Scalar(255, 0, 0);
    Scalar green = Scalar(0, 255, 0);
    Scalar red = Scalar(0, 0, 255);
    Mat img = imread(folder + "lenna.bmp"); //white colored image
    int keycode;

    namedWindow("img");
    imwrite("keyboard.jpg", img); //save image
    int fps = 30;
   


    int delay = cvRound(1000 / 30);
    Scalar a;

    while (true)
    {
        keycode = waitKey(delay);
        if(keycode != -1)
           cout << "keycode: " << keycode << endl;
        if (keycode == 27)
            break;
        if (keycode == 'i' || keycode == 'I')
        {
            //img = imread(folder + "lenna.bmp");
            //imshow("img", img);
            img = ~img;
            imwrite("keyboard2.jpg", img); //<<<<<<<<<<<
        }
        if (keycode == 'a' || keycode == 'A')
        {
            a = a + Scalar(1, 1, 1);
            img2 = img +a;
            imwrite("keyboard3.jpg", img2);
        }
        if (keycode == 'b' || keycode == 'B')
        {
           a = a - Scalar(1, 1, 1);
           img2 = img + a;
           imwrite("keyboard4.jpg", img2);
        }
    }
    return 0;
}