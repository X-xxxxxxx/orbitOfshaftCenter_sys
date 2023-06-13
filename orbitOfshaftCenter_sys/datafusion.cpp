#include "datafusion.h"
#include"weighting.h"
#include"tuzuhe1.h"
#include"xiefangcha.h"
#include"HPO.h"

#include"MainWindow.h"
#include <QtCore/qstandardpaths.h>
#include <QtWidgets/qfiledialog.h>
#include <QBitmap>
#include <QPainter>

#include<atlstr.h>

#pragma comment( lib, "libmex.lib" )
#pragma comment( lib, "mclmcr.lib" )
#pragma comment( lib, "libeng.lib" )
#pragma comment( lib, "libmx.lib" )
#pragma comment( lib, "libmat.lib" )
#pragma comment( lib, "mclmcrrt.lib" )

#pragma comment( lib, "weighting.lib" )
#pragma comment( lib, "tuzuhe1.lib" )
#pragma comment( lib, "xiefangcha.lib" )
#pragma comment( lib, "HPO.lib" )


#include <exception>
#include <new>
#include <typeinfo>
#include <ios>
#include <stdexcept>
#include <future>


void datafusion::show_up()
{
    if (flag == 1)
    {
        if (flag1 > 1)
        {
            flag1--;
        }
        else
        {
            flag1 = 6;
        }
        //获取桌面路径
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/datafusion/weighting/") + QString::number(flag1) + ".jpg");
        QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
        ui.label->setPixmap(dest);
    }
    else if (flag == 2)
    {
        if (flag2 > 1)
        {
            flag2--;
        }
        else
        {
            flag2 = 11;
        }
        //获取桌面路径
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/datafusion/tuzuhe/") + QString::number(flag2) + ".jpg");
        QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
        ui.label->setPixmap(dest);
    }
    else if (flag == 3)
    {
        if (flag3 > 1)
        {
            flag3--;
        }
        else
        {
            flag3 = 5;
        }
        //获取桌面路径
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/datafusion/xiefangcha/")+QString::number(flag3) + ".jpg");
        QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
        ui.label->setPixmap(dest);
    }
    else if (flag == 4)
    {
        if (flag4 > 1)
        {
            flag4--;
        }
        else
        {
            flag4 = 6;
        }
        //获取桌面路径
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/datafusion/HPO/")+ QString::number(flag4) + ".jpg");
        QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
        ui.label->setPixmap(dest);
    }

}
void datafusion::shou_down()
{
    if (flag == 1)
    {
        if (flag1 <6)
        {
            flag1++;
        }
        else
        {
            flag1 = 1;
        }
        //获取桌面路径
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/datafusion/weighting/") + QString::number(flag1) + ".jpg");
        QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
        ui.label->setPixmap(dest);
    }
    else if (flag == 2)
    {
        if (flag2 <11)
        {
            flag2++;
        }
        else
        {
            flag2 = 1;
        }
        //获取桌面路径
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/datafusion/tuzuhe/") + QString::number(flag2) + ".jpg");
        QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
        ui.label->setPixmap(dest);
    }
    else if (flag == 3)
    {
        if (flag3 <5)
        {
            flag3++;
        }
        else
        {
            flag3 = 1;
        }
        //获取桌面路径
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/datafusion/xiefangcha/")+QString::number(flag3) + ".jpg");
        QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
        ui.label->setPixmap(dest);
    }
    else if (flag == 4)
    {
        if (flag4 <6)
        {
            flag4++;
        }
        else
        {
            flag4 = 1;
        }
        //获取桌面路径
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/datafusion/HPO/") + QString::number(flag4) + ".jpg");
        QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
        ui.label->setPixmap(dest);
    }
}




void datafusion::updateLabel()
{
    dateTimeLabel->setText(tr("<h3>%1</h3>").arg(QDateTime::currentDateTime().toString("yyyy-MM-d hh:mm:ss")));
}

