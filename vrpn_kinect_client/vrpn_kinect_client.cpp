#include "vrpn_Tracker.h"
#include <iostream>
#include <shellapi.h>
#include "vrpn_kinect_client.h"
#include "Utils3D.h"
using std::cout;
using std::cin;
using std::endl;

int currentsqltTracked = 0;
int previousIndexJoint = -1;

Squelette3D currentSqlt3DTrk0;
Squelette3D prviousSqlt3DTrk0;

int roundindex = 0;
int OPENPAINT = 0;

int insertJoindInSqletton(vrpn_TRACKERCB b) {

	switch (b.sensor) {
	case (0): currentSqlt3DTrk0.SpineBase = copyTrkToJoint(b, currentSqlt3DTrk0.SpineBase); break;
	case (1): currentSqlt3DTrk0.SpineMid = copyTrkToJoint(b, currentSqlt3DTrk0.SpineMid);break;
	case (2): currentSqlt3DTrk0.Neck = copyTrkToJoint(b, currentSqlt3DTrk0.Neck);break;
	case (3): currentSqlt3DTrk0.head = copyTrkToJoint(b, currentSqlt3DTrk0.head);break;
	case (4): currentSqlt3DTrk0.ShoulderLeft = copyTrkToJoint(b, currentSqlt3DTrk0.ShoulderLeft);break;
	case (5): currentSqlt3DTrk0.ElbowLeft = copyTrkToJoint(b, currentSqlt3DTrk0.ElbowLeft);break;
	case (6): currentSqlt3DTrk0.WristLeft = copyTrkToJoint(b, currentSqlt3DTrk0.WristLeft);break;
	case (7): currentSqlt3DTrk0.HandLeft = copyTrkToJoint(b, currentSqlt3DTrk0.HandLeft);break;
	case (8): currentSqlt3DTrk0.ShoulderRight = copyTrkToJoint(b, currentSqlt3DTrk0.ShoulderRight);break;
	case (9): currentSqlt3DTrk0.ElbowRight = copyTrkToJoint(b, currentSqlt3DTrk0.ElbowRight);break;
	case (10): currentSqlt3DTrk0.WristRight = copyTrkToJoint(b, currentSqlt3DTrk0.WristRight);break;
	case (11): currentSqlt3DTrk0.HandRight = copyTrkToJoint(b, currentSqlt3DTrk0.HandRight);break;
	case (12): currentSqlt3DTrk0.HipLeft = copyTrkToJoint(b, currentSqlt3DTrk0.HipLeft);break;
	case (13): currentSqlt3DTrk0.KneeLeft = copyTrkToJoint(b, currentSqlt3DTrk0.KneeLeft);break;
	case (14): currentSqlt3DTrk0.AnkleLeft = copyTrkToJoint(b, currentSqlt3DTrk0.AnkleLeft);break;
	case (15): currentSqlt3DTrk0.FootLeft = copyTrkToJoint(b, currentSqlt3DTrk0.FootLeft);break;
	case (16): currentSqlt3DTrk0.HipRight = copyTrkToJoint(b, currentSqlt3DTrk0.HipRight);break;
	case (17): currentSqlt3DTrk0.KneeRight = copyTrkToJoint(b, currentSqlt3DTrk0.KneeRight);break;
	case (18): currentSqlt3DTrk0.AnkleRight = copyTrkToJoint(b, currentSqlt3DTrk0.AnkleRight);break;
	case (19): currentSqlt3DTrk0.FootRight = copyTrkToJoint(b, currentSqlt3DTrk0.FootRight);break;
	case (20): currentSqlt3DTrk0.SpineShoulder = copyTrkToJoint(b, currentSqlt3DTrk0.SpineShoulder);break;
	case (21): currentSqlt3DTrk0.HandTipLeft = copyTrkToJoint(b, currentSqlt3DTrk0.HandTipLeft);break;
	case (22): currentSqlt3DTrk0.ThumbLeft = copyTrkToJoint(b, currentSqlt3DTrk0.ThumbLeft);break;
	case (23): currentSqlt3DTrk0.HandTipRight = copyTrkToJoint(b, currentSqlt3DTrk0.HandTipRight);break;
	case (24): currentSqlt3DTrk0.ThumbRight = copyTrkToJoint(b, currentSqlt3DTrk0.ThumbRight);break;
	default: printf("Error of Joint Index");break;
	}

	return(b.sensor);
}

