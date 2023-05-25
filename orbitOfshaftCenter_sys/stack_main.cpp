#include "stack_main.h"


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
	stack->addWidget(lb1);
	stack->addWidget(lb2);
	bt1 = new QPushButton("push", stack);	
	
	connect(bt1, SIGNAL(clicked()), this, SLOT(test()));



	QObject::connect(list, SIGNAL(currentRowChanged(int)), stack, SLOT(setCurrentIndex(int)));
	
	dw1 = new QDockWidget(QStringLiteral("功能管理器"));//构建停靠窗口，指定父类

	dw1->setFeatures(QDockWidget::DockWidgetMovable | 
		QDockWidget:: DockWidgetFloatable | 
		QDockWidget:: DockWidgetClosable);//设置停靠窗口特性，可移动，可关闭
	dw1->setFloating(false);
	dw1->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);//设置可停靠区域为主窗口左边和右边
	
	dw1->setWidget(list);
	//addDockWidget(Qt::RightDockWidgetArea, dw1);
	// 布局	

	main_layout = new QHBoxLayout(this);
	main_layout->addWidget(dw1);
	main_layout->addWidget(stack);
	main_layout->setStretch(1, 4);


}
void stack_main::test()
{
	if (this->dw1->isFloating())
		this->dw1->setFloating(false);
	else
		this->dw1->setFloating(true);
}
stack_main::~stack_main()
{}
