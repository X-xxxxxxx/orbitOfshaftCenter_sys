#include "softA.h"


#include <QDebug>
#include <QFileInfoList>

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
	le_interval = new QLineEdit;
	//connect(le_interval, SIGNAL(textChanged(const QString& )), this, SLOT(interval_changed()));
	connect(le_interval, SIGNAL(editingFinished()), this, SLOT(interval_changed()));
	le_interval->setText("10");

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
}

void softA::data_read()
{
	//QString data_path = QFileDialog :: getOpenFileName(this, QStringLiteral("��ѡ�����������ļ���"),"C:/Users/X_xx/Desktop/test_dir/", "*.xlsx *.csv");
	QString data_path = QFileDialog::getExistingDirectory(this, QStringLiteral("��ѡ�����������ļ���"), "C:/Users/X_xx/Desktop/test_dir/");
	QDir dir(data_path);
	
	QFileInfoList file_list = dir.entryInfoList(QStringList("*.csv *.xlsx"), QDir::Files);
	//QFileInfoList file_info_list = GetFileList();
	if (file_list.count() == 0) // ����ļ�����ѡ�ļ���Ϊ��
	{
		//qDebug() << "�ļ���Ϊ��" << endl;
		QMessageBox::information(this, QStringLiteral("����ȱʧ��ʾ����"), 
			QStringLiteral("��ǰ��ѡ���ļ��в����������ļ���������ѡ������������"));
	}
	else
	{ 
		//showFileInfoList(file_list);

		//while (true)
		//{
		//	// �ȴ���ǰ��������
		//}
	}


}

void softA::interval_changed()
{
	// ���ʱ��仯�ۺ���
	qDebug() << QStringLiteral("�ۺ���������") << endl;
	interval = le_interval->text().toInt();
	qDebug() << interval << endl;
}

void softA::action()
{
	// ��ʼ�����ۺ���
	lb_options->setText(box_options->currentText());
	qDebug() << interval << endl;
}
softA::~softA()
{}


