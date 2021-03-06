//=================================================================================================
// Copyright (c) 2011, Paul Filitchkin
// All rights reserved.

// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of the UCSB Robotics Lab nor the
//       names of its contributors may be used to endorse or promote products
//       derived from this software without specific prior written permission.

// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL PAUL FILITCHKIN BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//=================================================================================================

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv/cvwimage.h>
#include <opencv/highgui.h>
#include <opencv/cv.h>


#if ROS_VERSION_MINIMUM(1, 9, 0)
  // new cv_bridge API in Groovy
  #include <cv_bridge/cv_bridge.h>
  #include <sensor_msgs/image_encodings.h>
#else
  // Fuerte support for cv_bridge will be deprecated
  #if defined(__GNUC__)
    #warning "Support for the old cv_bridge API (Fuerte) is derecated and will be removed when Hydro is released."
  #endif
  #include <cv_bridge/CvBridge.h>
#endif

#if ROS_VERSION_MINIMUM(1, 9, 0)
    cv_bridge::CvImagePtr capture_;
#else
    IplImage *capture_;
#endif

using namespace cv;
using namespace std;

//=================================================================================================
//=================================================================================================
int main (int argc, char **argv)
{
/*
  ros::init(argc, argv, "image_publisher");
  ros::NodeHandle nh;
  image_transport::ImageTransport it(nh);
  string pubName = argv[2];
  pubName.append("/image");
  image_transport::Publisher pub = it.advertise(pubName, 1);

  VideoCapture cap; // open the camera
  string videoStreamAddress = argv[1];
  videoStreamAddress.append("?.mjpg");

  if (!cap.open(videoStreamAddress)) {
 	 std::cout << videoStreamAddress << "Error opening video stream or file" << std::endl;
       return -1;
  }

  unsigned int CAPTURE_WIDTH = 640;
  unsigned int CAPTURE_HEIGHT = 480;
  const string& cvOutputWindowName = "CV Output";

  CAPTURE_WIDTH = cap.get(CV_CAP_PROP_FRAME_WIDTH);
  CAPTURE_HEIGHT = cap.get(CV_CAP_PROP_FRAME_HEIGHT);

  // check if we succeeded // Double Check
  if ( !cap.isOpened() )
  {
    cout << videoStreamAddress << "Could not open capture device\n";
    return -1;
  }

  Mat frame;
  ros::Rate loop_rate(5);
  cv_bridge::CvImagePtr cv_ptr;

  while (nh.ok())
  {
   // cap >> frame; // get a new frame from camera
    cap.read(frame);
    IplImage frm = _IplImage(frame); //Unfortunately must convert to old format

#if ROS_VERSION_MINIMUM(1, 9, 0)
    try
    {
      capture_ = cv_bridge::toCvCopy (&frm, sensor_msgs::image_encodings::BGR8);
    }
    catch (cv_bridge::Exception& e)
    {
      ROS_ERROR("cv_bridge exception: %s", e.what());
    }
    cv_ptr = ((IplImage) capture_->image).imageData;
#else
    try
    {
      capture_ = bridge_.imgMsgToCv (image_msg, "bgr8");
    }
    catch (sensor_msgs::CvBridgeException & e)
    {
      ROS_ERROR("cv_bridge exception: %s", e.what());
    }
    cv_ptr = capture_->imageData;
#endif


    pub.publish(cv_ptr->toImageMsg());
    ros::spinOnce();
    loop_rate.sleep();
  }*/
}
