#include "faceKits.h"
#ifdef _DEBUG
#include <qdebug.h>
#include <iostream>

#endif

using namespace std;
using namespace cv;
using namespace seeta;

faceKit::faceKit()
	:faceDetectorModel("../models/haarcascade_frontalface_alt.xml"),
	drawRectOnFrame(true), facesCascade(), face(), featureLib(), localFace(),
	threshold(0.5),
	detector(new seeta::FaceDetection("../models/seeta_fd_frontal_v1.0.bin")),
	point_detector(new seeta::FaceAlignment("../models/seeta_fa_v1.1.bin")),
	face_recognizer(new seeta::FaceIdentification("../models/seeta_fr_v1.0.bin"))
{
}

void faceKit::detectFace(cv::Mat & frame, cv::Mat & face)
{
	if (!facesCascade.load(faceDetectorModel))
	{
		cout << "face cascade model loading failed!!!" << endl;
		return;
	}
	vector<cv::Rect> faceRects;
	Mat frame_gray;
	cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);
	facesCascade.detectMultiScale(frame_gray, faceRects, 1.1, 3, 0 | CV_HAAR_SCALE_IMAGE, Size(20, 20));
	cv::Rect largestRoi(0, 0, 0, 0);	//choose the biggest face
	for (size_t i = 0; i < faceRects.size(); i++)
	{
		if (drawRectOnFrame)
			rectangle(frame, faceRects[i], Scalar(255, 255, 255), 1, 8);
		if (faceRects[i].width > largestRoi.width)
			largestRoi = faceRects[i];
	}
	face = frame(largestRoi);
}

void faceKit::addToFeatureLib(const string & name, const cv::Mat img)
{
	std::string filePath = "../data/featureLib/";
	filePath += name;
	float feature[2048];
	extractFeature(img, feature);
	FILE *file;
	file = fopen(filePath.c_str(), "wb");
	fwrite(feature, sizeof(float), 2048, file);
	fclose(file);
	//每次添加新成员要及时更新RAM中的特征库
	for (int i = 0; i < 2048; i++)
		this->featureLib[name][i] = feature[i];
}

void faceKit::loadFromFeatureLib()
{
	string featurePath = "../data/featureLib/";
	vector<string> files;
	getFiles(featurePath, files);
	for (string filename : files)
	{
		FILE *in;
		in = fopen((featurePath + filename).c_str(), "rb");
		float feature[2048];
		fread(feature, sizeof(float), 2048, in);
		fclose(in);
		for (int i = 0; i < 2048; i++)
			this->featureLib[filename][i] = feature[i];
	}
}

string faceKit::faceRetrieval(const cv::Mat & face)
{
	
	double maxSim = 0.0;
	string predictPeople = "";
	float feature1[2048];
	extractFeature(face, feature1);


#ifdef _DEBUG
	for (float i : feature1)
		std::cout << i << " ";
	std::cout << std::endl;
#endif // _DEBUG




	for (map<string, float[2048]>::iterator it = featureLib.begin(); it != featureLib.end(); it++)
	{
		float sim = face_recognizer->CalcSimilarity(feature1, it->second);
#ifdef _DEBUG
		qDebug() <<  QString::fromLocal8Bit((it->first).c_str()) << sim << "\n";
#endif
		if (sim > threshold &&sim > maxSim)
		{
			maxSim = sim;
			predictPeople = it->first;
		}
	}
#ifdef _DEBUG
	 qDebug()<<"max:"<< maxSim << "\n";
#endif
	return predictPeople;
}

bool faceKit::isFeatureLibEmpty()
{
	if (featureLib.empty())
		return true;
	else
		return false;
}

//参数img应该为BGR格式
void faceKit::extractFeature(const cv::Mat & img, float * const feature)
{
#ifdef _DEBUG
	


	//std::cout << cv::format(img,"python")<< endl;

#endif // _DEBUG
	detector->SetMinFaceSize(40);
	detector->SetScoreThresh(2.f);
	detector->SetImagePyramidScaleFactor(0.8f);
	detector->SetWindowStep(4, 4);

	cv::Mat img_gray;
	cv::cvtColor(img, img_gray, CV_BGR2GRAY);

	ImageData img_data_color(img.cols, img.rows, img.channels());
	img_data_color.data = img.data;
	ImageData img_data_gray(img_gray.cols, img_gray.rows, img_gray.channels());
	img_data_gray.data = img_gray.data;
	// Detect faces
	std::vector<seeta::FaceInfo> faces = detector->Detect(img_data_gray);
	int32_t face_num = static_cast<int32_t>(faces.size());

	if (face_num == 0)
	{
		std::cout << "Faces are not detected.";
		return;
	}
	// Detect 5 facial landmarks
	seeta::FacialLandmark points[5];
	point_detector->PointDetectLandmarks(img_data_gray, faces[0], points);
	face_recognizer->ExtractFeatureWithCrop(img_data_color, points, feature);


#ifdef _DEBUG
	/*for (int i=0;i++;i<2048)
		std::cout << feature[1] << endl;*/

#endif // _DEBUG
}
