#include "softA.h"


#include <QDebug>
#include <QFileInfoList>
#include <QSizePolicy>

softA::softA(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	// �ò������ sofa a  ������

	//setWindowTitle(QStringLiteral("���Ĺ켣�ᴿ�����ʶ��ϵͳ"));
	// ��ʼ��
	lb_dataread = new QLabel(QStringLiteral("���ݶ���"));
	lb_dataread->adjustSize();
	lb_options = new QLabel(QStringLiteral("����ѡ��"));
	lb_model = new QLabel(QStringLiteral("ģ��ѡ��"));
	lb_interval = new QLabel(QStringLiteral("���ʱ��"));
	lb_title = new QLabel(QStringLiteral("���Ĺ켣�ᴿ�����ʶ��ϵͳ"));
	lb_title->setMargin(0);
	//lb_title->setBaseSize();
	lb_title->setAlignment(Qt::AlignCenter);
	lb_title->setFont(QFont("΢���ź�", 40));
	
	bt_start = new QPushButton(QStringLiteral("��ʼ"));
	connect(bt_start, SIGNAL(clicked()), this, SLOT(action()));
	
	bt_dataread = new QPushButton;
	connect(bt_dataread, SIGNAL(clicked()), this, SLOT(data_read()));
	box_options = new QComboBox;
	box_options->insertItem(0, "ransac");
	box_options->insertItem(1, "ceemdan");
	box_options->insertItem(2, "emd");
	box_options->insertItem(3, "morphology");
	interval = 10;
	bt_model = new QPushButton;
	connect(bt_model, SIGNAL(clicked()), this, SLOT(model_choose()));


	le_interval = new QLineEdit;
	//connect(le_interval, SIGNAL(textChanged(const QString& )), this, SLOT(interval_changed()));
	connect(le_interval, SIGNAL(editingFinished()), this, SLOT(interval_changed()));
	le_interval->setText("10");


	// ��ʾ����

	view_all = new view_widget;
	this->view_all ->setFixedSize(QDesktopWidget().availableGeometry(this).size() * 0.7);
	//view_all->setBaseSize(QSize(this->size()));




	// ����
	layout_left = new QGridLayout;
	layout_right = new QHBoxLayout;	
	layout_up = new QVBoxLayout;
	layout_main = new QGridLayout(this);

	// �ϰ벿����
	layout_up->addWidget(lb_title);
	layout_up->setAlignment(Qt::AlignVCenter);
	// // ��벿��������
	//layout_left->addWidget(lb_title, 0, 0, 1, 5);
	layout_left->addWidget(lb_dataread, 0, 0);
	layout_left->addWidget(bt_dataread, 0, 1);

	layout_left->addWidget(lb_options, 1, 0);
	layout_left->addWidget(box_options, 1, 1);

	layout_left->addWidget(lb_model, 2, 0);
	layout_left->addWidget(bt_model, 2, 1);

	layout_left->addWidget(lb_interval, 3, 0);
	layout_left->addWidget(le_interval, 3, 1);

	layout_left->setMargin(100);
	layout_left->setHorizontalSpacing(20);
	layout_left->setVerticalSpacing(200);
	// �Ұ벿����

	layout_right->addWidget(bt_start);
	layout_right->setAlignment(Qt::AlignCenter);
	layout_right->setMargin(400);


	// �ܲ���

	layout_main->addLayout(layout_up, 0, 0, 1, 2);
	//layout_main->addWidget(lb_title, 0, 0, 1, 2);
	layout_main->addLayout(layout_left, 1, 0);
	layout_main->addLayout(layout_right, 1, 1);

	layout_main->setColumnStretch(1, 3);
	//layout_main->setRowStretch(1, 3);

	connect(this, SIGNAL(create_thread()), this, SLOT(create_thread_slot()));
}

