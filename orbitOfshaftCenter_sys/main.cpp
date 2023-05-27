#include "orbitOfshaftCenter_sys.h"
#include <QtWidgets/QApplication>


#include <QDebug>

#include "mydlladd.h"

#pragma comment (lib, "libmx.lib")
#pragma comment (lib, "libmat.lib")
#pragma comment (lib, "mclmcr.lib")
#pragma comment (lib, "mclmcrrt.lib")
#pragma comment (lib, "libmex.lib")
#pragma comment (lib, "libeng.lib")

#pragma comment(lib, "mydlladd.lib")




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
   if (!dir.exists(QString::fromLocal8Bit("test_dir")))  //创建文件夹
   {
       dir.mkdir(QString::fromLocal8Bit("test_dir"));
       dir.cd(QString::fromLocal8Bit("test_dir"));
	   dir.mkdir(QString::fromLocal8Bit("1.data"));
	   dir.mkdir(QString::fromLocal8Bit("2.data_save"));
	   dir.mkdir(QString::fromLocal8Bit("3.res_save"));
   }

    qDebug() << "lalallaallalalalala" << endl;
    qDebug() << s << endl;

    // 数据data_resolve引入



    // if( && )
        //get_data_demesionsInitialize();
        // //data_resolveInitialize();

        //QString path ="C:/Users/X_xx/Desktop/test_dir/1.data"; // 路径
        //std::string s_temp = path.toStdString();
        //const char* str = s_temp.c_str();
        // qDebug() << path<< endl;
        // qDebug() << QString:: fromLocal8Bit(str) << endl;
        // // 得到当前文件维度
        // mwArray row(1, 1, mxDOUBLE_CLASS);
        // mwArray col(1, 1, mxDOUBLE_CLASS);
        // qDebug() << str << endl;
        //
        ////data_resolveTerminate();


        //   mwArray datapath (str);
        //  //get_data_demesions (2, row, col, str);        


        //qDebug() << QStringLiteral("初始化成功") << endl;

        // get_data_demesionsTerminate(); 

        // mclTerminateApplication();



         // 路径转化

         
        // mwArray time(row, 1, mxDOUBLE_CLASS);
        // mwArray x_axis(row, 1, mxDOUBLE_CLASS);
        // mwArray y_axis(row, 1, mxDOUBLE_CLASS);

        ////mwArray t =static_cast<> s;
        // data_resolve(1, time, x_axis, y_axis, datapath);

       // qDebug() << QStringLiteral("初始化成功") << endl;
        

    if (mydlladdInitialize())
    {
        mwArray a(1, 1, mxDOUBLE_CLASS);
        //double *a_c = new double(110);
        double a_c[1] = { 100 };
        a.SetData(a_c, 1);
        mwArray b(1, 1, mxDOUBLE_CLASS);
      //  double* b_c = new double (50);
        double e = 50;
       // double &b_c = e;
        b.SetData(&e, 1);
        mwArray c(1, 1, mxDOUBLE_CLASS);
        mwArray d(1, 1, mxDOUBLE_CLASS);

        eval_test(2, c, d, a, b);
        double x[1]; c.GetData(x, 1);
        qDebug() <<x[0] << endl;
        mydlladdTerminate();
         mclTerminateApplication();
    
    }




       
    

    return a.exec();
}
