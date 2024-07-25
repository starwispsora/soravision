#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;
String folder = "/Users/sora/Desktop/soravision/opencv/data/";
//main = entry point


//0.tilted lenna image
void rotateImage()
{
    Rect rc1;
    rc1.x = 1;
    rc1.y = 1;
    rc1.width = 10;
    rc1.height = 10;
    Rect rc2(20, 30, 500, 400);

    Point pt1(10, 20);
    Size sz1(100, 100);
    RotatedRect rr1(pt1, sz1, 30);
    Point2f pts[4];
    rr1.points(pts);
    std::cout << pts[0] << std::endl;
    std::cout << pts[1] << std::endl;
}

int main()
{
    //1.imshow lenna image
    imshow("lenna", imread(folder + "lenna.bmp"));
    waitKey(0);

    //2. a rectacngle following the mouse
    Mat img = imread(folder + "lenna.bmp");
    int a = 0;
    namedWindow("img");
    createTrackbar("level", "img", &a, 255);
    while (true)
    {
        line(img, Point(0, 0), Point(a, a), Scalar(0, 0, 255), 3); 
        imshow("img", img);
        cout << a << endl;
        if(waitKey(100) == 27) break;
    }
    destroyAllWindows();

    return 0;
}

//3. print coordinates of mouse click
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

//4. write BGR values to a vector and save it to a file as "mouseBGRvector.json"
void fileStorageTest()
{
    Mat img(400, 600, CV_8UC3, Scalar(255, 255, 255));
    FileStorage fs;

    fs.open(folder + "mouseBGRvector.json", FileStorage::WRITE);
    Point pt1(30, 40);
    vector<float> v = {1.2, 4.5, 3.14};
    Mat mat1 = imread(folder + "lenna.bmp");

    fs << "vector" << v;
    fs.release();
}

//5. tickmeter