void softA::data_read()
{
	//QString data_path = QFileDialog :: getOpenFileName(this, QStringLiteral("��ѡ�����������ļ���"),"C:/Users/X_xx/Desktop/test_dir/", "*.xlsx *.csv");
	QString data_path = QFileDialog::getExistingDirectory(this, QStringLiteral("��ѡ�����������ļ���"), "C:/Users/X_xx/Desktop/test_dir/");
	QDir dir(data_path);
	QStringList s; 

	// datapath + list[0]
	s << "*.csv" << "*.xlsx";
	//file_list = new QFileInfoList;


	file_list = dir.entryInfoList(s, QDir::Files); // ѡȡdata�ļ�


	//QFileInfoList file_info_list = GetFileList();
	if (file_list.count() == 0) // ����ļ�����ѡ�ļ���Ϊ��
	{
		//qDebug() << "�ļ���Ϊ��" << endl;
		QMessageBox::information(this, QStringLiteral("���ݲ�����ʾ����"), 
			QStringLiteral("��ǰ��ѡ���ļ��в����������ļ���������ѡ������������"));
	}
	else
	{ 
		QMessageBox::information(this, QStringLiteral("����ѡȡ�ɹ���ʾ����"),
			QStringLiteral("��������·������ӳɹ�������к�������"));
	}
}

void softA::interval_changed()
{
	// ���ʱ��仯�ۺ���
	qDebug() << QStringLiteral("�ۺ���������") << endl;
	interval = le_interval->text().toInt();
	qDebug() << interval << endl;
}

void softA::model_choose()
{
	QString model_path = QFileDialog::getOpenFileName(this, QStringLiteral("��ѡ����Ҫʹ�õ�ģ��"), "C:/Users/X_xx/Desktop/test_dir/2.net");
	// ��ȡ��ǰ·��QString fileName = QCoreApplication::applicationDirPath();
	//qDebug() << model_path << endl;
	//qDebug() << fileName << endl;

	if (model_path.contains(".mat"))
	{
		// ģ���ļ���Ϣѡȡ
		QMessageBox::information(this, QStringLiteral("ģ��ѡȡ�ɹ���ʾ����"),
			QStringLiteral("ģ��ѡȡ�ɹ�������к�������"));	

		fileinfo_model = QFileInfo(model_path); //�õ�ģ���ļ���Ϣ
		
		//qDebug() << fileinfo_model.fileName() << endl;  
	}
	else 
	{
		QMessageBox::information(this, QStringLiteral("ģ��ѡȡ������ʾ����"),
			QStringLiteral("ģ��ѡȡ����������ѡȡģ��"));
	}


}

