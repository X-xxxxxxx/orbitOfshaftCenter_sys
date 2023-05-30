#include "workerThread.h"
#include <qDebug>
#include <QTime>

workerThread::workerThread(QFileInfoList& file_list, QFileInfo& fileinfo_model, int option_index, int interval)
{
	this->file_list = file_list;
    this->fileinfo_model = fileinfo_model;
    this->option_index = option_index;
	this->interval = interval;
	qDebug() << QStringLiteral("���̳߳�ʼ���ɹ�") << endl;
}

void workerThread::run()
{
	//QString result = file_list.at(0).fileName();
	QString result;


	qDebug() << QStringLiteral("���߳̿�ʼ����") << endl;
	qDebug() << QStringLiteral("��ǰ���߳�ID��") << "-----" << QThread::currentThreadId();


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
			result = file_list.at(i).fileName();
			// ��ȡ��ǰ�����ļ�·������
			QString data_path = file_list.at(i).path() + "/" + file_list.at(i).fileName();
			std::string datapathqstr_str = data_path.toStdString();
			const char* datapathstr_to_mw = datapathqstr_str.c_str();
			qDebug() << QStringLiteral("�����ļ�·��") << datapathstr_to_mw << endl;
			mwArray pathstr(datapathstr_to_mw);

			// ��ȡ���ڲ���
			QDateTime date_time = QDateTime::currentDateTime();//��ȡϵͳ��ǰ��ʱ��
			QString qstr = date_time.toString("yyyy-MM-dd_hh-mm-ss");//��ʽ��ʱ��
			std::string dateqstr_str = qstr.toStdString();
			const char* datestr_to_mw = dateqstr_str.c_str();

			qDebug() << datestr_to_mw << endl;
			//qDebug() << qstr << endl;
			//
			//std::cout << dateqstr_str << endl;

			//mwArray timestr("2221111111"); // time str ����
			mwArray timestr(datestr_to_mw); // time str ����
			// ��ȡ����ѡ������
					//box_options->currentIndex();
			mwArray option_index(option_index, mxDOUBLE_CLASS);

			// ��ȡmodel ����  ���а��� ����·�� �� �ļ�����

			// ģ�;���·��
			QString s = fileinfo_model.path(); // ģ�͵ľ���·��
			qDebug() << QStringLiteral("ģ�;���·�� QString") << s << endl;
			std::string modelpath = s.toStdString();

			const char* modelpath_to_mw = modelpath.c_str();
			qDebug() << QStringLiteral("ת����ģ�;���·��") << modelpath_to_mw << endl;
			mwArray absolutepath_Net(modelpath_to_mw);
			// ģ������
			std::string modelname = fileinfo_model.fileName().toStdString();; // ģ������
			//qDebug() 



			// 
			// 
			//qDebug() << modelpath << endl;
			const char* modelname_to_mw = modelname.c_str();
			qDebug() << QStringLiteral("��matlab ʹ�õ� ģ������") << modelname_to_mw << endl;
			mwArray NetName(modelname_to_mw);


			// ����dll ���д���
			//�õ����

			mwArray res(mxCHAR_CLASS);
			data_resolve(1, res, pathstr, absolutepath_Net, NetName, timestr, option_index);

			printf("%s\n", (const char*)(res.ToString()));
			



			//��ʶ����ɵ����ݼ��е� �����ļ���

			//if(QFile::copy(data_path, "C:/Users/X_xx/Desktop/test_dir/3.data_save/"  +  file_list.at(i).fileName()) 
			//	&&QFile::remove(data_path))

			if (QFile::rename(data_path, "C:/Users/X_xx/Desktop/test_dir/3.data_save/" + file_list.at(i).fileName()))
				qDebug() << QStringLiteral("ʶ����ļ�ת�Ƴɹ�") << endl;


			qDebug() << QStringLiteral("�������׼��") << endl;


			qDebug() << QStringLiteral("��ui�̷߳����ź�") << endl;			

			QString resImg_path = "C:/Users/X_xx/Desktop/test_dir/3.data_save/" + QStringLiteral("�ᴿͼƬ_") + qstr + ".jpg";
			QString prmiImg_path = "C:/Users/X_xx/Desktop/test_dir/3.data_save/" + QStringLiteral("ԭʼͼƬ_") + qstr + ".jpg";
			emit resultReady(result, resImg_path, prmiImg_path);

			QThread::msleep(this->interval * 1000);
		}


		//QMessageBox::information(this, QStringLiteral("ѵ�������ʾ����"),
		//	QStringLiteral("������������ȫ��ʶ����ɣ������¼�������"));
		data_resolveTerminate();
		mclTerminateApplication();









		emit massion_complete();

	}
}