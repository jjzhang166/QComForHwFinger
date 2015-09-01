#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QMessageBox>
#include <QFile>
#include <QInputDialog>
#include <QFileDialog>
#include <QTextStream>

#include "qextserial/qextserialport.h"
#include "aboutdialog.h"


//延时，TIME_OUT是串口读写的延时
#define TIME_OUT 10

//连续发送定时器计时间隔,200ms
#define OBO_TIMER_INTERVAL 200

//载入文件时，如果文件大小超过TIP_FILE_SIZE字节则提示文件过大是否继续打开
#define TIP_FILE_SIZE 5000
//载入文件最大长度限制在MAX_FILE_SIZE字节内
#define MAX_FILE_SIZE 10000

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void startInit();

    int Com_Send(char *p,uint len);
    uint ZFM_GetSum(uchar *p,uint len);
    char ZFM903_SendCMD(uchar cmd,char data1,uint data2,uint data3);

protected:
    void changeEvent(QEvent *e);
    void setActionsEnabled(bool status);
    void setComboBoxEnabled(bool status);

private:
    Ui::MainWindow *ui;
    AboutDialog aboutdlg;
    QextSerialPort *myCom;
    QTimer *obotimer;
    unsigned int timerdly;
    unsigned int obotimerdly;
    QString write2fileName;    //写读取的串口数据到该文件

    unsigned char openSerialPortFlag;//串口是否打开标志  打开==1  没打开==0

    char ZFM_SendBuf[1024];

private slots:

    void on_actionWriteToFile_triggered();
    void on_actionCleanPort_triggered();
    void on_actionLoadfile_triggered();
    void on_delayspinBox_valueChanged(int );
    void on_actionAdd_triggered();
    void on_actionExit_triggered();
    void on_actionSave_triggered();
    void on_obocheckBox_clicked();
    void on_actionClearBytes_triggered();
    void on_actionAbout_triggered();
    void on_actionClose_triggered();
    void on_actionOpen_triggered();
    void on_clearUpBtn_clicked();
    void on_sendmsgBtn_clicked();
    void readMyCom();
    void sendMsg();
    //end by

    void on_Btn_GetNum_clicked();
    //void on_pushButton_2_clicked();
    void on_Btn_DelOne_clicked();
    void on_Btn_DelAll_clicked();
    void on_Btn_EnrollOne_clicked();
    void on_Btn_VfyPwd_clicked();
    void on_Btn_GetTemplateNum_clicked();
    void on_pushButton_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_16_clicked();
};

#endif // MAINWINDOW_H