void softA::action()
{
	

	
	//this->hide();

	//view_all->show();
	// ��ʼ�����ۺ���
	
	 //����ѡ��test part
	//lb_options->setText(box_options->currentText());
	//qDebug() << interval << endl;

//	 list path

	//QString s = file_list.at(0).path() + "/" + file_list.at(0).fileName();
	//qDebug() << file_list.at(0).path()<< endl;
	//qDebug() << file_list.at(0).fileName() << endl;
	//qDebug() << s << endl;


	//qDebug() << "action" << endl;
	//if (data_resolveInitialize())
	//{
	//	qDebug() << " init success" << endl;
	//	for (int i = 0; i < file_list.count(); i++)
	//	/*for (int i = 1; i < 2; i++)*/
	//	{
	//		// ��ȡ��ǰ�����ļ�·������
	//		QString data_path = file_list.at(i).path() + "/" + file_list.at(i).fileName();
	//		std::string datapathqstr_str = data_path.toStdString();
	//		const char* datapathstr_to_mw = datapathqstr_str.c_str();
	//		qDebug() << QStringLiteral("�����ļ�·��") << datapathstr_to_mw << endl;
	//		mwArray pathstr(datapathstr_to_mw);

	//		// ��ȡ���ڲ���
	//		QDateTime date_time = QDateTime::currentDateTime();//��ȡϵͳ��ǰ��ʱ��
	//		QString qstr = date_time.toString("yyyy-MM-dd_hh-mm-ss");//��ʽ��ʱ��
	//		std::string dateqstr_str= qstr.toStdString();
	//		const char*  datestr_to_mw= dateqstr_str.c_str();

	//		qDebug() << datestr_to_mw << endl;
	//		//qDebug() << qstr << endl;
	//		//
	//		//std::cout << dateqstr_str << endl;

	//		//mwArray timestr("2221111111"); // time str ����
	//		mwArray timestr(datestr_to_mw); // time str ����
	//		// ��ȡ����ѡ������
	//				//box_options->currentIndex();
	//		mwArray option_index(box_options->currentIndex(), mxDOUBLE_CLASS);
	//		
	//		// ��ȡmodel ����  ���а��� ����·�� �� �ļ�����

	//		// ģ�;���·��
	//		QString s =  fileinfo_model.path(); // ģ�͵ľ���·��
	//		qDebug() << QStringLiteral("ģ�;���·�� QString")<< s << endl;
	//		std::string modelpath = s.toStdString();

	//		const char* modelpath_to_mw = modelpath.c_str();
	//		qDebug() << QStringLiteral("ת����ģ�;���·��") << modelpath_to_mw << endl;
	//		mwArray absolutepath_Net(modelpath_to_mw);
	//		// ģ������
	//		std::string modelname = fileinfo_model.fileName().toStdString();; // ģ������
	//		//qDebug() 
	//		


	//		// 
	//		// 
	//		//qDebug() << modelpath << endl;
	//		const char* modelname_to_mw = modelname.c_str();
	//	   qDebug() << QStringLiteral("��matlab ʹ�õ� ģ������") << modelname_to_mw << endl;
	//		mwArray NetName(modelname_to_mw);


	//		// ����dll ���д���
	//		//�õ����

	//		mwArray res(mxCHAR_CLASS);
	//		data_resolve(1, res, pathstr, absolutepath_Net, NetName, timestr, option_index);

	//		printf("%s\n", (const char*)(res.ToString()));
	//		Sleep(interval * 1000);



	//		//��ʶ����ɵ����ݼ��е� �����ļ���

	//		//if(QFile::copy(data_path, "C:/Users/X_xx/Desktop/test_dir/3.data_save/"  +  file_list.at(i).fileName()) 
	//		//	&&QFile::remove(data_path))

	//		if (QFile::rename(data_path, "C:/Users/X_xx/Desktop/test_dir/3.data_save/" + file_list.at(i).fileName()))
	//						qDebug() << QStringLiteral("ʶ����ļ�ת�Ƴɹ�") << endl;
	//	}


	//	QMessageBox::information(this, QStringLiteral("ѵ�������ʾ����"),
	//		QStringLiteral("������������ȫ��ʶ����ɣ������¼�������"));

	//	data_resolveTerminate();
	//	mclTerminateApplication();




		/**/
	//}
		

	emit mainwindow_hide();

	this->view_all->show();
	emit create_thread();
}

void softA::create_thread_slot()
{
	//this->view_all->hide();
	// �˴��������̴߳�������
	worker = new workerThread(this->file_list, 
		this -> fileinfo_model, 
		box_options->currentIndex(), 
		this ->interval);
	connect(worker, SIGNAL(resultReady(QString, QString, QString)), this, SLOT(handleResults(QString, QString, QString)));
	connect(worker, SIGNAL(massion_complete()), this, SLOT(getMassion_state()));
	worker->start();

}
void softA::handleResults(QString  s, QString res, QString prmi)
{
	qDebug() << "\n\n\n\n\n" << endl;


	qDebug() << QStringLiteral("ui�̲߳ۺ����յ����̴߳����ź�") << endl;
	qDebug() << QStringLiteral("�յ����߳̽��")  << s << endl;
	qDebug() << QStringLiteral("�յ����߳��ᴿͼƬ·��") << res << endl;
	qDebug() << QStringLiteral("�յ����߳�ԭʼͼƬ·��") << prmi << endl;

	qDebug() << "\n\n\n\n\n" << endl;
}

void softA::getMassion_state()
{
	qDebug() << "\n\n\n\n\n\n\n" << endl;

	qDebug() << QStringLiteral("���ݴ��������ʾ����");
	QMessageBox::information(this->view_all, QStringLiteral("���ݴ��������ʾ����"),
		QStringLiteral("��ǰ���������Ѿ��������"));
	
	worker->quit();
	worker->wait();
	delete worker;

}


softA::~softA()
{}


