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

	double num[9];

private:
	Ui::Parameter_optimizationClass ui;
};
