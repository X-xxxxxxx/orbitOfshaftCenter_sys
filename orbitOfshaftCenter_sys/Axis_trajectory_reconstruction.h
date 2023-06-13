#pragma once

#include <QMainWindow>
#include "ui_Axis_trajectory_reconstruction.h"

#include<qtimer.h>
#include<qdatetime.h>
#include<qlabel.h>
#include<qstatusbar.h>

class Axis_trajectory_reconstruction : public QMainWindow
{
	Q_OBJECT

public:
	Axis_trajectory_reconstruction(QWidget *parent = nullptr);
	~Axis_trajectory_reconstruction();

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

	void to_mainwindow();
	void myquit();

	void cg();
	void cg1();
	void cg2();

	int flag1;
	int flag2;
	int flag3;

	int flag;

	void show_up();
	void shou_down();

private:
	Ui::Axis_trajectory_reconstructionClass ui;
};
