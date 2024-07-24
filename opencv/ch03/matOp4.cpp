#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

String folder = "/Users/sora/Desktop/soravision/opencv/data/";

int main()
{
        //<matrix operation4 : pixel change>
        Mat mat1 = Mat::zeros(3, 4, CV_8UC1); //type here 0~225
        cout << "Before mat1 : " <<endl <<mat1 << endl;

        for (int j=0; j<mat1.rows; j++)
        {
            for (int i=0; i<mat1.cols ; i++)
            {
                mat1.at<uchar>(j, i)++;
            }
        }
        cout<<"After mat1 : " <<endl << mat1 << endl;

        //<ptr>
        for (int j=0; j<mat1.rows; j++)
        {
            uchar* p = mat1.ptr<uchar>(j);
            for (int i=0; i<mat1.cols; i++)
            {
                p[i]++;
            }
        }   
        cout << "After ptr mat1 : " << endl << mat1 << endl;    

        //<iterator>
        for(auto it = mat1.begin<uchar>(); it != mat1.end<uchar>(); it++)
        {
            (*it)++;
        }
          cout << "After iterator mat1 : " << endl << mat1 << endl;    

        retu