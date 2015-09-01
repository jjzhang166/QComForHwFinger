#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "zfm903_com.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startInit();
    myCom = NULL;

    //ui->qter->setText(
            //tr("<a href=\"http://www.qter.org\">www.qter.org</a>"));
 #ifdef Q_OS_LINUX
    ui->portNameComboBox->addItem( "ttyUSB0");
    ui->portNameComboBox->addItem( "ttyUSB1");
    ui->portNameComboBox->addItem( "ttyUSB2");
    ui->portNameComboBox->addItem( "ttyUSB3");
    ui->portNameComboBox->addItem( "ttyS0");
    ui->portNameComboBox->addItem( "ttyS1");
    ui->portNameComboBox->addItem( "ttyS2");
    ui->portNameComboBox->addItem( "ttyS3");
    ui->portNameComboBox->addItem( "ttyS4");
    ui->portNameComboBox->addItem( "ttyS5");
    ui->portNameComboBox->addItem( "ttyS6");
#elif defined (Q_OS_WIN)
    ui->portNameComboBox->addItem("COM0");
    ui->portNameComboBox->addItem("COM1");
    ui->portNameComboBox->addItem("COM2");
    ui->portNameComboBox->addItem("COM3");
    ui->portNameComboBox->addItem("COM4");
    ui->portNameComboBox->addItem("COM5");
    ui->portNameComboBox->addItem("COM6");
    ui->portNameComboBox->addItem("COM7");
    ui->portNameComboBox->addItem("COM8");
    ui->portNameComboBox->addItem("COM9");
    ui->portNameComboBox->addItem("COM10");
    ui->portNameComboBox->addItem("COM11");
    ui->portNameComboBox->addItem("COM12");
    ui->portNameComboBox->addItem("COM13");
    ui->portNameComboBox->addItem("COM14");
    ui->portNameComboBox->addItem("COM15");
    ///add by whatbook
    ui->portNameComboBox->addItem("COM16");
    ui->portNameComboBox->addItem("COM17");
    ui->portNameComboBox->addItem("COM18");
    ui->portNameComboBox->addItem("COM19");
    ui->portNameComboBox->addItem("COM20");

#endif

    //ui->statusBar->showMessage(tr("欢迎使用QCom串口调试助手!"));
    ui->statusBar->showMessage(tr("HwFinger指纹模块调试助手V1.0"));
    openSerialPortFlag = 0;
    ///
    //ui->ccradioButton->setDisabled(true);
    //ui->ccradioButton->setCheckable(true);
    //ui->ccradioButton->setChecked(true);
    ui->actionClearBytes->setEnabled(false);
}