void datafusion::to_mainwindow()
{
    this->close();
    MainWindow* m = new MainWindow;
    m->show();
}
void datafusion::myquit()
{
    this->close();
}



datafusion::datafusion(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
    ui.mainToolBar->hide();
    flag = 0;
    flag1 = 0;
    flag2 = 0;
    flag3 = 0;
    flag4 = 0;

    //融合

    /*背景
    QPalette pal = this->palette();
    QPixmap pixmap(":/image/26.jpg");
    QPixmap temp(pixmap.size());
    temp.fill(Qt::transparent);
    QPainter p1(&temp);
    p1.setCompositionMode(QPainter::CompositionMode_Source);
    p1.drawPixmap(0, 0, pixmap);
    p1.setCompositionMode(QPainter::CompositionMode_DestinationIn);

    根据QColor中第四个参数设置透明度，此处position的取值范围是0～255
    p1.fillRect(temp.rect(), QColor(0, 0, 0, 250));
    p1.end();
    pixmap = temp;
    pal.setBrush(QPalette::Background, QBrush(pixmap.scaled(this->size())));
    setPalette(pal);*/

    //setFixedSize(800, 600);//固定窗口大小
    this->setWindowTitle(QString::fromLocal8Bit("数据融合"));

    //状态栏
    bar = new QStatusBar(this);
    QLabel* authorLabel = new QLabel(QString::fromLocal8Bit("张勇，西安理工大学"), this);
    bar->addPermanentWidget(authorLabel, 0);
    //时间标签
    dateTimeLabel = new QLabel(tr("<h3>%1</h3>").arg(QDateTime::currentDateTime().toString("yyyy-MM-d hh:mm:ss")), this);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &datafusion::updateLabel);
    timer->start(1000);
    bar->addWidget(dateTimeLabel, 0);
    this->setStatusBar(bar);

    //主窗口
    connect(ui.pushButton_7, &QPushButton::clicked, this, &datafusion::to_mainwindow);
    //退出
    connect(ui.pushButton_8, &QPushButton::clicked, this, &datafusion::myquit);


    QIcon myicon1; //新建QIcon对象
    myicon1.addFile(tr(":/image/18.jpg")); //让QIcon对象指向想要的图标
    ui.pushButton->setIcon(myicon1); //给按钮添加图标
    ui.pushButton->setIconSize(QSize(113, 113));//重置图标大小
    ui.pushButton->setStyleSheet("background-color: #F6EBFF");
    ui.pushButton->setFocusPolicy(Qt::NoFocus);
    connect(ui.pushButton, &QPushButton::clicked, this, &datafusion::m_weighting);

    QIcon myicon2; //新建QIcon对象
    myicon2.addFile(tr(":/image/17.jpg")); //让QIcon对象指向想要的图标
    ui.pushButton_2->setIcon(myicon2); //给按钮添加图标
    ui.pushButton_2->setIconSize(QSize(113, 113));//重置图标大小
    ui.pushButton_2->setStyleSheet("background-color: #F6EBFF");
    ui.pushButton_2->setFocusPolicy(Qt::NoFocus);
    connect(ui.pushButton_2, &QPushButton::clicked, this, &datafusion::m_tuzuhe);


    QIcon myicon3; //新建QIcon对象
    myicon3.addFile(tr(":/image/19.jpg")); //让QIcon对象指向想要的图标
    ui.pushButton_3->setIcon(myicon3); //给按钮添加图标
    ui.pushButton_3->setIconSize(QSize(113, 113));//重置图标大小
    ui.pushButton_3->setStyleSheet("background-color: #F6EBFF");
    ui.pushButton_3->setFocusPolicy(Qt::NoFocus);
    connect(ui.pushButton_3, &QPushButton::clicked, this, &datafusion::m_xiefangcha);


    QIcon myicon4; //新建QIcon对象
    myicon4.addFile(tr(":/image/20.jpg")); //让QIcon对象指向想要的图标
    ui.pushButton_6->setIcon(myicon4); //给按钮添加图标
    ui.pushButton_6->setIconSize(QSize(113, 113));//重置图标大小
    ui.pushButton_6->setStyleSheet("background-color: #F6EBFF");
    ui.pushButton_6->setFocusPolicy(Qt::NoFocus);
    connect(ui.pushButton_6, &QPushButton::clicked, this, &datafusion::m_hpo);



    connect(ui.pushButton_4, &QPushButton::clicked, this, &datafusion::show_up);

    connect(ui.pushButton_5, &QPushButton::clicked, this, &datafusion::shou_down);

  

}

