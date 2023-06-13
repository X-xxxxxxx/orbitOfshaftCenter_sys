#pragma once

#include <QMainWindow>
#include "ui_image_recognition.h"

#include<qtimer.h>
#include<qdatetime.h>
#include<qlabel.h>
#include<qstatusbar.h>



class image_recognition : public QMainWindow
{
	Q_OBJECT

public:
	image_recognition(QWidget *parent = nullptr);
	~image_recognition();


	int flag1; //canny
	int flag2; //形态学
	int flag3;//边缘像素搜索
	int flag4;//颜色
	int flag5;//质心法

	
	int flag;

	void show_up();
	void shou_down();
	


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

	

	//canny算子
	void m_canny();
	//边缘检测
	void m_bianyuantu();
	//数学形态学
	void mathematical_morphology();

	void colour();

	void central_coordinate();

	void to_mainwindow();
	void myquit();


private:
	Ui::image_recognitionClass ui;
};
