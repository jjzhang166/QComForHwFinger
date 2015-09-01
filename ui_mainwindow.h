/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAdd;
    QAction *actionOpen;
    QAction *actionClose;
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionSave;
    QAction *actionClearBytes;
    QAction *actionLoadfile;
    QAction *actionCleanPort;
    QAction *actionWriteToFile;
    QWidget *centralWidget;
    QFormLayout *formLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *portNameComboBox;
    QLabel *label_2;
    QComboBox *baudRateComboBox;
    QLabel *label_3;
    QComboBox *dataBitsComboBox;
    QLabel *label_4;
    QComboBox *parityComboBox;
    QLabel *label_5;
    QComboBox *stopBitsComboBox;
    QSpacerItem *verticalSpacer;
    QCheckBox *obocheckBox;
    QLabel *label_6;
    QSpinBox *delayspinBox;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *sendAsHexcheckBox;
    QLineEdit *sendMsgLineEdit;
    QPushButton *sendmsgBtn;
    QToolButton *toolButton;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *Btn_GetNum;
    QPushButton *Btn_DelAll;
    QPushButton *Btn_DelOne;
    QPushButton *Btn_EnrollOne;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_3;
    QGridLayout *gridLayout_2;
    QPushButton *clearUpBtn;
    QRadioButton *ccradioButton;
    QLCDNumber *recvbyteslcdNumber;
    QRadioButton *chradioButton;
    QTextBrowser *textBrowser;
    QFrame *gridFrame;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_13;
    QPushButton *pushButton_11;
    QPushButton *pushButton_15;
    QPushButton *pushButton_12;
    QPushButton *pushButton_14;
    QPushButton *pushButton_16;
    QFrame *gridFrame_2;
    QGridLayout *gridLayout_5;
    QPushButton *pushButton_7;
    QPushButton *pushButton_5;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_6;
    QPushButton *pushButton_8;
    QFrame *gridFrame1;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_3;
    QPushButton *Btn_VfyPwd;
    QPushButton *Btn_GetTemplateNum;
    QPushButton *pushButton_4;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(820, 580);
        MainWindow->setMinimumSize(QSize(820, 580));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(9);
        MainWindow->setFont(font);
        MainWindow->setCursor(QCursor(Qt::PointingHandCursor));
        MainWindow->setContextMenuPolicy(Qt::NoContextMenu);
        MainWindow->setStyleSheet(QLatin1String("QDialog{background:rgb(229, 255, 239)}\n"
"QStatusBar{background:url(:/images/header.bmp)}\n"
"QPushButton{background:url(:/images/header.bmp)}\n"
"QLCDNumber{background:url(:/images/lcd.bmp)}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
""));
        MainWindow->setIconSize(QSize(16, 16));
        MainWindow->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        MainWindow->setAnimated(true);
        actionAdd = new QAction(MainWindow);
        actionAdd->setObjectName(QStringLiteral("actionAdd"));
        actionAdd->setCheckable(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd->setIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose->setIcon(icon2);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon3);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/mesage.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon4);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon5);
        actionClearBytes = new QAction(MainWindow);
        actionClearBytes->setObjectName(QStringLiteral("actionClearBytes"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/clearbytes.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClearBytes->setIcon(icon6);
        actionLoadfile = new QAction(MainWindow);
        actionLoadfile->setObjectName(QStringLiteral("actionLoadfile"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/loadfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoadfile->setIcon(icon7);
        actionCleanPort = new QAction(MainWindow);
        actionCleanPort->setObjectName(QStringLiteral("actionCleanPort"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/images/cleanport.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCleanPort->setIcon(icon8);
        actionWriteToFile = new QAction(MainWindow);
        actionWriteToFile->setObjectName(QStringLiteral("actionWriteToFile"));
        actionWriteToFile->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/images/write2file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionWriteToFile->setIcon(icon9);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        formLayout = new QFormLayout(centralWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setStyleSheet(QStringLiteral(""));
        groupBox->setFlat(false);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        portNameComboBox = new QComboBox(groupBox);
        portNameComboBox->setObjectName(QStringLiteral("portNameComboBox"));

        gridLayout->addWidget(portNameComboBox, 1, 0, 1, 2);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_2, 2, 0, 1, 2);

        baudRateComboBox = new QComboBox(groupBox);
        baudRateComboBox->setObjectName(QStringLiteral("baudRateComboBox"));

        gridLayout->addWidget(baudRateComboBox, 3, 0, 1, 2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_3, 4, 0, 1, 2);

        dataBitsComboBox = new QComboBox(groupBox);
        dataBitsComboBox->setObjectName(QStringLiteral("dataBitsComboBox"));

        gridLayout->addWidget(dataBitsComboBox, 5, 0, 1, 2);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_4, 6, 0, 1, 2);

        parityComboBox = new QComboBox(groupBox);
        parityComboBox->setObjectName(QStringLiteral("parityComboBox"));

        gridLayout->addWidget(parityComboBox, 7, 0, 1, 2);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_5, 8, 0, 1, 2);

        stopBitsComboBox = new QComboBox(groupBox);
        stopBitsComboBox->setObjectName(QStringLiteral("stopBitsComboBox"));

        gridLayout->addWidget(stopBitsComboBox, 9, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 10, 1, 1, 1);

        obocheckBox = new QCheckBox(groupBox);
        obocheckBox->setObjectName(QStringLiteral("obocheckBox"));

        gridLayout->addWidget(obocheckBox, 11, 0, 1, 2);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_6, 12, 0, 1, 2);

        delayspinBox = new QSpinBox(groupBox);
        delayspinBox->setObjectName(QStringLiteral("delayspinBox"));
        delayspinBox->setMinimum(10);
        delayspinBox->setMaximum(5000);
        delayspinBox->setValue(200);

        gridLayout->addWidget(delayspinBox, 13, 0, 1, 2);


        formLayout->setWidget(0, QFormLayout::LabelRole, groupBox);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setStyleSheet(QStringLiteral(""));
        groupBox_4->setFlat(true);
        horizontalLayout_2 = new QHBoxLayout(groupBox_4);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_2->setContentsMargins(9, -1, -1, -1);
        sendAsHexcheckBox = new QCheckBox(groupBox_4);
        sendAsHexcheckBox->setObjectName(QStringLiteral("sendAsHexcheckBox"));
        sendAsHexcheckBox->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(sendAsHexcheckBox);

        sendMsgLineEdit = new QLineEdit(groupBox_4);
        sendMsgLineEdit->setObjectName(QStringLiteral("sendMsgLineEdit"));
        sendMsgLineEdit->setMaximumSize(QSize(200, 23));
        sendMsgLineEdit->setMaxLength(10000);
        sendMsgLineEdit->setDragEnabled(false);

        horizontalLayout_2->addWidget(sendMsgLineEdit);

        sendmsgBtn = new QPushButton(groupBox_4);
        sendmsgBtn->setObjectName(QStringLiteral("sendmsgBtn"));
        sendmsgBtn->setMinimumSize(QSize(0, 23));
        sendmsgBtn->setMaximumSize(QSize(100, 23));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/images/send.png"), QSize(), QIcon::Normal, QIcon::Off);
        sendmsgBtn->setIcon(icon10);
        sendmsgBtn->setAutoDefault(false);
        sendmsgBtn->setDefault(false);

        horizontalLayout_2->addWidget(sendmsgBtn);


        formLayout->setWidget(1, QFormLayout::FieldRole, groupBox_4);

        toolButton = new QToolButton(centralWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));

        formLayout->setWidget(2, QFormLayout::LabelRole, toolButton);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        groupBox_3->setMinimumSize(QSize(0, 60));
        groupBox_3->setMaximumSize(QSize(16777215, 60));
        groupBox_3->setLayoutDirection(Qt::LeftToRight);
        groupBox_3->setStyleSheet(QStringLiteral(""));
        groupBox_3->setFlat(true);
        horizontalLayout_3 = new QHBoxLayout(groupBox_3);
        horizontalLayout_3->setSpacing(7);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, -1, 1);
        Btn_GetNum = new QPushButton(groupBox_3);
        Btn_GetNum->setObjectName(QStringLiteral("Btn_GetNum"));

        horizontalLayout_3->addWidget(Btn_GetNum);

        Btn_DelAll = new QPushButton(groupBox_3);
        Btn_DelAll->setObjectName(QStringLiteral("Btn_DelAll"));

        horizontalLayout_3->addWidget(Btn_DelAll);

        Btn_DelOne = new QPushButton(groupBox_3);
        Btn_DelOne->setObjectName(QStringLiteral("Btn_DelOne"));

        horizontalLayout_3->addWidget(Btn_DelOne);

        Btn_EnrollOne = new QPushButton(groupBox_3);
        Btn_EnrollOne->setObjectName(QStringLiteral("Btn_EnrollOne"));

        horizontalLayout_3->addWidget(Btn_EnrollOne);


        formLayout->setWidget(3, QFormLayout::SpanningRole, groupBox_3);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setStyleSheet(QStringLiteral(""));
        groupBox_2->setFlat(true);
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        frame_3 = new QFrame(groupBox_2);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setLayoutDirection(Qt::LeftToRight);
        frame_3->setStyleSheet(QStringLiteral(""));
        frame_3->setFrameShape(QFrame::WinPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_3->setLineWidth(1);
        frame_3->setMidLineWidth(0);
        gridLayout_2 = new QGridLayout(frame_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        clearUpBtn = new QPushButton(frame_3);
        clearUpBtn->setObjectName(QStringLiteral("clearUpBtn"));
        clearUpBtn->setMinimumSize(QSize(0, 23));
        clearUpBtn->setMaximumSize(QSize(100, 23));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/images/edit-clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearUpBtn->setIcon(icon11);

        gridLayout_2->addWidget(clearUpBtn, 0, 3, 1, 1);

        ccradioButton = new QRadioButton(frame_3);
        ccradioButton->setObjectName(QStringLiteral("ccradioButton"));
        ccradioButton->setChecked(true);

        gridLayout_2->addWidget(ccradioButton, 0, 0, 1, 1);

        recvbyteslcdNumber = new QLCDNumber(frame_3);
        recvbyteslcdNumber->setObjectName(QStringLiteral("recvbyteslcdNumber"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(recvbyteslcdNumber->sizePolicy().hasHeightForWidth());
        recvbyteslcdNumber->setSizePolicy(sizePolicy1);
        recvbyteslcdNumber->setStyleSheet(QStringLiteral(""));

        gridLayout_2->addWidget(recvbyteslcdNumber, 0, 2, 1, 1);

        chradioButton = new QRadioButton(frame_3);
        chradioButton->setObjectName(QStringLiteral("chradioButton"));

        gridLayout_2->addWidget(chradioButton, 0, 1, 1, 1);


        verticalLayout_2->addWidget(frame_3);

        textBrowser = new QTextBrowser(groupBox_2);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout_2->addWidget(textBrowser);

        gridFrame = new QFrame(groupBox_2);
        gridFrame->setObjectName(QStringLiteral("gridFrame"));
        gridFrame->setMinimumSize(QSize(0, 0));
        gridFrame->setFrameShape(QFrame::WinPanel);
        gridFrame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(gridFrame);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pushButton_13 = new QPushButton(gridFrame);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setMinimumSize(QSize(0, 23));
        pushButton_13->setMaximumSize(QSize(100, 16777215));

        gridLayout_3->addWidget(pushButton_13, 0, 1, 1, 1);

        pushButton_11 = new QPushButton(gridFrame);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setMinimumSize(QSize(0, 23));
        pushButton_11->setMaximumSize(QSize(100, 23));

        gridLayout_3->addWidget(pushButton_11, 0, 0, 1, 1);

        pushButton_15 = new QPushButton(gridFrame);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setMinimumSize(QSize(0, 23));
        pushButton_15->setMaximumSize(QSize(100, 16777215));

        gridLayout_3->addWidget(pushButton_15, 0, 2, 1, 1);

        pushButton_12 = new QPushButton(gridFrame);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setMinimumSize(QSize(0, 23));
        pushButton_12->setMaximumSize(QSize(100, 16777215));

        gridLayout_3->addWidget(pushButton_12, 0, 5, 1, 1);

        pushButton_14 = new QPushButton(gridFrame);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setMinimumSize(QSize(0, 23));
        pushButton_14->setMaximumSize(QSize(100, 16777215));

        gridLayout_3->addWidget(pushButton_14, 0, 4, 1, 1);

        pushButton_16 = new QPushButton(gridFrame);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setMinimumSize(QSize(0, 23));
        pushButton_16->setMaximumSize(QSize(100, 23));

        gridLayout_3->addWidget(pushButton_16, 0, 3, 1, 1);


        verticalLayout_2->addWidget(gridFrame);

        gridFrame_2 = new QFrame(groupBox_2);
        gridFrame_2->setObjectName(QStringLiteral("gridFrame_2"));
        gridFrame_2->setMinimumSize(QSize(0, 0));
        gridFrame_2->setMaximumSize(QSize(16777215, 16777215));
        gridFrame_2->setFrameShape(QFrame::WinPanel);
        gridFrame_2->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(gridFrame_2);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        pushButton_7 = new QPushButton(gridFrame_2);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(0, 23));
        pushButton_7->setMaximumSize(QSize(100, 23));

        gridLayout_5->addWidget(pushButton_7, 1, 4, 1, 1);

        pushButton_5 = new QPushButton(gridFrame_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(0, 23));
        pushButton_5->setMaximumSize(QSize(100, 23));

        gridLayout_5->addWidget(pushButton_5, 1, 1, 1, 1);

        pushButton = new QPushButton(gridFrame_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(0, 23));
        pushButton->setMaximumSize(QSize(100, 23));

        gridLayout_5->addWidget(pushButton, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(gridFrame_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 23));
        pushButton_2->setMaximumSize(QSize(100, 23));

        gridLayout_5->addWidget(pushButton_2, 1, 3, 1, 1);

        pushButton_6 = new QPushButton(gridFrame_2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(0, 23));
        pushButton_6->setMaximumSize(QSize(100, 23));

        gridLayout_5->addWidget(pushButton_6, 1, 2, 1, 1);

        pushButton_8 = new QPushButton(gridFrame_2);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(0, 23));
        pushButton_8->setMaximumSize(QSize(100, 23));

        gridLayout_5->addWidget(pushButton_8, 1, 5, 1, 1);


        verticalLayout_2->addWidget(gridFrame_2);

        gridFrame1 = new QFrame(groupBox_2);
        gridFrame1->setObjectName(QStringLiteral("gridFrame1"));
        gridFrame1->setMinimumSize(QSize(0, 0));
        gridFrame1->setMaximumSize(QSize(16777215, 16777215));
        gridFrame1->setFrameShape(QFrame::WinPanel);
        gridFrame1->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(gridFrame1);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        pushButton_3 = new QPushButton(gridFrame1);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 23));
        pushButton_3->setMaximumSize(QSize(100, 23));

        gridLayout_4->addWidget(pushButton_3, 5, 3, 1, 1);

        Btn_VfyPwd = new QPushButton(gridFrame1);
        Btn_VfyPwd->setObjectName(QStringLiteral("Btn_VfyPwd"));
        Btn_VfyPwd->setMinimumSize(QSize(0, 23));
        Btn_VfyPwd->setMaximumSize(QSize(100, 23));

        gridLayout_4->addWidget(Btn_VfyPwd, 5, 1, 1, 1);

        Btn_GetTemplateNum = new QPushButton(gridFrame1);
        Btn_GetTemplateNum->setObjectName(QStringLiteral("Btn_GetTemplateNum"));
        Btn_GetTemplateNum->setMinimumSize(QSize(0, 23));
        Btn_GetTemplateNum->setMaximumSize(QSize(100, 23));

        gridLayout_4->addWidget(Btn_GetTemplateNum, 5, 2, 1, 1);

        pushButton_4 = new QPushButton(gridFrame1);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(0, 23));
        pushButton_4->setMaximumSize(QSize(100, 23));

        gridLayout_4->addWidget(pushButton_4, 5, 4, 1, 1);

        pushButton_9 = new QPushButton(gridFrame1);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(0, 23));
        pushButton_9->setMaximumSize(QSize(100, 23));

        gridLayout_4->addWidget(pushButton_9, 5, 5, 1, 1);

        pushButton_10 = new QPushButton(gridFrame1);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setMinimumSize(QSize(0, 23));
        pushButton_10->setMaximumSize(QSize(100, 23));

        gridLayout_4->addWidget(pushButton_10, 5, 6, 1, 1);


        verticalLayout_2->addWidget(gridFrame1);


        formLayout->setWidget(0, QFormLayout::FieldRole, groupBox_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 820, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        sizePolicy.setHeightForWidth(mainToolBar->sizePolicy().hasHeightForWidth());
        mainToolBar->setSizePolicy(sizePolicy);
        mainToolBar->setMinimumSize(QSize(0, 0));
        mainToolBar->setMaximumSize(QSize(16777215, 55));
        QFont font1;
        font1.setPointSize(9);
        mainToolBar->setFont(font1);
        mainToolBar->setCursor(QCursor(Qt::PointingHandCursor));
        mainToolBar->setFocusPolicy(Qt::StrongFocus);
        mainToolBar->setContextMenuPolicy(Qt::NoContextMenu);
        mainToolBar->setMovable(false);
        mainToolBar->setAllowedAreas(Qt::NoToolBarArea);
        mainToolBar->setIconSize(QSize(20, 20));
        mainToolBar->setFloatable(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(actionAdd);
        menu->addSeparator();
        menu->addAction(actionOpen);
        menu->addAction(actionClose);
        menu->addSeparator();
        menu->addAction(actionSave);
        menu->addAction(actionLoadfile);
        menu->addAction(actionWriteToFile);
        menu->addSeparator();
        menu->addAction(actionClearBytes);
        menu->addAction(actionCleanPort);
        menu->addSeparator();
        menu->addAction(actionExit);
        menu_2->addAction(actionAbout);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionClose);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionAdd);
        mainToolBar->addAction(actionLoadfile);
        mainToolBar->addAction(actionWriteToFile);
        mainToolBar->addAction(actionSave);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionClearBytes);
        mainToolBar->addAction(actionCleanPort);

        retranslateUi(MainWindow);

        baudRateComboBox->setCurrentIndex(12);
        dataBitsComboBox->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "HwFinger\346\214\207\347\272\271\346\250\241\345\235\227\350\260\203\350\257\225\345\212\251\346\211\213V1.0", 0));
        actionAdd->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\344\270\262\345\217\243", 0));
