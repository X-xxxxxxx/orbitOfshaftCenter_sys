#include "view_widget.h"

view_widget::view_widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//����

	lb_option_hint = new QLabel(QStringLiteral("�ᴿ����"));
	lb_option_choose = new QLabel;

	// ����

	lb_net_hint = new QLabel(QStringLiteral("����ѡ��"));
	lb_net_choose = new QLabel;

	// ���ʱ��
	lb_interval_hint = new QLabel(QStringLiteral("���ʱ��"));
	lb_interval_choose = new QLabel;

	// ��Ͻ��
	lb_res_hint = new QLabel(QStringLiteral("��Ͻ��"));
	lb_res_show = new QLabel;

	// ͼƬ��ʾ
	lb_prmi_hint = new QLabel(QStringLiteral("ԭʼͼƬ"));
	lb_premi = new QLabel;

	lb_solv_hint = new QLabel(QStringLiteral("�ᴿͼƬ"));
	lb_solv = new QLabel;




	// ����
	main_layout = new QHBoxLayout(this);
    left_layout = new QVBoxLayout;
	left_layout->setAlignment(Qt::AlignHCenter);
	right_layout = new QGridLayout;
	right_layout->setAlignment(Qt::AlignHCenter);
	main_layout->addLayout(left_layout);
	main_layout->addLayout(right_layout);



	
	left_layout->addWidget(lb_premi);
	left_layout->addWidget(lb_prmi_hint);
	left_layout->addWidget(lb_solv);
	left_layout->addWidget(lb_solv_hint);








	right_layout->addWidget(lb_option_hint, 0, 0);
	right_layout->addWidget(lb_option_choose, 0, 1);
	right_layout->addWidget(lb_net_hint, 1, 0);
	right_layout->addWidget(lb_net_choose, 1, 1);
	right_layout->addWidget(lb_interval_hint, 2, 0);
	right_layout->addWidget(lb_interval_choose, 2, 1);
	right_layout->addWidget(lb_res_hint, 3, 0);
	right_layout->addWidget(lb_res_show, 3, 1);



}

view_widget::~view_widget()
{}
