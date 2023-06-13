#pragma once
#include "MainWindow.h"
#include "../Parameter_optimization.h"
#include"../image_recognition.h"
#include"../Axis_trajectory_reconstruction.h"
#include"../datafusion.h"

#include<qstring.h>
//#include<qtestsupport_widgets.h>
//#include<qtestsupport_gui.h>
//#include<qtestsupport_core.h>
#include<qfiledialog.h>
#include<iostream>
#include<qstandardpaths.h>
#include<qfile.h>
#include<qmessagebox.h>

#include<qlabel.h>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <fstream>

#include<qpixmap.h>
#include<qpalette.h>
#include <QBitmap>
#include <QPainter>



using namespace cv;
using namespace std;



void MainWindow::updateLabel()
{
    dateTimeLabel->setText(tr("<h3>%1</h3>").arg(QDateTime::currentDateTime().toString("yyyy-MM-d hh:mm:ss")));
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    
    ui.mainToolBar->hide();

    //主界面
    this->setWindowTitle(QString::fromLocal8Bit("轴心轨迹重建系统"));
    this->setWindowIcon(QIcon(":/MainWindow/1.jpg"));

   // //背景
   // QPalette pal = this->palette();
   // QPixmap pixmap(":/image/22.jpg");
   // QPixmap temp(pixmap.size());
   // temp.fill(Qt::transparent);
   // QPainter p1(&temp);
   // p1.setCompositionMode(QPainter::CompositionMode_Source);
   // p1.drawPixmap(0, 0, pixmap);
   // p1.setCompositionMode(QPainter::CompositionMode_DestinationIn);
   // 
   ////根据QColor中第四个参数设置透明度，此处position的取值范围是0～255
   // p1.fillRect(temp.rect(), QColor(0, 0, 0, 250));
   // p1.end();
   // pixmap = temp;
   // pal.setBrush(QPalette::Background, QBrush(pixmap.scaled(this->size())));
   // setPalette(pal);

    
    


    //setFixedSize(750, 500);//固定窗口大小

    //状态栏
   bar = new QStatusBar(this);
    QLabel* authorLabel = new QLabel(QString::fromLocal8Bit("张勇，西安理工大学"), this);
    bar->addPermanentWidget(authorLabel, 0);
    //时间标签
    dateTimeLabel = new QLabel(tr("<h3>%1</h3>").arg(QDateTime::currentDateTime().toString("yyyy-MM-d hh:mm:ss")), this);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateLabel);
    timer->start(1000);
    bar->addWidget(dateTimeLabel, 0);
    this->setStatusBar(bar);


    
    //相机标定
    QIcon myicon; //新建QIcon对象
  
    //myicon.addFile(tr(":/orbitOfshaftCenter_sys/button_background.png"));  
    ui.pushButton_5->setIcon(myicon); //给按钮添加图标
    ui.pushButton_5->setIconSize(QSize(102, 102));//重置图标大小
    ui.pushButton_5->setStyleSheet("background-color: #F6EBFF");
    ui.pushButton_5->setFocusPolicy(Qt::NoFocus);
    connect(ui.pushButton_5, &QPushButton::clicked, this, &MainWindow::camera_calobration);
	
    //相机参数优化
    QIcon myicon1; //新建QIcon对象
    //myicon1.addFile(tr(":/image/2.jpg")); //让QIcon对象指向想要的图标
    ui.pushButton_4->setIcon(myicon1); //给按钮添加图标
    ui.pushButton_4->setIconSize(QSize(102, 102));//重置图标大小
    ui.pushButton_4->setStyleSheet("background-color: #F6EBFF");
    ui.pushButton_4->setFocusPolicy(Qt::NoFocus);
    connect(ui.pushButton_4, &QPushButton::clicked, this, &MainWindow::to_paramter_optimization);
 
    //图像处理
    QIcon myicon2; //新建QIcon对象
    //myicon2.addFile(tr(":/image/3.jpg")); //让QIcon对象指向想要的图标
    ui.pushButton_3->setIcon(myicon2); //给按钮添加图标
    ui.pushButton_3->setIconSize(QSize(102, 102));//重置图标大小
    ui.pushButton_3->setStyleSheet("background-color: #F6EBFF");
    ui.pushButton_3->setFocusPolicy(Qt::NoFocus);
    connect(ui.pushButton_3, &QPushButton::clicked, this, &MainWindow::to_image_recognition);

    //轨迹解算
    QIcon myicon3; //新建QIcon对象
    //myicon3.addFile(tr(":/image/4.jpg")); //让QIcon对象指向想要的图标
    ui.pushButton_2->setIcon(myicon3); //给按钮添加图标
    ui.pushButton_2->setIconSize(QSize(102, 102));//重置图标大小
    ui.pushButton_2->setStyleSheet("background-color: #F6EBFF");
    ui.pushButton_2->setFocusPolicy(Qt::NoFocus);
    connect(ui.pushButton_2, &QPushButton::clicked, this, &MainWindow::to_Axis_trajectory_reconstruction);


    //测量数据融合
    QIcon myicon4; //新建QIcon对象
    //myicon4.addFile(tr(":/image/5.jpg")); //让QIcon对象指向想要的图标
    ui.pushButton->setIcon(myicon4); //给按钮添加图标
    ui.pushButton->setIconSize(QSize(200, 200));//重置图标大小
    ui.pushButton->setStyleSheet("background-color: #F6EBFF");
    ui.pushButton->setFocusPolicy(Qt::NoFocus);
    connect(ui.pushButton, &QPushButton::clicked, this, &MainWindow::to_datafusion);
   
}

