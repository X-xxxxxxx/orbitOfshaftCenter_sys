#include "softA.h"


#include <QDebug>
#include <QFileInfoList>

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
	le_interval = new QLineEdit;
	//connect(le_interval, SIGNAL(textChanged(const QString& )), this, SLOT(interval_changed()));
	connect(le_interval, SIGNAL(editingFinished()), this, SLOT(interval_changed()));
	le_interval->setText("10");

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
	file_list = dir.entryInfoList(s, QDir::Files);
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

void softA::action()
{
	// 开始按键槽函数
	
	// 方法选择test part
	//lb_options->setText(box_options->currentText());
	//qDebug() << interval << endl;

	//for (int )

	// list path

	//QString s = file_list.at(0).path() + "/" + file_list.at(0).fileName();
	//qDebug() << file_list.at(0).path()<< endl;
	//qDebug() << file_list.at(0).fileName() << endl;
	//qDebug() << s << endl;

	for (int i = 0; i < file_list.count(); i++)
	{
		QString data_path = file_list.at(i).path() + "/" + file_list.at(i).fileName();
		//qDebug() << file_list.at(i).path() << endl;
		//qDebug() << file_list.at(i).fileName() << endl;
		//qDebug() << s << endl;

		// 将data_path 输入matlab以供处理


	}
	//for (;;)
	//{
	//	//每一次处理一个
	//		// 将path 传入 matlab 做excel 读取
	//		// 做后续处理 
	//	// 将处理后的文件剪切至 data_save folder
	//	 
	//	// 生成窗口
	//}
}
softA::~softA()
{}


