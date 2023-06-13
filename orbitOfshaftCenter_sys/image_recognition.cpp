#include "image_recognition.h"
#include"my_canny.h"
#include"my_bianyuantu.h"
#include"Mathematical_morphology.h"


#include<qstandardpaths.h>
#include<qfiledialog.h>
#include<qstring.h>

#include<string>
#include <QMessageBox>
#include<qdir.h>
#include <stdio.h>
#include <QBitmap>
#include <QPainter>

#define PI 3.1415926
#include<opencv2\opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;
#include<vector>
#include "MainWindow.h"

static double xy[15][2];


#pragma comment( lib, "libmex.lib" )
#pragma comment( lib, "mclmcr.lib" )
#pragma comment( lib, "libeng.lib" )
#pragma comment( lib, "libmx.lib" )
#pragma comment( lib, "libmat.lib" )
#pragma comment( lib, "mclmcrrt.lib" )

#pragma comment( lib, "my_canny.lib" )
#pragma comment( lib, "my_bianyuantu.lib" )
#pragma comment( lib, "Mathematical_morphology.lib" )

void image_recognition::to_mainwindow()
{
    this->close();
    MainWindow* m = new MainWindow;
    m->show();
}
void image_recognition::myquit()
{
    this->close();
}





void RGB2HSV(double red, double green, double blue, double& hue, double& saturation, double& intensity)
{

    double r, g, b;
    double h, s, i;

    double sum;
    double minRGB, maxRGB;
    double theta;

    r = red / 255.0;
    g = green / 255.0;
    b = blue / 255.0;

    minRGB = ((r < g) ? (r) : (g));
    minRGB = (minRGB < b) ? (minRGB) : (b);

    maxRGB = ((r > g) ? (r) : (g));
    maxRGB = (maxRGB > b) ? (maxRGB) : (b);

    sum = r + g + b;
    i = sum / 3.0;

    if (i < 0.001 || maxRGB - minRGB < 0.001)
    {
        h = 0.0;
        s = 0.0;
    }
    else
    {
        s = 1.0 - 3.0 * minRGB / sum;
        theta = sqrt((r - g) * (r - g) + (r - b) * (g - b));
        theta = acos((r - g + r - b) * 0.5 / theta);
        if (b <= g)
            h = theta;
        else
            h = 2 * PI - theta;
        if (s <= 0.01)
            h = 0;
    }

    hue = (int)(h * 180 / PI);
    saturation = (int)(s * 100);
    intensity = (int)(i * 100);
}

Mat picture_red(Mat input)
{

    Mat frame;
    Mat srcImg = input;
    frame = srcImg;
    waitKey(1);
    int width = srcImg.cols;
    int height = srcImg.rows;

    int x, y;
    double B = 0.0, G = 0.0, R = 0.0, H = 0.0, S = 0.0, V = 0.0;
    Mat vec_rgb = Mat::zeros(srcImg.size(), CV_8UC1);
    for (x = 0; x < height; x++)
    {
        for (y = 0; y < width; y++)
        {
            B = srcImg.at<Vec3b>(x, y)[0];
            G = srcImg.at<Vec3b>(x, y)[1];
            R = srcImg.at<Vec3b>(x, y)[2];
            RGB2HSV(R, G, B, H, S, V);
            //��ɫ��Χ����Χ�ο������ϡ������Լ���
            //if ((H >= 312 && H <= 360) && (S >= 17 && S <= 100) && (V>18 && V < 100))
            if ((H >= 45 && H <= 60) && (S >= 17 && S <= 100) && (V > 18 && V < 100))
                //if ((H == 60) && ( S == 100) && (V == 100))
                vec_rgb.at<uchar>(x, y) = 255;
            /*cout << H << "," << S << "," << V << endl;*/
        }
    }
  
    return vec_rgb;
}
void O_x1y1(Mat in, double* x1, double* y1, double* x2, double* y2, double* x3, double* y3)

