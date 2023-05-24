#include "orbitOfshaftCenter_sys.h"
#include <iostream>

orbitOfshaftCenter_sys::orbitOfshaftCenter_sys(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    // 主框架
    setWindowTitle(QStringLiteral("轴心轨迹故障识别与重建"));
    main_split* showwidget = new main_split(this);
    setCentralWidget(showwidget); // 设置主窗口为分割窗口
    //showwidget->show();
    create_actions();
    create_menus();


    test_lb = new QLabel(showwidget);
    test_lb->setText(QStringLiteral("text"));
    test_lb->setGeometry(100, 100, 250, 250);
    //test_lb->setFont(QFont(tr("微软雅黑"), 20));
   // test_lb->setFrameStyle(1);
    test_lb->adjustSize();
}

void orbitOfshaftCenter_sys::create_menus()
{    
    file_mn = menuBar() -> addMenu(QStringLiteral("文件"));
    file_mn->addAction(newfile_ac); // 新建
    file_mn->addAction(openfile_ac); // 打开
    file_mn->addAction(savefile_ac); // 保存
    file_mn->addAction(exit_ac); // 退出


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



    // 关于菜单动作

    sys_info = new QAction(QStringLiteral("关于"), this);
    sys_info->setStatusTip(QStringLiteral("关于系统"));
    connect(sys_info, SIGNAL(triggered()), this, SLOT(show_info()));
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

void orbitOfshaftCenter_sys::show_info()
{
    test_lb->setText(QStringLiteral("系统信息"));
    test_lb->adjustSize();
}


orbitOfshaftCenter_sys::~orbitOfshaftCenter_sys()
{}