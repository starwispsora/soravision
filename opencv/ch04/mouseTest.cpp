#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;
String folder = "/Users/sora/Desktop/soravision/opencv/data/";
void onMouse(int event, int x, int y, int flags, void* data);

struct Mydata
{
    Point ptOld;
    Point ptNew;
    Mat img;
    Scalar white = Scalar(255, 255, 255);
    Scalar yellow = Scalar(0, 255, 255);
    Scalar blue = Scalar(255, 0, 0);
    Scalar green = Scalar(0, 255, 0);
    Scalar red = Scalar(0, 0, 255);
    bool flag = false;
    
};

int main() 
{
    //Mat img = imread(folder + "lenna.bmp"); 
    Mydata mydata;
    mydata.img = imread(folder + "lenna.bmp"); 

    namedWindow("img");
    setMouseCallback("img", onMouse, (void *)&mydata);

    imshow("img", mydata.img);
    waitKey(0);
    destroyAllWindows();

    return 0;
}

//algorithm for mouse event(when running)
void onMouse(int event, int x, int y, int flags, void* data)
{
    Mydata* ptr = (Mydata*)data;
    switch (event)
    {
        case EVENT_LBUTTONDOWN:
            cout << "mouse left button down" << x << y << endl;
            ptr->ptOld = Point(x, y); //save the point when mouse left button down
            ptr->flag = true;
            break;
        case EVENT_LBUTTONUP:
            cout << "mouse left button up" << x << y << endl;  
            ptr->flag = true; 
            break;
        case EVENT_MOUSEMOVE:
            if (ptr->flag & EVENT_FLAG_LBUTTON)
            {
                line(ptr->img, ptr->ptOld, Point(x, y), ptr->blue, 3);
                imshow("img", ptr->img); //show the image when mouse is moving
                ptr->ptOld = Point(x, y);

            }
                
    }
}