void MainWindow::to_Axis_trajectory_reconstruction()
{
   // this->close();
    Axis_trajectory_reconstruction* p = new Axis_trajectory_reconstruction();
    p->show();
}

void MainWindow::to_image_recognition()
{
    //this->close();
    image_recognition* p = new image_recognition();
    p->show();
}

void MainWindow::to_datafusion()
{
   // this->close();
   datafusion* p = new datafusion;
   p->show();
}


void MainWindow::to_paramter_optimization()
{
   // this->close();
    Parameter_optimization *p=new Parameter_optimization;
    p->show();
}


void MainWindow::camera_calobration()
{
    //获取桌面路径
    QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString dlgTitle = QString::fromLocal8Bit("选择多个文件"); //对话框标题
    QString filter = QString::fromLocal8Bit("所有文件(*.*)"); //文件过滤器

    QStringList fileList = QFileDialog::getOpenFileNames(this, dlgTitle, desktop_path, filter);

    cout << "开始提取角点………………" << endl;
    int image_count = 0;  /* 图像数量 */
    Size image_size;  /* 图像的尺寸 */
    Size board_size = Size(5, 8);    /* 标定板上每行、列的角点数 */
    vector<Point2f> image_points_buf;  /* 缓存每幅图像上检测到的角点 */
    vector<vector<Point2f>> image_points_seq; /* 保存检测到的所有角点 */
    string filename;
    while (image_count < fileList.count())
    {
        filename = fileList[image_count].toLocal8Bit().toStdString();
        Mat imageInput = imread(filename);

        if (image_count == 1)  //读入第一张图片时获取图像宽高信息
        {
            image_size.width = imageInput.cols;
            image_size.height = imageInput.rows;
            cout << "image_size.width = " << image_size.width << endl;
            cout << "image_size.height = " << image_size.height << endl;
        }
        /* 提取角点 */
        if (0 == findChessboardCorners(imageInput, board_size, image_points_buf))
        {
            cout << "can not find chessboard corners!\n"; //找不到角点
            exit(1);
        }
        else
        {
            Mat view_gray;
            cvtColor(imageInput, view_gray, CV_RGB2GRAY);
            /* 亚像素精确化 */
            //find4QuadCornerSubpix(view_gray, image_points_buf, Size(3,3)); //对粗提取的角点进行精确化
            cornerSubPix(view_gray, image_points_buf, Size(5, 5), Size(-1, -1), TermCriteria(CV_TERMCRIT_EPS + CV_TERMCRIT_ITER, 30, 0.001));
            image_points_seq.push_back(image_points_buf);  //保存亚像素角点

             /* 在图像上显示角点位置 */
            drawChessboardCorners(imageInput, board_size, image_points_buf, false); //用于在图片中标记角点

            namedWindow("Camera Calibration", 0);
            resizeWindow("Camera Calibration", 800, 800);
            imshow("Camera Calibration", imageInput);//显示图片
            waitKey(500);//暂停0.5S	
            image_count++;
        }
    }
    cout << "图像数量image_count = " << image_count << endl;
    int total = image_points_seq.size();
    int CornerNum = board_size.width * board_size.height;  //每张图片上总的角点数
    cout << "角点提取完成!" << endl;
    cout << endl;
    destroyAllWindows();//关闭所以窗口


    //以下是摄像机标定
    cout << "开始标定………………";
    /*棋盘三维信息*/

    Size square_size = Size(10, 10);  /* 实际测量得到的标定板上每个棋盘格的大小 */
    vector<vector<Point3f>> object_points; /* 保存标定板上角点的三维坐标 */
                                           /*内外参数*/
    Mat cameraMatrix = Mat(3, 3, CV_32FC1, Scalar::all(0)); /* 摄像机内参数矩阵 */
    vector<int> point_counts;  // 每幅图像中角点的数量
    Mat distCoeffs = Mat(1, 5, CV_32FC1, Scalar::all(0)); /* 摄像机的5个畸变系数：k1,k2,p1,p2,k3 */
    vector<Mat> tvecsMat;  /* 每幅图像的平移向量 */
    vector<Mat> rvecsMat; /* 每幅图像的旋转向量 */
                          /* 初始化标定板上角点的三维坐标 */
    int i, j, t;
    for (t = 0; t < image_count; t++)
    {
        vector<Point3f> tempPointSet;
        for (i = 0; i < board_size.height; i++)
        {
            for (j = 0; j < board_size.width; j++)
            {
                Point3f realPoint;
                /* 假设标定板放在世界坐标系中z=0的平面上 */
                realPoint.x = i * square_size.width;
                realPoint.y = j * square_size.height;
                realPoint.z = 0;
                tempPointSet.push_back(realPoint);
            }
        }
        object_points.push_back(tempPointSet);
    }
    /* 初始化每幅图像中的角点数量，假定每幅图像中都可以看到完整的标定板 */
    for (i = 0; i < image_count; i++)
    {
        point_counts.push_back(board_size.width * board_size.height);
    }
    /* 开始标定 */
    calibrateCamera(object_points, image_points_seq, image_size, cameraMatrix, distCoeffs, rvecsMat, tvecsMat, 0);
    cout << "标定完成！" << endl;
    cout << endl;


    QDir dir(desktop_path+ QString::fromLocal8Bit("/result"));
    if (!dir.exists())
    {
        dir.mkdir(desktop_path + QString::fromLocal8Bit("/result"));
    }
    QDir dir1(desktop_path + QString::fromLocal8Bit("/result/calibration"));
    if (!dir1.exists())
    {
        dir1.mkdir(desktop_path + QString::fromLocal8Bit("/result/calibration"));
    }
   
    ofstream ofs; 
    string path = desktop_path.toLocal8Bit().toStdString() + "/result/calibration/result.txt";
    ofs.open(path, ios::out);

    //对标定结果进行评价
    cout << "开始评价标定结果………………\n";
    double total_err = 0.0; /* 所有图像的平均误差的总和 */
    double err = 0.0; /* 每幅图像的平均误差 */
    vector<Point2f> image_points2; /* 保存重新计算得到的投影点 */
    ofs << "每幅图像的标定误差：\n";

    vector<vector<Point2f>> image_points_seq2;  //保存计算到的所有角点值
    for (i = 0; i < image_count; i++)
    {
        vector<Point3f> tempPointSet = object_points[i];
        /* 通过得到的摄像机内外参数，对空间的三维点进行重新投影计算，得到新的投影点 */
        projectPoints(tempPointSet, rvecsMat[i], tvecsMat[i], cameraMatrix, distCoeffs, image_points2);

        image_points_seq2.push_back(image_points2);

        /* 计算新的投影点和旧的投影点之间的误差*/
        vector<Point2f> tempImagePoint = image_points_seq[i];

        Mat tempImagePointMat = Mat(1, tempImagePoint.size(), CV_32FC2);
        Mat image_points2Mat = Mat(1, image_points2.size(), CV_32FC2);
        for (int j = 0; j < tempImagePoint.size(); j++)
        {
            image_points2Mat.at<Vec2f>(0, j) = Vec2f(image_points2[j].x, image_points2[j].y);
            tempImagePointMat.at<Vec2f>(0, j) = Vec2f(tempImagePoint[j].x, tempImagePoint[j].y);
        }
        err = norm(image_points2Mat, tempImagePointMat, NORM_L2);

        total_err += err /= point_counts[i];
        ofs << "第" << i + 1 << "幅图像的平均误差：" << err << "像素" << endl;
    }
    ofs << "总体平均误差：" << total_err / image_count << "像素" << endl << endl;

    vector<Point2f> corners1 = image_points_seq[0];  //0 代表第一张图的数据


    //保存定标结果  	
    std::cout << "开始保存定标结果………………" << endl;
    Mat rotation_matrix = Mat(3, 3, CV_32FC1, Scalar::all(0)); /* 保存每幅图像的旋转矩阵 */
    ofs << "相机内参数矩阵：" << endl;
    ofs << cameraMatrix << endl << endl;
    ofs << "畸变系数：\n";
    ofs << distCoeffs << endl << endl << endl;
    for (int i = 0; i < image_count; i++)
    {
        ofs << "第" << i + 1 << "幅图像的旋转向量：" << endl;
        ofs << rvecsMat[i] << endl;
        /* 将旋转向量转换为相对应的旋转矩阵 */
        Rodrigues(rvecsMat[i], rotation_matrix);
        ofs << "第" << i + 1 << "幅图像的旋转矩阵：" << endl;
        ofs << rotation_matrix << endl;

        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                ofs << rotation_matrix.at<double>(j, k) << " ";
            }
            ofs << endl;
        }

        ofs << "第" << i + 1 << "幅图像的平移向量：" << endl;
        ofs << tvecsMat[i] << endl << endl;

        for (int j = 0; j < 3; j++)
        {
            ofs << tvecsMat[i].at<double>(j, 0) << " ";
        }
        ofs << endl;
    }

   std::cout << "完成保存" << endl;
   ofs << endl;

	
    cout << "--> 第一张图片通过图像处理得到的数据(含有畸变) --> : " << endl;
    ofs << "--> 第一张图片通过图像处理得到的数据(含有畸变) --> : " << endl;
    for (int i = 0; i < corners1.size(); i++)
    {
        cout << i + 1 << " " << corners1[i] << "\t";
        ofs << i + 1 << " " << corners1[i] << "\t";
        if ((i + 1) % 5 == 0)
        {
            cout << endl;
            ofs << endl;
        }
    }
    cout << endl;


    vector<Point2f> corners2 = image_points_seq2[0];
    cout << "--> 第一张图片通过摄像机内外参数计算得到的理想值 --> : " << endl;
    ofs << "--> 第一张图片通过摄像机内外参数计算得到的理想值 --> : " << endl;
    for (int i = 0; i < corners2.size(); i++)
    {
        cout << i + 1 << " " << corners2[i] << "\t";
        ofs << i + 1 << " " << corners2[i] << "\t";
        if ((i + 1) % 5 == 0)
        {
            cout << endl;
            ofs << endl;
        }
    }
    cout << endl;


    cout << "x的误差" << "," << "y的误差" << endl;
    ofs << "x的误差" << "," << "y的误差" << endl;
    for (int i = 0; i < corners1.size(); i++)
    {
        cout << corners1[i].x - corners2[i].x << "," << corners1[i].y - corners2[i].y << "\t\t";
        ofs << i << "   " << corners1[i].x - corners2[i].x << "," << corners1[i].y - corners2[i].y << endl;
        if ((i + 1) % 4 == 0)
        {
            cout << endl;
        }
    }
    cout << endl;
    ofs.close();

    QMessageBox::information(this,
        QString::fromLocal8Bit("消息"),
        QString::fromLocal8Bit("标定完成"),
        QMessageBox::Ok,
        QMessageBox::Ok);
}

MainWindow::~MainWindow()
{

}
