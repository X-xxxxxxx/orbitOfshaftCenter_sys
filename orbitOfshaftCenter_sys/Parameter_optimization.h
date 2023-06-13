#pragma once

#include <QMainWindow>

#include<qtimer.h>
#include<qdatetime.h>
#include<qlabel.h>
#include<qstatusbar.h>
#include "ui_Parameter_optimization.h"



class Parameter_optimization : public QMainWindow
{
	Q_OBJECT



public:
	
	//void saveword();
	
	Parameter_optimization(QWidget *parent = nullptr);
	~Parameter_optimization();

	void pso();
	void hba();
	void de();
	
	void show_image();
	void show_parameter();
	void to_mainwindow();

	int flag;
	void myquit();

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

	double num[9];

private:
	Ui::Parameter_optimizationClass ui;
};