void VRPN_CALLBACK handle_tracker(void* userData, const vrpn_TRACKERCB b)
{
	//cout << "|" << currentsqltTracked << "  ";
	//cout << previousIndexJoint << "|" << "  ";
	if (currentsqltTracked == 0) {
		if (previousIndexJoint <= b.sensor) {
			previousIndexJoint = b.sensor;
			insertJoindInSqletton(b);
			copyTrkToJoint(b, currentSqlt3DTrk0.SpineBase);
			//cout << currentSqlt3DTrk0.SpineBase.x << endl;
		}
		else {
			//cout << endl;
			currentsqltTracked = 1;
			//TO DO GESTURAL DETECTION
			//cout << "|" << currentSqlt3DTrk0.HandLeft.y << ", " << currentSqlt3DTrk0.head.y << "|" << endl;
			if (prviousSqlt3DTrk0.HandLeft.y < prviousSqlt3DTrk0.ShoulderLeft.y && currentSqlt3DTrk0.HandLeft.y > currentSqlt3DTrk0.ShoulderRight.y) {
				cout << "Left Hand is putting up." << endl;
			}
			else if (prviousSqlt3DTrk0.HandLeft.y > prviousSqlt3DTrk0.ShoulderLeft.y && currentSqlt3DTrk0.HandLeft.y < currentSqlt3DTrk0.ShoulderRight.y) {
				cout << "Left Hand lowered." << endl;
			}
			//else {}
			
			if (prviousSqlt3DTrk0.HandRight.y < prviousSqlt3DTrk0.ShoulderRight.y && currentSqlt3DTrk0.HandRight.y > currentSqlt3DTrk0.ShoulderRight.y) {
				cout << "Right Hand is putting up." << endl;
			}
			else if (prviousSqlt3DTrk0.HandRight.y > prviousSqlt3DTrk0.ShoulderRight.y && currentSqlt3DTrk0.HandRight.y < currentSqlt3DTrk0.ShoulderRight.y) {
				cout << "Right Hand lowered." << endl;
			}
			//else {}
			double absCurrentHandDistanceY = getDistanceAbs(currentSqlt3DTrk0.HandRight.y, currentSqlt3DTrk0.HandLeft.y);
			double absCurrentHandDistanceX = getDistanceAbs(currentSqlt3DTrk0.HandRight.x, currentSqlt3DTrk0.HandLeft.x);
			double absPreviousHandDistanceY = getDistanceAbs(prviousSqlt3DTrk0.HandRight.y, prviousSqlt3DTrk0.HandLeft.y);
			double absPreviousHandDistanceX = getDistanceAbs(prviousSqlt3DTrk0.HandRight.x, prviousSqlt3DTrk0.HandLeft.x);
			double absCurrentHandDistanceZ = getDistanceAbs(currentSqlt3DTrk0.HandRight.z, currentSqlt3DTrk0.HandLeft.z);
			double absPreviousHandDistanceZ = getDistanceAbs(prviousSqlt3DTrk0.HandRight.z, prviousSqlt3DTrk0.HandLeft.z);
			if (absPreviousHandDistanceX > absCurrentHandDistanceX + 0.1 //&& absPreviousHandDistanceY > 0.3 && absPreviousHandDistanceZ > 0.3
				&& absCurrentHandDistanceX < 0.1 && absCurrentHandDistanceY< 0.1 && absCurrentHandDistanceZ < 0.1) {
				cout << "Clapping." << endl;
			}

		}
	}
	else if (currentsqltTracked == 1) {
		insertJoindInSqletton(b);
		previousIndexJoint = b.sensor;
		currentsqltTracked = 0;
		prviousSqlt3DTrk0 = copySqlt2Sqlt(currentSqlt3DTrk0,prviousSqlt3DTrk0);
	}
	
}

int main(int argc, char* argv[])
{
	vrpn_Tracker_Remote* vrpnTracker = new vrpn_Tracker_Remote("Tracker0@localhost:3883");//Changer en local

	vrpnTracker->register_change_handler(0, handle_tracker);
	while (1)
	{
		vrpnTracker->mainloop();
		Sleep(100);
		roundindex++;
	}

	return 0;
}