/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *closeBtn;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_5;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName(QString::fromUtf8("AboutDialog"));
        AboutDialog->resize(530, 420);
        AboutDialog->setMinimumSize(QSize(530, 420));
        AboutDialog->setMaximumSize(QSize(530, 420));
        AboutDialog->setStyleSheet(QString::fromUtf8("QPushButton{background:url(:/images/header.bmp)}"));
        label_2 = new QLabel(AboutDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 70, 411, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Black"));
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("font: 16pt \"Arial Black\";"));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(AboutDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(190, 110, 161, 16));
        QPalette palette;
        QBrush brush(QColor(0, 170, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_3->setPalette(palette);
        closeBtn = new QPushButton(AboutDialog);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));
        closeBtn->setGeometry(QRect(210, 370, 93, 23));
        closeBtn->setMinimumSize(QSize(0, 23));
        closeBtn->setMaximumSize(QSize(16777215, 23));
        label = new QLabel(AboutDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 121, 71));
        label_4 = new QLabel(AboutDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 150, 301, 20));
        label_5 = new QLabel(AboutDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 180, 501, 21));
        textBrowser = new QTextBrowser(AboutDialog);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(20, 220, 481, 131));

        retranslateUi(AboutDialog);

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QApplication::translate("AboutDialog", "\345\205\263\344\272\216HwFinger", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AboutDialog", "HwFinger\346\214\207\347\272\271\346\250\241\345\235\227\350\260\203\350\257\225\345\212\251\346\211\213V1.0", 0, QApplication::UnicodeUTF8));
        label_3->setText(QString());
        closeBtn->setText(QApplication::translate("AboutDialog", "\345\205\263\351\227\255(C)", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_4->setText(QApplication::translate("AboutDialog", "\345\274\200\345\217\221\344\272\272\345\221\230\357\274\232whatbook", 0, QApplication::UnicodeUTF8));
        label_5->setText(QString());
        textBrowser->setHtml(QApplication::translate("AboutDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\256\213\344\275\223'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600;\">\350\256\270\345\217\257\345\243\260\346\230\216</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; color:#008000;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:"
                        "0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">\346\234\254\350\275\257\344\273\266\347\211\210\346\235\203\345\275\222HwFinger\346\211\200\346\234\211\357\274\201</span></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
