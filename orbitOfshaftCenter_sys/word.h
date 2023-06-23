#pragma once



#include <QMainWindow>
#include <QString>
#include <QVariant>
#include <QAxObject>
#include <QAxWidget>
#include <QTextCodec>

struct testDataType
{
    QString user;   //使用者
    QString code; //设备编号
    QString fenshu;//得分
};


class QWord : public QObject
{
    Q_OBJECT

public:
    QWord(QObject* parent = 0);
    ~QWord();

public:
    QAxObject* getDocuments() { return m_documents; }
    QAxObject* getDocument() { return m_document; }
    QAxObject* getWordApp() { return m_word; }
public:
    /**************************************************************************/
    /* 文件   操作                                                            */
    /**************************************************************************/
    void save();				//保存操作内容
    void close();				//关闭 退出 析构时候也会自动调用一次
    void saveAs();				//新建excel另存为
    bool createNewWord();		//创建一个新的excel
    void openWord();			//打开一个现有的excel
    bool createNewWord(const QString& filePath);		//创建一个新的excel

    void setTableAutoFitBehavior(int flag);				//表格自动拉伸列 0固定  1根据内容调整  2 根据窗口调整
    void setPageOrientation(int flag);					//设置页面0为纵向wdOrientPortrait  1为横向wdOrientLandscape
    void setWordPageView(int flag);						//设置页面视图，是web视图wdWebView 6还是页面视图wdPrintView 3 或者阅读视图wdReadingView 7
    void setFontSize(int fontsize);						//设置字体大小
    void setFontName(QString& fontName);				//设置字体	比如 “宋体”
    void setFontBold(bool flag);						//字体加粗
    void setParagraphAlignment(int flag);				//设置选中位置文字居中 0 ,居左 1,居右 2
    void setColumnWidth(int column, int width);			//设置列宽
    void setCellString(int row, int column, const QString& text);
    void setCellFontBold(int row, int column, bool isBold);			//设置内容粗体  isBold控制是否粗体
    void setCellFontSize(int row, int column, int size);			//设置文字大小
    void setOptionCheckSpell(bool flags);							//设置审阅的拼写检查  true开启检查  false 取消检查

    QString GetText();												//获取内容
    void getUsedRange(int* topLeftRow, int* topLeftColumn, int* bottomRightRow, int* bottomRightColumn);
    void setSelectionRange(int start, int end);						//"SetRange(1, 9)"第1个字符后开始，到第9个字符结束范围
    QVariant getCellValue(int row, int column);						//获取单元格内容
    int getTableCount();											//获取word中表格总数


    QString getStrErrorInfo() { return m_strError; }					//获取代码中出现的错误信息可以用QMessageBox::information打印 在cpp不用QMessageBox 是怕你们在线程中调导出报表
    void deleteSelectColumn(int column);							//删除指定的列
    void moveForEnd();												//移动选定对象到文档末尾
    void insertCellPic(int row, int column, const QString& picPath);	//单元格插入图片
    void intsertTable(int row, int column);							//插入一个几行几列表格
    void insertMoveDown();											//插入回车
    void insertText(const QString& text);							//插入文字

    void inserttestdata(testDataType& str);

private:
    QAxObject* m_word;
    QAxObject* m_documents;
    QAxObject* m_document;
    QString  m_fileName;
    QString  m_saveName;
    QString  m_strError;

};
