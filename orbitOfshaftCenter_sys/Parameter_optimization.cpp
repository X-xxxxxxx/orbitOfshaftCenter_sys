
#pragma once
#include "Parameter_optimization.h"
#include"MainWindow.h"

#include"PSO.h"
#include"HBA.h"
#include"DE.h"
#include<qmessagebox.h>
#include<qstandardpaths.h>
#include<iostream>
#include<qdir.h>
#include<fstream>
#include<qstring.h>
#include<string>
#include<qdialog.h>
#include<thread>
#include<qthread.h>
#include<qlabel.h>
#include<qdialog.h>
#include <QBitmap>
#include <QPainter>
#include<qstring.h>


#include"word.h"

using namespace std;

#pragma comment( lib, "libmex.lib" )
#pragma comment( lib, "mclmcr.lib" )
#pragma comment( lib, "libeng.lib" )
#pragma comment( lib, "libmx.lib" )
#pragma comment( lib, "libmat.lib" )
#pragma comment( lib, "mclmcrrt.lib" )

#pragma comment( lib, "PSO.lib" )
#pragma comment( lib, "HBA.lib" )
#pragma comment( lib, "DE.lib" )

#include<qdebug.h>

void Parameter_optimization::saveword()
{
    QString filePath = "C:\\Users\\X_xx\\Desktop\\result1.docx";

    QFile file(filePath);
    if (file.exists())
    {
        file.remove();
    }

    QWord word;
    word.createNewWord(filePath);

    //先创建固定表头等内容
    word.setPageOrientation(0);			//页面纵向
    word.setWordPageView(3);			//页面视图
    word.insertMoveDown();				//插入回车
    word.setFontSize(20);				//字体大小
    word.setParagraphAlignment(0);		//下面文字置中
    word.setFontBold(true);				//字体加粗
    word.insertText((QString::fromLocal8Bit("轴心轨迹测量系统结果报告")));//插入文字
    word.setFontBold(false);			//字体加粗
    word.insertMoveDown();              //插入回车
    word.setParagraphAlignment(1);		//下面文字置左
    word.setFontSize(10);
    word.insertMoveDown();



    word.intsertTable(4, 1);//插入表格 10行 3列
    
    QString text = QString::fromLocal8Bit("基于摄影测量的旋转机械轴心轨迹测量系统是一套集相机标定、图像识别，中心坐标定位、轨迹重建、数据融合等功能的软件系统。该软件根据所输入的数据可实现对单、双目相机的标定，标志点图像信息的提取，异类测量数据的融合，并输出测试报告。");
    word.setCellString(1, 1, text);

    QString text1 = QString::fromLocal8Bit("上图为基于摄影测量的旋转机械轴心轨迹测试三维轨迹图，分别为同一组实验数据采用三角测量法和立体像对空间前方交会方法解算出的三维轴心轨迹。");
    word.setCellString(2, 1, text1);

    QString imagepath = QString::fromLocal8Bit("C:\\Users\\X_xx\\Desktop\\result\\parameter_optimization\\PSO\\PSO.jpg");
    word.insertCellPic(2, 1, imagepath);
    
    QString imagepath1 = QString::fromLocal8Bit("C:\\Users\\Gao\\Desktop\\结果\\参数优化\\粒子群\\PSO.jpg");
    word.insertCellPic(2, 1, imagepath1);

    std::string str[9] = { "Cx","Cy","Vx","Vy","k1","k2","p1","p2","p3" };

    QString text3 = QString::fromLocal8Bit("基于粒子群的相机参数优化结果如下所示：");
    word.setCellString(3, 1, text3);


    QString temp= QString::fromLocal8Bit("基于粒子群的相机参数优化结果如下所示：")+'\n';
    for (int i = 0; i < 9; i++)
    {
        temp = temp+QString::fromStdString(str[i]) + ":" + QString::number(num[i], 'f', 10);
        temp = temp + '\n';
    }
    word.setCellString(3, 1, temp);
    

    QString text4= QString::fromLocal8Bit("审阅人：") + '\n'+ QString::fromLocal8Bit("日期：");
    word.setCellString(4, 1, text4);

    word.close();                   //关闭word
    
}




