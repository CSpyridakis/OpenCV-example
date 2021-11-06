#include "../include/example.h"

int main(int argc, char** argv ){
    // Open Video
    cv::VideoCapture cap;
    cap.open(0, cv::CAP_V4L2);
    if (!cap.isOpened()){ printf("Cannot open camera\n"); return -1;} 

    // Set up video parameters
    // cap.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('Y', 'U', 'Y', 'V'));   // Better resolution less fps (at least for my setup)
    cap.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'));      // More fps less resolution (at least for my setup)
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 1920);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 1080);
    cap.set(cv::CAP_PROP_FPS, 30);
    int dWidth = cap.get(cv::CAP_PROP_FRAME_WIDTH); 
    int dHeight = cap.get(cv::CAP_PROP_FRAME_HEIGHT);
    int fps_counter = cap.get(cv::CAP_PROP_FPS);
    printf("After set, actual resolution of the video w:%d h:%d fps:%d\n", dWidth, dHeight, fps_counter); 

    // Create window and display image
    cv::namedWindow("Display Image", cv::WINDOW_NORMAL );
    cv::resizeWindow("Display Image", 1280, 720);

    cv::Mat img;
    while(true){
        if (!cap.read(img)){printf("Input has disconnected\n"); break;}
        cv::imshow("Display Image", img);
        if (cv::waitKey(1) == 27){ printf("Esc key is pressed by user. Exit!\n"); break;}
    }
    return 0;
}