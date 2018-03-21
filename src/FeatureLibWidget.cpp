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


//更新(初始化)表
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
	//每一行会选中两个对象 所以要i+=2否则会删除两次 报错
	for (int i = 0; i < selectItems.size(); i += 2)
	{
		QString name= selectItems[i]->text();	//在删除之前先获取文本 否则就访问已删除内存了。。。
		std::string path = "../data/featureLib/" + name.toLocal8Bit();
		remove(path.c_str());	//删除本地文件
		pfKit->featureLib.erase((std::string)name.toLocal8Bit());	
		uiFeaLibWid.tableWidget->removeRow(selectItems[i]->row());//删除表中内容
		itemNum--;
	}
}
