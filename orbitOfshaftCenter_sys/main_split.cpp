#include "main_split.h"

main_split::main_split(QWidget *parent)
	: QWidget(parent)
{
	//ui.setupUi();

	splitter_main = new QSplitter(Qt:: Horizontal, 0); // 指定横向分割
	splitter_main->setOpaqueResize(true);  // 实时显示分割条
	splitter_main->setWindowTitle(QStringLiteral("主分割窗口"));

	list = new QListWidget(splitter_main); // 指定父窗口为分割窗口
	list->insertItem(0, QObject::tr("轴心轨迹识别")); // 乔友友
	list->insertItem(1, QObject::tr("轴心轨迹重建")); // 张勇
	
	content = new Content(splitter_main);

	//splitter_main->addWidget(list);


}

main_split::~main_split()
{}
