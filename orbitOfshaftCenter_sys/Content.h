#pragma once

#include <QWidget>
#include "ui_content.h"

class Content : public QWidget
{
	Q_OBJECT

public:
	Content(QWidget *parent = nullptr);
	~Content();

private:
	Ui::contentClass ui;


};
