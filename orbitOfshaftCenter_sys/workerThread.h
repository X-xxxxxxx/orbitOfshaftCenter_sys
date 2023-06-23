#pragma once
#include <qthread.h>
#include <qDebug>

#include <QFileInfoList>



#include <QStandardPaths>

//


#include "mydlladd.h"
#include "get_data_demesions.h"
#include "data_resolve.h"

#include <mat.h>
#include <matrix.h>



#pragma comment (lib, "libmx.lib")
#pragma comment (lib, "libmat.lib")
#pragma comment (lib, "mclmcr.lib")
#pragma comment (lib, "mclmcrrt.lib")
#pragma comment (lib, "libmex.lib")
#pragma comment (lib, "libeng.lib")

#pragma comment(lib, "mydlladd.lib")
#pragma comment(lib, "get_data_demesions.lib")
#pragma comment(lib, "data_resolve.lib")

class workerThread :
    public QThread
{
    Q_OBJECT

public:
    // 重写run函数
    QFileInfoList file_list;
    QFileInfo fileinfo_model;
    int option_index;
    int interval;
    workerThread(QFileInfoList& file_list, QFileInfo& fileinfo_model, int option_index, int interval);
    void run() override;

signals:
    void resultReady(const char*, QString, QString);
    void massion_complete(); // 批次数据已经处理完成
};

