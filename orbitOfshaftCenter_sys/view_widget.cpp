#include "view_widget.h"

view_widget::view_widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//����

	lb_option_hint = new QLabel(QStringLiteral("�ᴿ����"));
	lb_option_choose = new QLabel;
	lb_option_choose->setFrameShape(QFrame::Box);
	lb_option_choose->setFrameStyle(QFrame::Panel | QFrame::Sunken);

	// ����

	lb_net_hint = new QLabel(QStringLiteral("����ѡ��"));
	lb_net_choose = new QLabel;
	lb_net_choose->setFrameShape(QFrame::Box);
	lb_net_choose->setFrameStyle(QFrame::Panel | QFrame::Sunken);

	// ���ʱ��
	lb_interval_hint = new QLabel(QStringLiteral("���ʱ��"));
	lb_interval_choose = new QLabel;
	lb_interval_choose->setFrameShape(QFrame::Box);
	lb_interval_choose->setFrameStyle(QFrame::Panel | QFrame::Sunken);

	// ��Ͻ��
	lb_res_hint = new QLabel(QStringLiteral("��Ͻ��"));
	lb_res_show = new QLabel;
	lb_res_show->setFrameShape(QFrame::Box);
	lb_res_show->setFrameStyle(QFrame::Panel | QFrame::Sunken);

	// ͼƬ��ʾ
	lb_prmi_hint = new QLabel(QStringLiteral("ԭʼͼƬ"));
	lb_prmi_hint->setAlignment(Qt::AlignHCenter);
	lb_prmi_hint->setFixedSize(QSize(500, 50));
	lb_prmi = new QLabel;
	lb_prmi->setFrameShape(QFrame::Box);
	lb_prmi->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	lb_prmi->setFixedSize(QSize(500, 400));

	lb_solv_hint = new QLabel(QStringLiteral("�ᴿͼƬ"));
	lb_solv_hint->setAlignment(Qt::AlignHCenter);
	lb_solv_hint->setFixedSize(QSize(500, 50));
	lb_solv = new QLabel;
	lb_solv->setFrameShape(QFrame::Box);
	lb_solv->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	lb_solv->setFixedSize(QSize(500, 400));




	// ����
	main_layout = new QHBoxLayout(this);
    left_layout = new QVBoxLayout;
	left_layout->setAlignment(Qt::AlignHCenter);
	left_layout->setMargin(10);
	right_layout = new QGridLayout;
	right_layout->setAlignment(Qt::AlignVCenter);
	right_layout->setHorizontalSpacing(1);
	right_layout->setVerticalSpacing(250);
	right_layout->setMargin(100);
	main_layout->addLayout(left_layout);
	main_layout->addLayout(right_layout);
	///main_layout->setStretch(2, 1);



	
	left_layout->addWidget(lb_prmi);
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
void view_widget::closeEvent(QCloseEvent* event)
{
	// ����ǰ���ڹر� �����ź����´�������

	emit view_to_softa();
	event->accept();
}
view_widget::~view_widget()
{}


