#include "../include/example.h"

// For undistortion
static float cameraCalibrationdata[9] = {9.113812935295416e+02, 0.651033616843436, 6.644831723997970e+02, 0, 9.113086377881884e+02, 3.713670194501918e+02,  0, 0, 1};
static float distCoeffsCalibrationdata[5] = {-0.032436584225176, 0.087146504956371, -4.167775601669913e-04, -4.631801852683015e-04, -0.073076772853399};
cv::Mat camCalib = cv::Mat(3, 3, CV_32F, cameraCalibrationdata);
cv::Mat distCoef = cv::Mat(1, 5, CV_32F, distCoeffsCalibrationdata);

int main(int argc, char** argv ){
    // Open Video
    cv::VideoCapture cap;
    cap.open(0, cv::CAP_V4L2);
    if (!cap.isOpened()){ printf("Cannot open camera\n"); return -1;} 

    // Set up video parameters
    // cap.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('Y', 'U', 'Y', 'V'));   // Better resolution less fps (at least for my setup)
    cap.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'));      // More fps less resolution (at least for my setup)
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 1280);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 720);
    cap.set(cv::CAP_PROP_FPS, 30);
    int dWidth = cap.get(cv::CAP_PROP_FRAME_WIDTH); 
    int dHeight = cap.get(cv::CAP_PROP_FRAME_HEIGHT);
    int fps_counter = cap.get(cv::CAP_PROP_FPS);
    printf("After set, actual resolution of the video w:%d h:%d fps:%d\n", dWidth, dHeight, fps_counter); 

    // Create window and display image
    // cv::namedWindow("Display Image", cv::WINDOW_NORMAL );
    // cv::resizeWindow("Display Image", 1280, 720);

    cv::Mat img, Unimg;
    while(true){
        if (!cap.read(img)){printf("Input has disconnected\n"); break;}
        cv::imshow("Display Image", img);

        cv::undistort(img, Unimg, camCalib, distCoef);
        cv::imshow("Undistorted", Unimg);

        if (cv::waitKey(1) == 27){ printf("Esc key is pressed by user. Exit!\n"); break;}
    }
    return 0;
}