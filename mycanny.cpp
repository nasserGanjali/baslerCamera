#include "mycanny.h"

myCanny::myCanny()
{
}

void myCanny::CannyThreshold(int, void*)
{
  /// Reduce noise with a kernel 3x3
  blur( src_gray, detected_edges, Size(3,3) );

  /// Canny detector
  Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size );

  /// Using Canny's output as a mask, we display our result
  dst = Scalar::all(0);

  src.copyTo( dst, detected_edges);
  imshow( window_name, dst );
 }

void myCanny::start(uchar *input)
{
    /// Load an image
    /*uchar * mem = new uchar [800*600];
    std::ifstream file("/tmp/image.raw", std::ios::in);
    file.read((char*)mem,800*600);
    file.close();*/
    //src.create(800,600,CV_8U);
    Mat img(600,800,CV_8U,input);
    //img=img.t();
    //imshow("img",img);
//    waitKey();
//    return;
    src = img;
    //src.create(800,600,CV_8U);
    if( !src.data )
    { return ; }

    /// Create a matrix of the same type and size as src (for dst)
    dst.create( src.size(), src.type() );

    /// Convert the image to grayscale
    cvtColor( src, src_gray, CV_BayerGR2GRAY );

    /// Create a window
    namedWindow( window_name, CV_WINDOW_AUTOSIZE );

    /// Create a Trackbar for user to enter threshold
    //createTrackbar( "Min Threshold:", window_name, &lowThreshold, max_lowThreshold, CannyThreshold );

    /// Show the image
    CannyThreshold(0, 0);

    /// Wait until user exit program by pressing a key
    waitKey(0);

    return ;
}
