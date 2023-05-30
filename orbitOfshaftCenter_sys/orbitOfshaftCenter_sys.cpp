#include "orbitOfshaftCenter_sys.h"
#include <iostream>
#include <QDesktopWidget>
#include <QDockWidget>

orbitOfshaftCenter_sys::orbitOfshaftCenter_sys(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    // 主框架
    setWindowTitle(QStringLiteral("轴心轨迹故障识别与重建"));

    show_widget = new stack_main();
    setCentralWidget(show_widget); // 设置主窗口为分割窗口
   // resize(QDesktopWidget().availableGeometry(this).size() * 0.7);
    this->setFixedSize(QDesktopWidget().availableGeometry(this).size() * 0.7);
    this->centralWidget()->layout()->setMargin(0);
    
    create_actions();
    create_menus();


    test_lb = new QLabel(this);
    test_lb->setText(QStringLiteral(""));
    test_lb->setGeometry(100, 100, 250, 250);
    //test_lb->setFont(QFont(tr("微软雅黑"), 20));
   // test_lb->setFrameStyle(1);
    test_lb->adjustSize();


    
}

void orbitOfshaftCenter_sys::create_menus()
{    
    // 文件菜单
    file_mn = menuBar() -> addMenu(QStringLiteral("文件"));
    file_mn->addAction(newfile_ac); // 新建
    file_mn->addAction(openfile_ac); // 打开
    file_mn->addAction(savefile_ac); // 保存
    file_mn->addAction(exit_ac); // 退出

    // 视图菜单
    view_mn = menuBar()->addMenu(QStringLiteral("视图"));
    view_func = new QMenu(QStringLiteral("功能管理器"));
    view_func->addAction(view_func_ac);
    view_func->addAction(view_nonfunc_ac);
    view_func->addAction(dock_view_ac);
    view_mn->addMenu(view_func);

    // 关于菜单
    about_mn = menuBar()->addMenu(QStringLiteral("关于"));
    about_mn->addAction(sys_info);


}

void orbitOfshaftCenter_sys::create_actions()
{
    // 文件菜单动作
    newfile_ac = new QAction(QStringLiteral("新建"), this);
    newfile_ac->setStatusTip(QStringLiteral("新建一个文件"));
    connect (newfile_ac, SIGNAL(triggered()), this, SLOT(new_file()));

    openfile_ac = new QAction(QStringLiteral("打开"), this);
    openfile_ac->setStatusTip(QStringLiteral("打开一个文件"));
    connect(openfile_ac, SIGNAL(triggered()), this, SLOT(open_file()));
    
    savefile_ac = new QAction(QStringLiteral("保存"), this);
    savefile_ac->setStatusTip(QStringLiteral("保存一个文件"));
    connect(savefile_ac, SIGNAL(triggered()), this, SLOT(save_file()));

    exit_ac = new QAction(QStringLiteral("退出"), this);
    connect(exit_ac, SIGNAL(triggered()), this, SLOT(exit()));

    // 选项菜单动作


    // 视图菜单动作
    view_func_ac = new QAction(QStringLiteral("打开"));
    connect(view_func_ac, SIGNAL(triggered()), this, SLOT(show_funcview()));

    view_nonfunc_ac = new QAction(QStringLiteral("隐藏"));
    connect(view_nonfunc_ac, SIGNAL(triggered()), this, SLOT(hide_funcview()));

    dock_view_ac = new QAction(QStringLiteral("浮动"));
    connect(dock_view_ac, SIGNAL(triggered()), this, SLOT(dock_funcview()));
    // 关于菜单动作

    sys_info = new QAction(QStringLiteral("关于"), this);
    sys_info->setStatusTip(QStringLiteral("关于系统"));
    connect(sys_info, SIGNAL(triggered()), this, SLOT(show_info()));




    connect(show_widget, SIGNAL(change_mainwindow()), this, SLOT(hide_mainwindow()));
}

void orbitOfshaftCenter_sys::new_file()
{
    test_lb->setText(QStringLiteral("新建一个文件"));
    test_lb->adjustSize();
}
void orbitOfshaftCenter_sys::open_file()
{
    test_lb->setText(QStringLiteral("打开一个文件"));
    test_lb->adjustSize(); 
}

void orbitOfshaftCenter_sys::save_file()
{
    test_lb->setText(QStringLiteral("保存一个文件"));
    test_lb->adjustSize();
}

void orbitOfshaftCenter_sys::exit()
{
    switch (QMessageBox:: question(this, QStringLiteral("退出提示"), 
        QStringLiteral("你确定要退出吗？"), 
        QMessageBox:: Ok |QMessageBox::Cancel,
        QMessageBox:: Ok))
    {
    case QMessageBox:: Ok:
        this->close();
        break;
    case QMessageBox:: Cancel:
        test_lb->setText(QStringLiteral("取消退出"));
        test_lb->adjustSize();
        break;
    default:
        break;
    }
}

// 视图功能槽函数
void orbitOfshaftCenter_sys::hide_funcview()
{
    if (this->show_widget->dw1->isVisible())
        this->show_widget->dw1->hide();
}

void orbitOfshaftCenter_sys::show_funcview()
{
    if (this -> show_widget -> dw1 -> isHidden()) 
        this->show_widget->dw1->show();
}

void orbitOfshaftCenter_sys::dock_funcview()
{
    if (this->show_widget->dw1->isFloating())
    {
        delete show_widget;
        show_widget = new stack_main();
        setCentralWidget(show_widget);
        //this->show_widget->dw1->setFloating(false);
    }  
    else
    {
        this->show_widget->dw1->setFloating(true);
    }
}


// 关于功能槽函数
void orbitOfshaftCenter_sys::show_info()
{
    test_lb->setText(QStringLiteral("系统信息"));
    test_lb->adjustSize();
}

// 收到开始的信号 隐藏此窗口
void orbitOfshaftCenter_sys::hide_mainwindow()
{
    this->hide();
}


orbitOfshaftCenter_sys::~orbitOfshaftCenter_sys()
{}