{
    Mat matSrc = in;
    /*Mat matSrc = imread("qwer9.png", 0);*/

    GaussianBlur(matSrc, matSrc, Size(5, 5), 0);//��˹�˲��������

    vector<vector<Point> > contours;//contours�����ͣ�˫�ص�vector

    vector<Vec4i> hierarchy;//Vec4i��ָÿһ��vectorԪ�������ĸ�int�����ݡ�

                            //��ֵ

    threshold(matSrc, matSrc, 100, 255, THRESH_BINARY);//ͼ���ֵ��

                                                       //Ѱ������������ע�⣬findContours���������Ҫ���Ƕ�ֵͼ�񣬶�ֵͼ�����Դ���������֣���һ����threshold���ڶ�����canny

    findContours(matSrc.clone(), contours, hierarchy, CV_RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0));

    /// �����

    vector<Moments> mu(contours.size());

    for (int i = 0; i < contours.size(); i++)

    {
        mu[i] = moments(contours[i], false);
    }

    /// ���������:

    vector<Point2f> mc(contours.size());

    for (int i = 0; i < contours.size(); i++)

    {
        mc[i] = Point2f(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00);
    }

    /// ��������

    Mat drawing = Mat::zeros(matSrc.size(), CV_8UC1);

    for (int i = 0; i < contours.size(); i++)

    {
        Scalar color = Scalar(255);

        //drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());//������������

        circle(drawing, mc[i], 4, color, -1, 8, 0);

    }
    *x1 = mc[0].x;
    *y1 = mc[0].y;
    *x3 = mc[1].x;
    *y3 = mc[1].y;
    *x2 = mc[contours.size() - 1].x;
    *y2 = mc[contours.size() - 1].y;

    for (int i = 0; i < contours.size(); i++)
    {
        xy[i][1] = mc[i].x;
        xy[i][2] = mc[i].y;
    }
}


void image_recognition::colour()
{
    flag = 4;
    flag4 = 2;

    //��ȡ����·��
    QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString dlgTitle = QString::fromLocal8Bit("ѡ���ļ�"); //�Ի������
    QString filter = QString::fromLocal8Bit("�����ļ�(*.*)"); //�ļ�������
    QStringList fileList = QFileDialog::getOpenFileNames(this, dlgTitle, desktop_path, filter);

    QDir dir(desktop_path + QString::fromLocal8Bit("/result"));
    if (!dir.exists())
    {
        dir.mkdir(desktop_path + QString::fromLocal8Bit("/result"));
    }
    QDir dir1(desktop_path + QString::fromLocal8Bit("/result/image_recognition"));
    if (!dir1.exists())
    {
        dir1.mkdir(desktop_path + QString::fromLocal8Bit("/result/image_recognition"));
    }
    QDir dir2(desktop_path + QString::fromLocal8Bit("/result/image_recognition/colour"));
    if (!dir2.exists())
    {
        dir2.mkdir(desktop_path + QString::fromLocal8Bit("/result/image_recognition/colour"));
    }

    double xx1, yy1, xx2, yy2, xx3, yy3;
    double x1, y1, x2, y2, x3, y3;

    Mat matSrc = imread(fileList[0].toLocal8Bit().toStdString());

    Mat middle = picture_red(matSrc);
    O_x1y1(middle, &xx1, &yy1, &xx2, &yy2, &xx3, &yy3);
    x1 = xx1;
    y1 = yy1;
    x2 = xx2;
    y2 = yy2;

    x3 = xx3;
    y3 = yy3;

    QString temp = desktop_path + QString::fromLocal8Bit("/result/image_recognition/colour");


    imwrite(temp.toLocal8Bit().toStdString()+"/1.jpg", matSrc);
    imwrite(temp.toLocal8Bit().toStdString() + "/2.jpg", picture_red(matSrc));

    QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/image_recognition/colour/1.jpg"));
    QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
    ui.label->setPixmap(dest);
    QMessageBox::information(this, QString::fromLocal8Bit("��Ϣ"), QString::fromLocal8Bit("����������ȡ���"), QMessageBox::Ok, QMessageBox::Ok);

}


void image_recognition::updateLabel()
{
    dateTimeLabel->setText(tr("<h3>%1</h3>").arg(QDateTime::currentDateTime().toString("yyyy-MM-d hh:mm:ss")));
}

