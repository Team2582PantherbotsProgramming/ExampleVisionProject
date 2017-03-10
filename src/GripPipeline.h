#pragma once
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/contrib/contrib.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/features2d.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <vector>
#include <string>
#include <math.h>
#include <Timer.h>
#include <CameraServer.h>

namespace grip {

//
enum class Target
{
	kPeg,
	kBoiler
};

// Summary:
//
struct CameraStuff
{
	double targetHeight;
	double angle;
	Target target;

	CameraStuff(double height, double angle, Target target)
	{
		targetHeight = height;
		this->angle = angle;
		this->target = target;
	}

	CameraStuff()
	{
		targetHeight = 0;
		this->angle = 0;
		this->target = Target::kPeg;
	}
};

#define BOILER grip::CameraStuff(CS_TARGET_BOILER_HEIGHT, CS_CAM2_HORIZON_ANGLE, grip::Target::kBoiler)
#define PEG	grip::CameraStuff(CS_TARGET_PEG_HEIGHT, CS_CAM1_HORIZON_ANGLE, grip::Target::kPeg)

class GripPipeline
{
	private:
		cv::Mat resizeImageOutput;
		cv::Mat hslThresholdOutput;
		std::vector<std::vector<cv::Point> > findContoursOutput;
		std::vector<std::vector<cv::Point> > filterContoursOutput;
		std::vector<cv::Rect> targets;
		frc::Timer* timer;
		double procTime;
		CameraStuff stuff;
		void findContours(cv::Mat&, bool, std::vector<std::vector<cv::Point> >&);
		void filterContours(
				std::vector<std::vector<cv::Point> >& inputContours,
				const double minArea,
				const double minPerimeter,
				const double minWidth,
				const double maxWidth,
				const double minHeight,
				const double maxHeight,
				const double solidity[],
				const double maxVertexCount,
				const double minVertexCount,
				const double minRatio,
				const double maxRatio,
				std::vector<std::vector<cv::Point> >& output);
		double getOffsetCenter(double, double);

	public:
		GripPipeline();
		void Process(cv::Mat source);
		bool getTarget(int, cv::Rect&);
		double getTargetCenterX(int);
		double getTargetCenterY(int);
		double getProcTime();
		double getDistance();

		int getTargets() { return targets.size(); }

		void setStuff(grip::CameraStuff cs);
};


} // end namespace grip


