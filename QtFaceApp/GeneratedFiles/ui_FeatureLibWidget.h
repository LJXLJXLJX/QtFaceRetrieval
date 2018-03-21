/********************************************************************************
** Form generated from reading UI file 'FeatureLibWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEATURELIBWIDGET_H
#define UI_FEATURELIBWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FeatureLibWidgetClass
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_deleteFeature;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *FeatureLibWidgetClass)
    {
        if (FeatureLibWidgetClass->objectName().isEmpty())
            FeatureLibWidgetClass->setObjectName(QStringLiteral("FeatureLibWidgetClass"));
        FeatureLibWidgetClass->resize(412, 460);
        FeatureLibWidgetClass->setMinimumSize(QSize(350, 460));
        FeatureLibWidgetClass->setMaximumSize(QSize(9999, 9999));
        gridLayout = new QGridLayout(FeatureLibWidgetClass);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidget = new QTableWidget(FeatureLibWidgetClass);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QFont font;
        font.setKerning(true);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        tableWidget->setShowGrid(false);
        tableWidget->setGridStyle(Qt::DashLine);
        tableWidget->setSortingEnabled(true);
        tableWidget->setWordWrap(false);
        tableWidget->setCornerButtonEnabled(true);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(2);
        tableWidget->horizontalHeader()->setVisible(true);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(130);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(30);
        tableWidget->verticalHeader()->setHighlightSections(true);
        tableWidget->verticalHeader()->setMinimumSectionSize(25);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->verticalHeader()->setStretchLastSection(false);

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_deleteFeature = new QPushButton(FeatureLibWidgetClass);
        pushButton_deleteFeature->setObjectName(QStringLiteral("pushButton_deleteFeature"));

        horizontalLayout->addWidget(pushButton_deleteFeature);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(FeatureLibWidgetClass);

        QMetaObject::connectSlotsByName(FeatureLibWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *FeatureLibWidgetClass)
    {
        FeatureLibWidgetClass->setWindowTitle(QApplication::translate("FeatureLibWidgetClass", "\347\211\271\345\276\201\345\272\223", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("FeatureLibWidgetClass", "\345\247\223\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("FeatureLibWidgetClass", "\345\212\240\345\205\245\346\227\266\351\227\264", Q_NULLPTR));
        pushButton_deleteFeature->setText(QApplication::translate("FeatureLibWidgetClass", "\345\210\240\351\231\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FeatureLibWidgetClass: public Ui_FeatureLibWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEATURELIBWIDGET_H
