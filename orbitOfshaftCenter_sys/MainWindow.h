#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include<qtimer.h>
#include<qdatetime.h>
#include<qlabel.h>
#include<qstatusbar.h>

#include <QMessageBox>

//#include"Parameter_optimization.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //״̬��
    QStatusBar* bar;
    //����
    QLabel* authorLabel;
    //��ǰʱ��
    QLabel* dateTimeLabel;
    //��ʱ�������ڸ���ʱ�䡣
    QTimer* timer;
    //����ʱ��
    void updateLabel();

    //����궨
    void camera_calobration();
    //�л����ڵ������Ż�
    void to_paramter_optimization();

    //�л����ڵ�ͼ����--ʶ��
    void to_image_recognition();

    void to_Axis_trajectory_reconstruction();

    void to_datafusion();

private:
    Ui::MainWindowClass ui;
};
