#include "Axis_trajectory_reconstruction.h"
#include "MainWindow.h"
#include <QtCore/qstandardpaths.h>
#include <QtWidgets/qfiledialog.h>

#include"two_dimensional.h"
#include"three_dimensional.h"
#include"x_y.h"

#include <QBitmap>
#include <QPainter>

#pragma comment( lib, "libmex.lib" )
#pragma comment( lib, "mclmcr.lib" )
#pragma comment( lib, "libeng.lib" )
#pragma comment( lib, "libmx.lib" )
#pragma comment( lib, "libmat.lib" )
#pragma comment( lib, "mclmcrrt.lib" )

#pragma comment( lib, "two_dimensional.lib" )
#pragma comment( lib, "three_dimensional.lib" )
#pragma comment( lib, "x_y.lib" )

void Axis_trajectory_reconstruction::updateLabel()
{
	dateTimeLabel->setText(tr("<h3>%1</h3>").arg(QDateTime::currentDateTime().toString("yyyy-MM-d hh:mm:ss")));
}

void Axis_trajectory_reconstruction::to_mainwindow()
{
    this->close();
    MainWindow* m = new MainWindow;
    m->show();
}
void Axis_trajectory_reconstruction::myquit()
{
    this->close();
}

Axis_trajectory_reconstruction::Axis_trajectory_reconstruction(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

    ui.mainToolBar->hide();
    //轴心轨迹重建
    
    ////背景
    //QPalette pal = this->palette();
    //QPixmap pixmap(":/image/25.jpg");
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



    //setFixedSize(800, 600);//固定窗口大小
    this->setWindowTitle(QString::fromLocal8Bit("轴心轨迹重建"));

    //状态栏；
   bar = new QStatusBar(this);
    QLabel* authorLabel = new QLabel(QString::fromLocal8Bit("张勇，西安理工大学"), this);
    bar->addPermanentWidget(authorLabel, 0);
    //时间标签
    dateTimeLabel = new QLabel(tr("<h3>%1</h3>").arg(QDateTime::currentDateTime().toString("yyyy-MM-d hh:mm:ss")), this);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Axis_trajectory_reconstruction::updateLabel);
    timer->start(1000);
    bar->addWidget(dateTimeLabel, 0);
    this->setStatusBar(bar);

    //主窗口
    connect(ui.pushButton_7, &QPushButton::clicked, this, &Axis_trajectory_reconstruction::to_mainwindow);
    //退出
    connect(ui.pushButton_8, &QPushButton::clicked, this, &Axis_trajectory_reconstruction::myquit);


    QIcon myicon1; //新建QIcon对象
    myicon1.addFile(tr(":/image/14.jpg")); //让QIcon对象指向想要的图标
    ui.pushButton->setIcon(myicon1); //给按钮添加图标
    ui.pushButton->setIconSize(QSize(113, 113));//重置图标大小
    ui.pushButton->setStyleSheet("background-color: #F6EBFF");
    ui.pushButton->setFocusPolicy(Qt::NoFocus);
    connect(ui.pushButton, &QPushButton::clicked, this, &Axis_trajectory_reconstruction::cg);

    QIcon myicon2; //新建QIcon对象
    myicon2.addFile(tr(":/image/16.jpg")); //让QIcon对象指向想要的图标
    ui.pushButton_2->setIcon(myicon2); //给按钮添加图标
    ui.pushButton_2->setIconSize(QSize(113, 113));//重置图标大小
    ui.pushButton_2->setStyleSheet("background-color: #F6EBFF");
    ui.pushButton_2->setFocusPolicy(Qt::NoFocus);
    connect(ui.pushButton_2, &QPushButton::clicked, this, &Axis_trajectory_reconstruction::cg1);
   

    QIcon myicon3; //新建QIcon对象
    myicon3.addFile(tr(":/image/15.jpg")); //让QIcon对象指向想要的图标
    ui.pushButton_3->setIcon(myicon3); //给按钮添加图标
    ui.pushButton_3->setIconSize(QSize(113, 113));//重置图标大小
    ui.pushButton_3->setStyleSheet("background-color: #F6EBFF");
    ui.pushButton_3->setFocusPolicy(Qt::NoFocus);
    connect(ui.pushButton_3, &QPushButton::clicked, this, &Axis_trajectory_reconstruction::cg2);


    connect(ui.pushButton_4, &QPushButton::clicked, this, &Axis_trajectory_reconstruction::show_up);

    connect(ui.pushButton_5, &QPushButton::clicked, this, &Axis_trajectory_reconstruction::shou_down);
}