image_recognition::image_recognition(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    //ͼ����
    ui.mainToolBar->hide();

    ////����
    //QPalette pal = this->palette();
    //QPixmap pixmap(":/image/24.jpg");
    //QPixmap temp(pixmap.size());
    //temp.fill(Qt::transparent);
    //QPainter p1(&temp);
    //p1.setCompositionMode(QPainter::CompositionMode_Source);
    //p1.drawPixmap(0, 0, pixmap);
    //p1.setCompositionMode(QPainter::CompositionMode_DestinationIn);

    ////����QColor�е��ĸ���������͸���ȣ��˴�position��ȡֵ��Χ��0��255
    //p1.fillRect(temp.rect(), QColor(0, 0, 0, 250));
    //p1.end();
    //pixmap = temp;
    //pal.setBrush(QPalette::Background, QBrush(pixmap.scaled(this->size())));
    //setPalette(pal);


    flag = 0;

    flag1 = 0;
    flag2 = 0;
    flag3 = 0;

   // setFixedSize(800, 600);//�̶����ڴ�С
    this->setWindowTitle(QString::fromLocal8Bit("����궨�����Ż�"));

    //״̬��
    bar = new QStatusBar(this);
    QLabel* authorLabel = new QLabel(QString::fromLocal8Bit("���£���������ѧ"), this);
    bar->addPermanentWidget(authorLabel, 0);
    //ʱ���ǩ
    dateTimeLabel = new QLabel(tr("<h3>%1</h3>").arg(QDateTime::currentDateTime().toString("yyyy-MM-d hh:mm:ss")), this);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &image_recognition::updateLabel);
    timer->start(1000);
    bar->addWidget(dateTimeLabel, 0);
    this->setStatusBar(bar);





    QIcon myicon1; //�½�QIcon����
    myicon1.addFile(tr(":/image/10.jpg")); //��QIcon����ָ����Ҫ��ͼ��
    ui.pushButton->setIcon(myicon1); //����ť���ͼ��
    ui.pushButton->setIconSize(QSize(113, 113));//����ͼ���С
    ui.pushButton->setStyleSheet("background-color: #F6EBFF");
    ui.pushButton->setFocusPolicy(Qt::NoFocus);
    connect(ui.pushButton, &QPushButton::clicked, this, &image_recognition::m_canny);


    QIcon myicon2; //�½�QIcon����
    myicon2.addFile(tr(":/image/11.jpg")); //��QIcon����ָ����Ҫ��ͼ��
    ui.pushButton_3->setIcon(myicon2); //����ť���ͼ��
    ui.pushButton_3->setIconSize(QSize(113, 113));//����ͼ���С
    ui.pushButton_3->setStyleSheet("background-color: #F6EBFF");
    ui.pushButton_3->setFocusPolicy(Qt::NoFocus);
    connect(ui.pushButton_3, &QPushButton::clicked, this, &image_recognition::m_bianyuantu);


    QIcon myicon3; //�½�QIcon����
    myicon3.addFile(tr(":/image/12.jpg")); //��QIcon����ָ����Ҫ��ͼ��
    ui.pushButton_2->setIcon(myicon3); //����ť���ͼ��
    ui.pushButton_2->setIconSize(QSize(113, 113));//����ͼ���С
    ui.pushButton_2->setStyleSheet("background-color: #F6EBFF");
    ui.pushButton_2->setFocusPolicy(Qt::NoFocus);
    connect(ui.pushButton_2, &QPushButton::clicked, this, &image_recognition::mathematical_morphology);

    QIcon myicon4; //�½�QIcon����
    myicon4.addFile(tr(":/image/13.jpg")); //��QIcon����ָ����Ҫ��ͼ��
    ui.pushButton_6->setIcon(myicon4); //����ť���ͼ��
    ui.pushButton_6->setIconSize(QSize(113, 113));//����ͼ���С
    ui.pushButton_6->setStyleSheet("background-color: #F6EBFF");
    ui.pushButton_6->setFocusPolicy(Qt::NoFocus);
    connect(ui.pushButton_6, &QPushButton::clicked, this, &image_recognition::colour);


    QIcon myicon5; //�½�QIcon����
    myicon5.addFile(tr(":/image/21.jpg")); //��QIcon����ָ����Ҫ��ͼ��
    ui.pushButton_10->setIcon(myicon5); //����ť���ͼ��
    ui.pushButton_10->setIconSize(QSize(113, 113));//����ͼ���С
    ui.pushButton_10->setStyleSheet("background-color: #F6EBFF");
    ui.pushButton_10->setFocusPolicy(Qt::NoFocus);
    connect(ui.pushButton_10, &QPushButton::clicked, this, &image_recognition::central_coordinate);


    //��һ��
    connect(ui.pushButton_4, &QPushButton::clicked, this, &image_recognition::show_up);
    //��һ��
    connect(ui.pushButton_5, &QPushButton::clicked, this, &image_recognition::shou_down);

    
    connect(ui.pushButton_7, &QPushButton::clicked, this, &image_recognition::to_mainwindow);

    connect(ui.pushButton_8, &QPushButton::clicked, this, &image_recognition::myquit);




}

