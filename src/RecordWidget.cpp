#include "RecordWidget.h"
#include <fstream>
#include <sstream>
#include <qdebug.h>





RecordWidget::RecordWidget(QWidget * parent):
	QWidget(parent), itemNum(0)
{
	uiRecWid.setupUi(this);
	updateRecordTable();
	connect(uiRecWid.tableWidget, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(showImage()));
}

void RecordWidget::updateRecordTable()
{
	std::string recPath = "../data/records/All.txt";
	std::ifstream in(recPath);
	while (1)
	{
		std::string line, name, data, series;
		std::getline(in, line);
		std::stringstream word(line);
		word >> name >> data >> series;
		QTableWidgetItem* nameItem = new QTableWidgetItem(QString::fromLocal8Bit(name.c_str()));
		QTableWidgetItem* seriesItem = new QTableWidgetItem(QString::fromLocal8Bit(series.c_str()));
		QTableWidgetItem* dataItem = new QTableWidgetItem(QString::fromLocal8Bit(data.c_str()));
		
		uiRecWid.tableWidget->setRowCount(itemNum + 1);
		uiRecWid.tableWidget->setItem(itemNum, 0, nameItem);
		uiRecWid.tableWidget->setItem(itemNum, 1, seriesItem);
		uiRecWid.tableWidget->setItem(itemNum, 2, dataItem);
		++itemNum;
		
		if (line.size() == 0)
			break;
	}
}

QImage RecordWidget::Mat2QImage(cv::Mat cvImg)
{
	QImage qImg;
	if (cvImg.channels() == 3)                             //3 channels color image
	{

		cv::cvtColor(cvImg, cvImg, CV_BGR2RGB);
		qImg = QImage((const unsigned char*)(cvImg.data),
			cvImg.cols, cvImg.rows, cvImg.step,
			QImage::Format_RGB888);
	}
	else if (cvImg.channels() == 1)                    //grayscale image
	{
		qImg = QImage((const unsigned char*)(cvImg.data),
			cvImg.cols, cvImg.rows, cvImg.step,
			QImage::Format_Indexed8);
	}
	else
	{
		qImg = QImage((const unsigned char*)(cvImg.data),
			cvImg.cols, cvImg.rows, cvImg.step,
			QImage::Format_RGB888);
	}
	return qImg;
}

void RecordWidget::showImage()
{
	QList<QTableWidgetItem*> selectItems = uiRecWid.tableWidget->selectedItems();
	QString series = selectItems[1]->text();
	std::string path =   "../data/records/face/"+  series.toLocal8Bit()+".bmp";


	cv::Mat face = cv::imread(path);
	QImage qface = Mat2QImage(face);
	uiRecWid.label_faceViewer->setScaledContents(true);
	uiRecWid.label_faceViewer->setPixmap(QPixmap::fromImage(qface));
}
