#ifndef MYCANNY_H
#define MYCANNY_H

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace cv;

class myCanny
{
public:
    myCanny();
    void CannyThreshold(int, void*);
    void start(uchar *input);
    Mat src, src_gray;
    Mat dst, detected_edges;

    int edgeThresh = 1;
    int lowThreshold;
    int const max_lowThreshold = 100;
    int ratio = 3;
    int kernel_size = 3;
    char* window_name = "Edge Map";

};

#endif // MYCANNY_H