void image_recognition::show_up()
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
        //��ȡ����·��
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/image_recognition/canny/") + QString::number(flag1) + ".jpg");
        QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
        ui.label->setPixmap(dest);
    }
    else if(flag==2)
    {
        if (flag2 > 1)
        {
            flag2--;
        }
        else
        {
            flag2 = 6;
        }
        //��ȡ����·��
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/image_recognition/mathematical_morphology/") + QString::number(flag2) + ".jpg");
        QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
        ui.label->setPixmap(dest);
    }
    else if (flag == 3)
    {
        //��ȡ����·��
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/image_recognition/bianyuantu/") + "1.jpg");
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
            flag4 = 2;
        }
        //��ȡ����·��
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/image_recognition/colour/") + QString::number(flag4) + ".jpg");
        QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
        ui.label->setPixmap(dest);
    }
    else if (flag == 5)
    {
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/image_recognition/central_coordinate/") + "1.jpg");
        QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
        ui.label->setPixmap(dest);
    }

}
void  image_recognition::shou_down()
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
        //��ȡ����·��
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);

        QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/image_recognition/canny/") + QString::number(flag1) + ".jpg");
        QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
        ui.label->setPixmap(dest);

    }
    else if (flag == 2)
    {
        if (flag2 < 6)
        {
            flag2++;
        }
        else
        {
            flag2 = 1;
        }
        //��ȡ����·��
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);

        QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/image_recognition/mathematical_morphology/") + QString::number(flag2) + ".jpg");
        QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
        ui.label->setPixmap(dest);
    }
    else if (flag == 3)
    {
        //��ȡ����·��
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/image_recognition/bianyuantu/") + "1.jpg");
        QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
        ui.label->setPixmap(dest);
    }
    else if (flag == 4)
    {
        if (flag4 < 2)
        {
            flag4++;
        }
        else
        {
            flag4 = 1;
        }
        //��ȡ����·��
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/image_recognition/colour/") + QString::number(flag4) + ".jpg");
        QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
        ui.label->setPixmap(dest);
    }
    else if (flag == 5)
    {
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/image_recognition/central_coordinate/") + "1.jpg");
        QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
        ui.label->setPixmap(dest);
    }
   
}



void image_recognition::m_canny()
{
    flag = 1;
    flag1 = 2;

    ui.label->clear();

    //��ȡ����·��
    QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString dlgTitle = QString::fromLocal8Bit("ѡ���ļ�"); //�Ի������
    QString filter = QString::fromLocal8Bit("�����ļ�(*.*)"); //�ļ�������
    QStringList fileList = QFileDialog::getOpenFileNames(this, dlgTitle, desktop_path, filter);

    QDir dir(desktop_path + QString::fromLocal8Bit("/result"));
    if (!dir.exists())
    {
        dir.mkdir(desktop_path + QString::fromLocal8Bit("/result"));
    }
    QDir dir1(desktop_path + QString::fromLocal8Bit("/result/image_recognition"));
    if (!dir1.exists())
    {
        dir1.mkdir(desktop_path + QString::fromLocal8Bit("/result/image_recognition"));
    }
    QDir dir2(desktop_path + QString::fromLocal8Bit("/result/image_recognition/canny"));
    if (!dir2.exists())
    {
        dir2.mkdir(desktop_path + QString::fromLocal8Bit("/result/image_recognition/canny"));
    }

    my_cannyInitialize();

    std::string str = fileList[0].toLocal8Bit().toStdString();
    const char* p = str.c_str();
  

    QString path = desktop_path + QString::fromLocal8Bit("/result/image_recognition/canny");
    std::string path1 = path.toLocal8Bit().toStdString();
    const char* p1 = path1.c_str();

    my_canny(p,p1);

    //��ȡ����·��
    my_cannyTerminate();

    
    QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/image_recognition/canny/1.jpg"));
    QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
    ui.label->setPixmap(dest);
    QMessageBox::information(this, QString::fromLocal8Bit("��Ϣ"), QString::fromLocal8Bit("canny��Ե������"), QMessageBox::Ok, QMessageBox::Ok);



}

