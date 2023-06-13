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
	int flag2; //��̬ѧ
	int flag3;//��Ե��������
	int flag4;//��ɫ
	int flag5;//���ķ�

	
	int flag;

	void show_up();
	void shou_down();
	


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

	

	//canny����
	void m_canny();
	//��Ե���
	void m_bianyuantu();
	//��ѧ��̬ѧ
	void mathematical_morphology();

	void colour();

	void central_coordinate();

	void to_mainwindow();
	void myquit();


private:
	Ui::image_recognitionClass ui;
};
