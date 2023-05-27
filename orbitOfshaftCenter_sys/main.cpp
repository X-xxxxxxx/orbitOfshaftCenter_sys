#include "orbitOfshaftCenter_sys.h"
#include <QtWidgets/QApplication>


#include <QDebug>

#include "mydlladd.h"
#include "get_data_demesions.h"
#include "data_resolve.h"
//#include "smoothdata.h"
//#include "ransac.h"

#pragma comment (lib, "libmx.lib")
#pragma comment (lib, "libmat.lib")
#pragma comment (lib, "mclmcr.lib")
#pragma comment (lib, "mclmcrrt.lib")
#pragma comment (lib, "libmex.lib")
#pragma comment (lib, "libeng.lib")

#pragma comment(lib, "mydlladd.lib")
#pragma comment(lib, "get_data_demesions.lib")
#pragma comment(lib, "data_resolve.lib")
//#pragma comment (lib, "ransac.lib")
//#pragma comment(lib, "smoothdata.lib")


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
   //dir.cd("./project");  //����ĳ�ļ���
   //dir.cd("./data");
   if (!dir.exists(QString::fromLocal8Bit("test_dir")))  //�����ļ���
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

    // ����data_resolve����



    // if( && )
        //get_data_demesionsInitialize();
   // smoothdataInitialize();
    //ransacInitialize();

         data_resolveInitialize();

        QString path_data ="C:/Users/X_xx/Desktop/test_dir/1.data/data1.xlsx"; // ·��
        std::string s_data = path_data.toStdString();
        const char* str_data = s_data.c_str();
        mwArray datapath (str_data);
        // �õ�����·��
        QString absolute_path_net = "C:/Users/X_xx/Desktop/test_dir/2.net";
        std::string s_net__ = absolute_path_net.toStdString();
        const char* str_net = s_net__.c_str();
        mwArray net_abs_path(str_net);

        // �õ����·��
        QString relative_path_net = "Net1.mat";
        std::string s_net__rr = relative_path_net.toStdString();
        const char* str_net_rr = s_net__rr.c_str();
        mwArray net_rel_path(str_net_rr);


         //qDebug() << path_data<< endl;
         //qDebug() << QString:: fromLocal8Bit(str) << endl;
         //// �õ���ǰ�ļ�ά��
         //mwArray row(1, 1, mxDOUBLE_CLASS);
         //mwArray col(1, 1, mxDOUBLE_CLASS);
         //qDebug() << str << endl;
        
        //data_resolveTerminate();

        mwArray res(1, 1, mxCHAR_CLASS);


           data_resolve(1, res,datapath, net_abs_path, net_rel_path);

          //get_data_demesions (2, row, col, str);        

          //double r, c;

          //row.GetData(&r, 1);
          //col.GetData(&c, 1);

          //qDebug() << r << "    " << c << endl;
        qDebug() << QStringLiteral("��ʼ���ɹ�") << endl;

         //get_data_demesionsTerminate(); 
        data_resolveTerminate();
        //ransacTerminate();
        //smoothdataTerminate();
         mclTerminateApplication();



         // ·��ת��

         
        // mwArray time(row, 1, mxDOUBLE_CLASS);
        // mwArray x_axis(row, 1, mxDOUBLE_CLASS);
        // mwArray y_axis(row, 1, mxDOUBLE_CLASS);

        ////mwArray t =static_cast<> s;
        // data_resolve(1, time, x_axis, y_axis, datapath);

       // qDebug() << QStringLiteral("��ʼ���ɹ�") << endl;
        

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


       
    

    return a.exec();
}
