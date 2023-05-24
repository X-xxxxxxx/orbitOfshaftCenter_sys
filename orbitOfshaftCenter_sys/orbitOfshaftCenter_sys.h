#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_orbitOfshaftCenter_sys.h"
#include <QMenu> // 菜单类
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

    // 创建菜单
    void create_menus();
    void create_actions();

    ~orbitOfshaftCenter_sys();

private:
    Ui::orbitOfshaftCenter_sysClass ui;

    // 菜单栏选项
    QLabel* test_lb;
    QMenu* file_mn;  // 文件菜单
    QMenu* about_mn; // 关于菜单


    // 文件菜单动作选项
    QAction* openfile_ac;
    QAction* savefile_ac;
    QAction* newfile_ac;
    QAction* exit_ac;


    // 关于菜单
    QAction* sys_info;

private slots:

    // 文件菜单栏目槽函数
    void new_file();
    void open_file();
    void save_file();
    void exit();
    
    // 关于菜单栏目槽函数

    void show_info();
};
