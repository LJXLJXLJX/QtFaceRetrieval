#include "MainWindow.h"
#include <qfiledialog.h>
#include <qinputdialog.h>
#include <qtimer.h>
#include <qmessagebox.h>
#include <qtabwidget.h>
#include <time.h>
#include <fstream>

#ifdef _DEBUG
#include <qdebug.h>
#endif

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent), fKit(), faceSource(-1), pfeaLibWid(nullptr), precWid(nullptr)
{
	uiMainWin.setupUi(this);



	//this->setFixedSize(1000, 630);
	uiMainWin.pushButton_detectFace->hide();
	uiMainWin.videoViewer->setScaledContents(true);	//fit video to videoViewer area
	connect(uiMainWin.pushButton_exit, SIGNAL(clicked()), this, SLOT(close()));




	//启动初始化，载入本地人脸特征库
	QMessageBox *loadFeatureMsgBox = new QMessageBox();
	loadFeatureMsgBox->setText(QString::fromLocal8Bit("第一次启动，载入本地人脸库特征数据中..."));
	loadFeatureMsgBox->setWindowTitle(QString::fromLocal8Bit("载入特征"));
	loadFeatureMsgBox->setStandardButtons(0);
	loadFeatureMsgBox->show();
	fKit.loadFromFeatureLib();
	loadFeatureMsgBox->close();
	delete loadFeatureMsgBox;
}

QImage MainWindow::Mat2QImage(cv::Mat cvImg)
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

void MainWindow::nextFrame()
{
	capture >> frame;

	if (!frame.empty())
	{
		fKit.detectFace(frame, fKit.face);
		cv::Mat frameClone = frame.clone();
		image = Mat2QImage(frameClone);

#ifdef _DEBUG
		if (fKit.face.rows > 0)
			cv::imshow("test", fKit.face);
#endif // _DEBUG

		uiMainWin.videoViewer->setPixmap(QPixmap::fromImage(image));
	}
}

void MainWindow::on_pushButton_open_clicked()
{
	uiMainWin.videoViewer->setScaledContents(false);
	fKit.localFace = 0;	//将上次缓存的localFace清除
	QString filename = QFileDialog::getOpenFileName(this, ("Open Image File"), ".", tr("Video Files(*.jpg *.bmp *.png)"));
	if (filename.isEmpty())
		return;
	QRect originGeo = uiMainWin.videoViewer->geometry();
	int h = originGeo.height();
	int w = h;
	int x = originGeo.left() + (originGeo.width() - h) / 2;
	int y = originGeo.top();
	uiMainWin.videoViewer->setGeometry(x, y, w, h);

	fKit.localFace = cv::imread(std::string(filename.toLocal8Bit()));
	cv::Mat face = fKit.localFace.clone();
	const QImage qface = Mat2QImage(face);
	uiMainWin.videoViewer->setPixmap(QPixmap::fromImage(qface));
	uiMainWin.pushButton_addToLib->setEnabled(true);
	uiMainWin.pushButton_retrieval->setEnabled(true);
	uiMainWin.pushButton_detectFace->show();
	faceSource = 2;
}


//关闭mainwindows之后应该关掉其他所有的窗口
void MainWindow::closeEvent(QCloseEvent *event)
{
	pfeaLibWid.reset();
	precWid.reset();
}

