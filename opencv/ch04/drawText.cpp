#include "opencv2/opencv.hpp"
#include "opencv2/freetype.hpp"
#include <iostream>

using namespace cv;
using namespace std;
String folder = "/workspaces/soravision/opencv/data/";

int main()
{
    Scalar white = Scalar(255, 255, 255);
    Scalar yellow = Scalar(0, 255, 255);
    Scalar blue = Scalar(255, 0, 0);
    Scalar green = Scalar(0, 255, 0);
    Scalar red = Scalar(0, 0, 255);
    Mat img(400, 600, CV_8UC3, Scalar(255, 255, 255)); //white colored image

    Ptr<freetype::FreeType2> ft2 = freetype::createFreeType2(); //smart pointer / create FreeType2 object in heap memory
    ft2->loadFontData("/workspaces/soravision/opencv/data/NanumGothic.ttf", 0); //load font data
    String text = u8"폰트 한글 써지나2"; //UTF-8 encoded string
    int fontHeight = 60;
    Size textSize = ft2->getTextSize(text, fontHeight, -1, 0); //get text size

    putText(img, "FONT_HERSHEY_SIMPLEX", Point(20, 50), FONT_HERSHEY_SIMPLEX, 1, green);
    putText(img, "폰트 한글 써지나", Point(20, 150), FONT_HERSHEY_PLAIN, 1, red);

    ft2->putText(img, text, Point(20, 250), fontHeight, red, -1, LINE_AA, true); //draw text with FreeType2 object  

    imwrite("font.jpg", img); //save image
    
    return 0;
}