void Parameter_optimization::updateLabel()
{
    dateTimeLabel->setText(tr("<h3>%1</h3>").arg(QDateTime::currentDateTime().toString("yyyy-MM-d hh:mm:ss")));
}

Parameter_optimization::Parameter_optimization(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

    //参数优化
    ui.mainToolBar->hide();
    ////背景
    //QPalette pal = this->palette();
    //QPixmap pixmap(":/image/23.jpg");
    //QPixmap temp(pixmap.size());
    //temp.fill(Qt::transparent);
    //QPainter p1(&temp);
    //p1.setCompositionMode(QPainter::CompositionMode_Source);
    //p1.drawPixmap(0, 0, pixmap);
    //p1.setCompositionMode(QPainter::CompositionMode_DestinationIn);

    ////根据QColor中第四个参数设置透明度，此处position的取值范围是0～255
    //p1.fillRect(temp.rect(), QColor(0, 0, 0, 250));
    //p1.end();
    //pixmap = temp;
    //pal.setBrush(QPalette::Background, QBrush(pixmap.scaled(this->size())));
    //setPalette(pal);



    flag = 0;
    //setFixedSize(2000, 600);//固定窗口大小
    this->setWindowTitle(QString::fromLocal8Bit("相机标定参数优化"));

    //状态栏
    bar = new QStatusBar(this);
    QLabel* authorLabel = new QLabel(QString::fromLocal8Bit("张勇，西安理工大学"), this);
    bar->addPermanentWidget(authorLabel, 0);
    //时间标签
    dateTimeLabel = new QLabel(tr("<h3>%1</h3>").arg(QDateTime::currentDateTime().toString("yyyy-MM-d hh:mm:ss")), this);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Parameter_optimization::updateLabel);
    timer->start(1000);
    bar->addWidget(dateTimeLabel, 0);
    this->setStatusBar(bar);


    //粒子群  flag=1;
    QIcon myicon; //新建QIcon对象
    myicon.addFile(tr(":/image/6.jpg")); //让QIcon对象指向想要的图标
    ui.pushButton->setIcon(myicon); //给按钮添加图标
    ui.pushButton->setIconSize(QSize(113, 113));//重置图标大小
    ui.pushButton->setStyleSheet("background-color: #F6EBFF");
    ui.pushButton->setFocusPolicy(Qt::NoFocus);


    connect(ui.pushButton, &QPushButton::clicked, this, &Parameter_optimization::pso);


    //蜜獾   flag=2;
    QIcon myicon1; //新建QIcon对象
    myicon1.addFile(tr(":/image/7.jpg")); //让QIcon对象指向想要的图标
    ui.pushButton_2->setIcon(myicon1); //给按钮添加图标
    ui.pushButton_2->setIconSize(QSize(113, 113));//重置图标大小
    ui.pushButton_2->setStyleSheet("background-color: #F6EBFF");
    ui.pushButton_2->setFocusPolicy(Qt::NoFocus);
    connect(ui.pushButton_2, &QPushButton::clicked, this, &Parameter_optimization::hba);

    
   

    //差分进化粒子群   flag=4;
    QIcon myicon3; //新建QIcon对象
    myicon3.addFile(tr(":/image/9.jpg")); //让QIcon对象指向想要的图标
    ui.pushButton_6->setIcon(myicon3); //给按钮添加图标
    ui.pushButton_6->setIconSize(QSize(113, 113));//重置图标大小
    ui.pushButton_6->setStyleSheet("background-color: #F6EBFF");
    ui.pushButton_6->setFocusPolicy(Qt::NoFocus);
    connect(ui.pushButton_6, &QPushButton::clicked, this, &Parameter_optimization::de);


    //显示图像
    connect(ui.pushButton_4, &QPushButton::clicked, this, &Parameter_optimization::show_image);

    //显示参数
    connect(ui.pushButton_5, &QPushButton::clicked, this, &Parameter_optimization::show_parameter);

    //回主窗口
    connect(ui.pushButton_7, &QPushButton::clicked, this, &Parameter_optimization::to_mainwindow);

    //退出
    connect(ui.pushButton_8, &QPushButton::clicked, this, &Parameter_optimization::myquit);

    connect(ui.pushButton_9, &QPushButton::clicked, this, &Parameter_optimization::saveword);

    
}

