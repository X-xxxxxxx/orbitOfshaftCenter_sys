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

    //状态栏
    QStatusBar* bar;
    //作者
    QLabel* authorLabel;
    //当前时间
    QLabel* dateTimeLabel;
    //定时器，用于更新时间。
    QTimer* timer;
    //更新时间
    void updateLabel();

    //相机标定
    void camera_calobration();
    //切换窗口到参数优化
    void to_paramter_optimization();

    //切换窗口到图像处理--识别
    void to_image_recognition();

    void to_Axis_trajectory_reconstruction();

    void to_datafusion();

private:
    Ui::MainWindowClass ui;
};
