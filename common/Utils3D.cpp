#include "Utils3D.h"

JOINT3D copyTrkToJoint(const vrpn_TRACKERCB src, JOINT3D dis) {
	dis.x = src.pos[0];
	dis.y = src.pos[1];
	dis.z = src.pos[2];
	//dis.a = src.quat[0];
	//dis.b = src.quat[1];
	//dis.c = src.quat[2];
	//dis.d = src.quat[3];
	return dis;
}

double getDistanceAbs(double a, double b) {
	double c = abs(a - b);
	return c;
}

Squelette3D copySqlt2Sqlt(Squelette3D current, Squelette3D previous) {

	previous.SpineBase = current.SpineBase;
	previous.SpineMid = current.SpineMid;
	previous.Neck = current.Neck;
	previous.head = current.head;
	previous.ShoulderLeft = current.ShoulderLeft;

	previous.ElbowLeft = current.ElbowLeft;
	previous.WristLeft = current.WristLeft;
	previous.HandLeft = current.HandLeft;
	previous.ShoulderRight = current.ShoulderRight;
	previous.ElbowRight = current.ElbowRight;

	previous.WristRight = current.WristRight;
	previous.HandRight = current.HandRight;
	previous.HipLeft = current.HipLeft;
	previous.KneeLeft = current.KneeLeft;
	previous.AnkleLeft = current.AnkleLeft;

	previous.FootLeft = current.FootLeft;
	previous.HipRight = current.HipRight;
	previous.KneeRight = current.KneeRight;
	previous.AnkleRight = current.AnkleRight;
	previous.FootRight = current.FootRight;

	previous.SpineShoulder = current.SpineShoulder;
	previous.HandTipLeft = current.HandTipLeft;
	previous.ThumbLeft = current.ThumbLeft;
	previous.HandTipRight = current.HandTipRight;
	previous.ThumbRight = current.ThumbRight;

	////
	//previous.SpineBaseORIENT = current.SpineBaseORIENT;
	//previous.SpineMidORIENT = current.SpineMidORIENT;
	//previous.NeckORIENT = current.NeckORIENT;
	//previous.headORIENT = current.headORIENT;
	//previous.ShoulderLeftORIENT = current.ShoulderLeftORIENT;

	//previous.ElbowLeftORIENT = current.ElbowLeftORIENT;
	//previous.WristLeftORIENT = current.WristLeftORIENT;
	//previous.HandLeftORIENT = current.HandLeftORIENT;
	//previous.ShoulderRightORIENT = current.ShoulderRightORIENT;
	//previous.ElbowRightORIENT = current.ElbowRightORIENT;

	//previous.WristRightORIENT = current.WristRightORIENT;
	//previous.HandRightORIENT = current.HandRightORIENT;
	//previous.HipLeftORIENT = current.HipLeftORIENT;
	//previous.KneeLeftORIENT = current.KneeLeftORIENT;
	//previous.AnkleLeftORIENT = current.AnkleLeftORIENT;

	//previous.FootLeftORIENT = current.FootLeftORIENT;
	//previous.HipRightORIENT = current.HipRightORIENT;
	//previous.KneeRightORIENT = current.KneeRightORIENT;
	//previous.AnkleRightORIENT = current.AnkleRightORIENT;
	//previous.FootRightORIENT = current.FootRightORIENT;

	//previous.SpineShoulderORIENT = current.SpineShoulderORIENT;
	//previous.HandTipLeftORIENT = current.HandTipLeftORIENT;
	//previous.ThumbLeftORIENT = current.ThumbLeftORIENT;
	//previous.HandTipRightORIENT = current.HandTipRightORIENT;
	//previous.ThumbRightORIENT = current.ThumbRightORIENT;
	return previous;
}