#ifndef QT_NO_TOOLTIP
        actionAdd->setToolTip(QApplication::translate("MainWindow", "\346\267\273\345\212\240\344\270\262\345\217\243\350\256\276\345\244\207\346\226\207\344\273\266", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionAdd->setStatusTip(QApplication::translate("MainWindow", "\346\267\273\345\212\240\344\270\262\345\217\243\350\256\276\345\244\207\346\226\207\344\273\266", 0));
#endif // QT_NO_STATUSTIP
        actionOpen->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", 0));
#ifndef QT_NO_STATUSTIP
        actionOpen->setStatusTip(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", 0));
#endif // QT_NO_STATUSTIP
        actionClose->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\344\270\262\345\217\243", 0));
#ifndef QT_NO_STATUSTIP
        actionClose->setStatusTip(QApplication::translate("MainWindow", "\345\205\263\351\227\255\344\270\262\345\217\243", 0));
#endif // QT_NO_STATUSTIP
        actionExit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\250\213\345\272\217", 0));
#ifndef QT_NO_STATUSTIP
        actionExit->setStatusTip(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\250\213\345\272\217", 0));
#endif // QT_NO_STATUSTIP
        actionAbout->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216HwFinger", 0));
#ifndef QT_NO_STATUSTIP
        actionAbout->setStatusTip(QApplication::translate("MainWindow", "\345\205\263\344\272\216HwFinger", 0));
#endif // QT_NO_STATUSTIP
        actionSave->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\225\260\346\215\256", 0));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\224\266\345\217\221\346\241\206\345\206\205\347\232\204\346\225\260\346\215\256", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSave->setStatusTip(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\224\266\345\217\221\346\241\206\345\206\205\347\232\204\346\225\260\346\215\256", 0));
#endif // QT_NO_STATUSTIP
        actionClearBytes->setText(QApplication::translate("MainWindow", "\350\256\241\346\225\260\346\270\205\351\233\266", 0));
#ifndef QT_NO_TOOLTIP
        actionClearBytes->setToolTip(QApplication::translate("MainWindow", "\346\270\205\351\233\266\345\267\262\346\224\266\345\210\260\347\232\204\345\255\227\350\212\202\346\225\260", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionClearBytes->setStatusTip(QApplication::translate("MainWindow", "\346\270\205\351\233\266\345\267\262\346\224\266\345\210\260\347\232\204\345\255\227\350\212\202\346\225\260", 0));
#endif // QT_NO_STATUSTIP
        actionLoadfile->setText(QApplication::translate("MainWindow", "\350\257\273\345\217\226\346\226\207\344\273\266", 0));
#ifndef QT_NO_TOOLTIP
        actionLoadfile->setToolTip(QApplication::translate("MainWindow", "\350\275\275\345\205\245\345\244\226\351\203\250\346\226\207\344\273\266\344\275\234\344\270\272\345\217\221\351\200\201\345\206\205\345\256\271", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionLoadfile->setStatusTip(QApplication::translate("MainWindow", "\350\275\275\345\205\245\345\244\226\351\203\250\346\226\207\344\273\266\344\275\234\344\270\272\345\217\221\351\200\201\345\206\205\345\256\271", 0));
#endif // QT_NO_STATUSTIP
        actionCleanPort->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\344\270\262\345\217\243", 0));
#ifndef QT_NO_TOOLTIP
        actionCleanPort->setToolTip(QApplication::translate("MainWindow", "\346\270\205\347\251\272\344\270\262\345\217\243\344\270\255I/O\346\225\260\346\215\256", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionCleanPort->setStatusTip(QApplication::translate("MainWindow", "\346\270\205\347\251\272\344\270\262\345\217\243\344\270\255I/O\346\225\260\346\215\256", 0));
#endif // QT_NO_STATUSTIP
        actionWriteToFile->setText(QApplication::translate("MainWindow", "\345\206\231\345\205\245\346\226\207\344\273\266", 0));
#ifndef QT_NO_TOOLTIP
        actionWriteToFile->setToolTip(QApplication::translate("MainWindow", "\345\260\206\350\257\273\345\217\226\346\225\260\346\215\256\345\206\231\345\205\245\345\210\260\346\226\207\344\273\266", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionWriteToFile->setStatusTip(QApplication::translate("MainWindow", "\345\260\206\350\257\273\345\217\226\346\225\260\346\215\256\345\206\231\345\205\245\345\210\260\346\226\207\344\273\266", 0));
#endif // QT_NO_STATUSTIP
        groupBox->setTitle(QApplication::translate("MainWindow", "\344\270\262\345\217\243\350\256\276\347\275\256", 0));
        label->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243", 0));
        label_2->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", 0));
        baudRateComboBox->clear();
        baudRateComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "50", 0)
         << QApplication::translate("MainWindow", "75", 0)
         << QApplication::translate("MainWindow", "110", 0)
         << QApplication::translate("MainWindow", "134", 0)
         << QApplication::translate("MainWindow", "150", 0)
         << QApplication::translate("MainWindow", "200", 0)
         << QApplication::translate("MainWindow", "300", 0)
         << QApplication::translate("MainWindow", "600", 0)
         << QApplication::translate("MainWindow", "1200", 0)
         << QApplication::translate("MainWindow", "1800", 0)
         << QApplication::translate("MainWindow", "2400", 0)
         << QApplication::translate("MainWindow", "4800", 0)
         << QApplication::translate("MainWindow", "9600", 0)
         << QApplication::translate("MainWindow", "14400", 0)
         << QApplication::translate("MainWindow", "19200", 0)
         << QApplication::translate("MainWindow", "38400", 0)
         << QApplication::translate("MainWindow", "56000", 0)
         << QApplication::translate("MainWindow", "57600", 0)
         << QApplication::translate("MainWindow", "76800", 0)
         << QApplication::translate("MainWindow", "115200", 0)
         << QApplication::translate("MainWindow", "128000", 0)
         << QApplication::translate("MainWindow", "256000", 0)
        );
        label_3->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", 0));
        dataBitsComboBox->clear();
        dataBitsComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "5", 0)
         << QApplication::translate("MainWindow", "6", 0)
         << QApplication::translate("MainWindow", "7", 0)
         << QApplication::translate("MainWindow", "8", 0)
        );
        label_4->setText(QApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215", 0));
        parityComboBox->clear();
        parityComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\227\240", 0)
         << QApplication::translate("MainWindow", "\345\245\207", 0)
         << QApplication::translate("MainWindow", "\345\201\266", 0)
        );
        label_5->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", 0));
        stopBitsComboBox->clear();
        stopBitsComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", 0)
         << QApplication::translate("MainWindow", "1.5", 0)
         << QApplication::translate("MainWindow", "2", 0)
        );
        obocheckBox->setText(QApplication::translate("MainWindow", "\350\277\236\347\273\255\345\217\221\351\200\201", 0));
        label_6->setText(QApplication::translate("MainWindow", "\351\227\264\351\232\224(\346\257\253\347\247\222)", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\345\217\221\351\200\201\346\225\260\346\215\256", 0));
#ifndef QT_NO_TOOLTIP
        sendAsHexcheckBox->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\344\273\245\345\215\201\345\205\255\350\277\233\345\210\266\346\226\271\345\274\217\345\217\221\351\200\201\346\225\260\346\215\256\357\274\210\351\273\230\350\256\244\344\270\272\345\255\227\347\254\246\346\226\271\345\274\217\357\274\211</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        sendAsHexcheckBox->setText(QApplication::translate("MainWindow", "\345\215\201\345\205\255\350\277\233\345\210\266\345\217\221\351\200\201", 0));
        sendmsgBtn->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", 0));
        toolButton->setText(QApplication::translate("MainWindow", "...", 0));
        groupBox_3->setTitle(QString());
        Btn_GetNum->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226\346\214\207\347\272\271\346\263\250\345\206\214\346\225\260", 0));
        Btn_DelAll->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\345\205\250\351\203\250\346\214\207\347\272\271", 0));
        Btn_DelOne->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\344\270\200\346\236\232\346\214\207\347\272\271", 0));
        Btn_EnrollOne->setText(QApplication::translate("MainWindow", "\346\263\250\345\206\214\344\270\200\346\236\232\346\214\207\347\272\271", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\346\216\245\346\224\266\346\225\260\346\215\256", 0));
        clearUpBtn->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\346\230\276\347\244\272", 0));
#ifndef QT_NO_TOOLTIP
        ccradioButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\344\273\245\345\255\227\347\254\246\346\226\271\345\274\217\346\230\276\347\244\272\346\225\260\346\215\256</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        ccradioButton->setText(QApplication::translate("MainWindow", "\345\255\227\347\254\246\345\275\242\345\274\217\346\230\276\347\244\272", 0));
#ifndef QT_NO_TOOLTIP
        recvbyteslcdNumber->setToolTip(QApplication::translate("MainWindow", "\345\267\262\346\216\245\346\224\266\345\255\227\350\212\202\346\225\260", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        chradioButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\344\273\245\345\215\201\345\205\255\350\277\233\345\210\266\346\226\271\345\274\217\346\230\276\347\244\272\346\225\260\346\215\256</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        chradioButton->setText(QApplication::translate("MainWindow", "\345\215\201\345\205\255\350\277\233\345\210\266\345\275\242\345\274\217\346\230\276\347\244\272", 0));
        pushButton_13->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\346\214\207\347\272\271\345\272\223", 0));
        pushButton_11->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\346\250\241\346\235\277", 0));
        pushButton_15->setText(QApplication::translate("MainWindow", "\346\257\224\345\257\271\344\270\244\346\236\232\346\214\207\347\272\271\347\211\271\345\276\201", 0));
        pushButton_12->setText(QApplication::translate("MainWindow", "\344\270\213\350\275\275\347\211\271\345\276\201\346\250\241\346\235\277\344\272\214", 0));
        pushButton_14->setText(QApplication::translate("MainWindow", "\344\270\213\350\275\275\347\211\271\345\276\201\346\250\241\346\235\277\344\270\200", 0));
        pushButton_16->setText(QApplication::translate("MainWindow", "\346\220\234\347\264\242\346\214\207\347\272\271", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "\345\233\276\345\203\217\347\224\237\346\210\220\347\211\271\345\276\201\344\272\214", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "\344\270\212\344\274\240\346\214\207\347\272\271\345\233\276\345\203\217", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\345\275\225\345\205\245\346\214\207\347\272\271\345\233\276\345\203\217", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "\345\233\276\345\203\217\347\224\237\346\210\220\347\211\271\345\276\201\344\270\200", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "\344\270\213\350\275\275\346\214\207\347\272\271\345\233\276\345\203\217", 0));
        pushButton_8->setText(QApplication::translate("MainWindow", "\347\211\271\345\276\201\345\220\210\346\210\220\346\250\241\346\235\277", 0));
#ifndef QT_NO_TOOLTIP
        gridFrame1->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_3->setText(QApplication::translate("MainWindow", "\344\270\212\344\274\240\347\211\271\345\276\201\346\250\241\346\235\277\344\270\200", 0));
        Btn_VfyPwd->setText(QApplication::translate("MainWindow", "\351\252\214\350\257\201\346\250\241\345\235\227\345\217\243\344\273\244", 0));
        Btn_GetTemplateNum->setText(QApplication::translate("MainWindow", "\350\257\273\345\217\226\346\234\211\346\225\210\346\250\241\346\235\277\346\225\260", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "\344\270\212\344\274\240\347\211\271\345\276\201\346\250\241\346\235\277\344\272\214", 0));
        pushButton_9->setText(QApplication::translate("MainWindow", "\345\255\230\345\202\250\346\250\241\346\235\277", 0));
        pushButton_10->setText(QApplication::translate("MainWindow", "\350\257\273\345\207\272\346\250\241\346\235\277", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\346\223\215\344\275\234(&C)", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\205\263\344\272\216(&A)", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
