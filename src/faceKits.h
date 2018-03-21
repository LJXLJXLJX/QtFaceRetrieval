#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#include <opencv/cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>


#include "face_identification.h"
#include "recognizer.h"
#include "face_detection.h"
#include "face_alignment.h"
#include "math_functions.h"
#include "utils.h"

class faceKit {
public:
	faceKit();
	void detectFace(cv::Mat &frame, cv::Mat &face);
	cv::Mat face;
	cv::Mat localFace;
	void addToFeatureLib(const std::string &name, const cv::Mat img);
	void loadFromFeatureLib();
	std::string faceRetrieval(const cv::Mat &face);
	bool isFeatureLibEmpty();
	double threshold;
	std::map<std::string, float[2048]> featureLib;

private:
	std::string faceDetectorModel;
	cv::CascadeClassifier facesCascade;
	bool drawRectOnFrame;	//if true , draw rectangle around the face on the frame.
	seeta::FaceDetection *detector;
	seeta::FaceAlignment *point_detector;
	seeta::FaceIdentification *face_recognizer;
	
	
	void extractFeature(const cv::Mat &img, float* const feature);
};