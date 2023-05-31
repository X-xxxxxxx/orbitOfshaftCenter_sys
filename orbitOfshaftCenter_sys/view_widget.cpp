#include "view_widget.h"

view_widget::view_widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//方法

	lb_option_hint = new QLabel(QStringLiteral("提纯方法"));
	lb_option_choose = new QLabel;
	lb_option_choose->setFrameShape(QFrame::Box);
	lb_option_choose->setFrameStyle(QFrame::Panel | QFrame::Sunken);

	// 网络

	lb_net_hint = new QLabel(QStringLiteral("网络选择"));
	lb_net_choose = new QLabel;
	lb_net_choose->setFrameShape(QFrame::Box);
	lb_net_choose->setFrameStyle(QFrame::Panel | QFrame::Sunken);

	// 间隔时间
	lb_interval_hint = new QLabel(QStringLiteral("间隔时间"));
	lb_interval_choose = new QLabel;
	lb_interval_choose->setFrameShape(QFrame::Box);
	lb_interval_choose->setFrameStyle(QFrame::Panel | QFrame::Sunken);

	// 诊断结果
	lb_res_hint = new QLabel(QStringLiteral("诊断结果"));
	lb_res_show = new QLabel;
	lb_res_show->setFrameShape(QFrame::Box);
	lb_res_show->setFrameStyle(QFrame::Panel | QFrame::Sunken);

	// 图片显示
	lb_prmi_hint = new QLabel(QStringLiteral("原始图片"));
	lb_prmi_hint->setAlignment(Qt::AlignHCenter);
	lb_prmi_hint->setFixedSize(QSize(500, 50));
	lb_prmi = new QLabel;
	lb_prmi->setFrameShape(QFrame::Box);
	lb_prmi->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	lb_prmi->setFixedSize(QSize(500, 400));

	lb_solv_hint = new QLabel(QStringLiteral("提纯图片"));
	lb_solv_hint->setAlignment(Qt::AlignHCenter);
	lb_solv_hint->setFixedSize(QSize(500, 50));
	lb_solv = new QLabel;
	lb_solv->setFrameShape(QFrame::Box);
	lb_solv->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	lb_solv->setFixedSize(QSize(500, 400));




	// 布局
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
	// 当当前窗口关闭 发出信号重新打开主窗口

	emit view_to_softa();
	event->accept();
}
view_widget::~view_widget()
{}