void Axis_trajectory_reconstruction::show_up()
{
    if (flag == 1)
    {
        if (flag1 > 1)
        {
            flag1--;
        }
        else
        {
            flag1 = 5;
        }
        //获取桌面路径
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/Axis_trajectory_reconstruction/two_dimensional/") + QString::number(flag1) + ".jpg");
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
            flag2 = 3;
        }
        //获取桌面路径
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/Axis_trajectory_reconstruction/three_dimensional/") + QString::number(flag2) + ".jpg");
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
            flag3 = 4;
        }
        //获取桌面路径
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/Axis_trajectory_reconstruction/XY/") + QString::number(flag3) + ".jpg");
        QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
        ui.label->setPixmap(dest);
    }
}
void Axis_trajectory_reconstruction::shou_down()
{
    if (flag == 1)
    {
        if (flag1 < 5)
        {
            flag1++;
        }
        else
        {
            flag1 = 1;
        }
        //获取桌面路径
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/Axis_trajectory_reconstruction/two_dimensional/") + QString::number(flag1) + ".jpg");
        QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
        ui.label->setPixmap(dest);
    }
    else if (flag == 2)
    {
        if (flag2 < 3)
        {
            flag2++;
        }
        else
        {
            flag2 = 1;
        }
        //获取桌面路径
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/Axis_trajectory_reconstruction/three_dimensional/") + QString::number(flag2) + ".jpg");
        QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
        ui.label->setPixmap(dest);
    }
    else if (flag == 3)
    {
        if (flag3 < 4)
        {
            flag3++;
        }
        else
        {
            flag3 = 1;
        }
        //获取桌面路径
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/Axis_trajectory_reconstruction/XY/") + QString::number(flag3) + ".jpg");
        QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
        ui.label->setPixmap(dest);
    }
}


void Axis_trajectory_reconstruction::cg()
{
    ui.label->clear();
    flag = 1;
    flag1 = 2;
    QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString dlgTitle = QString::fromLocal8Bit("选择文件"); //对话框标题
    QString filter = QString::fromLocal8Bit("所有文件(*.*)"); //文件过滤器
    QStringList fileList = QFileDialog::getOpenFileNames(this, dlgTitle, desktop_path, filter);

    QDir dir(desktop_path + QString::fromLocal8Bit("/result"));
    if (!dir.exists())
    {
        dir.mkdir(desktop_path + QString::fromLocal8Bit("/result"));
    }
    QDir dir1(desktop_path + QString::fromLocal8Bit("/result/Axis_trajectory_reconstruction"));
    if (!dir1.exists())
    {
        dir1.mkdir(desktop_path + QString::fromLocal8Bit("/result/Axis_trajectory_reconstruction"));
    }
    QDir dir2(desktop_path + QString::fromLocal8Bit("/result/Axis_trajectory_reconstruction/two_dimensional"));
    if (!dir2.exists())
    {
        dir2.mkdir(desktop_path + QString::fromLocal8Bit("/result/Axis_trajectory_reconstruction/two_dimensional"));
    }

    std::string str1 = fileList[0].toLocal8Bit().toStdString();
    const char* p1 = str1.c_str();

    std::string str2 = fileList[1].toLocal8Bit().toStdString();
    const char* p2 = str2.c_str();

    std::string str3 = fileList[2].toLocal8Bit().toStdString();
    const char* p3 = str3.c_str();

    two_dimensionalInitialize();

    

    QString path = desktop_path + QString::fromLocal8Bit("/result/Axis_trajectory_reconstruction/two_dimensional");
    std::string path1 = path.toLocal8Bit().toStdString();
    const char* p4 = path1.c_str();

    two_dimensional(p1, p2,p3,p4);

    two_dimensionalTerminate();

    QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/Axis_trajectory_reconstruction/two_dimensional/1.jpg"));
    QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
    ui.label->setPixmap(dest);
    QMessageBox::information(this, QString::fromLocal8Bit("消息"), QString::fromLocal8Bit("轴心轨迹重构二维完成"), QMessageBox::Ok, QMessageBox::Ok);


}

