#include "../include/example.h"

using namespace cv;

int main(int argc, char** argv ){
    // Read Image
    Mat img = imread( "OpenCV-logo.png", 1 );
    
    // Check that image has data
    if ( !img.data ){
        printf("No image data \n");
        return -1;
    }

    // Create window and display image
    namedWindow("Display Image", WINDOW_NORMAL );
    resizeWindow("Display Image", 800, 600);
    imshow("Display Image", img);
    waitKey(0);

    return 0;
}