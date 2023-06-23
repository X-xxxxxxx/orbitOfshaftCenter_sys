#include "LoadingFrom.h"

LoadingFrom::LoadingFrom(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	show_proc = new QLabel;
	layout = new QHBoxLayout(this);
	layout->addWidget(show_proc);
	layout->setAlignment(Qt::AlignCenter);

	QMovie* movie;
	movie = new QMovie(":/orbitOfshaftCenter_sys/loading.gif");
	show_proc->setMovie(movie);
	movie->start();





	//int appWindowWidth = this ->show_proc->geometry().width();
	//int appWindowHeight = this->show_proc ->geometry().height();

	//int center_y = QDesktopWidget().availableGeometry(this).height() * 0.7 / 2 - appWindowHeight / 2;
	//int center_x = QDesktopWidget().availableGeometry(this).width() *0.7 / 2 - appWindowWidth / 2;
	////此处的Width,Height不要被修改了(例如除以2了)
 //  //不然看起来不是居中的
	//setGeometry(center_x, center_y,
	//	appWindowWidth, appWindowHeight);
}

LoadingFrom::~LoadingFrom()
{}
