#include "view_widget.h"

view_widget::view_widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//方法

	lb_option_hint = new QLabel(QStringLiteral("提纯方法"));
	lb_option_choose = new QLabel;

	// 网络

	lb_net_hint = new QLabel(QStringLiteral("网络选择"));
	lb_net_choose = new QLabel;

	// 间隔时间
	lb_interval_hint = new QLabel(QStringLiteral("间隔时间"));
	lb_interval_choose = new QLabel;

	// 诊断结果
	lb_res_hint = new QLabel(QStringLiteral("诊断结果"));
	lb_res_show = new QLabel;

	// 图片显示
	lb_prmi_hint = new QLabel(QStringLiteral("原始图片"));
	lb_premi = new QLabel;

	lb_solv_hint = new QLabel(QStringLiteral("提纯图片"));
	lb_solv = new QLabel;




	// 布局
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
