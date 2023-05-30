#pragma once

#include <QWidget>



#include "ui_stack_main.h"

//
#include "softA.h"


//
#include <QLabel>
#include <QListWidget>
#include <QStackedWidget>
#include <QDockWidget>
#include <QPushButton>

//
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>


class stack_main : public QWidget
{
	Q_OBJECT

public:
	stack_main(QWidget *parent = nullptr);
	~stack_main();

	QDockWidget* dw1;	
	QLabel* lb1;
	QLabel* lb2;

	QListWidget* list;
	QStackedWidget* stack;

	QHBoxLayout* main_layout;


	QPushButton* bt1;


	softA* A;

private:
	Ui::stack_mainClass ui;
signals:
	void change_mainwindow();

public slots:
	void this_to_main();
};
