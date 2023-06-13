#pragma once

#include<qtimer.h>
#include<qdatetime.h>
#include<qlabel.h>
#include<qstatusbar.h>

#include <QMainWindow>
#include "ui_datafusion.h"

class datafusion : public QMainWindow
{
	Q_OBJECT

public:
	datafusion(QWidget *parent = nullptr);
	~datafusion();

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

	void m_weighting();
	void m_tuzuhe();
	void m_xiefangcha();
	void m_hpo();


	int flag1; 
	int flag2;
	int flag3;
	int flag4;

	int flag;

	void show_up();
	void shou_down();

private:
	Ui::datafusionClass ui;
};
