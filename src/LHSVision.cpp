/*
 * LHSVision.cpp
 *
 *  Created on: Jan 26, 2016
 *      Author: Michael Conard
 *
 *  THING TO CHECK:
 *  	-In Internet Explorer, roborio-4237-frc.local,
 *  	 confirm the camera names in Silverlight. These
 *  	 should be "cam0", "cam1", or "cam2".
 *
 *  	-These names can be adjusted in the CAMERA
 *  	 namespace.
 */

#include "WPILib.h"
#include "LHSVision.h"

namespace CAMERA	//Camera Names
{
	const char* CAM_ONE = "cam1";
	const char* CAM_TWO = "cam2";
}

//NOTE: Camera 1 is the default camera. Can toggle to 2 later.
LHSVision::LHSVision() //Constructor
{

	frame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
	IMAQdxOpenCamera(CAMERA::CAM_ONE, IMAQdxCameraControlModeController, &session);
	Wait(.5);
	IMAQdxConfigureGrab(session);
	Wait(.5);
	IMAQdxStartAcquisition(session);
	Wait(.5);

	//frame2 = imaqCreateImage(IMAQ_IMAGE_RGB, 0);

}

//Used for opening, configuring, and starting acquisition of a camera
void LHSVision::StartCamera(bool camEnable)
{
	if(camEnable) //Camera 1 Startup
	{
		IMAQdxOpenCamera(CAMERA::CAM_ONE, IMAQdxCameraControlModeController, &session);
		Wait(.01);
		IMAQdxConfigureGrab(session);
		Wait(.01);
		IMAQdxStartAcquisition(session);
		Wait(.01);
	}else{
		IMAQdxStopAcquisition(session);
		Wait(.01);
		IMAQdxCloseCamera(session);
	}
//	else			//Camera 2 Startup
//	{
//		IMAQdxOpenCamera(CAMERA::CAM_TWO, IMAQdxCameraControlModeController, &session2);
//		Wait(.01);
//		IMAQdxConfigureGrab(session2);
//		Wait(.01);
//		IMAQdxStartAcquisition(session2);
//		Wait(.01);
//	}
}

//Send image to FRC PC Dashboard
void LHSVision::SendToDashboard(Image *image)
{
	CameraServer::GetInstance()->SetImage(image);
}

void LHSVision::UpdateVision(bool photoeyeTrue) //by Michael
{
	if(photoeyeTrue)	//Toggle on A button press
	{
		StartCamera(false);
	}else{
		StartCamera(true);
		IMAQdxGrab(session, frame, true, NULL);
		SendToDashboard(frame);		//Send Cam 1
		Wait(.1);
	}

//	if(send == 1)
//	{
//		IMAQdxGrab(session, frame, true, NULL);
//		SendToDashboard(frame);		//Send Cam 1
//		Wait(.1);
//	}
//	else
//	{
//		IMAQdxGrab(session2, frame2, true, NULL);
//		SendToDashboard(frame2);	//Send Cam 2
//		Wait(.1);
//	}
}




