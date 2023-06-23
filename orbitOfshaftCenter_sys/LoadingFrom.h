#pragma once

#include <QWidget>
#include "ui_LoadingFrom.h"


#include <QLabel>
#include <QMovie>
//
#include <QDesktopWidget>

//
#include <QHBoxLayout>

class LoadingFrom : public QWidget
{
	Q_OBJECT

public:
	LoadingFrom(QWidget* parent = nullptr);
	~LoadingFrom();

	QLabel* show_proc;
	QHBoxLayout* layout;
private:
	Ui::LoadingFromClass ui;
};
