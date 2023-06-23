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

	loading->setFixedSize(this->size());//���ô��ڴ�С
	loading->setAutoFillBackground(true); //�������Ҫ�����򲻻���ʾ���ֲ�
	QPalette pal_mask = loading->palette();
	//QColor color;
	//color.setRgb(0, 255, 255, 255);
	pal_mask.setColor(QPalette::Background, QColor(0x00, 0x00, 0x00, 0x00));
	loading->setPalette(pal_mask);


	//loading->setVisible(false);//��ʼ״̬�����أ�����Ҫ��ʾʱʹ��



	//����
	setWindowTitle(QStringLiteral("���н����ʾ����"));
	lb_option_hint = new QLabel(QStringLiteral("�ᴿ����"));
	lb_option_hint->adjustSize();
	lb_option_hint->setFont(QFont("΢���ź�", 15));

	lb_option_choose = new QLabel;
	lb_option_choose->setFrameShape(QFrame::Box);
	lb_option_choose->setFrameStyle(QFrame::Panel | QFrame::Sunken);

	// ����

	lb_net_hint = new QLabel(QStringLiteral("����ѡ��"));
	lb_net_hint->adjustSize();
	lb_net_hint->setFont(QFont("΢���ź�", 15));

	lb_net_choose = new QLabel;
	lb_net_choose->setFrameShape(QFrame::Box);
	lb_net_choose->setFrameStyle(QFrame::Panel | QFrame::Sunken);

	// ���ʱ��
	lb_interval_hint = new QLabel(QStringLiteral("���ʱ��"));
	lb_interval_hint->adjustSize();
	lb_interval_hint->setFont(QFont("΢���ź�", 15));

	lb_interval_choose = new QLabel;
	lb_interval_choose->setFrameShape(QFrame::Box);
	lb_interval_choose->setFrameStyle(QFrame::Panel | QFrame::Sunken);

	// ��Ͻ��
	lb_res_hint = new QLabel(QStringLiteral("��Ͻ��"));
	lb_res_hint->adjustSize();
	lb_res_hint->setFont(QFont("΢���ź�", 15));

	lb_res_show = new QLabel;
	lb_res_show->setFrameShape(QFrame::Box);
	lb_res_show->setFrameStyle(QFrame::Panel | QFrame::Sunken);

	// ͼƬ��ʾ
	lb_prmi_hint = new QLabel(QStringLiteral("ԭʼͼƬ"));
	lb_prmi_hint->setAlignment(Qt::AlignHCenter);
	lb_prmi_hint->setFont(QFont("΢���ź�", 15));
	lb_prmi_hint->adjustSize();

	lb_prmi = new QLabel;
	lb_prmi->setFrameShape(QFrame::Box);
	lb_prmi->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	lb_prmi->setFixedSize(QSize(550, 440));

	lb_solv_hint = new QLabel(QStringLiteral("�ᴿͼƬ"));
	lb_solv_hint->setAlignment(Qt::AlignHCenter);
	lb_solv_hint->setFont(QFont("΢���ź�", 15));
	lb_solv_hint->adjustSize();

	lb_solv = new QLabel;
	lb_solv->setFrameShape(QFrame::Box);
	lb_solv->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	lb_solv->setFixedSize(QSize(550, 440));




	// ����
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
	// ����ǰ���ڹر� �����ź����´�������

	emit view_to_softa();
	event->accept();
}
view_widget::~view_widget()
{}


