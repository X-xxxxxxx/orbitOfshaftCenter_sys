#pragma once

#include <QWidget>
#include "ui_softB.h"

class softB : public QWidget
{
	Q_OBJECT

public:
	softB(QWidget *parent = nullptr);
	~softB();

private:
	Ui::softBClass ui;
};
