/********************************************************************************
** Form generated from reading UI file 'RecordWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDWIDGET_H
#define UI_RECORDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecordWidgetClass
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_faceViewer;
    QSpacerItem *verticalSpacer_2;
    QTableWidget *tableWidget;

    void setupUi(QWidget *RecordWidgetClass)
    {
        if (RecordWidgetClass->objectName().isEmpty())
            RecordWidgetClass->setObjectName(QStringLiteral("RecordWidgetClass"));
        RecordWidgetClass->resize(985, 691);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RecordWidgetClass->sizePolicy().hasHeightForWidth());
        RecordWidgetClass->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(RecordWidgetClass);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_faceViewer = new QLabel(RecordWidgetClass);
        label_faceViewer->setObjectName(QStringLiteral("label_faceViewer"));
        label_faceViewer->setMinimumSize(QSize(300, 300));
        label_faceViewer->setMaximumSize(QSize(300, 300));
        label_faceViewer->setPixmap(QPixmap(QString::fromUtf8(":/bg")));

        verticalLayout->addWidget(label_faceViewer);

        verticalSpacer_2 = new QSpacerItem(20, 192, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        tableWidget = new QTableWidget(RecordWidgetClass);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setAlternatingRowColors(false);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setShowGrid(false);
        tableWidget->setRowCount(0);
        tableWidget->horizontalHeader()->setDefaultSectionSize(150);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);

        gridLayout->addWidget(tableWidget, 0, 1, 1, 1);


        retranslateUi(RecordWidgetClass);

        QMetaObject::connectSlotsByName(RecordWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *RecordWidgetClass)
    {
        RecordWidgetClass->setWindowTitle(QApplication::translate("RecordWidgetClass", "\350\256\260\345\275\225\350\241\250", Q_NULLPTR));
        label_faceViewer->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("RecordWidgetClass", "\345\247\223\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("RecordWidgetClass", "\345\272\217\345\210\227\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("RecordWidgetClass", "\350\256\260\345\275\225\346\227\266\351\227\264", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RecordWidgetClass: public Ui_RecordWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDWIDGET_H
