
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

    //�ȴ����̶���ͷ������
    word.setPageOrientation(0);			//ҳ������
    word.setWordPageView(3);			//ҳ����ͼ
    word.insertMoveDown();				//����س�
    word.setFontSize(20);				//�����С
    word.setParagraphAlignment(0);		//������������
    word.setFontBold(true);				//����Ӵ�
    word.insertText((QString::fromLocal8Bit("���Ĺ켣����ϵͳ�������")));//��������
    word.setFontBold(false);			//����Ӵ�
    word.insertMoveDown();              //����س�
    word.setParagraphAlignment(1);		//������������
    word.setFontSize(10);
    word.insertMoveDown();



    word.intsertTable(4, 1);//������ 10�� 3��
    
    QString text = QString::fromLocal8Bit("������Ӱ��������ת��е���Ĺ켣����ϵͳ��һ�׼�����궨��ͼ��ʶ���������궨λ���켣�ؽ��������ںϵȹ��ܵ����ϵͳ���������������������ݿ�ʵ�ֶԵ���˫Ŀ����ı궨����־��ͼ����Ϣ����ȡ������������ݵ��ںϣ���������Ա��档");
    word.setCellString(1, 1, text);

    QString text1 = QString::fromLocal8Bit("��ͼΪ������Ӱ��������ת��е���Ĺ켣������ά�켣ͼ���ֱ�Ϊͬһ��ʵ�����ݲ������ǲ�������������Կռ�ǰ�����᷽�����������ά���Ĺ켣��");
    word.setCellString(2, 1, text1);

    QString imagepath = QString::fromLocal8Bit("C:\\Users\\X_xx\\Desktop\\result\\parameter_optimization\\PSO\\PSO.jpg");
    word.insertCellPic(2, 1, imagepath);
    
    QString imagepath1 = QString::fromLocal8Bit("C:\\Users\\Gao\\Desktop\\���\\�����Ż�\\����Ⱥ\\PSO.jpg");
    word.insertCellPic(2, 1, imagepath1);

    std::string str[9] = { "Cx","Cy","Vx","Vy","k1","k2","p1","p2","p3" };

    QString text3 = QString::fromLocal8Bit("��������Ⱥ����������Ż����������ʾ��");
    word.setCellString(3, 1, text3);


    QString temp= QString::fromLocal8Bit("��������Ⱥ����������Ż����������ʾ��")+'\n';
    for (int i = 0; i < 9; i++)
    {
        temp = temp+QString::fromStdString(str[i]) + ":" + QString::number(num[i], 'f', 10);
        temp = temp + '\n';
    }
    word.setCellString(3, 1, temp);
    

    QString text4= QString::fromLocal8Bit("�����ˣ�") + '\n'+ QString::fromLocal8Bit("���ڣ�");
    word.setCellString(4, 1, text4);

    word.close();                   //�ر�word
    
}




void Parameter_optimization::updateLabel()
{
    dateTimeLabel->setText(tr("<h3>%1</h3>").arg(QDateTime::currentDateTime().toString("yyyy-MM-d hh:mm:ss")));
}

