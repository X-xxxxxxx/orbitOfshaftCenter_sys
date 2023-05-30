#pragma once
#include <QThread>
#include"workerThread.h"

#include <QWidget>
#include "ui_softA.h"
#include <iostream>
#include <windows.h>



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
#include <QDesktopWidget>

// 
#include "view_widget.h"


// 
#include <QDir>
#include <QStandardPaths>
#include <QDesktopServices>
#include <QUrl>
#include <QFileDialog>
#include <QMessageBox>
#include <QDateTime> // ������ȡ��ǰʱ����Ϣ



// dll��
#include "mydlladd.h"
#include "get_data_demesions.h"
#include "data_resolve.h"
//#include "smoothdata.h"
//#include "ransac.h"


#include <mat.h>
#include <matrix.h>



#pragma comment (lib, "libmx.lib")
#pragma comment (lib, "libmat.lib")
#pragma comment (lib, "mclmcr.lib")
#pragma comment (lib, "mclmcrrt.lib")
#pragma comment (lib, "libmex.lib")
#pragma comment (lib, "libeng.lib")

#pragma comment(lib, "mydlladd.lib")
#pragma comment(lib, "get_data_demesions.lib")
#pragma comment(lib, "data_resolve.lib")


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
	QFileInfo fileinfo_model;



	// ��ʾ����

	view_widget* view_all;




	workerThread* worker;
private:
	Ui::softAClass ui;


private slots:
	// ���ݶ��밴ť�ۺ���
	void data_read();
	void interval_changed();
	void model_choose();
	void action();
	void create_thread_slot(); // �����̲߳ۺ���
	void handleResults(QString, QString, QString);
	void getMassion_state();
signals:
	void mainwindow_hide();
	void create_thread();
};
