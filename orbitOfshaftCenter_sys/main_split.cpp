#include "main_split.h"

main_split::main_split(QWidget *parent)
	: QWidget(parent)
{
	//ui.setupUi();

	splitter_main = new QSplitter(Qt:: Horizontal, 0); // ָ������ָ�
	splitter_main->setOpaqueResize(true);  // ʵʱ��ʾ�ָ���
	splitter_main->setWindowTitle(QStringLiteral("���ָ��"));

	list = new QListWidget(splitter_main); // ָ��������Ϊ�ָ��
	list->insertItem(0, QObject::tr("���Ĺ켣ʶ��")); // ������
	list->insertItem(1, QObject::tr("���Ĺ켣�ؽ�")); // ����
	
	content = new Content(splitter_main);

	//splitter_main->addWidget(list);


}

main_split::~main_split()
{}
