#include "stack_main.h"

#include <QDesktopWidget>



stack_main::stack_main(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);


	list = new QListWidget();
	list->insertItem(0, QStringLiteral("轴心轨迹故障识别")); // 乔
	list->insertItem(1, QStringLiteral("轴心故障重建")); // 张

	lb1 = new QLabel(QStringLiteral("TEST1"));
	lb2 = new QLabel(QStringLiteral("TEST2"));
	stack = new QStackedWidget();

	// 于此堆栈窗口内分别加入功能软件
	A = new softA();
	//A->setFixedSize(QSize(1000, 1000));
	stack->addWidget(A); // 乔师哥
	B = new MainWindow();
	stack->addWidget(B); // 张师哥



	//bt1 = new QPushButton("push", stack);	
	//
	//connect(bt1, SIGNAL(clicked()), this, SLOT(test()));



	QObject::connect(list, SIGNAL(currentRowChanged(int)), stack, SLOT(setCurrentIndex(int)));
	
	dw1 = new QDockWidget(QStringLiteral("功能管理器"));//构建停靠窗口，指定父类

	dw1->setFeatures(QDockWidget::DockWidgetMovable | 
		QDockWidget:: DockWidgetFloatable | 
		QDockWidget:: DockWidgetClosable);//设置停靠窗口特性，可移动，可关闭
	//dw1->setFloating(false);
	dw1->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);//设置可停靠区域为主窗口左边和右边
	
	dw1->setWidget(list);
	//addDockWidget(Qt::RightDockWidgetArea, dw1);
	// 布局	

	main_layout = new QHBoxLayout(this);
	//main_layout->addWidget(dw1);
	main_layout->addWidget(stack);
	main_layout->setStretch(1, 4);


	// 子窗口到当前窗口发送信号使得主窗口关闭
	connect(A, SIGNAL(mainwindow_hide()), this, SLOT(this_to_main_hide()));
	connect(A, SIGNAL(mainwindow_show()), this, SLOT(this_to_main_show()));
}
void stack_main:: this_to_main_hide()
{
	//if (this->dw1->isFloating())
	//	this->dw1->setFloating(false);
	//else
	//	this->dw1->setFloating(true);
	emit hide_mainwindow();
}
stack_main::~stack_main()
{}

void stack_main::this_to_main_show()
{
	emit show_mainwindow();
}
