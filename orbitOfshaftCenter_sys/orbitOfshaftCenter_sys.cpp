#include "orbitOfshaftCenter_sys.h"
#include <iostream>
#include <QDesktopWidget>
#include <QDockWidget>

orbitOfshaftCenter_sys::orbitOfshaftCenter_sys(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    // �����
    setWindowTitle(QStringLiteral("���Ĺ켣����ʶ�����ؽ�"));

    show_widget = new stack_main();
    setCentralWidget(show_widget); // ����������Ϊ�ָ��
   // resize(QDesktopWidget().availableGeometry(this).size() * 0.7);
    this->setFixedSize(QDesktopWidget().availableGeometry(this).size() * 0.7);
    this->centralWidget()->layout()->setMargin(0);
    
    create_actions();
    create_menus();


    test_lb = new QLabel(this);
    test_lb->setText(QStringLiteral(""));
    test_lb->setGeometry(100, 100, 250, 250);
    //test_lb->setFont(QFont(tr("΢���ź�"), 20));
   // test_lb->setFrameStyle(1);
    test_lb->adjustSize();


    
}

void orbitOfshaftCenter_sys::create_menus()
{    
    // �ļ��˵�
    file_mn = menuBar() -> addMenu(QStringLiteral("�ļ�"));
    file_mn->addAction(newfile_ac); // �½�
    file_mn->addAction(openfile_ac); // ��
    file_mn->addAction(savefile_ac); // ����
    file_mn->addAction(exit_ac); // �˳�

    // ��ͼ�˵�
    view_mn = menuBar()->addMenu(QStringLiteral("��ͼ"));
    view_func = new QMenu(QStringLiteral("���ܹ�����"));
    view_func->addAction(view_func_ac);
    view_func->addAction(view_nonfunc_ac);
    view_func->addAction(dock_view_ac);
    view_mn->addMenu(view_func);

    // ���ڲ˵�
    about_mn = menuBar()->addMenu(QStringLiteral("����"));
    about_mn->addAction(sys_info);


}

void orbitOfshaftCenter_sys::create_actions()
{
    // �ļ��˵�����
    newfile_ac = new QAction(QStringLiteral("�½�"), this);
    newfile_ac->setStatusTip(QStringLiteral("�½�һ���ļ�"));
    connect (newfile_ac, SIGNAL(triggered()), this, SLOT(new_file()));

    openfile_ac = new QAction(QStringLiteral("��"), this);
    openfile_ac->setStatusTip(QStringLiteral("��һ���ļ�"));
    connect(openfile_ac, SIGNAL(triggered()), this, SLOT(open_file()));
    
    savefile_ac = new QAction(QStringLiteral("����"), this);
    savefile_ac->setStatusTip(QStringLiteral("����һ���ļ�"));
    connect(savefile_ac, SIGNAL(triggered()), this, SLOT(save_file()));

    exit_ac = new QAction(QStringLiteral("�˳�"), this);
    connect(exit_ac, SIGNAL(triggered()), this, SLOT(exit()));

    // ѡ��˵�����


    // ��ͼ�˵�����
    view_func_ac = new QAction(QStringLiteral("��"));
    connect(view_func_ac, SIGNAL(triggered()), this, SLOT(show_funcview()));

    view_nonfunc_ac = new QAction(QStringLiteral("����"));
    connect(view_nonfunc_ac, SIGNAL(triggered()), this, SLOT(hide_funcview()));

    dock_view_ac = new QAction(QStringLiteral("����"));
    connect(dock_view_ac, SIGNAL(triggered()), this, SLOT(dock_funcview()));
    // ���ڲ˵�����

    sys_info = new QAction(QStringLiteral("����"), this);
    sys_info->setStatusTip(QStringLiteral("����ϵͳ"));
    connect(sys_info, SIGNAL(triggered()), this, SLOT(show_info()));




    connect(show_widget, SIGNAL(change_mainwindow()), this, SLOT(hide_mainwindow()));
}

void orbitOfshaftCenter_sys::new_file()
{
    test_lb->setText(QStringLiteral("�½�һ���ļ�"));
    test_lb->adjustSize();
}
void orbitOfshaftCenter_sys::open_file()
{
    test_lb->setText(QStringLiteral("��һ���ļ�"));
    test_lb->adjustSize(); 
}

void orbitOfshaftCenter_sys::save_file()
{
    test_lb->setText(QStringLiteral("����һ���ļ�"));
    test_lb->adjustSize();
}

void orbitOfshaftCenter_sys::exit()
{
    switch (QMessageBox:: question(this, QStringLiteral("�˳���ʾ"), 
        QStringLiteral("��ȷ��Ҫ�˳���"), 
        QMessageBox:: Ok |QMessageBox::Cancel,
        QMessageBox:: Ok))
    {
    case QMessageBox:: Ok:
        this->close();
        break;
    case QMessageBox:: Cancel:
        test_lb->setText(QStringLiteral("ȡ���˳�"));
        test_lb->adjustSize();
        break;
    default:
        break;
    }
}

// ��ͼ���ܲۺ���
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


// ���ڹ��ܲۺ���
void orbitOfshaftCenter_sys::show_info()
{
    test_lb->setText(QStringLiteral("ϵͳ��Ϣ"));
    test_lb->adjustSize();
}

// �յ���ʼ���ź� ���ش˴���
void orbitOfshaftCenter_sys::hide_mainwindow()
{
    this->hide();
}


orbitOfshaftCenter_sys::~orbitOfshaftCenter_sys()
{}