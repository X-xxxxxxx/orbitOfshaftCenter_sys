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

    //������
    this->setWindowTitle(QString::fromLocal8Bit("���Ĺ켣�ؽ�ϵͳ"));
    this->setWindowIcon(QIcon(":/MainWindow/1.jpg"));

   // //����
   // QPalette pal = this->palette();
   // QPixmap pixmap(":/image/22.jpg");
   // QPixmap temp(pixmap.size());
   // temp.fill(Qt::transparent);
   // QPainter p1(&temp);
   // p1.setCompositionMode(QPainter::CompositionMode_Source);
   // p1.drawPixmap(0, 0, pixmap);
   // p1.setCompositionMode(QPainter::CompositionMode_DestinationIn);
   // 
   ////����QColor�е��ĸ���������͸���ȣ��˴�position��ȡֵ��Χ��0��255
   // p1.fillRect(temp.rect(), QColor(0, 0, 0, 250));
   // p1.end();
   // pixmap = temp;
   // pal.setBrush(QPalette::Background, QBrush(pixmap.scaled(this->size())));
   // setPalette(pal);

    
    


    //setFixedSize(750, 500);//�̶����ڴ�С

    //״̬��
   bar = new QStatusBar(this);
    QLabel* authorLabel = new QLabel(QString::fromLocal8Bit("���£���������ѧ"), this);
    bar->addPermanentWidget(authorLabel, 0);
    //ʱ���ǩ
    dateTimeLabel = new QLabel(tr("<h3>%1</h3>").arg(QDateTime::currentDateTime().toString("yyyy-MM-d hh:mm:ss")), this);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateLabel);
    timer->start(1000);
    bar->addWidget(dateTimeLabel, 0);
    this->setStatusBar(bar);


    
    //����궨
    QIcon myicon; //�½�QIcon����
  
    //myicon.addFile(tr(":/orbitOfshaftCenter_sys/button_background.png"));  
    ui.pushButton_5->setIcon(myicon); //����ť���ͼ��
    ui.pushButton_5->setIconSize(QSize(102, 102));//����ͼ���С
    ui.pushButton_5->setStyleSheet("background-color: #F6EBFF");
    ui.pushButton_5->setFocusPolicy(Qt::NoFocus);
    connect(ui.pushButton_5, &QPushButton::clicked, this, &MainWindow::camera_calobration);
	
    //��������Ż�
    QIcon myicon1; //�½�QIcon����
    //myicon1.addFile(tr(":/image/2.jpg")); //��QIcon����ָ����Ҫ��ͼ��
    ui.pushButton_4->setIcon(myicon1); //����ť���ͼ��
    ui.pushButton_4->setIconSize(QSize(102, 102));//����ͼ���С
    ui.pushButton_4->setStyleSheet("background-color: #F6EBFF");
    ui.pushButton_4->setFocusPolicy(Qt::NoFocus);
    connect(ui.pushButton_4, &QPushButton::clicked, this, &MainWindow::to_paramter_optimization);
 
    //ͼ����
    QIcon myicon2; //�½�QIcon����
    //myicon2.addFile(tr(":/image/3.jpg")); //��QIcon����ָ����Ҫ��ͼ��
    ui.pushButton_3->setIcon(myicon2); //����ť���ͼ��
    ui.pushButton_3->setIconSize(QSize(102, 102));//����ͼ���С
    ui.pushButton_3->setStyleSheet("background-color: #F6EBFF");
    ui.pushButton_3->setFocusPolicy(Qt::NoFocus);
    connect(ui.pushButton_3, &QPushButton::clicked, this, &MainWindow::to_image_recognition);

    //�켣����
    QIcon myicon3; //�½�QIcon����
    //myicon3.addFile(tr(":/image/4.jpg")); //��QIcon����ָ����Ҫ��ͼ��
    ui.pushButton_2->setIcon(myicon3); //����ť���ͼ��
    ui.pushButton_2->setIconSize(QSize(102, 102));//����ͼ���С
    ui.pushButton_2->setStyleSheet("background-color: #F6EBFF");
    ui.pushButton_2->setFocusPolicy(Qt::NoFocus);
    connect(ui.pushButton_2, &QPushButton::clicked, this, &MainWindow::to_Axis_trajectory_reconstruction);


    //���������ں�
    QIcon myicon4; //�½�QIcon����
    //myicon4.addFile(tr(":/image/5.jpg")); //��QIcon����ָ����Ҫ��ͼ��
    ui.pushButton->setIcon(myicon4); //����ť���ͼ��
    ui.pushButton->setIconSize(QSize(200, 200));//����ͼ���С
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
    //��ȡ����·��
    QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString dlgTitle = QString::fromLocal8Bit("ѡ�����ļ�"); //�Ի������
    QString filter = QString::fromLocal8Bit("�����ļ�(*.*)"); //�ļ�������

    QStringList fileList = QFileDialog::getOpenFileNames(this, dlgTitle, desktop_path, filter);

    cout << "��ʼ��ȡ�ǵ㡭����������" << endl;
    int image_count = 0;  /* ͼ������ */
    Size image_size;  /* ͼ��ĳߴ� */
    Size board_size = Size(5, 8);    /* �궨����ÿ�С��еĽǵ��� */
    vector<Point2f> image_points_buf;  /* ����ÿ��ͼ���ϼ�⵽�Ľǵ� */
    vector<vector<Point2f>> image_points_seq; /* �����⵽�����нǵ� */
    string filename;
    while (image_count < fileList.count())
    {
        filename = fileList[image_count].toLocal8Bit().toStdString();
        Mat imageInput = imread(filename);

        if (image_count == 1)  //�����һ��ͼƬʱ��ȡͼ������Ϣ
        {
            image_size.width = imageInput.cols;
            image_size.height = imageInput.rows;
            cout << "image_size.width = " << image_size.width << endl;
            cout << "image_size.height = " << image_size.height << endl;
        }
        /* ��ȡ�ǵ� */
        if (0 == findChessboardCorners(imageInput, board_size, image_points_buf))
        {
            cout << "can not find chessboard corners!\n"; //�Ҳ����ǵ�
            exit(1);
        }
        else
        {
            Mat view_gray;
            cvtColor(imageInput, view_gray, CV_RGB2GRAY);
            /* �����ؾ�ȷ�� */
            //find4QuadCornerSubpix(view_gray, image_points_buf, Size(3,3)); //�Դ���ȡ�Ľǵ���о�ȷ��
            cornerSubPix(view_gray, image_points_buf, Size(5, 5), Size(-1, -1), TermCriteria(CV_TERMCRIT_EPS + CV_TERMCRIT_ITER, 30, 0.001));
            image_points_seq.push_back(image_points_buf);  //���������ؽǵ�

             /* ��ͼ������ʾ�ǵ�λ�� */
            drawChessboardCorners(imageInput, board_size, image_points_buf, false); //������ͼƬ�б�ǽǵ�

            namedWindow("Camera Calibration", 0);
            resizeWindow("Camera Calibration", 800, 800);
            imshow("Camera Calibration", imageInput);//��ʾͼƬ
            waitKey(500);//��ͣ0.5S	
            image_count++;
        }
    }
    cout << "ͼ������image_count = " << image_count << endl;
    int total = image_points_seq.size();
    int CornerNum = board_size.width * board_size.height;  //ÿ��ͼƬ���ܵĽǵ���
    cout << "�ǵ���ȡ���!" << endl;
    cout << endl;
    destroyAllWindows();//�ر����Դ���


    //������������궨
    cout << "��ʼ�궨������������";
    /*������ά��Ϣ*/

    Size square_size = Size(10, 10);  /* ʵ�ʲ����õ��ı궨����ÿ�����̸�Ĵ�С */
    vector<vector<Point3f>> object_points; /* ����궨���Ͻǵ����ά���� */
                                           /*�������*/
    Mat cameraMatrix = Mat(3, 3, CV_32FC1, Scalar::all(0)); /* ������ڲ������� */
    vector<int> point_counts;  // ÿ��ͼ���нǵ������
    Mat distCoeffs = Mat(1, 5, CV_32FC1, Scalar::all(0)); /* �������5������ϵ����k1,k2,p1,p2,k3 */
    vector<Mat> tvecsMat;  /* ÿ��ͼ���ƽ������ */
    vector<Mat> rvecsMat; /* ÿ��ͼ�����ת���� */
                          /* ��ʼ���궨���Ͻǵ����ά���� */
    int i, j, t;
    for (t = 0; t < image_count; t++)
    {
        vector<Point3f> tempPointSet;
        for (i = 0; i < board_size.height; i++)
        {
            for (j = 0; j < board_size.width; j++)
            {
                Point3f realPoint;
                /* ����궨�������������ϵ��z=0��ƽ���� */
                realPoint.x = i * square_size.width;
                realPoint.y = j * square_size.height;
                realPoint.z = 0;
                tempPointSet.push_back(realPoint);
            }
        }
        object_points.push_back(tempPointSet);
    }
    /* ��ʼ��ÿ��ͼ���еĽǵ��������ٶ�ÿ��ͼ���ж����Կ��������ı궨�� */
    for (i = 0; i < image_count; i++)
    {
        point_counts.push_back(board_size.width * board_size.height);
    }
    /* ��ʼ�궨 */
    calibrateCamera(object_points, image_points_seq, image_size, cameraMatrix, distCoeffs, rvecsMat, tvecsMat, 0);
    cout << "�궨��ɣ�" << endl;
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

    //�Ա궨�����������
    cout << "��ʼ���۱궨���������������\n";
    double total_err = 0.0; /* ����ͼ���ƽ�������ܺ� */
    double err = 0.0; /* ÿ��ͼ���ƽ����� */
    vector<Point2f> image_points2; /* �������¼���õ���ͶӰ�� */
    ofs << "ÿ��ͼ��ı궨��\n";

    vector<vector<Point2f>> image_points_seq2;  //������㵽�����нǵ�ֵ
    for (i = 0; i < image_count; i++)
    {
        vector<Point3f> tempPointSet = object_points[i];
        /* ͨ���õ������������������Կռ����ά���������ͶӰ���㣬�õ��µ�ͶӰ�� */
        projectPoints(tempPointSet, rvecsMat[i], tvecsMat[i], cameraMatrix, distCoeffs, image_points2);

        image_points_seq2.push_back(image_points2);

        /* �����µ�ͶӰ��;ɵ�ͶӰ��֮������*/
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
        ofs << "��" << i + 1 << "��ͼ���ƽ����" << err << "����" << endl;
    }
    ofs << "����ƽ����" << total_err / image_count << "����" << endl << endl;

    vector<Point2f> corners1 = image_points_seq[0];  //0 �����һ��ͼ������


    //���涨����  	
    std::cout << "��ʼ���涨����������������" << endl;
    Mat rotation_matrix = Mat(3, 3, CV_32FC1, Scalar::all(0)); /* ����ÿ��ͼ�����ת���� */
    ofs << "����ڲ�������" << endl;
    ofs << cameraMatrix << endl << endl;
    ofs << "����ϵ����\n";
    ofs << distCoeffs << endl << endl << endl;
    for (int i = 0; i < image_count; i++)
    {
        ofs << "��" << i + 1 << "��ͼ�����ת������" << endl;
        ofs << rvecsMat[i] << endl;
        /* ����ת����ת��Ϊ���Ӧ����ת���� */
        Rodrigues(rvecsMat[i], rotation_matrix);
        ofs << "��" << i + 1 << "��ͼ�����ת����" << endl;
        ofs << rotation_matrix << endl;

        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                ofs << rotation_matrix.at<double>(j, k) << " ";
            }
            ofs << endl;
        }

        ofs << "��" << i + 1 << "��ͼ���ƽ��������" << endl;
        ofs << tvecsMat[i] << endl << endl;

        for (int j = 0; j < 3; j++)
        {
            ofs << tvecsMat[i].at<double>(j, 0) << " ";
        }
        ofs << endl;
    }

   std::cout << "��ɱ���" << endl;
   ofs << endl;

	
    cout << "--> ��һ��ͼƬͨ��ͼ����õ�������(���л���) --> : " << endl;
    ofs << "--> ��һ��ͼƬͨ��ͼ����õ�������(���л���) --> : " << endl;
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
    cout << "--> ��һ��ͼƬͨ������������������õ�������ֵ --> : " << endl;
    ofs << "--> ��һ��ͼƬͨ������������������õ�������ֵ --> : " << endl;
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


    cout << "x�����" << "," << "y�����" << endl;
    ofs << "x�����" << "," << "y�����" << endl;
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
        QString::fromLocal8Bit("��Ϣ"),
        QString::fromLocal8Bit("�궨���"),
        QMessageBox::Ok,
        QMessageBox::Ok);
}

MainWindow::~MainWindow()
{

}