void MainWindow::on_pushButton_camera_clicked()
{
	uiMainWin.videoViewer->setScaledContents(true);
	//uiMainWin.videoViewer->setGeometry(QRect(20, 20, 661, 461));
	if (capture.isOpened())
	{
		faceSource = -1;
		capture.release();	//decide if capture is already opened;if so, close it
		uiMainWin.pushButton_camera->setText(QString::fromLocal8Bit("打开摄像头(C)"));
		uiMainWin.pushButton_camera->setShortcut(tr("C"));
		uiMainWin.pushButton_open->setEnabled(true);
		uiMainWin.pushButton_addToLib->setEnabled(false);
		uiMainWin.pushButton_retrieval->setEnabled(false);
		uiMainWin.videoViewer->setPixmap((QPixmap(QString::fromUtf8(":/bg"))));
		timer->stop();
		return;
	}
	faceSource = 1;
	uiMainWin.pushButton_camera->setText(QString::fromLocal8Bit("关闭摄像头(C)"));
	uiMainWin.pushButton_camera->setShortcut(tr("C"));
	uiMainWin.pushButton_open->setEnabled(false);	//关闭摄像头之前不允许打开图片
	capture.open(0);	//open the default camera
	if (capture.isOpened())
	{
		uiMainWin.pushButton_addToLib->setEnabled(true);
		uiMainWin.pushButton_retrieval->setEnabled(true);
		double rate = 30;
		capture >> frame;
		if (!frame.empty())
		{
			cv::Mat frame2 = frame.clone();
			image = Mat2QImage(frame2);
			uiMainWin.videoViewer->setPixmap(QPixmap::fromImage(image));
			timer = new QTimer(this);
			timer->setInterval(1000 / rate);	//set timer match with fps
			connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
			timer->start();
		}
	}

}

void MainWindow::on_pushButton_addToLib_clicked()
{
	if (faceSource == 1)
	{
		if (fKit.face.rows < 10)
			return;
		cv::Mat face = fKit.face.clone();	//下一个Mat2QImage会改变实参通道顺序 所以弄个副本让它去折腾
		const QImage qface = Mat2QImage(face);
		uiMainWin.videoViewer->setScaledContents(false);
		uiMainWin.videoViewer->setPixmap(QPixmap::fromImage(qface));
		timer->stop();
		QString name = QInputDialog::getText(this, QString::fromLocal8Bit("请输入用户名"), QString::fromLocal8Bit("请输入用户名"));
		if (!name.isEmpty())
		{
			std::string nameStr = std::string((const char*)name.toLocal8Bit());

#ifdef _DEBUG
			cv::imshow("test", fKit.face);
			cv::waitKey(0);
			cv::destroyAllWindows();
#endif // _DEBUG

			//请勿修改此处代码 道理同Retrieval
			cv::Mat temp = fKit.face.clone();
			fKit.addToFeatureLib(nameStr, temp);
			//--------------------------


			QMessageBox::about(this, QString::fromLocal8Bit("导入成功！"), QString::fromLocal8Bit("特征已成功导入库中！ "));
		}
		uiMainWin.videoViewer->setScaledContents(true);
		timer->start();
	}
	if (faceSource == 2)
	{
		if (fKit.localFace.rows < 10)
			return;
		cv::Mat face = fKit.localFace.clone();
		QString name = QInputDialog::getText(this, QString::fromLocal8Bit("请输入用户名"), QString::fromLocal8Bit("请输入用户名"));
		if (!name.isEmpty())
		{
			std::string nameStr = std::string((const char*)name.toLocal8Bit());
#ifdef _DEBUG
			cv::imshow("test", fKit.localFace);
			cv::waitKey(0);
			cv::destroyAllWindows();
#endif // _DEBUG

			

			fKit.addToFeatureLib(nameStr, fKit.localFace);
			QMessageBox::about(this, QString::fromLocal8Bit("导入成功！"), QString::fromLocal8Bit("特征已成功导入库中！ "));
		}
	}

}