void Axis_trajectory_reconstruction::cg2()
{
    flag = 2;
    flag2 = 2;

    ui.label->clear();
    QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString dlgTitle = QString::fromLocal8Bit("选择文件"); //对话框标题
    QString filter = QString::fromLocal8Bit("所有文件(*.*)"); //文件过滤器
    QStringList fileList = QFileDialog::getOpenFileNames(this, dlgTitle, desktop_path, filter);

    QDir dir(desktop_path + QString::fromLocal8Bit("/result"));
    if (!dir.exists())
    {
        dir.mkdir(desktop_path + QString::fromLocal8Bit("/result"));
    }
    QDir dir1(desktop_path + QString::fromLocal8Bit("/result/Axis_trajectory_reconstruction"));
    if (!dir1.exists())
    {
        dir1.mkdir(desktop_path + QString::fromLocal8Bit("/result/Axis_trajectory_reconstruction"));
    }
    QDir dir2(desktop_path + QString::fromLocal8Bit("/result/Axis_trajectory_reconstruction/three_dimensional"));
    if (!dir2.exists())
    {
        dir2.mkdir(desktop_path + QString::fromLocal8Bit("/result/Axis_trajectory_reconstruction/three_dimensional"));
    }

    std::string str1 = fileList[0].toLocal8Bit().toStdString();
    const char* p1 = str1.c_str();

    std::string str2 = fileList[1].toLocal8Bit().toStdString();
    const char* p2 = str2.c_str();

    std::string str3 = fileList[2].toLocal8Bit().toStdString();
    const char* p3 = str3.c_str();

    three_dimensionalInitialize();

    QString path = desktop_path + QString::fromLocal8Bit("/result/Axis_trajectory_reconstruction/three_dimensional");
    std::string path1 = path.toLocal8Bit().toStdString();
    const char* p4 = path1.c_str();
    three_dimensional(p1, p2, p3,p4);

    three_dimensionalTerminate();

    QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/Axis_trajectory_reconstruction/three_dimensional/1.jpg"));
    QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
    ui.label->setPixmap(dest);
    QMessageBox::information(this, QString::fromLocal8Bit("消息"), QString::fromLocal8Bit("轴心轨迹重构三维完成"), QMessageBox::Ok, QMessageBox::Ok);



}
void Axis_trajectory_reconstruction::cg1()
{
    flag = 3;
    flag3 = 2;
    ui.label->clear();
    QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString dlgTitle = QString::fromLocal8Bit("选择文件"); //对话框标题
    QString filter = QString::fromLocal8Bit("所有文件(*.*)"); //文件过滤器
    QStringList fileList = QFileDialog::getOpenFileNames(this, dlgTitle, desktop_path, filter);

    QDir dir(desktop_path + QString::fromLocal8Bit("/result"));
    if (!dir.exists())
    {
        dir.mkdir(desktop_path + QString::fromLocal8Bit("/result"));
    }
    QDir dir1(desktop_path + QString::fromLocal8Bit("/result/Axis_trajectory_reconstruction"));
    if (!dir1.exists())
    {
        dir1.mkdir(desktop_path + QString::fromLocal8Bit("/result/Axis_trajectory_reconstruction"));
    }
    QDir dir2(desktop_path + QString::fromLocal8Bit("/result/Axis_trajectory_reconstruction/XY"));
    if (!dir2.exists())
    {
        dir2.mkdir(desktop_path + QString::fromLocal8Bit("/result/Axis_trajectory_reconstruction/XY"));
    }

    std::string str1 = fileList[0].toLocal8Bit().toStdString();
    const char* p1 = str1.c_str();

    std::string str2 = fileList[1].toLocal8Bit().toStdString();
    const char* p2 = str2.c_str();

    std::string str3 = fileList[2].toLocal8Bit().toStdString();
    const char* p3 = str3.c_str();

    QString path = desktop_path + QString::fromLocal8Bit("/result/Axis_trajectory_reconstruction/XY");
    std::string path1 = path.toLocal8Bit().toStdString();
    const char* p4 = path1.c_str();

    x_yInitialize();

    x_y(p1,p2, p3,p4);
    x_yTerminate();

    

    QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/Axis_trajectory_reconstruction/XY/1.jpg"));
    QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
    ui.label->setPixmap(dest);
    QMessageBox::information(this, QString::fromLocal8Bit("消息"), QString::fromLocal8Bit("轴心轨迹重构XY完成"), QMessageBox::Ok, QMessageBox::Ok);

}

Axis_trajectory_reconstruction::~Axis_trajectory_reconstruction()
{

}
