#include "workerThread.h"
#include <qDebug>
#include <QTime>

workerThread::workerThread(QFileInfoList& file_list, QFileInfo& fileinfo_model, int option_index, int interval)
{
	this->file_list = file_list;
    this->fileinfo_model = fileinfo_model;
    this->option_index = option_index;
	this->interval = interval;
	qDebug() << QStringLiteral("子线程初始化成功") << endl;
}

void workerThread::run()
{
	//QString result = file_list.at(0).fileName();
	//QString result;


	qDebug() << QStringLiteral("子线程开始工作") << endl;
	qDebug() << QStringLiteral("当前子线程ID：") << "-----" << QThread::currentThreadId();


	//qDebug() << fileinfo_model.fileName()<< endl;
	//qDebug() << option_index << endl;
	//QString result = "hello gui thread";








	// block run


	if (data_resolveInitialize())
	{
		qDebug() << " init success" << endl;
		for (int i = 0; i < file_list.count(); i++)
			/*for (int i = 1; i < 2; i++)*/
		{
			//result = file_list.at(i).fileName();
			// 获取当前数据文件路径参数
			QString data_path = file_list.at(i).path() + "/" + file_list.at(i).fileName();
			std::string datapathqstr_str = data_path.toStdString();
			const char* datapathstr_to_mw = datapathqstr_str.c_str();
			qDebug() << QStringLiteral("数据文件路径") << datapathstr_to_mw << endl;
			mwArray pathstr(datapathstr_to_mw);

			// 获取日期参数
			QDateTime date_time = QDateTime::currentDateTime();//获取系统当前的时间
			QString qstr = date_time.toString("yyyy-MM-dd_hh-mm-ss");//格式化时间
			std::string dateqstr_str = qstr.toStdString();
			const char* datestr_to_mw = dateqstr_str.c_str();

			qDebug() << datestr_to_mw << endl;
			//qDebug() << qstr << endl;
			//
			//std::cout << dateqstr_str << endl;

			//mwArray timestr("2221111111"); // time str 参数
			mwArray timestr(datestr_to_mw); // time str 参数
			// 获取方法选择索引
					//box_options->currentIndex();
			mwArray option_index(option_index, mxDOUBLE_CLASS);

			// 获取model 参数  其中包括 绝对路径 和 文件名字

			// 模型绝对路径
			QString s = fileinfo_model.path(); // 模型的绝对路径
			qDebug() << QStringLiteral("模型绝对路径 QString") << s << endl;
			std::string modelpath = s.toStdString();

			const char* modelpath_to_mw = modelpath.c_str();
			qDebug() << QStringLiteral("转化后模型绝对路径") << modelpath_to_mw << endl;
			mwArray absolutepath_Net(modelpath_to_mw);
			// 模型名字
			std::string modelname = fileinfo_model.fileName().toStdString();; // 模型名字
			//qDebug() 



			// 
			// 
			//qDebug() << modelpath << endl;
			const char* modelname_to_mw = modelname.c_str();
			qDebug() << QStringLiteral("供matlab 使用的 模型名字") << modelname_to_mw << endl;
			mwArray NetName(modelname_to_mw);


			// 调用dll 进行处理
			//得到结果



			// 保存结果的路径
			QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
			QString resimgpath = desktop_path + "/" + QStringLiteral("轴心轨迹提纯与故障识别系统") + "/" + "4.result";

			std::string res_imgpath = resimgpath.toStdString();

			const char* res_imgpath_to_mw = res_imgpath.c_str();
			qDebug() << QStringLiteral("转化后模型绝对路径") << modelpath_to_mw << endl;
			mwArray absolutepath_img(res_imgpath_to_mw);



			mwArray res(mxCHAR_CLASS);
			data_resolve(1, res, pathstr, absolutepath_img, absolutepath_Net, NetName, timestr, option_index);

			printf("%s\n", (const char*)(res.ToString()));
			

			//std::string temp = (const char*)res.ToString();
			//qDebug() << temp << endl;
			//printf("%s\n", temp);
			const char* result = (const char*)(res.ToString());
			//将识别完成的数据剪切到 其他文件夹

			qDebug() << result << endl;
			
			//if(QFile::copy(data_path, "C:/Users/X_xx/Desktop/test_dir/3.data_save/"  +  file_list.at(i).fileName()) 
			//	&&QFile::remove(data_path))
			//QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
			QString ss = desktop_path + "/" + QStringLiteral("轴心轨迹提纯与故障识别系统") + "/" + "3.data_save/";

			if (QFile::rename(data_path, ss + file_list.at(i).fileName()))
				qDebug() << QStringLiteral("识别后文件转移成功") << endl;


			qDebug() << QStringLiteral("结果传输准备") << endl;


			qDebug() << QStringLiteral("向ui线程发送信号") << endl;			

			QString resImg_path = desktop_path + "/" + QStringLiteral("轴心轨迹提纯与故障识别系统") + "/" + "4.result/" + QStringLiteral("提纯图片_") + qstr + ".jpg";
			QString prmiImg_path = desktop_path + "/" + QStringLiteral("轴心轨迹提纯与故障识别系统") + "/" + "4.result/" + QStringLiteral("原始图片_") + qstr + ".jpg";
			emit resultReady(result, resImg_path, prmiImg_path);

			QThread::msleep(this->interval * 1000);
		}


		//QMessageBox::information(this, QStringLiteral("训练完成提示窗口"),
		//	QStringLiteral("该批次数据已全部识别完成，请重新加载数据"));
		data_resolveTerminate();
		mclTerminateApplication();









		emit massion_complete();

	}
}