void datafusion::m_weighting()
{
    ui.label->clear();
    flag = 1;
    flag1 = 2;
    //获取桌面路径
    QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString dlgTitle = QString::fromLocal8Bit("选择文件"); //对话框标题
    QString filter = QString::fromLocal8Bit("所有文件(*.*)"); //文件过滤器
    QStringList fileList = QFileDialog::getOpenFileNames(this, dlgTitle, desktop_path, filter);

    QDir dir(desktop_path + QString::fromLocal8Bit("/result"));
    if (!dir.exists())
    {
        dir.mkdir(desktop_path + QString::fromLocal8Bit("/result"));
    }
    QDir dir1(desktop_path + QString::fromLocal8Bit("/result/datafusion"));
    if (!dir1.exists())
    {
        dir1.mkdir(desktop_path + QString::fromLocal8Bit("/result/datafusion"));
    }
    QDir dir2(desktop_path + QString::fromLocal8Bit("/result/datafusion/weighting"));
    if (!dir2.exists())
    {
        dir2.mkdir(desktop_path + QString::fromLocal8Bit("/result/datafusion/weighting"));
    }

    weightingInitialize();
    
    std::string str = fileList[0].toLocal8Bit().toStdString();
    const char* p = str.c_str();

    QString path = desktop_path + QString::fromLocal8Bit("/result/datafusion/weighting");
    std::string path1 = path.toLocal8Bit().toStdString();
    const char* p1 = path1.c_str();

    weighting(p,p1);

     weightingTerminate();
 

    QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/datafusion/weighting/1.jpg"));
    QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
    ui.label->setPixmap(dest);
    QMessageBox::information(this, QString::fromLocal8Bit("消息"), QString::fromLocal8Bit("加权融合完成"), QMessageBox::Ok, QMessageBox::Ok);


}

