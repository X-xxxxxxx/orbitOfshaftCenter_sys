#include "view_widget.h"

view_widget::view_widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//QPalette pal = this->palette();
	//pal.setBrush(QPalette::Background, QBrush(QPixmap(":/orbitOfshaftCenter_sys/background.png")));
	//setPalette(pal);
	setWindowIcon(QIcon(":/orbitOfshaftCenter_sys/view.png"));
	this->setFixedSize(QDesktopWidget().availableGeometry(this).size() * 0.7);

	loading = new LoadingFrom(this);

	loading->setFixedSize(this->size());//设置窗口大小
	loading->setAutoFillBackground(true); //这个很重要，否则不会显示遮罩层
	QPalette pal_mask = loading->palette();
	//QColor color;
	//color.setRgb(0, 255, 255, 255);
	pal_mask.setColor(QPalette::Background, QColor(0x00, 0x00, 0x00, 0x00));
	loading->setPalette(pal_mask);


	//loading->setVisible(false);//初始状态下隐藏，待需要显示时使用



	//方法
	setWindowTitle(QStringLiteral("运行结果显示窗口"));
	lb_option_hint = new QLabel(QStringLiteral("提纯方法"));
	lb_option_hint->adjustSize();
	lb_option_hint->setFont(QFont("微软雅黑", 15));

	lb_option_choose = new QLabel;
	lb_option_choose->setFrameShape(QFrame::Box);
	lb_option_choose->setFrameStyle(QFrame::Panel | QFrame::Sunken);

	// 网络

	lb_net_hint = new QLabel(QStringLiteral("网络选择"));
	lb_net_hint->adjustSize();
	lb_net_hint->setFont(QFont("微软雅黑", 15));

	lb_net_choose = new QLabel;
	lb_net_choose->setFrameShape(QFrame::Box);
	lb_net_choose->setFrameStyle(QFrame::Panel | QFrame::Sunken);

	// 间隔时间
	lb_interval_hint = new QLabel(QStringLiteral("间隔时间"));
	lb_interval_hint->adjustSize();
	lb_interval_hint->setFont(QFont("微软雅黑", 15));

	lb_interval_choose = new QLabel;
	lb_interval_choose->setFrameShape(QFrame::Box);
	lb_interval_choose->setFrameStyle(QFrame::Panel | QFrame::Sunken);

	// 诊断结果
	lb_res_hint = new QLabel(QStringLiteral("诊断结果"));
	lb_res_hint->adjustSize();
	lb_res_hint->setFont(QFont("微软雅黑", 15));

	lb_res_show = new QLabel;
	lb_res_show->setFrameShape(QFrame::Box);
	lb_res_show->setFrameStyle(QFrame::Panel | QFrame::Sunken);

	// 图片显示
	lb_prmi_hint = new QLabel(QStringLiteral("原始图片"));
	lb_prmi_hint->setAlignment(Qt::AlignHCenter);
	lb_prmi_hint->setFont(QFont("微软雅黑", 15));
	lb_prmi_hint->adjustSize();

	lb_prmi = new QLabel;
	lb_prmi->setFrameShape(QFrame::Box);
	lb_prmi->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	lb_prmi->setFixedSize(QSize(550, 440));

	lb_solv_hint = new QLabel(QStringLiteral("提纯图片"));
	lb_solv_hint->setAlignment(Qt::AlignHCenter);
	lb_solv_hint->setFont(QFont("微软雅黑", 15));
	lb_solv_hint->adjustSize();

	lb_solv = new QLabel;
	lb_solv->setFrameShape(QFrame::Box);
	lb_solv->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	lb_solv->setFixedSize(QSize(550, 440));




	// 布局
	main_layout = new QHBoxLayout(this);
    left_layout = new QVBoxLayout;
	left_layout->setAlignment(Qt::AlignHCenter);
	//left_layout->setMargin(10);
	left_layout->setContentsMargins(20, 50, 50, 30);
	right_layout = new QGridLayout;
	right_layout->setAlignment(Qt::AlignVCenter);
	//right_layout->setHorizontalSpacing(1);
	right_layout->setVerticalSpacing(250);
	//right_layout->setMargin(100);
	main_layout->addLayout(left_layout);
	main_layout->addLayout(right_layout);
	right_layout->setContentsMargins(100, 50, 250, 30);
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


