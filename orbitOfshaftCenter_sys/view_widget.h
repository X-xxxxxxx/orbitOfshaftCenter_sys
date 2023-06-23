#pragma once

#include <QWidget>
#include "ui_view_widget.h"

// 
#include <QLabel>



// 
#include <QGridLayout>
#include<QHBoxLayout>
#include <QVBoxLayout>

// ͼƬ������
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
	void closeEvent(QCloseEvent*); // ��д�ر��¼����� 
	// ��ʾͼƬ
	QLabel* lb_prmi;
	QLabel* lb_prmi_hint;
	QLabel* lb_solv;
	QLabel* lb_solv_hint;

	// 
	//����
	QLabel* lb_option_hint;
	QLabel* lb_option_choose;

	// ����
	QLabel* lb_net_hint;
	QLabel* lb_net_choose;

	// ���ʱ��
	QLabel* lb_interval_hint;
	QLabel* lb_interval_choose;

	// ���
	QLabel* lb_res_hint;
	QLabel* lb_res_show;


	// �ұ߲���
	QVBoxLayout* left_layout;

	QGridLayout* right_layout;

	QHBoxLayout* main_layout;

	QWidget* loading;
private:
	Ui::view_widgetClass ui;
};
