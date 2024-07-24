#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;
String folder = "/Users/sora/Desktop/soravision/opencv/data/";


int main()
{
    Mat frame, doubleFrame, reshapeFrame;
    VideoCapture cap(folder + "vtest.avi");

    //VideoCapture cap(0, CAP_V4L2);
    double fps = cap.get(CAP_PROP_FPS);
    int delay = cvRound(1000 / fps);
    Size sz1(cap.get(CAP_PROP_FRAME_WIDTH), cap.get(CAP_PROP_FRAME_HEIGHT)); //get origianl frame size
    std::vector<int> shape = {sz1.width / 2, sz1.height / 2};

    //<open check>
    if (!cap.isOpened())
    {
        cerr << "Video open failed " << endl;
        return -1;
    }
    cout << "Video open" << endl;
    
    int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');
    VideoWriter outputVideo(folder + "output10.avi", fourcc, fps, sz1);

    //<frame image(vid) show>
    while(true){
        cap >> frame;   
        if (frame.empty())
            break;
        resize(frame, doubleFrame, sz1 * 2);
        reshapeFrame = frame.reshape(3,cap.get(CAP_PROP_FRAME_HEIGHT * 2)); 
        imshow("frame", frame);
        imshow("doubleframe", doubleFrame);
        imshow("rashape", reshapeFrame);
        //imwrite("frame.jpg", frame);
        //imwrite("doubleFrame.jpg", doubleFrame);
        //imwrite("reshape.jpg", reshapeFrame);

        outputVideo << frame;
        if (waitKey(delay) == 27)
            break;
    }
    cap.release();
    outputVideo.release();
    return 0;
}
