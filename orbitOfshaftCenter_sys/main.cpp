#include "orbitOfshaftCenter_sys.h"
#include <QtWidgets/QApplication>


#include <QDebug>

#include "view_widget.h"


//#pragma comment (lib, "ransac.lib")
//#pragma comment(lib, "smoothdata.lib")


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);    

    orbitOfshaftCenter_sys w;
   w.show();


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
       dir.mkdir(QString::fromLocal8Bit("2.net"));
	   dir.mkdir(QString::fromLocal8Bit("3.data_save"));
	   dir.mkdir(QString::fromLocal8Bit("4.res_save"));
   }

    qDebug() << "lalallaallalalalala" << endl;
    qDebug() << s << endl;

    // 数据data_resolve引入



    // if( && )
        //get_data_demesionsInitialize();
   // smoothdataInitialize();
    //ransacInitialize();


    /*
    
         data_resolveInitialize();

        QString path_data ="C:/Users/X_xx/Desktop/test_dir/1.data/data1.xlsx"; // 路径
        std::string s_data = path_data.toStdString();
        const char* str_data = s_data.c_str();
        mwArray datapath (str_data);
        // 拿到绝对路径
        QString absolute_path_net = "C:/Users/X_xx/Desktop/test_dir/2.net";
        std::string s_net__ = absolute_path_net.toStdString();
        const char* str_net = s_net__.c_str();
        mwArray net_abs_path(str_net);

        // 拿到相对路径
        QString relative_path_net = "Net1.mat";
        std::string s_net__rr = relative_path_net.toStdString();
        const char* str_net_rr = s_net__rr.c_str();
        mwArray net_rel_path(str_net_rr);




        //char res_[] = "";
        //char res_[] = " ";
        mwArray res(mxCHAR_CLASS);
        //mwArray t(1, 1, mxDOUBLE_CLASS);
        //double x = 0;
        //t.SetData(&x, 1);
        //printf("%s\n", (const char*)(t.ToString()));

           data_resolve(1, res,datapath, net_abs_path, net_rel_path);

           printf("%s\n", (const char*)(res.ToString()));
           //char* res_;
           ////std::string res_;
           //res.GetCharData(res_);

          //get_data_demesions (2, row, col, str);        

          //double r, c;

          //row.GetData(&r, 1);
          //col.GetData(&c, 1);

          //qDebug() << r << "    " << c << endl;
        qDebug() << QStringLiteral("测试成功") << endl;

         //get_data_demesionsTerminate(); 
        data_resolveTerminate();
        //ransacTerminate();
        //smoothdataTerminate();
         mclTerminateApplication();



         // 路径转化

         
        // mwArray time(row, 1, mxDOUBLE_CLASS);
        // mwArray x_axis(row, 1, mxDOUBLE_CLASS);
        // mwArray y_axis(row, 1, mxDOUBLE_CLASS);

        ////mwArray t =static_cast<> s;
        // data_resolve(1, time, x_axis, y_axis, datapath);

       // qDebug() << QStringLiteral("初始化成功") << endl;
        

    //if (mydlladdInitialize())
    //{
    //    mwArray a(1, 1, mxDOUBLE_CLASS);
    //    //double *a_c = new double(110);
    //    double a_c[1] = { 100 };
    //    a.SetData(a_c, 1);
    //    mwArray b(1, 1, mxDOUBLE_CLASS);
    //  //  double* b_c = new double (50);
    //    double e = 50;
    //   // double &b_c = e;
    //    b.SetData(&e, 1);
    //    mwArray c(1, 1, mxDOUBLE_CLASS);
    //    mwArray d(1, 1, mxDOUBLE_CLASS);

    //    eval_test(2, c, d, a, b);
    //    double x[1]; c.GetData(x, 1);
    //    qDebug() <<x[0] << endl;
    //    mydlladdTerminate();
    //     
    //
    //}

//mclTerminateApplication();


       
    





    */
    return a.exec();
}
