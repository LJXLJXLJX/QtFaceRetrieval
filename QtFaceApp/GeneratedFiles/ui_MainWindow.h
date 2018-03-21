/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *action_threshold;
    QAction *action_manageFeatureLib;
    QAction *action_lookupRecord;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *videoViewer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_detectFace;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_open;
    QPushButton *pushButton_camera;
    QPushButton *pushButton_addToLib;
    QPushButton *pushButton_retrieval;
    QPushButton *pushButton_exit;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(815, 571);
        action_threshold = new QAction(MainWindowClass);
        action_threshold->setObjectName(QStringLiteral("action_threshold"));
        action_manageFeatureLib = new QAction(MainWindowClass);
        action_manageFeatureLib->setObjectName(QStringLiteral("action_manageFeatureLib"));
        action_lookupRecord = new QAction(MainWindowClass);
        action_lookupRecord->setObjectName(QStringLiteral("action_lookupRecord"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        videoViewer = new QLabel(centralWidget);
        videoViewer->setObjectName(QStringLiteral("videoViewer"));
        videoViewer->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(videoViewer->sizePolicy().hasHeightForWidth());
        videoViewer->setSizePolicy(sizePolicy);
        videoViewer->setMinimumSize(QSize(200, 150));
        videoViewer->setMaximumSize(QSize(1000, 750));
        videoViewer->setBaseSize(QSize(1000, 750));
        videoViewer->setAutoFillBackground(true);
        videoViewer->setPixmap(QPixmap(QString::fromUtf8(":/bg")));
        videoViewer->setScaledContents(false);
        videoViewer->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(videoViewer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_detectFace = new QPushButton(centralWidget);
        pushButton_detectFace->setObjectName(QStringLiteral("pushButton_detectFace"));

        horizontalLayout_2->addWidget(pushButton_detectFace);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_open = new QPushButton(centralWidget);
        pushButton_open->setObjectName(QStringLiteral("pushButton_open"));

        verticalLayout->addWidget(pushButton_open);

        pushButton_camera = new QPushButton(centralWidget);
        pushButton_camera->setObjectName(QStringLiteral("pushButton_camera"));

        verticalLayout->addWidget(pushButton_camera);

        pushButton_addToLib = new QPushButton(centralWidget);
        pushButton_addToLib->setObjectName(QStringLiteral("pushButton_addToLib"));
        pushButton_addToLib->setEnabled(false);

        verticalLayout->addWidget(pushButton_addToLib);

        pushButton_retrieval = new QPushButton(centralWidget);
        pushButton_retrieval->setObjectName(QStringLiteral("pushButton_retrieval"));
        pushButton_retrieval->setEnabled(false);

        verticalLayout->addWidget(pushButton_retrieval);

        pushButton_exit = new QPushButton(centralWidget);
        pushButton_exit->setObjectName(QStringLiteral("pushButton_exit"));

        verticalLayout->addWidget(pushButton_exit);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        horizontalLayout->setStretch(0, 10);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 1);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 815, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action_threshold);
        menu->addAction(action_manageFeatureLib);
        menu->addAction(action_lookupRecord);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "\344\272\272\350\204\270\346\243\200\347\264\242demo", Q_NULLPTR));
        action_threshold->setText(QApplication::translate("MainWindowClass", "\350\256\276\347\275\256\351\230\210\345\200\274", Q_NULLPTR));
        action_manageFeatureLib->setText(QApplication::translate("MainWindowClass", "\347\256\241\347\220\206\347\211\271\345\276\201\345\272\223", Q_NULLPTR));
        action_manageFeatureLib->setIconText(QApplication::translate("MainWindowClass", "\347\256\241\347\220\206\347\211\271\345\276\201\345\272\223", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_manageFeatureLib->setToolTip(QApplication::translate("MainWindowClass", "\347\256\241\347\220\206\347\211\271\345\276\201\345\272\223", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_lookupRecord->setText(QApplication::translate("MainWindowClass", "\346\237\245\347\234\213\350\256\260\345\275\225", Q_NULLPTR));
        action_lookupRecord->setIconText(QApplication::translate("MainWindowClass", "\346\237\245\347\234\213\350\256\260\345\275\225", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_lookupRecord->setToolTip(QApplication::translate("MainWindowClass", "\346\237\245\347\234\213\350\256\260\345\275\225", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        videoViewer->setText(QString());
        pushButton_detectFace->setText(QApplication::translate("MainWindowClass", "\346\243\200\346\265\213\344\272\272\350\204\270(D)\n"
"(\345\246\202\346\236\234\345\267\262\347\273\217\346\230\257\344\272\272\350\204\270\357\274\214\350\257\267\345\213\277\347\202\271\345\207\273)", Q_NULLPTR));
        pushButton_detectFace->setShortcut(QApplication::translate("MainWindowClass", "D", Q_NULLPTR));
        pushButton_open->setText(QApplication::translate("MainWindowClass", "\346\211\223\345\274\200\346\226\207\344\273\266(F)", Q_NULLPTR));
        pushButton_open->setShortcut(QApplication::translate("MainWindowClass", "F", Q_NULLPTR));
        pushButton_camera->setText(QApplication::translate("MainWindowClass", "\346\211\223\345\274\200\346\221\204\345\203\217\345\244\264(C)", Q_NULLPTR));
        pushButton_camera->setShortcut(QApplication::translate("MainWindowClass", "C", Q_NULLPTR));
        pushButton_addToLib->setText(QApplication::translate("MainWindowClass", "\346\267\273\345\212\240\345\210\260\345\272\223(A)", Q_NULLPTR));
        pushButton_addToLib->setShortcut(QApplication::translate("MainWindowClass", "A", Q_NULLPTR));
        pushButton_retrieval->setText(QApplication::translate("MainWindowClass", "\346\243\200\347\264\242(SPACE)", Q_NULLPTR));
        pushButton_retrieval->setShortcut(QApplication::translate("MainWindowClass", "Space", Q_NULLPTR));
        pushButton_exit->setText(QApplication::translate("MainWindowClass", "\351\200\200\345\207\272(ESC)", Q_NULLPTR));
        pushButton_exit->setShortcut(QApplication::translate("MainWindowClass", "Esc", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindowClass", "\350\256\276\347\275\256\344\270\216\347\256\241\347\220\206", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
