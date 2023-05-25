#pragma once

#include <QWidget>



#include "ui_stack_main.h"



#include <QLabel>
#include <QListWidget>
#include <QStackedWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDockWidget>
#include <QPushButton>


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

private:
	Ui::stack_mainClass ui;

private slots:
	void test();
};
