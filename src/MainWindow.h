#pragma once
#include <opencv.hpp>
#include <QtWidgets/QMainWindow>
#include <qevent.h>
#include <memory>



#include "ui_MainWindow.h"
#include "FeatureLibWidget.h"
#include "RecordWidget.h"
#include "faceKits.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = Q_NULLPTR);
private:
	QImage Mat2QImage(cv::Mat cvImg);

	Ui::MainWindowClass uiMainWin;
	std::unique_ptr<FeatureLibWidget>pfeaLibWid;
	std::unique_ptr<RecordWidget> precWid;
	
	cv::Mat frame;
	cv::VideoCapture capture;
	QImage image;
	QTimer *timer;
	cv::VideoWriter writer;	//make a video record
	faceKit fKit;
	int faceSource;	//当前待处理人脸来源 1摄像头 2本地
	
	void closeEvent(QCloseEvent *event);


	private slots:
	void on_pushButton_open_clicked();
	void on_pushButton_camera_clicked();
	void on_pushButton_addToLib_clicked();
	void on_pushButton_retrieval_clicked();
	void on_pushButton_detectFace_clicked();
	void on_action_threshold_triggered();
	void on_action_manageFeatureLib_triggered();
	void on_action_lookupRecord_triggered();
	void nextFrame();
	
};

