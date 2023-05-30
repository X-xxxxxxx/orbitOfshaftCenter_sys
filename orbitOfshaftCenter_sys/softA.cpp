#include "softA.h"


#include <QDebug>
#include <QFileInfoList>
#include <QSizePolicy>

softA::softA(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	// 该部分完成 sofa a  主界面搭建

	//setWindowTitle(QStringLiteral("轴心轨迹提纯与故障识别系统"));
	// 初始化
	lb_dataread = new QLabel(QStringLiteral("数据读入"));
	lb_dataread->adjustSize();
	lb_options = new QLabel(QStringLiteral("方法选择"));
	lb_model = new QLabel(QStringLiteral("模型选择"));
	lb_interval = new QLabel(QStringLiteral("间隔时间"));
	lb_title = new QLabel(QStringLiteral("轴心轨迹提纯与故障识别系统"));
	lb_title->setMargin(0);
	//lb_title->setBaseSize();
	lb_title->setAlignment(Qt::AlignCenter);
	lb_title->setFont(QFont("微软雅黑", 40));
	
	bt_start = new QPushButton(QStringLiteral("开始"));
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


	// 显示窗口

	view_all = new view_widget;
	this->view_all ->setFixedSize(QDesktopWidget().availableGeometry(this).size() * 0.7);
	//view_all->setBaseSize(QSize(this->size()));




	// 布局
	layout_left = new QGridLayout;
	layout_right = new QHBoxLayout;	
	layout_up = new QVBoxLayout;
	layout_main = new QGridLayout(this);

	// 上半部布局
	layout_up->addWidget(lb_title);
	layout_up->setAlignment(Qt::AlignVCenter);
	// // 左半部布局设置
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
	// 右半部布局

	layout_right->addWidget(bt_start);
	layout_right->setAlignment(Qt::AlignCenter);
	layout_right->setMargin(400);


	// 总布局

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
	//QString data_path = QFileDialog :: getOpenFileName(this, QStringLiteral("请选择数据所在文件夹"),"C:/Users/X_xx/Desktop/test_dir/", "*.xlsx *.csv");
	QString data_path = QFileDialog::getExistingDirectory(this, QStringLiteral("请选择数据所在文件夹"), "C:/Users/X_xx/Desktop/test_dir/");
	QDir dir(data_path);
	QStringList s; 

	// datapath + list[0]
	s << "*.csv" << "*.xlsx";
	//file_list = new QFileInfoList;


	file_list = dir.entryInfoList(s, QDir::Files); // 选取data文件


	//QFileInfoList file_info_list = GetFileList();
	if (file_list.count() == 0) // 如果文件夹所选文件夹为空
	{
		//qDebug() << "文件夹为空" << endl;
		QMessageBox::information(this, QStringLiteral("数据不足提示窗口"), 
			QStringLiteral("当前所选择文件夹不存在数据文件，请重新选择或者添加数据"));
	}
	else
	{ 
		QMessageBox::information(this, QStringLiteral("数据选取成功提示窗口"),
			QStringLiteral("您的数据路径已添加成功，请进行后续操作"));
	}
}

void softA::interval_changed()
{
	// 间隔时间变化槽函数
	qDebug() << QStringLiteral("槽函数被调用") << endl;
	interval = le_interval->text().toInt();
	qDebug() << interval << endl;
}

void softA::model_choose()
{
	QString model_path = QFileDialog::getOpenFileName(this, QStringLiteral("请选择需要使用的模型"), "C:/Users/X_xx/Desktop/test_dir/2.net");
	// 获取当前路径QString fileName = QCoreApplication::applicationDirPath();
	//qDebug() << model_path << endl;
	//qDebug() << fileName << endl;

	if (model_path.contains(".mat"))
	{
		// 模型文件信息选取
		QMessageBox::information(this, QStringLiteral("模型选取成功提示窗口"),
			QStringLiteral("模型选取成功，请进行后续操作"));	

		fileinfo_model = QFileInfo(model_path); //拿到模型文件信息
		
		//qDebug() << fileinfo_model.fileName() << endl;  
	}
	else 
	{
		QMessageBox::information(this, QStringLiteral("模型选取错误提示窗口"),
			QStringLiteral("模型选取有误，请重新选取模型"));
	}


}

