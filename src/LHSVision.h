/*
 * LHSVision.h
 *
 *  Created on: Jan 25, 2016
 *      Author: Michael Conard
 */

#ifndef LHS_VISION_H
#define LHS_VISION_H

//#include "Robot.h"


class LHSVision
{
public:
	LHSVision(); //Constructor
	void SendToDashboard(Image*); //Send Image to Dashboard
	void UpdateVision(bool photoeyeTrue);	//Toggle and Display Camera
	void StartCamera(bool camEnable);	//Start/stop Specified Camera

private:
	IMAQdxSession session;
	Image* frame;

//	IMAQdxSession session2;
//	Image* frame2;

	int send = 1;
};

#endif
