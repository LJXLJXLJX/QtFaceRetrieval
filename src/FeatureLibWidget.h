#pragma once
#include "ui_FeatureLibWidget.h"
#include <QtWidgets/qwidget.h>
#include "faceKits.h"
#include <qevent.h>



class FeatureLibWidget :public QWidget
{
	Q_OBJECT;
public:
	explicit FeatureLibWidget(QWidget *parent = Q_NULLPTR);
	
	faceKit *pfKit;	//ָ��w.fKit

private:
	Ui::FeatureLibWidgetClass uiFeaLibWid;
	void updateFeatureTable();

	void closeEvent(QCloseEvent *event);

	int itemNum;	//��Ŀ�����˴�һ����һ����Ŀ��
	private slots:

	void on_pushButton_deleteFeature_clicked();

};