#include "orbitOfshaftCenter_sys.h"
#include <QtWidgets/QApplication>


#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    orbitOfshaftCenter_sys w;
   w.show();
    //
    //stack_main* test = new stack_main();
    //test->show();

   QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);


  QString s = desktop_path;
   //QDesktopServices::openUrl(QUrl(desktop_path));
   QDir dir(desktop_path);
   //dir.cd("./project");  //进入某文件夹
   //dir.cd("./data");
   if (!dir.exists(QString::fromLocal8Bit("test_dir")))  //创建二级子文件夹
   {
       dir.mkdir(QString::fromLocal8Bit("test_dir"));
       dir.cd(QString::fromLocal8Bit("test_dir"));
	   dir.mkdir(QString::fromLocal8Bit("1.data"));
	   dir.mkdir(QString::fromLocal8Bit("2.data_save"));
	   dir.mkdir(QString::fromLocal8Bit("3.res_save"));
   }

   qDebug() << "lalallaallalalalala" << endl;
    qDebug() << s << endl;
    return a.exec();
}
