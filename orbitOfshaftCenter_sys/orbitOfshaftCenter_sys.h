#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_orbitOfshaftCenter_sys.h"

// ����
#include "stack_main.h"


// 
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
    stack_main* show_widget;
    ~orbitOfshaftCenter_sys();

private:
    Ui::orbitOfshaftCenter_sysClass ui;

    // �˵���ѡ��
    QLabel* test_lb;
    QMenu* file_mn;  // �ļ��˵�
    QMenu* about_mn; // ���ڲ˵�
    QMenu* options_mn; // ѡ��˵�

    QMenu* view_mn; // ��ͼ�˵�
    QMenu* view_func;


    // �ļ��˵�����ѡ��
    QAction* openfile_ac;
    QAction* savefile_ac;
    QAction* newfile_ac;
    QAction* exit_ac;

    // ��ͼ�˵�����ѡ��
    QAction* view_func_ac;
    QAction* view_nonfunc_ac;
    QAction* dock_view_ac;
    // ���ڲ˵�
    QAction* sys_info;

private slots:

    // �ļ��˵���Ŀ�ۺ���
    void new_file();
    void open_file();
    void save_file();
    void exit();
    
    // ��ͼ�˵����ۺ���
    
    // ѡ��˵����ۺ���
    void hide_funcview();
    void show_funcview();
    void dock_funcview();
    // ���ڲ˵���Ŀ�ۺ���

    void show_info();


public slots :
    void hide_mainwindow();
    void show_mainwindow();
};
