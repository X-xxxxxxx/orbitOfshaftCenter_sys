#pragma once

#include <QWidget>
#include "ui_main_split.h"

// 
#include "Content.h"

// 
#include <QSplitter>
#include <QListWidget>

class main_split : public QWidget
{
	Q_OBJECT

public:
	main_split(QWidget *parent = nullptr);

	~main_split();

private:
	Ui::main_splitClass ui;

	QListWidget* list; // ��Ŀ�б�
	QSplitter* splitter_main; // ���ָ��

	Content* content;
};