MainWindow::~MainWindow()
{
    if(myCom != NULL){
        if(myCom->isOpen()){
            myCom->close();
        }
        delete myCom;
    }
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::startInit(){
    setActionsEnabled(false);
    ui->delayspinBox->setEnabled(false);
    ui->sendmsgBtn->setEnabled(false);
    ui->sendMsgLineEdit->setEnabled(false);
    ui->obocheckBox->setEnabled(false);
    ui->actionAdd->setEnabled(true);


    //add by whatbook
    ui->sendmsgBtn->setEnabled(false);
    ui->sendAsHexcheckBox->setEnabled(false);

    //初始化连续发送计时器计时间隔
    obotimerdly = OBO_TIMER_INTERVAL;

    //设置连续发送计时器
    obotimer = new QTimer(this);
    connect(obotimer, SIGNAL(timeout()), this, SLOT(sendMsg()));

}

void MainWindow::setActionsEnabled(bool status)
{
    ui->actionSave->setEnabled(status);
    ui->actionClose->setEnabled(status);
    ui->actionLoadfile->setEnabled(status);
    ui->actionCleanPort->setEnabled(status);
    ui->actionWriteToFile->setEnabled(status);
}

void MainWindow::setComboBoxEnabled(bool status)
{
    ui->portNameComboBox->setEnabled(status);
    ui->baudRateComboBox->setEnabled(status);
    ui->dataBitsComboBox->setEnabled(status);
    ui->parityComboBox->setEnabled(status);
    ui->stopBitsComboBox->setEnabled(status);
}

//打开串口
void MainWindow::on_actionOpen_triggered()
{
    QString portName = ui->portNameComboBox->currentText();   //获取串口名
#ifdef Q_OS_LINUX
    myCom = new QextSerialPort("/dev/" + portName);
#elif defined (Q_OS_WIN)
    myCom = new QextSerialPort(portName);
#endif
    connect(myCom, SIGNAL(readyRead()), this, SLOT(readMyCom()));

    //设置波特率
    myCom->setBaudRate((BaudRateType)ui->baudRateComboBox->currentText().toInt());

    //设置数据位
    myCom->setDataBits((DataBitsType)ui->dataBitsComboBox->currentText().toInt());

    //设置校验
    switch(ui->parityComboBox->currentIndex()){
    case 0:
         myCom->setParity(PAR_NONE);
         break;
    case 1:
        myCom->setParity(PAR_ODD);
        break;
    case 2:
        myCom->setParity(PAR_EVEN);
        break;
    default:
        myCom->setParity(PAR_NONE);
        qDebug("set to default : PAR_NONE");
        break;
    }

    //设置停止位
    switch(ui->stopBitsComboBox->currentIndex()){
    case 0:
        myCom->setStopBits(STOP_1);
        break;
    case 1:
 #ifdef Q_OS_WIN
        myCom->setStopBits(STOP_1_5);
 #endif
        break;
    case 2:
        myCom->setStopBits(STOP_2);
        break;
    default:
        myCom->setStopBits(STOP_1);
        qDebug("set to default : STOP_1");
        break;
    }    

    //设置数据流控制
    myCom->setFlowControl(FLOW_OFF);
    //设置延时
    myCom->setTimeout(TIME_OUT);

    if(myCom->open(QIODevice::ReadWrite)){
        QMessageBox::information(this, tr("打开成功"), tr("已成功打开串口") + portName, QMessageBox::Ok);
		//界面控制
        ///ui->sendmsgBtn->setEnabled(true);
        setComboBoxEnabled(false);

        ///ui->sendMsgLineEdit->setEnabled(true);
        ui->sendMsgLineEdit->setEnabled(false);

        ui->actionOpen->setEnabled(false);
        ui->sendMsgLineEdit->setFocus();
        ///ui->obocheckBox->setEnabled(true);
        ui->actionAdd->setEnabled(false);



        setActionsEnabled(true);

        ///
        ui->actionSave->setEnabled(false);
        //ui->actionClose->setEnabled(status);
        ui->actionLoadfile->setEnabled(false);
        //ui->actionCleanPort->setEnabled(false);
        ui->actionWriteToFile->setEnabled(false);
        ui->actionClearBytes->setEnabled(false);

        openSerialPortFlag = 1;


    }else
    {
        openSerialPortFlag = 0;
        QMessageBox::critical(this, tr("打开失败"), tr("未能打开串口 ") + portName + tr("\n该串口设备不存在或已被占用"), QMessageBox::Ok);
        return;
    }

    ui->statusBar->showMessage(tr("打开串口成功"));
}


//关闭串口
void MainWindow::on_actionClose_triggered()
{

    myCom->close();
    delete myCom;
    myCom = NULL;

    openSerialPortFlag = 0;

    ui->sendmsgBtn->setEnabled(false);

    setComboBoxEnabled(true);

    ui->actionOpen->setEnabled(true);
    ui->sendMsgLineEdit->setEnabled(false);
    ui->obocheckBox->setEnabled(false);
    ui->actionAdd->setEnabled(true);

    setActionsEnabled(false);

    ui->actionWriteToFile->setChecked(false);
    ui->statusBar->showMessage(tr("串口已经关闭"));
}

//关于
void MainWindow::on_actionAbout_triggered()
{
    aboutdlg.show();
    // 在主窗口中间显示
    int x =this->x() + (this->width() - aboutdlg.width()) / 2;
    int y =this->y() + (this->height() - aboutdlg.height()) / 2;
    aboutdlg.move(x, y);
    ui->statusBar->showMessage(tr("关于HwFinger"));
}

char readbuf[8];

//读取数据
void MainWindow::readMyCom()
{
    QByteArray temp = myCom->readAll();
    QString buf;
    int i=0;
    static unsigned char Readlen = 0;

/*
    for(i=0;i<temp.length();i++)
    {
        readbuf[Readlen+i] = temp[i];
    }

    Readlen += temp.length();
    qDebug("temp len==%d\r\n",temp.length());
    if(Readlen == 8)
    {
       //获取指纹枚数
       if(readbuf[2] == 0x01)
       {
           //qDebug("Number of finger==%d\r\n",readbuf[4]);

           buf = QString::number(readbuf[4], 10);

           ui->sendAsHexcheckBox->setEnabled(true);
           ui->sendAsHexcheckBox->setText(tr("指纹枚数共："));

           ui->sendMsgLineEdit->setEnabled(true);
           ui->sendMsgLineEdit->setText(buf);

       }
       //验证
       if(readbuf[2] == 0x05)
       {
          if(readbuf[4] == 0x06)
          {
              ui->statusBar->showMessage(tr("验证指纹成功"));
          }
          if(readbuf[4] == 0x07)
          {
              ui->statusBar->showMessage(tr("验证指纹失败"));
          }
       }
       //删除全部
       if(readbuf[2] == 0x03)
       {
          if(readbuf[4] == 0x08)
          {
              ui->statusBar->showMessage(tr("删除全部成功"));
          }
          if(readbuf[4] == 0x09)
          {
              ui->statusBar->showMessage(tr("删除全部失败"));
          }
       }
       //删除单个指纹
       if(readbuf[2] == 0x02)
       {
          if(readbuf[4] == 0x08)
          {
              ui->statusBar->showMessage(tr("删除成功"));
          }
          if(readbuf[4] == 0x09)
          {
              ui->statusBar->showMessage(tr("删除失败"));
          }
       }


       //指纹注册
       if(readbuf[2] == 0x04)
       {
          if(readbuf[4] == 0x0d)
          {
              ui->statusBar->showMessage(tr("指纹图像有误，重新按压"));
          }
          if(readbuf[4] == 0x0b)
          {
              ui->statusBar->showMessage(tr("请按压第二次"));
          }
          if(readbuf[4] == 0x0c)
          {
              ui->statusBar->showMessage(tr("请按压第三次"));
          }
          if(readbuf[4] == 0x08)
          {
              ui->statusBar->showMessage(tr("指纹注册成功"));
          }
          if(readbuf[4] == 0x09)
          {
              ui->statusBar->showMessage(tr("指纹注册失败"));
          }
       }

       Readlen = 0;
    }

*/



    if(!temp.isEmpty())
    {
        ui->textBrowser->setTextColor(Qt::black);
        if(ui->ccradioButton->isChecked())
        {
            buf = temp;
        }else if(ui->chradioButton->isChecked())
        {
            QString str;
            for(int i = 0; i < temp.count(); i++)
            {
                QString s;
                s.sprintf("0x%02x, ", (unsigned char)temp.at(i));
                buf += s;
            }
        }


        if(!write2fileName.isEmpty())
        {
            QFile file(write2fileName);
            //如果打开失败则给出提示并退出函数
            if(!file.open(QFile::WriteOnly | QIODevice::Text)){
                QMessageBox::warning(this, tr("写入文件"), tr("打开文件 %1 失败, 无法写入\n%2").arg(write2fileName).arg(file.errorString()), QMessageBox::Ok);
                return;
            }
            QTextStream out(&file);
            out<<buf;
            file.close();
        }

        ui->textBrowser->setText(ui->textBrowser->document()->toPlainText() + buf);
        QTextCursor cursor = ui->textBrowser->textCursor();
        cursor.movePosition(QTextCursor::End);
        ui->textBrowser->setTextCursor(cursor);

        ui->recvbyteslcdNumber->display(ui->recvbyteslcdNumber->value() + temp.size());
        ///ui->statusBar->showMessage(tr("成功读取%1字节数据").arg(temp.size()));
    }


}

//发送数据
void MainWindow::sendMsg()
{
    QByteArray buf;
    if(ui->sendAsHexcheckBox->isChecked()){
        QString str;
        bool ok;
        char data;
        QStringList list;
        str = ui->sendMsgLineEdit->text();
        list = str.split(" ");
        for(int i = 0; i < list.count(); i++){
            if(list.at(i) == " ")
                continue;
            if(list.at(i).isEmpty())
                continue;
            data = (char)list.at(i).toInt(&ok, 16);
            if(!ok){
                QMessageBox::information(this, tr("提示消息"), tr("输入的数据格式有错误！"), QMessageBox::Ok);
                return;
            }
            buf.append(data);
        }
    }else{
#if QT_VERSION < 0x050000
        buf = ui->sendMsgLineEdit->text().toAscii();
#else
        buf = ui->sendMsgLineEdit->text().toLocal8Bit();
#endif
    }
    //发送数据
    myCom->write(buf);
    ui->statusBar->showMessage(tr("发送数据成功"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}

//发送数据按钮
void MainWindow::on_sendmsgBtn_clicked()
{
    //如果当前正在连续发送数据，暂停发送
    if(ui->sendmsgBtn->text() == tr("暂停")){
        obotimer->stop();
        ui->sendmsgBtn->setText(tr("发送"));
        ui->sendmsgBtn->setIcon(QIcon(":new/prefix1/src/send.png"));
        return;
    }
    //如果发送数据为空，给出提示并返回
    if(ui->sendMsgLineEdit->text().isEmpty()){
        QMessageBox::information(this, tr("提示消息"), tr("没有需要发送的数据"), QMessageBox::Ok);
        return;
    }
    //发送数据
    sendMsg();
    //如果不是连续发送
    if(!ui->obocheckBox->isChecked()){
        ui->sendMsgLineEdit->setFocus();
    }else{ //连续发送
        obotimer->start(obotimerdly);
        ui->sendmsgBtn->setText(tr("暂停"));
        ui->sendmsgBtn->setIcon(QIcon(":new/prefix1/src/pause.png"));
    }
}
//清空记录
void MainWindow::on_clearUpBtn_clicked()
{
    ui->textBrowser->clear();
    ui->statusBar->showMessage(tr("记录已经清空"));


    if(ui->recvbyteslcdNumber->value() == 0)
    {
        //QMessageBox::information(this, tr("提示消息"), tr("貌似已经清零了呀:)"), QMessageBox::Ok);
    }else
    {
        ui->recvbyteslcdNumber->display(0);
        ui->statusBar->showMessage(tr("计数器已经清零"));
    }
}



//计数器清零
void MainWindow::on_actionClearBytes_triggered()
{
    if(ui->recvbyteslcdNumber->value() == 0){
        QMessageBox::information(this, tr("提示消息"), tr("貌似已经清零了呀:)"), QMessageBox::Ok);
    }else{
        ui->recvbyteslcdNumber->display(0);
        ui->statusBar->showMessage(tr("计数器已经清零"));
    }
}

//单击连续发送checkBox
void MainWindow::on_obocheckBox_clicked()
{
    if(ui->obocheckBox->isChecked()){
        ui->delayspinBox->setEnabled(true);
        //检查是否有数据，如有则启动定时器
        ui->statusBar->showMessage(tr("启用连续发送"));
    }else{
        ui->delayspinBox->setEnabled(false);
        //若定时器已经启动则关闭它
        ui->statusBar->showMessage(tr("停止连续发送"));
    }
}

//保存textBrowser中的内容
void MainWindow::on_actionSave_triggered()
{

    if(ui->textBrowser->toPlainText().isEmpty()){
        QMessageBox::information(this, "提示消息", tr("貌似还没有数据! 您需要在发送编辑框中输入要发送的数据"), QMessageBox::Ok);
        return;
    }

    QString filename = QFileDialog::getSaveFileName(this, tr("保存为"), tr("未命名.txt"));
    QFile file(filename);
    //如果用户取消了保存则直接退出函数
    if(file.fileName().isEmpty()){
        return;
    }
    //如果打开失败则给出提示并退出函数
    if(!file.open(QFile::WriteOnly | QIODevice::Text)){
        QMessageBox::warning(this, tr("保存文件"), tr("打开文件 %1 失败, 无法保存\n%2").arg(filename).arg(file.errorString()), QMessageBox::Ok);
        return;
    }
    //写数据到文件
    QTextStream out(&file);
    out<<ui->textBrowser->toPlainText();
    file.close();
    //修改窗口标题为保存文件路径
    setWindowTitle("saved: " + QFileInfo(filename).canonicalFilePath());

}

//退出程序
void MainWindow::on_actionExit_triggered()
{
    this->close();
}

//添加串口
void MainWindow::on_actionAdd_triggered()
{
    bool ok = false;
    QString portname;

    portname = QInputDialog::getText(this, tr("添加串口"), tr("设备文件名"), QLineEdit::Normal, 0, &ok);
    if(ok && !portname.isEmpty()){
        ui->portNameComboBox->addItem(portname);
        ui->statusBar->showMessage(tr("添加串口成功"));
    }
}

//调整连续发送时间间隔
void MainWindow::on_delayspinBox_valueChanged(int )
{
    obotimerdly = ui->delayspinBox->value();
}

//载入外部文件
void MainWindow::on_actionLoadfile_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("读取文件"), 0, tr("保存为 (*.txt *.log)"));  //添加更多的文件类型
    QFile file(filename);

    //如果取消打开则退出函数
    if(file.fileName().isEmpty()){
        return;
    }

    //如果打开失败则提示并退出函数
    if(!file.open(QFile::ReadOnly | QIODevice::Text)){
        QMessageBox::warning(this, tr("打开失败"),
                             tr("抱歉! Wincom未能打开此文件, 这可能是由于没有足够的权限造成的. 您可以尝试使用chmod命令修改文件权限."),
                             QMessageBox::Ok);
        return;
    }

    //文件大小超过限制
    if(file.size() > MAX_FILE_SIZE){
        QMessageBox::critical(this, tr("载入失败"), tr("文件大小为 %1 字节, 超过限制大小 10000 字节").arg(file.size()), QMessageBox::Ok);
        return;
    }
    //文件太大时提示是否继续打开
    if(file.size() > TIP_FILE_SIZE){
        if(QMessageBox::question(this, tr("提示消息"), tr("您要打开的文件过大, 这将消耗更多一些的时间,要继续打开么?"),
                                 QMessageBox::Yes | QMessageBox::No) == QMessageBox::No){

            return;
        }
    }

    //读取数据并加入到发送数据编辑框
    QByteArray line;
    while(!file.atEnd()){
        line = file.readLine();
        ui->sendMsgLineEdit->setText(ui->sendMsgLineEdit->text() + tr(line));

    }
    file.close();
    ui->statusBar->showMessage(tr("已经成功读取文件中的数据"));
}

//清空串口中的I/O数据
void MainWindow::on_actionCleanPort_triggered()
{
    myCom->flush();
}

//写入文件菜单
void MainWindow::on_actionWriteToFile_triggered()
{
    if(ui->actionWriteToFile->isChecked()){
        QString filename = QFileDialog::getSaveFileName(this, tr("写入文件"), 0, tr("保存为 (*.*)"));  //添加更多的文件类型
        if(filename.isEmpty()){
            ui->actionWriteToFile->setChecked(false);
        }else{
            write2fileName = filename;
            //ui->textBrowser->setEnabled(false);
            ui->actionWriteToFile->setToolTip(tr("停止写入到文件"));
        }
    }else{
        write2fileName.clear();
        //ui->textBrowser->setEnabled(true);
        ui->actionWriteToFile->setToolTip(tr("将读取数据写入到文件"));
    }

}

void MainWindow::on_Btn_GetNum_clicked()
{
    QByteArray buf;
    //QString portName = ui->portNameComboBox->currentText();   //获取串口名

    if(openSerialPortFlag == 0)
    {
        QMessageBox::critical(this, tr("打开失败"), tr("请首先打开可以使用的串口！"), QMessageBox::Ok);
        return;
    }

    // 1 : 获取指纹注册多少枚数字
    //5A 55 01 01 00 02 6A 69
    buf.append(0x5A);
    buf.append(0x55);
    buf.append(0x01);
    buf.append(0x01);
    buf.append((char)0x00);
    buf.append(0x02);
    buf.append(0x6A);
    buf.append(0x69);

    //发送数据
    myCom->write(buf);
    ui->statusBar->showMessage(tr("发送数据成功"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}


void MainWindow::on_Btn_DelOne_clicked()
{
    QByteArray buf;

    if(openSerialPortFlag == 0)
    {
        QMessageBox::critical(this, tr("打开失败"), tr("请首先打开可以使用的串口！"), QMessageBox::Ok);
        return;
    }
    // 3 : 删除一枚指纹
    //5A 55 02 01 00 03 6A 69
    buf.append(0x5A);
    buf.append(0x55);
    buf.append(0x02);
    buf.append(0x01);
    buf.append((char)0x00);
    buf.append(0x03);
    buf.append(0x6A);
    buf.append(0x69);

    //发送数据
    myCom->write(buf);
    ui->statusBar->showMessage(tr("发送数据成功"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}

void MainWindow::on_Btn_DelAll_clicked()
{
    QByteArray buf;
    if(openSerialPortFlag == 0)
    {
        QMessageBox::critical(this, tr("打开失败"), tr("请首先打开可以使用的串口！"), QMessageBox::Ok);
        return;
    }
    // 3 : 删除全部指纹
    //5A 55 03 01 00 04 6A 69
    buf.append(0x5A);
    buf.append(0x55);
    buf.append(0x03);
    buf.append(0x01);
    buf.append((char)0x00);
    buf.append(0x04);
    buf.append(0x6A);
    buf.append(0x69);

    //发送数据
    myCom->write(buf);
    ui->statusBar->showMessage(tr("发送数据成功"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}

void MainWindow::on_Btn_EnrollOne_clicked()
{
    QByteArray buf;
    if(openSerialPortFlag == 0)
    {
        QMessageBox::critical(this, tr("打开失败"), tr("请首先打开可以使用的串口！"), QMessageBox::Ok);
        return;
    }
    // 2 : 注册一枚指纹
    //5A 55 04 01 00 05 6A 69
    buf.append(0x5A);
    buf.append(0x55);
    buf.append(0x04);
    buf.append(0x01);
    buf.append((char)0x00);
    buf.append(0x05);
    buf.append(0x6A);
    buf.append(0x69);

    //发送数据
    myCom->write(buf);
    //->statusBar->showMessage(tr("发送数据成功"));
    ui->statusBar->showMessage(tr("请按压第一次"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}

int MainWindow::Com_Send(char *p,uint len)
{
    //QByteArray buf;
    if(openSerialPortFlag == 0)
    {
        QMessageBox::critical(this, tr("打开失败"), tr("请首先打开可以使用的串口！"), QMessageBox::Ok);
        return 0;
    }
    //发送数据
    myCom->write(p,len);
    ui->statusBar->showMessage(tr("发送数据成功"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
    return 1;
}
uint MainWindow::ZFM_GetSum(uchar *p,uint len)
{
    uchar i;
    uint sum;

    sum = *p;
    for (i=1; i<len; i++)
    {
        sum += p[i];
    }

    return (sum);
}

//发送命令包
char MainWindow::ZFM903_SendCMD(uchar cmd,char data1,uint data2,uint data3)
{
    my_word sum;//校验和
    char *pbuf=ZFM_SendBuf;
    if(openSerialPortFlag == 0)
    {
        QMessageBox::critical(this, tr("打开失败"), tr("请首先打开可以使用的串口！"), QMessageBox::Ok);
        return 0;
    }
    pbuf[0] = 0xef; // 包头
    pbuf[1] = 0x01; // 包头
    pbuf[2] = 0xff; // 模块地址
    pbuf[3] = 0xff; // 模块地址
    pbuf[4] = 0xff; // 模块地址
    pbuf[5] = 0xff; // 模块地址
    pbuf[6] = 0x01; // 命令包标识

    switch(cmd)
    {
    case CMD_VFY_PWD:
    case CMD_DEL_CHAR:
        pbuf[7] = 0x00; // 长度
        pbuf[8] = 0x07; // 长度
        pbuf[9] = cmd; // 指令代码

        pbuf[10] = (char)(data2>>8);
        pbuf[11] = (char)data2;
        pbuf[12] = (char)(data3>>8);
        pbuf[13] = (char)data3;
        //指令包校验和(2 bytes)=包标识(1 byte)+包长度(2 bytes)+指令码(1 byte)+口令(4 bytes)；
        sum.word = ZFM_GetSum((uchar*)&pbuf[6],8);// 计算数据校验和
        pbuf[14]=sum.byte.high; // 校验和
        pbuf[15]=sum.byte.low;// 校验和
        //发送数据
        myCom->write(pbuf,16);
        break;

    case CMD_UP_CHAR:
    case CMD_IMG2TZ:
    case CMD_DOWN_CHAR:
        pbuf[7] = 0x00; // 长度
        pbuf[8] = 0x04; // 长度
        pbuf[9] = cmd; // 指令代码
        pbuf[10] = data1;
        //指令包校验和(2 bytes)=包标识(1 byte)+包长度(2 bytes)+指令码(1 byte)+缓冲区号(1 byte)；
        sum.word = ZFM_GetSum((uchar*)&pbuf[6],5);// 计算数据校验和
        pbuf[11]=sum.byte.high; 	// 校验和
        pbuf[12]=sum.byte.low;	// 校验和
        //发送数据
        myCom->write(pbuf,13);
        break;
    case CMD_STORE:
    case CMD_LOAD_CHAR:
        pbuf[7] = 0x00; // 长度
        pbuf[8] = 0x06; // 长度
        pbuf[9] = cmd; // 指令代码

        pbuf[10] = data1;
        pbuf[11] = (char)(data2>>8);
        pbuf[12] = (char)data2;
        //指令包校验和(2 bytes)=包标识(1 byte)+包长度(2 bytes)+指令码(1 byte)+缓冲区号(1 byte) +位置号(2 bytes)；
        sum.word = ZFM_GetSum((uchar*)&pbuf[6],7);// 计算数据校验和
        pbuf[13]=sum.byte.high; // 校验和
        pbuf[14]=sum.byte.low;// 校验和
        //发送数据
        myCom->write(pbuf,15);
        break;

    case CMD_SERACH:
        pbuf[7] = 0x00; // 长度
        pbuf[8] = 0x08; // 长度
        pbuf[9] = cmd; // 指令代码

        pbuf[10] = data1;
        pbuf[11] = (char)(data2>>8);
        pbuf[12] = (char)data2;
        pbuf[13] = (char)(data3>>8);
        pbuf[14] = (char)data3;
        //指令包校验和(2 bytes)=包标识(1 byte)+包长度(2 bytes)+指令码(1 byte)+缓冲区号(1 bytes) +起始页(2 bytes)+个数(2 bytes)；
        sum.word = ZFM_GetSum((uchar*)&pbuf[6],9);// 计算数据校验和
        pbuf[15]=sum.byte.high; // 校验和
        pbuf[16]=sum.byte.low;// 校验和
        //发送数据
        myCom->write(pbuf,17);
        break;

    default:
        pbuf[7] = 0x00; // 长度
        pbuf[8] = 0x03; // 长度
        pbuf[9] = cmd; // 指令代码
        //指令包校验和(2 bytes)=包标识(1 byte)+包长度(2 bytes)+指令码(1 byte)
        sum.word = ZFM_GetSum((uchar*)&pbuf[6],4);// 计算数据校验和
        pbuf[10]=sum.byte.high;// 校验和
        pbuf[11]=sum.byte.low;// 校验和
        //发送数据
        myCom->write(pbuf,12);
        break;
    }
}
//1）验证口令 VfyPwd
//功能说明：验证模块口令（串行通讯必须进行的握手）。
//输入参数：PassWord
//返回参数：确认码
//指令代码：0x13
void MainWindow::on_Btn_VfyPwd_clicked()
{
    ZFM903_SendCMD(CMD_VFY_PWD,0,0,0);
    ui->statusBar->showMessage(tr("验证模块口令发送成功"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}
//7）读有效模板个数 TemplateNum
//功能说明：读模块内已存储的指纹模板个数。
//输入参数：none
//返回参数：确认字 + 模板个数N
//指令代码：0x1d
void MainWindow::on_Btn_GetTemplateNum_clicked()
{
    ZFM903_SendCMD(CMD_GET_TEMPLATE_NUM,0,0,0);
    ui->statusBar->showMessage(tr("读有效模板个数指令发送成功"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);

}
//8）录指纹图像 GenImg
//功能说明：探测手指，探测到后录入指纹图像存于ImageBuffer，
//并返回录入成功确认码；若探测不到手指，直接返回无手指确认码
//(模块对于每一条指令都快速反应，因此如连续探测，需进行循环处理，可限定循环的次数或总时间)。
//输入参数：none
//返回参数：确认字
//指令代码：0x01
void MainWindow::on_pushButton_clicked()
{
    ZFM903_SendCMD(CMD_GET_IMAGE,0,0,0);
    ui->statusBar->showMessage(tr("录指纹图像指令发送成功"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}
//9）上传图像 UpImage
//功能说明：将模块图像缓冲区ImageBuffer中的数据上传给上位机（参见4.1.1图像缓冲区）。
//输入参数：none
//返回参数：确认字
//指令代码：0x0a
void MainWindow::on_pushButton_5_clicked()
{
    ZFM903_SendCMD(CMD_UP_IMAGE,0,0,0);
    ui->statusBar->showMessage(tr("上传指纹图像指令发送成功"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}
//10）下载图像DownImage
//功能说明：上位机下载图像数据到模块图像缓冲区ImageBuffer(参见4.1.1图像缓冲区），图像必须为256*288大小BMP格式。
//输入参数：none
//返回参数：确认字
//指令代码：0x0b
void MainWindow::on_pushButton_6_clicked()
{
    ZFM903_SendCMD(CMD_DOWN_IMAGE,0,0,0);
    ui->statusBar->showMessage(tr("下载指纹图像指令发送成功"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}
//11）图像生成特征 Img2Tz
//功能说明：将ImageBuffer中的原始图像生成指纹特征,
//特征存储于CharBuffer1 或CharBuffer2。
//输入参数：BufferID(特征缓冲区号)
//返回参数：确认字
//指令代码：0x02
void MainWindow::on_pushButton_2_clicked()
{
    ZFM903_SendCMD(CMD_IMG2TZ,0x01,0,0);
    ui->statusBar->showMessage(tr("图像生成特征一指令发送成功"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}
void MainWindow::on_pushButton_7_clicked()
{
    ZFM903_SendCMD(CMD_IMG2TZ,0x02,0,0);
    ui->statusBar->showMessage(tr("图像生成特征二指令发送成功"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}
//12）特征合成模板RegModel
//功能说明：将CharBuffer1与CharBuffer2中的特征文件合并生成模板，
//模板存于CharBuffer1与CharBuffer2(两者内容相同)。
//输入参数：none
//返回参数：确认字
//指令代码：0x05
void MainWindow::on_pushButton_8_clicked()
{
    ZFM903_SendCMD(CMD_REG_MODEL,0,0,0);
    ui->statusBar->showMessage(tr("特征合成模板指令发送成功"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}
//13）上传特征或模板 UpChar
//功能说明：将特征缓冲区CharBuffer1或CharBuffer2中的特征文件上传给上位机。
//输入参数：BufferID(缓冲区号)
//返回参数：确认字
//指令代码：0x08
void MainWindow::on_pushButton_3_clicked()
{
    ZFM903_SendCMD(CMD_UP_CHAR,0x01,0,0);
    ui->statusBar->showMessage(tr("上传特征模板一指令发送成功"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}

void MainWindow::on_pushButton_4_clicked()
{
    ZFM903_SendCMD(CMD_UP_CHAR,0x02,0,0);
    ui->statusBar->showMessage(tr("上传特征模板二指令发送成功"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}

//14）下载特征或模板 DownChar
//功能说明：上位机下载特征文件到模块的一个特征缓冲区中。
//输入参数：BufferID(缓冲区号)
//返回参数：确认字
//指令代码：0x09
void MainWindow::on_pushButton_14_clicked()
{
    ZFM903_SendCMD(CMD_DOWN_CHAR,0x01,0,0);
    ui->statusBar->showMessage(tr("下载特征模板一指令发送成功"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}

void MainWindow::on_pushButton_12_clicked()
{
    ZFM903_SendCMD(CMD_DOWN_CHAR,0x02,0,0);
    ui->statusBar->showMessage(tr("下载特征模板二指令发送成功"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}
//15）存储模板 Store
//功能说明：将指定的特征缓冲区（CharBuffer1或CharBuffer2）中的模板数据存储到Flash指纹库中指定位置。
//输入参数：BufferID(缓冲区号) + PageID（指纹库位置号，两个字节，高字节在前）。
//返回参数：确认字
//指令代码：0x06

void MainWindow::on_pushButton_9_clicked()
{
    ZFM903_SendCMD(CMD_STORE,0x01,0x0102,0);
    ui->statusBar->showMessage(tr("存储模板指令发送成功"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}
//16）读出模板 LoadChar
//功能说明：将flash数据库中指定ID号的指纹模板读入到模板缓冲区CharBuffer1或 CharBuffer2 。
//输入参数：BufferID(缓冲区号) + PageID(指纹库模板号，两个字节，高字节在前)。
//返回参数：确认字
//指令代码：0x07
void MainWindow::on_pushButton_10_clicked()
{
    ZFM903_SendCMD(CMD_LOAD_CHAR,0x01,0x0102,0);
    ui->statusBar->showMessage(tr("读出模板指令发送成功"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}
//17）删除模板 DeletChar
//功能说明：删除模块指纹库中指定的一段（指定ID号开始的N个指纹模板）模板。
//输入参数：PageID(指纹库模板号) + N删除的模板个数。
//返回参数：确认字
//指令代码：0x0c
void MainWindow::on_pushButton_11_clicked()
{
    ZFM903_SendCMD(CMD_DEL_CHAR,0x00,0x0102,0x0103);
    ui->statusBar->showMessage(tr("删除模板指令发送成功"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}
//18）清空指纹库 Empty
//功能说明：删除模块中指纹库内所有指纹模板。
//输入参数：none
//返回参数：确认字
//指令代码：0x0d
void MainWindow::on_pushButton_13_clicked()
{
    ZFM903_SendCMD(CMD_CLEAR_ALL_TEMPLATE,0,0,0);
    ui->statusBar->showMessage(tr("清空指纹库指令发送成功"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}
//19）精确比对两枚指纹特征 Match
//功能说明：模块精确比对（1:1）CharBuffer1 与CharBuffer2 中的特征文件，并给出比对结果。
//输入参数：none
//返回参数：确认字 + 比对得分
//指令代码：0x03
void MainWindow::on_pushButton_15_clicked()
{
    ZFM903_SendCMD(CMD_MATCH,0,0,0);
    ui->statusBar->showMessage(tr("比对两枚指纹特征指令发送成功"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}
//20）搜索指纹 Search
//功能说明：以CharBuffer1或CharBuffer2中的特征文件搜索整个或部分指纹库。若搜索到，则返回序号。
//输入参数：BufferID + StartPage(起始序号) + PageNum（个数）
//返回参数：确认字 + 序号（相配指纹模板）
//指令代码：0x04
void MainWindow::on_pushButton_16_clicked()
{
    ZFM903_SendCMD(CMD_SERACH,0x01,0x0102,0x0103);
    ui->statusBar->showMessage(tr("搜索指纹指令发送成功"));
    //界面控制
    ui->textBrowser->setTextColor(Qt::lightGray);
}
