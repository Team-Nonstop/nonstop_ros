/*
 * webcam_adaptor.cpp
 *
 *  Created on: 2013. 4. 19.
 *      Author: richu
 */


#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <iostream>


int main (int argc, char *argv[])
{
     cv::VideoCapture vcap;
     cv::Mat image;

     std::string videoStreamAddress = argv[1];
     videoStreamAddress.append("?.mjpg");

     if (!vcap.open(videoStreamAddress)) {
    	 std::cout << "Error opening video stream or file" << std::endl;
          return -1;
     }

     for(;;) {
          if(!vcap.read(image)) {
               std::cout << "No frame" << std::endl;
               cv::waitKey();
          }
          imshow("Output Window", image);
          if(cv::waitKey(1) >= 0) break;
     }
     return 0;
}