void image_recognition::m_bianyuantu()
{
    flag = 3;
    flag2 = 2;

    ui.label->clear();
    //��ȡ����·��
    QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString dlgTitle = QString::fromLocal8Bit("ѡ���ļ�"); //�Ի������
    QString filter = QString::fromLocal8Bit("�����ļ�(*.*)"); //�ļ�������
    QStringList fileList = QFileDialog::getOpenFileNames(this, dlgTitle, desktop_path, filter);

    QDir dir(desktop_path + QString::fromLocal8Bit("/result"));
    if (!dir.exists())
    {
        dir.mkdir(desktop_path + QString::fromLocal8Bit("/result"));
    }
    QDir dir1(desktop_path + QString::fromLocal8Bit("/result/image_recognition"));
    if (!dir1.exists())
    {
        dir1.mkdir(desktop_path + QString::fromLocal8Bit("/result/image_recognition"));
    }
    QDir dir2(desktop_path + QString::fromLocal8Bit("/result/image_recognition/bianyuantu"));
    if (!dir2.exists())
    {
        dir2.mkdir(desktop_path + QString::fromLocal8Bit("/result/image_recognition/bianyuantu"));
    }
    my_bianyuantuInitialize();

    std::string str = fileList[0].toLocal8Bit().toStdString();

    const char* p = str.c_str();
    QString path = desktop_path + QString::fromLocal8Bit("/result/image_recognition/bianyuantu");
    std::string path1 = path.toLocal8Bit().toStdString();
    const char* p1 = path1.c_str();
   
    my_bianyuantu(p,p1);

    my_bianyuantuTerminate();

    QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/image_recognition/bianyuantu/1.jpg"));
    QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
    ui.label->setPixmap(dest);
    QMessageBox::information(this, QString::fromLocal8Bit("��Ϣ"), QString::fromLocal8Bit("��Ե������"), QMessageBox::Ok, QMessageBox::Ok);
}

void image_recognition::mathematical_morphology()
{
    flag = 2;
    flag3 = 2;

    ui.label->clear();

    //��ȡ����·��
    QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString dlgTitle = QString::fromLocal8Bit("ѡ���ļ�"); //�Ի������
    QString filter = QString::fromLocal8Bit("�����ļ�(*.*)"); //�ļ�������
    QStringList fileList = QFileDialog::getOpenFileNames(this, dlgTitle, desktop_path, filter);

    QDir dir(desktop_path + QString::fromLocal8Bit("/result"));
    if (!dir.exists())
    {
        dir.mkdir(desktop_path + QString::fromLocal8Bit("/result"));
    }
    QDir dir1(desktop_path + QString::fromLocal8Bit("/result/image_recognition"));
    if (!dir1.exists())
    {
        dir1.mkdir(desktop_path + QString::fromLocal8Bit("/result/image_recognition"));
    }
    QDir dir2(desktop_path + QString::fromLocal8Bit("/result/image_recognition/mathematical_morphology"));
    if (!dir2.exists())
    {
        dir2.mkdir(desktop_path + QString::fromLocal8Bit("/result/image_recognition/mathematical_morphology"));
    }
    Mathematical_morphologyInitialize();
    std::string str = fileList[0].toLocal8Bit().toStdString();

    const char* p = str.c_str();
    QString path = desktop_path + QString::fromLocal8Bit("/result/image_recognition/mathematical_morphology");
    std::string path1 = path.toLocal8Bit().toStdString();
    const char* p1 = path1.c_str();

    Mathematical_morphology(p,p1);

    Mathematical_morphologyTerminate();

    QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/image_recognition/mathematical_morphology/1.jpg"));
    QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
    ui.label->setPixmap(dest);
    QMessageBox::information(this, QString::fromLocal8Bit("��Ϣ"), QString::fromLocal8Bit("��ѧ��̬ѧ��Ե������"), QMessageBox::Ok, QMessageBox::Ok);

}