void softA::action()
{
	

	
	//this->hide();

	//view_all->show();
	// 开始按键槽函数
	
	 //方法选择test part
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
	//		// 获取当前数据文件路径参数
	//		QString data_path = file_list.at(i).path() + "/" + file_list.at(i).fileName();
	//		std::string datapathqstr_str = data_path.toStdString();
	//		const char* datapathstr_to_mw = datapathqstr_str.c_str();
	//		qDebug() << QStringLiteral("数据文件路径") << datapathstr_to_mw << endl;
	//		mwArray pathstr(datapathstr_to_mw);

	//		// 获取日期参数
	//		QDateTime date_time = QDateTime::currentDateTime();//获取系统当前的时间
	//		QString qstr = date_time.toString("yyyy-MM-dd_hh-mm-ss");//格式化时间
	//		std::string dateqstr_str= qstr.toStdString();
	//		const char*  datestr_to_mw= dateqstr_str.c_str();

	//		qDebug() << datestr_to_mw << endl;
	//		//qDebug() << qstr << endl;
	//		//
	//		//std::cout << dateqstr_str << endl;

	//		//mwArray timestr("2221111111"); // time str 参数
	//		mwArray timestr(datestr_to_mw); // time str 参数
	//		// 获取方法选择索引
	//				//box_options->currentIndex();
	//		mwArray option_index(box_options->currentIndex(), mxDOUBLE_CLASS);
	//		
	//		// 获取model 参数  其中包括 绝对路径 和 文件名字

	//		// 模型绝对路径
	//		QString s =  fileinfo_model.path(); // 模型的绝对路径
	//		qDebug() << QStringLiteral("模型绝对路径 QString")<< s << endl;
	//		std::string modelpath = s.toStdString();

	//		const char* modelpath_to_mw = modelpath.c_str();
	//		qDebug() << QStringLiteral("转化后模型绝对路径") << modelpath_to_mw << endl;
	//		mwArray absolutepath_Net(modelpath_to_mw);
	//		// 模型名字
	//		std::string modelname = fileinfo_model.fileName().toStdString();; // 模型名字
	//		//qDebug() 
	//		


	//		// 
	//		// 
	//		//qDebug() << modelpath << endl;
	//		const char* modelname_to_mw = modelname.c_str();
	//	   qDebug() << QStringLiteral("供matlab 使用的 模型名字") << modelname_to_mw << endl;
	//		mwArray NetName(modelname_to_mw);


	//		// 调用dll 进行处理
	//		//得到结果

	//		mwArray res(mxCHAR_CLASS);
	//		data_resolve(1, res, pathstr, absolutepath_Net, NetName, timestr, option_index);

	//		printf("%s\n", (const char*)(res.ToString()));
	//		Sleep(interval * 1000);



	//		//将识别完成的数据剪切到 其他文件夹

	//		//if(QFile::copy(data_path, "C:/Users/X_xx/Desktop/test_dir/3.data_save/"  +  file_list.at(i).fileName()) 
	//		//	&&QFile::remove(data_path))

	//		if (QFile::rename(data_path, "C:/Users/X_xx/Desktop/test_dir/3.data_save/" + file_list.at(i).fileName()))
	//						qDebug() << QStringLiteral("识别后文件转移成功") << endl;
	//	}


	//	QMessageBox::information(this, QStringLiteral("训练完成提示窗口"),
	//		QStringLiteral("该批次数据已全部识别完成，请重新加载数据"));

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
	// 此处创建子线程处理数据
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


	qDebug() << QStringLiteral("ui线程槽函数收到子线程传出信号") << endl;
	qDebug() << QStringLiteral("收到子线程结果")  << s << endl;
	qDebug() << QStringLiteral("收到子线程提纯图片路径") << res << endl;
	qDebug() << QStringLiteral("收到子线程原始图片路径") << prmi << endl;

	qDebug() << "\n\n\n\n\n" << endl;
}

void softA::getMassion_state()
{
	qDebug() << "\n\n\n\n\n\n\n" << endl;

	qDebug() << QStringLiteral("数据处理完成提示窗口");
	QMessageBox::information(this->view_all, QStringLiteral("数据处理完成提示窗口"),
		QStringLiteral("当前批次数据已经处理完成"));
	
	worker->quit();
	worker->wait();
	delete worker;

}


softA::~softA()
{}


