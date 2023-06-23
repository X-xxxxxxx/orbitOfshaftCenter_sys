#pragma once

#include <QWidget>
#include "ui_view_widget.h"

// 
#include <QLabel>



// 
#include <QGridLayout>
#include<QHBoxLayout>
#include <QVBoxLayout>

// 图片加载类
#include <QImageReader>
#include<QPixmap>
#include <QImage>


//
#include <QCloseEvent>
//
#include "LoadingFrom.h"

class view_widget : public QWidget
{
	Q_OBJECT

signals:
	void view_to_softa();
public:
	view_widget(QWidget *parent = nullptr);
	~view_widget();
	void closeEvent(QCloseEvent*); // 重写关闭事件函数 
	// 显示图片
	QLabel* lb_prmi;
	QLabel* lb_prmi_hint;
	QLabel* lb_solv;
	QLabel* lb_solv_hint;

	// 
	//方法
	QLabel* lb_option_hint;
	QLabel* lb_option_choose;

	// 网络
	QLabel* lb_net_hint;
	QLabel* lb_net_choose;

	// 间隔时间
	QLabel* lb_interval_hint;
	QLabel* lb_interval_choose;

	// 结果
	QLabel* lb_res_hint;
	QLabel* lb_res_show;


	// 右边布局
	QVBoxLayout* left_layout;

	QGridLayout* right_layout;

	QHBoxLayout* main_layout;

	QWidget* loading;
private:
	Ui::view_widgetClass ui;
};