void Parameter_optimization::myquit()
{
    this->close();
}

void Parameter_optimization::to_mainwindow()
{
    this->close();
    MainWindow *m=new MainWindow;
    m->show();
}
void Parameter_optimization::show_image()
{
    if(flag == 1)
    {
        //获取桌面路径
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/parameter_optimization/PSO/PSO.jpg"));
        QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
        ui.label->setPixmap(dest);
    }
    if (flag == 2)
    {
        //获取桌面路径
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/parameter_optimization/HBA/HBA.jpg"));
        QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
        ui.label->setPixmap(dest);
    }
    if (flag == 3)
    {
      
    }
    if (flag == 4)
    {
        //获取桌面路径
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/parameter_optimization/DE/DE.jpg"));
        QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
        ui.label->setPixmap(dest);
    }
}

void Parameter_optimization::show_parameter()
{
    if (flag == 1)
    {
        //获取桌面路径
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        ifstream ifs;
        std::string path = desktop_path.toLocal8Bit().toStdString() + "/result/parameter_optimization/PSO/result.txt";
        ifs.open(path, ios::in);

        std::string buf;
        QString str;
        str = QString::fromLocal8Bit("优化后的参数Cx Cy u v k1 k2 k3 p1 p2分别为");
        str += '\n';
        while (getline(ifs, buf))
        {
            str += QString::fromStdString(buf);
            str += '\n';
        }
        ifs.close();
        ui.label->setText(str);
    }
    if (flag == 2)
    {
        //获取桌面路径
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        ifstream ifs;
        std::string path = desktop_path.toLocal8Bit().toStdString() + "/result/parameter_optimization/HBA/result.txt";
        ifs.open(path, ios::in);

        std::string buf;
        QString str;
        str = QString::fromLocal8Bit("优化后的参数Cx Cy u v k1 k2 k3 p1 p2分别为");
        str += '\n';
        while (getline(ifs, buf))
        {
            str += QString::fromStdString(buf);
            str += '\n';
        }
        ifs.close();
        ui.label->setText(str);
      
    }
    if (flag == 3)
    {
       
    }
    if (flag == 4)
    {
        //获取桌面路径
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        ifstream ifs;
        std::string path = desktop_path.toLocal8Bit().toStdString() + "/result/parameter_optimization/DE/result.txt";
        ifs.open(path, ios::in);

        std::string buf;
        QString str;
        str = QString::fromLocal8Bit("优化后的参数Cx Cy u v k1 k2 k3 p1 p2分别为");
        str += '\n';
        while (getline(ifs, buf))
        {
            str += QString::fromStdString(buf);
            str += '\n';
        }
        ifs.close();
        ui.label->setText(str);
    }
}



//*****************************粒子群*****************************
void Parameter_optimization::pso()
{

    flag = 1;
    ui.label->clear();

    //获取桌面路径
    QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QDir dir(desktop_path + QString::fromLocal8Bit("/result"));
    if (!dir.exists())
    {
        dir.mkdir(desktop_path + QString::fromLocal8Bit("/result"));
    }
    QDir dir1(desktop_path + QString::fromLocal8Bit("/result/parameter_optimization"));
    if (!dir1.exists())
    {
        dir1.mkdir(desktop_path + QString::fromLocal8Bit("/result/parameter_optimization"));
    }
    QDir dir2(desktop_path + QString::fromLocal8Bit("/result/parameter_optimization/PSO"));
    if (!dir2.exists())
    {
        dir2.mkdir(desktop_path + QString::fromLocal8Bit("/result/parameter_optimization/PSO"));
    }

    PSOInitialize();
    mwArray a(1, 9, mxDOUBLE_CLASS,mxREAL);

    QString path = desktop_path + QString::fromLocal8Bit("/result/parameter_optimization/PSO");
    std::string path1 = path.toLocal8Bit().toStdString();
    const char* p = path1.c_str();

    PSO(1, a,p);
    
    ofstream ofs;
    std::string path2 = desktop_path.toLocal8Bit().toStdString() + "/result/parameter_optimization/PSO/result.txt";
    ofs.open(path2, ios::out);
   
    for (int i = 1; i < 10; i++)
    {
        ofs << a.Get(1,i) << endl;
        num[i - 1] = a.Get(1, i);
    }
    ofs.close();
    PSOTerminate();

    QMessageBox::information(this,QString::fromLocal8Bit("消息"),QString::fromLocal8Bit("粒子群优化完成"),QMessageBox::Ok,QMessageBox::Ok);

   
}