void datafusion::m_tuzuhe()
{
    ui.label->clear();
    

    flag = 2;
    flag2 = 2;
    //获取桌面路径
    QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString dlgTitle = QString::fromLocal8Bit("选择文件"); //对话框标题
    QString filter = QString::fromLocal8Bit("所有文件(*.*)"); //文件过滤器
    QStringList fileList = QFileDialog::getOpenFileNames(this, dlgTitle, desktop_path, filter);

    QDir dir(desktop_path + QString::fromLocal8Bit("/result"));
    if (!dir.exists())
    {
        dir.mkdir(desktop_path + QString::fromLocal8Bit("/result"));
    }
    QDir dir1(desktop_path + QString::fromLocal8Bit("/result/datafusion"));
    if (!dir1.exists())
    {
        dir1.mkdir(desktop_path + QString::fromLocal8Bit("/result/datafusion"));
    }
    QDir dir2(desktop_path + QString::fromLocal8Bit("/result/datafusion/tuzuhe"));
    if (!dir2.exists())
    {
        dir2.mkdir(desktop_path + QString::fromLocal8Bit("/result/datafusion/tuzuhe"));
    }

   
  
    tuzuhe1Initialize();
   
    std::string str = fileList[0].toLocal8Bit().toStdString();
    const char* p = str.c_str();
    QString path = desktop_path + QString::fromLocal8Bit("/result/datafusion/tuzuhe");
    std::string path1 = path.toLocal8Bit().toStdString();
    const char* p1 = path1.c_str();

    tuzuhe1(p,p1);

    tuzuhe1Terminate();
   

    QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/datafusion/tuzuhe/1.jpg"));
    QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
    ui.label->setPixmap(dest);
    QMessageBox::information(this, QString::fromLocal8Bit("消息"), QString::fromLocal8Bit("凸组合完成"), QMessageBox::Ok, QMessageBox::Ok);


}
void datafusion::m_xiefangcha()
{
    ui.label->clear();
    flag= 3;
    flag3 = 2;
    //获取桌面路径
    QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString dlgTitle = QString::fromLocal8Bit("选择文件"); //对话框标题
    QString filter = QString::fromLocal8Bit("所有文件(*.*)"); //文件过滤器
    QStringList fileList = QFileDialog::getOpenFileNames(this, dlgTitle, desktop_path, filter);

    QDir dir(desktop_path + QString::fromLocal8Bit("/result"));
    if (!dir.exists())
    {
        dir.mkdir(desktop_path + QString::fromLocal8Bit("/result"));
    }
    QDir dir1(desktop_path + QString::fromLocal8Bit("/result/datafusion"));
    if (!dir1.exists())
    {
        dir1.mkdir(desktop_path + QString::fromLocal8Bit("/result/datafusion"));
    }
    QDir dir2(desktop_path + QString::fromLocal8Bit("/result/datafusion/xiefangcha"));
    if (!dir2.exists())
    {
        dir2.mkdir(desktop_path + QString::fromLocal8Bit("/result/datafusion/xiefangcha"));
    }
   
   
    xiefangchaInitialize();
    
    QString path = desktop_path + QString::fromLocal8Bit("/result/datafusion/xiefangcha");
    std::string path1 = path.toLocal8Bit().toStdString();
    const char* p1 = path1.c_str();

    std::string str = fileList[0].toLocal8Bit().toStdString();
    const char* p = str.c_str();
    

    xiefangcha(p,p1);

   

    xiefangchaTerminate();
    

    QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/datafusion/xiefangcha/1.jpg"));
    QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
    ui.label->setPixmap(dest);
    QMessageBox::information(this, QString::fromLocal8Bit("消息"), QString::fromLocal8Bit("协方差交叉融合完成"), QMessageBox::Ok, QMessageBox::Ok);

}

void datafusion::m_hpo()
{
    ui.label->clear();
    flag = 4;
    flag4 = 2;
    //获取桌面路径
    QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString dlgTitle = QString::fromLocal8Bit("选择文件"); //对话框标题
    QString filter = QString::fromLocal8Bit("所有文件(*.*)"); //文件过滤器
    QStringList fileList = QFileDialog::getOpenFileNames(this, dlgTitle, desktop_path, filter);



    QDir dir(desktop_path + QString::fromLocal8Bit("/result"));
    if (!dir.exists())
    {
        dir.mkdir(desktop_path + QString::fromLocal8Bit("/result"));
    }
    QDir dir1(desktop_path + QString::fromLocal8Bit("/result/datafusion"));
    if (!dir1.exists())
    {
        dir1.mkdir(desktop_path + QString::fromLocal8Bit("/result/datafusion"));
    }
    QDir dir2(desktop_path + QString::fromLocal8Bit("/result/datafusion/HPO"));
    if (!dir2.exists())
    {
        dir2.mkdir(desktop_path + QString::fromLocal8Bit("/result/datafusion/HPO"));
    }

    HPOInitialize();
    
    std::string str = fileList[0].toLocal8Bit().toStdString();

    const char* p = str.c_str();
  
    QString path = desktop_path + QString::fromLocal8Bit("/result/datafusion/HPO");
    std::string path1 = path.toLocal8Bit().toStdString();
    const char* p1 = path1.c_str();

    HPO(p,p1);
    HPOTerminate();
  
   

    QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/datafusion/HPO/1.jpg"));
    QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
    ui.label->setPixmap(dest);
    QMessageBox::information(this, QString::fromLocal8Bit("消息"), QString::fromLocal8Bit("HPO融合完成"), QMessageBox::Ok, QMessageBox::Ok);

}


datafusion::~datafusion()
{

}
