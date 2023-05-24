#include "orbitOfshaftCenter_sys.h"
#include <iostream>

orbitOfshaftCenter_sys::orbitOfshaftCenter_sys(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    // �����
    setWindowTitle(QStringLiteral("���Ĺ켣����ʶ�����ؽ�"));
    main_split* showwidget = new main_split(this);
    setCentralWidget(showwidget); // ����������Ϊ�ָ��
    //showwidget->show();
    create_actions();
    create_menus();


    test_lb = new QLabel(showwidget);
    test_lb->setText(QStringLiteral("text"));
    test_lb->setGeometry(100, 100, 250, 250);
    //test_lb->setFont(QFont(tr("΢���ź�"), 20));
   // test_lb->setFrameStyle(1);
    test_lb->adjustSize();
}

void orbitOfshaftCenter_sys::create_menus()
{    
    file_mn = menuBar() -> addMenu(QStringLiteral("�ļ�"));
    file_mn->addAction(newfile_ac); // �½�
    file_mn->addAction(openfile_ac); // ��
    file_mn->addAction(savefile_ac); // ����
    file_mn->addAction(exit_ac); // �˳�


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



    // ���ڲ˵�����

    sys_info = new QAction(QStringLiteral("����"), this);
    sys_info->setStatusTip(QStringLiteral("����ϵͳ"));
    connect(sys_info, SIGNAL(triggered()), this, SLOT(show_info()));
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

void orbitOfshaftCenter_sys::show_info()
{
    test_lb->setText(QStringLiteral("ϵͳ��Ϣ"));
    test_lb->adjustSize();
}


orbitOfshaftCenter_sys::~orbitOfshaftCenter_sys()
{}