void MainWindow::on_pushButton_retrieval_clicked()
{
	if (faceSource == 1)
	{
		if (fKit.face.rows < 10)
			return;
		cv::Mat face = fKit.face.clone();
		const QImage qface = Mat2QImage(face);
		uiMainWin.videoViewer->setScaledContents(false);
		uiMainWin.videoViewer->setPixmap(QPixmap::fromImage(qface));
		timer->stop();
		//获取当前时间
		time_t timep;
		time(&timep);
		char tmp[64];
		strftime(tmp, sizeof(tmp), "%Y-%m-%d_%A_%H:%M:%S", localtime(&timep));
		std::string currentTime = tmp;


		//cv::cvtColor(fKit.face, fKit.face, CV_BGR2RGB);

#ifdef _DEBUG

		cv::imshow("test", fKit.face);
		cv::waitKey(0);
		cv::destroyAllWindows();
#endif // _DEBUG

		//---------高能预警！千万不要尝试修改以下两行代码！虽然它们看起来很蠢---------
		//按道理的话 下面Retrieval参数直接用 fKit.face就行了 
		//为什么非得多此一举弄个副本去浪费宝贵的内存呢？
		//说实话我也不知道 也许是opecv的bug 但就是这两个完全一样的Mat 提出来的特征却完全不一样
		//it doesn't work, why? it works ,why?
		//同理导出特征到硬盘的时候也需要建立副本 再用副本作为实参
		cv::Mat temp = fKit.face.clone();
		std::string predictPeole = fKit.faceRetrieval(temp);
		//------------------------------------------------------------------------------------
		//------------------------------------------------------------------------------------

		if (predictPeole.empty())
			predictPeole = "未知用户";
		else
		{
			std::ofstream out("../data/records/" + predictPeole + ".txt", std::ios::app);

			out << tmp << std::endl;
		}
		std::string serise = randomSerise();
		std::string imgPath = "../data/records/face/" + serise + ".bmp";
		cv::imwrite(imgPath, fKit.face);
		//添加到总表
		std::ofstream out("../data/records/All.txt", std::ios::app);
		out << predictPeole << " " << tmp << " " << serise << std::endl;
		out.close();

		QString qPredictPeople = QString::fromLocal8Bit(predictPeole.c_str());
		QMessageBox::about(this, QString::fromLocal8Bit("检索结果"), qPredictPeople);
		uiMainWin.videoViewer->setScaledContents(true);
		timer->start();


	}
	if (faceSource == 2)
	{
		if (fKit.localFace.rows < 10)
			return;
#ifdef _DEBUG

		cv::imshow("test", fKit.localFace);
		cv::waitKey(0);
		cv::destroyAllWindows();
#endif // _DEBUG


		//------------请勿修改-----------------
		cv::Mat temp = fKit.localFace.clone();
		std::string predictPeole = fKit.faceRetrieval(temp);
		//-------------------------------------
		if (predictPeole.empty())
			predictPeole = "未知用户";
		QString qPredictPeople = QString::fromLocal8Bit(predictPeole.c_str());
		QMessageBox::about(this, QString::fromLocal8Bit("检索结果"), qPredictPeople);
	}

}

void MainWindow::on_pushButton_detectFace_clicked()
{
	fKit.detectFace(fKit.localFace, fKit.localFace);
	cv::Mat face = fKit.localFace.clone();
	const QImage qface = Mat2QImage(face);	//由于此时的localFace已经是RGB，而此语句会对其再进行一次转换，后面应该转换回来
	uiMainWin.videoViewer->setScaledContents(false);
	uiMainWin.videoViewer->setPixmap(QPixmap::fromImage(qface));
	uiMainWin.pushButton_detectFace->hide();
}

void MainWindow::on_action_threshold_triggered()
{
	double threshold = -1;
	threshold = QInputDialog::getDouble(this, QString::fromLocal8Bit("请输入阈值"), QString::fromLocal8Bit("请输入阈值（0到1）"), fKit.threshold, 0, 1, 2);
	fKit.threshold = threshold;
}

void MainWindow::on_action_manageFeatureLib_triggered()
{
	pfeaLibWid.reset(new FeatureLibWidget);
	pfeaLibWid->pfKit = &fKit;
	pfeaLibWid->show();
}

void MainWindow::on_action_lookupRecord_triggered()
{
	precWid.reset(new RecordWidget);
	precWid->show();
}
