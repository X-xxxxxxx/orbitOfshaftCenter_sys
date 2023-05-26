#pragma once

#include <QWidget>
#include "ui_softA.h"




#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QFont>





//
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>



// 
#include <QDir>
#include <QStandardPaths>
#include <QDesktopServices>
#include <QUrl>
#include <QFileDialog>
#include <QMessageBox>




class softA : public QWidget
{
	Q_OBJECT

public:
	softA(QWidget *parent = nullptr);
	~softA();
	
	QLabel* lb_dataread; // �ļ�����
	QLabel* lb_options; // ����ѡ��
	QLabel* lb_model; // ģ��ѡ��
	QLabel* lb_interval; // ���ʱ��

	QPushButton* bt_dataread;
	QComboBox* box_options;
	QPushButton* bt_model;
	QLineEdit* le_interval;

	QLabel* lb_title;

	QPushButton* bt_start;
	// ����

	QGridLayout* layout_left;
	QHBoxLayout* layout_right;
	QVBoxLayout* layout_up;
	QGridLayout* layout_main;

	int interval;

	QString s;


	QFileInfoList file_list;
private:
	Ui::softAClass ui;


private slots:
	// ���ݶ��밴ť�ۺ���
	void data_read();
	void interval_changed();
	void action();
};
