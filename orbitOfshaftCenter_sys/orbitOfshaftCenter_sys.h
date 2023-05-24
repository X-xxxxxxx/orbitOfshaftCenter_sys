#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_orbitOfshaftCenter_sys.h"
#include <QMenu> // �˵���
#include <QAction>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLayout>
#include <QMessageBox>

class orbitOfshaftCenter_sys : public QMainWindow
{
    Q_OBJECT

public:
    orbitOfshaftCenter_sys(QWidget *parent = nullptr);

    // �����˵�
    void create_menus();
    void create_actions();

    ~orbitOfshaftCenter_sys();

private:
    Ui::orbitOfshaftCenter_sysClass ui;

    // �˵���ѡ��
    QLabel* test_lb;
    QMenu* file_mn;  // �ļ��˵�
    QMenu* about_mn; // ���ڲ˵�


    // �ļ��˵�����ѡ��
    QAction* openfile_ac;
    QAction* savefile_ac;
    QAction* newfile_ac;
    QAction* exit_ac;


    // ���ڲ˵�
    QAction* sys_info;

private slots:

    // �ļ��˵���Ŀ�ۺ���
    void new_file();
    void open_file();
    void save_file();
    void exit();
    
    // ���ڲ˵���Ŀ�ۺ���

    void show_info();
};
