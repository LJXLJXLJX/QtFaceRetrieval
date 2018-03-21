#pragma once
#include "ui_RecordWidget.h"
#include <opencv.hpp>

class RecordWidget :public QWidget
{
	Q_OBJECT;
public:
	RecordWidget(QWidget *parent = Q_NULLPTR);
private:
	Ui::RecordWidgetClass uiRecWid;
	void updateRecordTable();
	int itemNum;	//һ����һ����Ŀ



private slots:
	void showImage();
	QImage Mat2QImage(cv::Mat cvImg);
};