//*****************************蜜獾*****************************
void Parameter_optimization::hba()
{
    flag = 2;
    ui.label->clear();
    //获取桌面路径
    QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QDir dir(desktop_path + QString::fromLocal8Bit("/result"));
    if (!dir.exists())
    {
        dir.mkdir(desktop_path + QString::fromLocal8Bit("/result"));
    }
    QDir dir1(desktop_path + QString::fromLocal8Bit("/result/parameter_optimization"));
    if (!dir1.exists())
    {
        dir1.mkdir(desktop_path + QString::fromLocal8Bit("/result/parameter_optimization"));
    }
    QDir dir2(desktop_path + QString::fromLocal8Bit("/result/parameter_optimization/HBA"));
    if (!dir2.exists())
    {
        dir2.mkdir(desktop_path + QString::fromLocal8Bit("/result/parameter_optimization/HBA"));
    }

    

    HBAInitialize();
    mwArray a(1, 9, mxDOUBLE_CLASS, mxREAL);
    QString path = desktop_path + QString::fromLocal8Bit("/result/parameter_optimization/HBA");
    std::string path1 = path.toLocal8Bit().toStdString();
    const char* p = path1.c_str();

    HBA(1, a,p);

    ofstream ofs;
    std::string path2 = desktop_path.toLocal8Bit().toStdString() + "/result/parameter_optimization/HBA/result.txt";
    ofs.open(path2, ios::out);

    for (int i = 1; i < 10; i++)
    {
        ofs << a.Get(1, i) << endl;
        num[i - 1] = a.Get(1, i);
    }
    ofs.close();
    HBATerminate();
    QMessageBox::information(this, QString::fromLocal8Bit("消息"), QString::fromLocal8Bit("蜜獾优化完成"), QMessageBox::Ok, QMessageBox::Ok);
}

//*****************************遗传算法*****************************




//*****************************差分进化粒子群*****************************
void Parameter_optimization::de()
{
    flag = 4;
    ui.label->clear();
    //获取桌面路径
    QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QDir dir(desktop_path + QString::fromLocal8Bit("/result"));
    if (!dir.exists())
    {
        dir.mkdir(desktop_path + QString::fromLocal8Bit("/result"));
    }
    QDir dir1(desktop_path + QString::fromLocal8Bit("/result/parameter_optimization"));
    if (!dir1.exists())
    {
        dir1.mkdir(desktop_path + QString::fromLocal8Bit("/result/parameter_optimization"));
    }
    QDir dir2(desktop_path + QString::fromLocal8Bit("/result/parameter_optimization/DE"));
    if (!dir2.exists())
    {
        dir2.mkdir(desktop_path + QString::fromLocal8Bit("/result/parameter_optimization/DE"));
    }

    DEInitialize();
    mwArray a(1, 9, mxDOUBLE_CLASS, mxREAL);
    QString path = desktop_path + QString::fromLocal8Bit("/result/parameter_optimization/DE");
    std::string path1 = path.toLocal8Bit().toStdString();
    const char* p = path1.c_str();

    DE(1, a,p);

    ofstream ofs;
    std::string path2 = desktop_path.toLocal8Bit().toStdString() + "/result/parameter_optimization/DE/result.txt";
    ofs.open(path2, ios::out);

    for (int i = 1; i < 10; i++)
    {
        ofs << a.Get(1, i) << endl;
        num[i - 1] = a.Get(1, i);
    }
    ofs.close();
    DETerminate();
    QMessageBox::information(this, QString::fromLocal8Bit("消息"), QString::fromLocal8Bit("差分进化粒子群优化完成"), QMessageBox::Ok, QMessageBox::Ok);

}

Parameter_optimization::~Parameter_optimization()
{


}
