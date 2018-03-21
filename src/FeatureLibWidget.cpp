#include "FeatureLibWidget.h"

#include "MainWindow.h"
#include "utils.h"
#include <qdebug.h>
#include <qfileinfo.h>
#include <qdatetime.h>

FeatureLibWidget::FeatureLibWidget(QWidget * parent) :
	QWidget(parent),itemNum(0),pfKit(nullptr)
{
	uiFeaLibWid.setupUi(this);
	updateFeatureTable();


}


//����(��ʼ��)��
void FeatureLibWidget::updateFeatureTable()
{
	std::string libPath = "../data/featureLib/";
	std::vector<std::string>files;
	getFiles(libPath, files);

	for (std::string file : files)
	{
		QTableWidgetItem *item1 = new QTableWidgetItem(QString::fromLocal8Bit(file.c_str()));
		QFileInfo fileInfo(QString::fromLocal8Bit((libPath + file).c_str()));
		QDateTime lastMdTime = fileInfo.lastModified();
		QString timeStr = lastMdTime.toString(QString::fromLocal8Bit("yyyy-MM-dd ddd hh:mm:ss"));
		QTableWidgetItem *item2 = new QTableWidgetItem(timeStr);

		uiFeaLibWid.tableWidget->setRowCount(itemNum + 1);
		uiFeaLibWid.tableWidget->setItem(itemNum, 0, item1);
		uiFeaLibWid.tableWidget->setItem(itemNum, 1, item2);
		++itemNum;
	}
}

void FeatureLibWidget::closeEvent(QCloseEvent * event)
{
	//delete this;
}

void FeatureLibWidget::on_pushButton_deleteFeature_clicked()
{
	QList<QTableWidgetItem*> selectItems = uiFeaLibWid.tableWidget->selectedItems();
	//ÿһ�л�ѡ���������� ����Ҫi+=2�����ɾ������ ����
	for (int i = 0; i < selectItems.size(); i += 2)
	{
		QString name= selectItems[i]->text();	//��ɾ��֮ǰ�Ȼ�ȡ�ı� ����ͷ�����ɾ���ڴ��ˡ�����
		std::string path = "../data/featureLib/" + name.toLocal8Bit();
		remove(path.c_str());	//ɾ�������ļ�
		pfKit->featureLib.erase((std::string)name.toLocal8Bit());	
		uiFeaLibWid.tableWidget->removeRow(selectItems[i]->row());//ɾ����������
		itemNum--;
	}
}
