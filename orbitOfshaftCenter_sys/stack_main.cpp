#include "stack_main.h"

#include <QDesktopWidget>



stack_main::stack_main(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);


	list = new QListWidget();
	list->insertItem(0, QStringLiteral("���Ĺ켣����ʶ��")); // ��
	list->insertItem(1, QStringLiteral("���Ĺ����ؽ�")); // ��

	lb1 = new QLabel(QStringLiteral("TEST1"));
	lb2 = new QLabel(QStringLiteral("TEST2"));
	stack = new QStackedWidget();

	// �ڴ˶�ջ�����ڷֱ���빦�����
	A = new softA();
	//A->setFixedSize(QSize(1000, 1000));
	stack->addWidget(A); // ��ʦ��
	B = new MainWindow();
	stack->addWidget(B); // ��ʦ��



	//bt1 = new QPushButton("push", stack);	
	//
	//connect(bt1, SIGNAL(clicked()), this, SLOT(test()));



	QObject::connect(list, SIGNAL(currentRowChanged(int)), stack, SLOT(setCurrentIndex(int)));
	
	dw1 = new QDockWidget(QStringLiteral("���ܹ�����"));//����ͣ�����ڣ�ָ������

	dw1->setFeatures(QDockWidget::DockWidgetMovable | 
		QDockWidget:: DockWidgetFloatable | 
		QDockWidget:: DockWidgetClosable);//����ͣ���������ԣ����ƶ����ɹر�
	//dw1->setFloating(false);
	dw1->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);//���ÿ�ͣ������Ϊ��������ߺ��ұ�
	
	dw1->setWidget(list);
	//addDockWidget(Qt::RightDockWidgetArea, dw1);
	// ����	

	main_layout = new QHBoxLayout(this);
	//main_layout->addWidget(dw1);
	main_layout->addWidget(stack);
	main_layout->setStretch(1, 4);


	// �Ӵ��ڵ���ǰ���ڷ����ź�ʹ�������ڹر�
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
