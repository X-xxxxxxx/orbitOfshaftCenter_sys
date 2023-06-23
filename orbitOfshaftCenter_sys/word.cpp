#include "word.h"
#include <QDateTime>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <Ole2.h>
QWord::QWord(QObject* parent)
{
    m_word = new QAxObject(parent);
    m_documents = NULL;
    m_document = NULL;
}

QWord::~QWord()
{
    close();
}

bool QWord::createNewWord()		//创建一个新的word
{
    //这种方式有些bug，选择路径取消会导致程序崩溃，直接传入路径，自己操作路径则不会出现问题
    /*QString defaultFileName = tr("测试记录%1").arg(QDateTime::currentDateTime().toString("yyyy年MM月dd日hh时mm分"));
    m_saveName=QFileDialog::getSaveFileName(0,"日志信息",defaultFileName,tr("*.doc"));
    QFile file(m_saveName);
    if(file.exists())
    {
        m_strError += "错误：目标文件已存在!";
        return false;
    }
    if(!m_saveName.isEmpty())
    {
        if(!m_word->setControl("Word.Application"))
        {
            m_strError += "错误：获取word组件失败，请确定是否安装了word!";
            return false;
        }
        m_word->setProperty("Visible",false);
        m_word->setProperty("DisplayAlerts", false);//不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示
        m_documents = m_word->querySubObject("Documents");
        m_documents->dynamicCall("Add (void)");
        m_document = m_word->querySubObject("ActiveDocument");//获取当前激活的文档
        return true;
    }else
    {
        m_strError += "错误：文件名为空";
        return false;
    }*/
    return true;
}
bool QWord::createNewWord(const QString& filePath)
{
   
    m_saveName = filePath;
    QFile file(m_saveName);
    if (file.exists())
    {
        m_strError += "错误：目标文件已存在!";
        return false;
    }
    if (!m_saveName.isEmpty())
    {
        if (!m_word->setControl("Word.Application"))
        {
            m_strError += "错误：获取word组件失败，请确定是否安装了word!\n";
            return false;
        }
        m_word->setProperty("Visible", false);
        m_word->setProperty("DisplayAlerts", false);//不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示
        m_documents = m_word->querySubObject("Documents");
        if (!m_documents)
        {
            m_strError += "获取文档失败！\n";
            return false;
        }
        m_documents->dynamicCall("Add (void)");
        m_document = m_word->querySubObject("ActiveDocument");//获取当前激活的文档
        return true;
    }
    else
    {
        m_strError += "错误：文件名为空";
        return false;
    }
}
//保存
void QWord::save()
{
    if (m_document)
        m_document->dynamicCall("Save()");
    else
        return;
}
//关闭word
void QWord::close()				//关闭 退出 析构时候也会自动调用一次
{
    if (!m_saveName.isEmpty())		//如果不为空  则为新建
    {
        saveAs();
        m_saveName = "";
    }
    if (m_document)
        m_document->dynamicCall("Close (boolean)", false);
    if (m_word)
        m_word->dynamicCall("Quit (void)");
    if (m_documents)
        delete m_documents;
    if (m_word)
        delete m_word;
    m_document = NULL;
    m_documents = NULL;
    m_word = NULL;
}
//另存为
void QWord::saveAs()
{
    if (m_document)
        m_document->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(m_saveName));
    else
        return;
}
//设置页面1 横向还是 0竖向
void QWord::setPageOrientation(int flag)
{
    QAxObject* selection = m_word->querySubObject("Selection");
    QString page;
    switch (flag)
    {
    case 0:
        page = "wdOrientPortrait";
        break;
    case 1:
        page = "wdOrientLandscape";
        break;
    }
    selection->querySubObject("PageSetUp")->setProperty("Orientation", page);
}
//设置页面视图
void QWord::setWordPageView(int flag)
{
    QAxObject* viewPage = m_word->querySubObject("ActiveWindow");
    QString view;
    switch (flag)
    {
    case 1:
        view = "wdNormalView";
        break;
    case 2:
        view = "wdOutlineView";
        break;
    case 3:
        view = "wdPrintView";
        break;
    case 4:
        view = "wdPrintPreview";
        break;
    case 5:
        view = "wdMasterView";
        break;
    case 6:
        view = "wdWebView";
        break;
    case 7:
        view = "wdReadingView";
        break;
    case 8:
        view = "wdConflictView";
        break;
    }
    viewPage->querySubObject("View")->setProperty("Type", view);
}
//插入回车
void QWord::insertMoveDown()
{
    QAxObject* selection = m_word->querySubObject("Selection");
    selection->dynamicCall("TypeParagraph(void)");
}
//插入文字
void QWord::insertText(const QString& text)
{
    QAxObject* selection = m_word->querySubObject("Selection");
    selection->dynamicCall("TypeText(const QString&)", text);
}
//获取文本
QString QWord::GetText()
{
    QAxObject* selection = m_word->querySubObject("Selection");
    QString str = selection->dynamicCall("GetText(void)").toString();
    return str;
}
//设置文字对齐方向
void QWord::setParagraphAlignment(int flag)
{
    QAxObject* selection = m_word->querySubObject("Selection");
    if (flag == 0)
    {
        selection->querySubObject("ParagraphFormat")->setProperty("Alignment", "wdAlignParagraphCenter");
    }
    else if (flag == 1)
    {
        selection->querySubObject("ParagraphFormat")->setProperty("Alignment", "wdAlignParagraphJustify");
    }
    else if (flag == 2)
    {
        selection->querySubObject("ParagraphFormat")->setProperty("Alignment", "wdAlignParagraphRight");
    }
}
//设置字体大小
void QWord::setFontSize(int fontsize)
{
    QAxObject* selection = m_word->querySubObject("Selection");
    selection->querySubObject("Font")->setProperty("Size", fontsize);
}
//设置字体加粗
void QWord::setFontBold(bool flag)
{
    QAxObject* selection = m_word->querySubObject("Selection");
    selection->querySubObject("Font")->setProperty("Bold", flag);
}
//设置字体名称
void QWord::setFontName(QString& fontName)
{
    QAxObject* selection = m_word->querySubObject("Selection");
    selection->querySubObject("Font")->setProperty("Name", fontName);
}
//未知
void QWord::setSelectionRange(int start, int end)
{
    QAxObject* selection = m_word->querySubObject("Selection");
    selection->dynamicCall("SetRange(int, int)", start, end);	//第1个字符后开始，到第9个字符结束范围
}
//未知
void QWord::getUsedRange(int* topLeftRow, int* topLeftColumn, int* bottomRightRow, int* bottomRightColumn)
{
    QAxObject* range = m_document->querySubObject("Range");
    *topLeftRow = range->property("Row").toInt();
    *topLeftColumn = range->property("Column").toInt();

    QAxObject* rows = range->querySubObject("Rows");
    *bottomRightRow = *topLeftRow + rows->property("Count").toInt() - 1;

    QAxObject* columns = range->querySubObject("Columns");
    *bottomRightColumn = *topLeftColumn + columns->property("Count").toInt() - 1;
}
//插入表格
void QWord::intsertTable(int row, int column)
{
    QAxObject* tables = m_document->querySubObject("Tables");
    QAxObject* selection = m_word->querySubObject("Selection");
    QAxObject* range = selection->querySubObject("Range");
    QVariantList params;
    params.append(range->asVariant());
    params.append(row);
    params.append(column);
    tables->querySubObject("Add(QAxObject*, int, int, QVariant&, QVariant&)", params);
    QAxObject* table = selection->querySubObject("Tables(1)");
    table->setProperty("Style", QString::fromLocal8Bit("网格型"));
}
//设置表格列宽
void QWord::setColumnWidth(int column, int width)		//设置列宽
{
    QAxObject* selection = m_word->querySubObject("Selection");
    QAxObject* table = selection->querySubObject("Tables(1)");
    table->querySubObject("Columns(int)", column)->setProperty("Width", width);
}
//设置表格某行某列的字符串
void QWord::setCellString(int row, int column, const QString& text)
{
    QAxObject* selection = m_word->querySubObject("Selection");
    QAxObject* table = selection->querySubObject("Tables(1)");
    table->querySubObject("Cell(int, int)", row, column)->querySubObject("Range")->dynamicCall("SetText(QString)", text);
}
//设置表格内容粗体  isBold控制是否粗体
void QWord::setCellFontBold(int row, int column, bool isBold)
{
    QAxObject* selection = m_word->querySubObject("Selection");
    QAxObject* table = selection->querySubObject("Tables(1)");
    table->querySubObject("Cell(int, int)", row, column)->querySubObject("Range")->dynamicCall("SetBold(int)", isBold);
}
//设置表格文字大小
void QWord::setCellFontSize(int row, int column, int size)
{
    QAxObject* selection = m_word->querySubObject("Selection");
    QAxObject* table = selection->querySubObject("Tables(1)");
    table->querySubObject("Cell(int, int)", row, column)->querySubObject("Range")->querySubObject("Font")->setProperty("Size", size);
}
//获取单元格内容 此处对于Excel来说列和行从1开始最少
QVariant QWord::getCellValue(int row, int column)
{
    QAxObject* selection = m_word->querySubObject("Selection");
    QAxObject* table = selection->querySubObject("Tables(1)");
    return table->querySubObject("Cell(int, int)", row, column)->querySubObject("Range")->property("Text");
}
//获取表格数量
int QWord::getTableCount()
{
    QAxObject* tables = m_document->querySubObject("Tables");
    int val = tables->property("Count").toInt();
    return val;
}
//移动选定对象到文档末尾
void QWord::moveForEnd()
{
    QAxObject* selection = m_word->querySubObject("Selection");
    QVariantList params;
    params.append(6);
    params.append(0);
    selection->dynamicCall("EndOf(QVariant&, QVariant&)", params).toInt();
}
//表格插入图片
void QWord::insertCellPic(int row, int column, const QString& picPath)
{
    QPixmap pixmap(picPath);
   
    pixmap = pixmap.scaled(152, 76, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放

    QString path= QString::fromLocal8Bit("C:\\Users\\Gao\\Desktop\\结果\\参数优化\\粒子群\\PSO1.jpg");

    pixmap.save(path);

    QAxObject* selection = m_word->querySubObject("Selection");
    QAxObject* table = selection->querySubObject("Tables(1)");
    QAxObject* range = table->querySubObject("Cell(int, int)", row, column)->querySubObject("Range");
    range->querySubObject("InlineShapes")->dynamicCall("AddPicture(const QString&)", picPath);
}
//未知
void QWord::setTableAutoFitBehavior(int flag)
{
    QAxObject* selection = m_word->querySubObject("Selection");
    QAxObject* table = selection->querySubObject("Tables(1)");
    if (0 <= flag & flag <= 2)
        table->dynamicCall("AutoFitBehavior(WdAutoFitBehavior)", flag);
}
//删除选中列
void QWord::deleteSelectColumn(int column)
{
    QAxObject* selection = m_word->querySubObject("Selection");
    QAxObject* table = selection->querySubObject("Tables(1)");
    QAxObject* columns = table->querySubObject("Columns(int)", column);
    columns->dynamicCall("Delete()");
}

void QWord::setOptionCheckSpell(bool flags)
{
    QAxObject* opetions = m_word->querySubObject("Options");
    if (!opetions)
        return;
    opetions->setProperty("CheckGrammarAsYouType", flags);
    opetions->setProperty("CheckGrammarWithSpelling", flags);
    opetions->setProperty("ContextualSpeller", flags);
    opetions->setProperty("CheckSpellingAsYouType", flags);
}