Parameter_optimization::Parameter_optimization(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

    //�����Ż�
    ui.mainToolBar->hide();
    ////����
    //QPalette pal = this->palette();
    //QPixmap pixmap(":/image/23.jpg");
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
    //setFixedSize(2000, 600);//�̶����ڴ�С
    this->setWindowTitle(QString::fromLocal8Bit("����궨�����Ż�"));

    //״̬��
    bar = new QStatusBar(this);
    QLabel* authorLabel = new QLabel(QString::fromLocal8Bit("���£���������ѧ"), this);
    bar->addPermanentWidget(authorLabel, 0);
    //ʱ���ǩ
    dateTimeLabel = new QLabel(tr("<h3>%1</h3>").arg(QDateTime::currentDateTime().toString("yyyy-MM-d hh:mm:ss")), this);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Parameter_optimization::updateLabel);
    timer->start(1000);
    bar->addWidget(dateTimeLabel, 0);
    this->setStatusBar(bar);


    //����Ⱥ  flag=1;
    QIcon myicon; //�½�QIcon����
    myicon.addFile(tr(":/image/6.jpg")); //��QIcon����ָ����Ҫ��ͼ��
    ui.pushButton->setIcon(myicon); //����ť���ͼ��
    ui.pushButton->setIconSize(QSize(113, 113));//����ͼ���С
    ui.pushButton->setStyleSheet("background-color: #F6EBFF");
    ui.pushButton->setFocusPolicy(Qt::NoFocus);


    connect(ui.pushButton, &QPushButton::clicked, this, &Parameter_optimization::pso);


    //���   flag=2;
    QIcon myicon1; //�½�QIcon����
    myicon1.addFile(tr(":/image/7.jpg")); //��QIcon����ָ����Ҫ��ͼ��
    ui.pushButton_2->setIcon(myicon1); //����ť���ͼ��
    ui.pushButton_2->setIconSize(QSize(113, 113));//����ͼ���С
    ui.pushButton_2->setStyleSheet("background-color: #F6EBFF");
    ui.pushButton_2->setFocusPolicy(Qt::NoFocus);
    connect(ui.pushButton_2, &QPushButton::clicked, this, &Parameter_optimization::hba);

    
   

    //��ֽ�������Ⱥ   flag=4;
    QIcon myicon3; //�½�QIcon����
    myicon3.addFile(tr(":/image/9.jpg")); //��QIcon����ָ����Ҫ��ͼ��
    ui.pushButton_6->setIcon(myicon3); //����ť���ͼ��
    ui.pushButton_6->setIconSize(QSize(113, 113));//����ͼ���С
    ui.pushButton_6->setStyleSheet("background-color: #F6EBFF");
    ui.pushButton_6->setFocusPolicy(Qt::NoFocus);
    connect(ui.pushButton_6, &QPushButton::clicked, this, &Parameter_optimization::de);


    //��ʾͼ��
    connect(ui.pushButton_4, &QPushButton::clicked, this, &Parameter_optimization::show_image);

    //��ʾ����
    connect(ui.pushButton_5, &QPushButton::clicked, this, &Parameter_optimization::show_parameter);

    //��������
    connect(ui.pushButton_7, &QPushButton::clicked, this, &Parameter_optimization::to_mainwindow);

    //�˳�
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
        //��ȡ����·��
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        QPixmap pix(desktop_path + QString::fromLocal8Bit("/result/parameter_optimization/PSO/PSO.jpg"));
        QPixmap dest = pix.scaled(ui.label->size(), Qt::KeepAspectRatio);
        ui.label->setPixmap(dest);
    }
    if (flag == 2)
    {
        //��ȡ����·��
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
        //��ȡ����·��
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
        //��ȡ����·��
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        ifstream ifs;
        std::string path = desktop_path.toLocal8Bit().toStdString() + "/result/parameter_optimization/PSO/result.txt";
        ifs.open(path, ios::in);

        std::string buf;
        QString str;
        str = QString::fromLocal8Bit("�Ż���Ĳ���Cx Cy u v k1 k2 k3 p1 p2�ֱ�Ϊ");
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
        //��ȡ����·��
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        ifstream ifs;
        std::string path = desktop_path.toLocal8Bit().toStdString() + "/result/parameter_optimization/HBA/result.txt";
        ifs.open(path, ios::in);

        std::string buf;
        QString str;
        str = QString::fromLocal8Bit("�Ż���Ĳ���Cx Cy u v k1 k2 k3 p1 p2�ֱ�Ϊ");
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
        //��ȡ����·��
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        ifstream ifs;
        std::string path = desktop_path.toLocal8Bit().toStdString() + "/result/parameter_optimization/DE/result.txt";
        ifs.open(path, ios::in);

        std::string buf;
        QString str;
        str = QString::fromLocal8Bit("�Ż���Ĳ���Cx Cy u v k1 k2 k3 p1 p2�ֱ�Ϊ");
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



//*****************************����Ⱥ*****************************
void Parameter_optimization::pso()
{

    flag = 1;
    ui.label->clear();

    //��ȡ����·��
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

    QMessageBox::information(this,QString::fromLocal8Bit("��Ϣ"),QString::fromLocal8Bit("����Ⱥ�Ż����"),QMessageBox::Ok,QMessageBox::Ok);

   
}


//*****************************���*****************************
void Parameter_optimization::hba()
{
    flag = 2;
    ui.label->clear();
    //��ȡ����·��
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
    QMessageBox::information(this, QString::fromLocal8Bit("��Ϣ"), QString::fromLocal8Bit("����Ż����"), QMessageBox::Ok, QMessageBox::Ok);
}

//*****************************�Ŵ��㷨*****************************




//*****************************��ֽ�������Ⱥ*****************************
void Parameter_optimization::de()
{
    flag = 4;
    ui.label->clear();
    //��ȡ����·��
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
    QMessageBox::information(this, QString::fromLocal8Bit("��Ϣ"), QString::fromLocal8Bit("��ֽ�������Ⱥ�Ż����"), QMessageBox::Ok, QMessageBox::Ok);

}

Parameter_optimization::~Parameter_optimization()
{


}