void drawCross(Mat& img, Point2f point, Scalar color, int size, int thickness /*= 1*/)
{
    //���ƺ���  
    line(img, cvPoint(point.x - size / 2, point.y), cvPoint(point.x + size / 2, point.y), color, thickness, 9, 0);
    //��������  	
    line(img, cvPoint(point.x, point.y - size / 2), cvPoint(point.x, point.y + size / 2), color, thickness, 9, 0);
    return;
}
void FeaturePoint(Mat img)
{
    map<double, double> point;
    Mat imgq = img.clone();
    Point2f center; //�������
    vector<Point2f> ellipsecenterleft;
    Mat edges;
    threshold(img, img, 107, 255, CV_THRESH_BINARY_INV);
    GaussianBlur(img, edges, Size(5, 5), 0, 0);
    Mat edges1;
    Canny(edges, edges1, 80, 150, 3);


    vector<vector<Point> > contours;// �����������洢����
    vector<Vec4i> hierarchy;// Ѱ�������������

    findContours(edges1, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
    for (int i = 0; i < contours.size(); i++)
    {
        RotatedRect m_ellipsetemp;  // fitEllipse����ֵ����������
        if (contours[i].size() <= 4)
        {
            continue;
        }
        if (contourArea(contours[i]) < 0.001 && contourArea(contours[i]) > 10000)
        {
            continue;
        }
        m_ellipsetemp = fitEllipse(contours[i]);  //�ҵ��ĵ�һ�����������õ�m_ellipsetemp

        if (m_ellipsetemp.size.width / m_ellipsetemp.size.height < 0.000001)
        {
            continue;
        }
        center = m_ellipsetemp.center;//��ȡ��Բ����

        //point.insert(make_pair(center.x, center.y));
        //drawCross(imgq, center, Scalar(255, 0, 0), 30, 2);
        if (48 < center.x && center.x < 49)
        {
            point.insert(make_pair(center.x, center.y));
            drawCross(imgq, center, Scalar(0, 0, 255), 50, 4);
        }

        if (158 < center.x && center.x < 160)
        {
            point.insert(make_pair(center.x, center.y));
            drawCross(imgq, center, Scalar(0, 0, 255), 50, 4);
        }
        if (190 < center.x && center.x < 190.2)
        {
            point.insert(make_pair(center.x, center.y));
            drawCross(imgq, center, Scalar(0, 0, 255), 50, 4);
        }
        if ((int)center.x == 196)
        {
            point.insert(make_pair(center.x, center.y));
            drawCross(imgq, center, Scalar(0, 0, 255), 50, 4);
        }
        if ((int)center.x == 265)
        {
            point.insert(make_pair(center.x, center.y));
            drawCross(imgq, center, Scalar(0, 0, 255), 50, 4);
        }
        if ((int)center.x == 340)
        {
            point.insert(make_pair(center.x, center.y));
            drawCross(imgq, center, Scalar(0, 0, 255), 50, 4);
        }
        if ((int)center.x == 534 && (int)center.y == 497)
        {
            point.insert(make_pair(center.x, center.y));
            drawCross(imgq, center, Scalar(0, 0, 255), 50, 4);
        }
        if ((int)center.x == 707)
        {
            point.insert(make_pair(center.x, center.y));
            drawCross(imgq, center, Scalar(0, 0, 255), 50, 4);
        }
        if ((int)center.x == 761)
        {
            point.insert(make_pair(center.x, center.y));
            drawCross(imgq, center, Scalar(0, 0, 255), 50, 4);
        }
        if ((int)center.x == 632)
        {
            point.insert(make_pair(center.x, center.y));
            drawCross(imgq, center, Scalar(0, 0, 255), 50, 4);
        }
    }
    //��ȡ����·��
    QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);

    QString temp = desktop_path + QString::fromLocal8Bit("/result/image_recognition/central_coordinate");
    imwrite(temp.toLocal8Bit().toStdString() + "/1.jpg", imgq);

}
void image_recognition::central_coordinate()
{
    flag = 5;
    flag5 = 2;

    ui.label->clear();

    //��ȡ����·��
    QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString dlgTitle = QString::fromLocal8Bit("ѡ���ļ�"); //�Ի������
    QString filter = QString::fromLocal8Bit("�����ļ�(*.*)"); //�ļ�������
    QStringList fileList = QFileDialog::getOpenFileNames(this, dlgTitle, desktop_path, filter);

    QDir dir(desktop_path + QString::fromLocal8Bit("/result"));
    if (!dir.exists())
    {
        dir.mkdir(desktop_path + QString::fromLocal8Bit("/result"));
    }
    QDir dir1(desktop_path + QString::fromLocal8Bit("/result/image_recognition"));
    if (!dir1.exists())
    {
        dir1.mkdir(desktop_path + QString::fromLocal8Bit("/result/image_recognition"));
    }
    QDir dir2(desktop_path + QString::fromLocal8Bit("/result/image_recognition/central_coordinate"));
    if (!dir2.exists())
    {
        dir2.mkdir(desktop_path + QString::fromLocal8Bit("/result/image_recognition/central_coordinate"));
    }

    //���ļ��ж���ͼ��
    Mat img = imread(fileList[0].toLocal8Bit().toStdString());
    FeaturePoint(img);

    QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/image_recognition/central_coordinate/1.jpg"));
    QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
    ui.label->setPixmap(dest);
    QMessageBox::information(this, QString::fromLocal8Bit("��Ϣ"), QString::fromLocal8Bit("����������ȡ���"), QMessageBox::Ok, QMessageBox::Ok);

}



image_recognition::~image_recognition()
{


}
