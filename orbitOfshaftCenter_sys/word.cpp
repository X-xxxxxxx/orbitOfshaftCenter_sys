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

bool QWord::createNewWord()		//����һ���µ�word
{
    //���ַ�ʽ��Щbug��ѡ��·��ȡ���ᵼ�³��������ֱ�Ӵ���·�����Լ�����·���򲻻��������
    /*QString defaultFileName = tr("���Լ�¼%1").arg(QDateTime::currentDateTime().toString("yyyy��MM��dd��hhʱmm��"));
    m_saveName=QFileDialog::getSaveFileName(0,"��־��Ϣ",defaultFileName,tr("*.doc"));
    QFile file(m_saveName);
    if(file.exists())
    {
        m_strError += "����Ŀ���ļ��Ѵ���!";
        return false;
    }
    if(!m_saveName.isEmpty())
    {
        if(!m_word->setControl("Word.Application"))
        {
            m_strError += "���󣺻�ȡword���ʧ�ܣ���ȷ���Ƿ�װ��word!";
            return false;
        }
        m_word->setProperty("Visible",false);
        m_word->setProperty("DisplayAlerts", false);//����ʾ�κξ�����Ϣ�����Ϊtrue��ô�ڹر��ǻ�������ơ��ļ����޸ģ��Ƿ񱣴桱����ʾ
        m_documents = m_word->querySubObject("Documents");
        m_documents->dynamicCall("Add (void)");
        m_document = m_word->querySubObject("ActiveDocument");//��ȡ��ǰ������ĵ�
        return true;
    }else
    {
        m_strError += "�����ļ���Ϊ��";
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
        m_strError += "����Ŀ���ļ��Ѵ���!";
        return false;
    }
    if (!m_saveName.isEmpty())
    {
        if (!m_word->setControl("Word.Application"))
        {
            m_strError += "���󣺻�ȡword���ʧ�ܣ���ȷ���Ƿ�װ��word!\n";
            return false;
        }
        m_word->setProperty("Visible", false);
        m_word->setProperty("DisplayAlerts", false);//����ʾ�κξ�����Ϣ�����Ϊtrue��ô�ڹر��ǻ�������ơ��ļ����޸ģ��Ƿ񱣴桱����ʾ
        m_documents = m_word->querySubObject("Documents");
        if (!m_documents)
        {
            m_strError += "��ȡ�ĵ�ʧ�ܣ�\n";
            return false;
        }
        m_documents->dynamicCall("Add (void)");
        m_document = m_word->querySubObject("ActiveDocument");//��ȡ��ǰ������ĵ�
        return true;
    }
    else
    {
        m_strError += "�����ļ���Ϊ��";
        return false;
    }
}
//����
void QWord::save()
{
    if (m_document)
        m_document->dynamicCall("Save()");
    else
        return;
}
//�ر�word
void QWord::close()				//�ر� �˳� ����ʱ��Ҳ���Զ�����һ��
{
    if (!m_saveName.isEmpty())		//�����Ϊ��  ��Ϊ�½�
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
//���Ϊ
void QWord::saveAs()
{
    if (m_document)
        m_document->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(m_saveName));
    else
        return;
}
//����ҳ��1 ������ 0����
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
//����ҳ����ͼ
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
//����س�
void QWord::insertMoveDown()
{
    QAxObject* selection = m_word->querySubObject("Selection");
    selection->dynamicCall("TypeParagraph(void)");
}
//��������
void QWord::insertText(const QString& text)
{
    QAxObject* selection = m_word->querySubObject("Selection");
    selection->dynamicCall("TypeText(const QString&)", text);
}
//��ȡ�ı�
QString QWord::GetText()
{
    QAxObject* selection = m_word->querySubObject("Selection");
    QString str = selection->dynamicCall("GetText(void)").toString();
    return str;
}
//�������ֶ��뷽��
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
//���������С
void QWord::setFontSize(int fontsize)
{
    QAxObject* selection = m_word->querySubObject("Selection");
    selection->querySubObject("Font")->setProperty("Size", fontsize);
}
//��������Ӵ�
void QWord::setFontBold(bool flag)
{
    QAxObject* selection = m_word->querySubObject("Selection");
    selection->querySubObject("Font")->setProperty("Bold", flag);
}
//������������
void QWord::setFontName(QString& fontName)
{
    QAxObject* selection = m_word->querySubObject("Selection");
    selection->querySubObject("Font")->setProperty("Name", fontName);
}
//δ֪
void QWord::setSelectionRange(int start, int end)
{
    QAxObject* selection = m_word->querySubObject("Selection");
    selection->dynamicCall("SetRange(int, int)", start, end);	//��1���ַ���ʼ������9���ַ�������Χ
}
//δ֪
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
//������
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
    table->setProperty("Style", QString::fromLocal8Bit("������"));
}
//���ñ���п�
void QWord::setColumnWidth(int column, int width)		//�����п�
{
    QAxObject* selection = m_word->querySubObject("Selection");
    QAxObject* table = selection->querySubObject("Tables(1)");
    table->querySubObject("Columns(int)", column)->setProperty("Width", width);
}
//���ñ��ĳ��ĳ�е��ַ���
void QWord::setCellString(int row, int column, const QString& text)
{
    QAxObject* selection = m_word->querySubObject("Selection");
    QAxObject* table = selection->querySubObject("Tables(1)");
    table->querySubObject("Cell(int, int)", row, column)->querySubObject("Range")->dynamicCall("SetText(QString)", text);
}
//���ñ�����ݴ���  isBold�����Ƿ����
void QWord::setCellFontBold(int row, int column, bool isBold)
{
    QAxObject* selection = m_word->querySubObject("Selection");
    QAxObject* table = selection->querySubObject("Tables(1)");
    table->querySubObject("Cell(int, int)", row, column)->querySubObject("Range")->dynamicCall("SetBold(int)", isBold);
}
//���ñ�����ִ�С
void QWord::setCellFontSize(int row, int column, int size)
{
    QAxObject* selection = m_word->querySubObject("Selection");
    QAxObject* table = selection->querySubObject("Tables(1)");
    table->querySubObject("Cell(int, int)", row, column)->querySubObject("Range")->querySubObject("Font")->setProperty("Size", size);
}
//��ȡ��Ԫ������ �˴�����Excel��˵�к��д�1��ʼ����
QVariant QWord::getCellValue(int row, int column)
{
    QAxObject* selection = m_word->querySubObject("Selection");
    QAxObject* table = selection->querySubObject("Tables(1)");
    return table->querySubObject("Cell(int, int)", row, column)->querySubObject("Range")->property("Text");
}
//��ȡ�������
int QWord::getTableCount()
{
    QAxObject* tables = m_document->querySubObject("Tables");
    int val = tables->property("Count").toInt();
    return val;
}
//�ƶ�ѡ�������ĵ�ĩβ
void QWord::moveForEnd()
{
    QAxObject* selection = m_word->querySubObject("Selection");
    QVariantList params;
    params.append(6);
    params.append(0);
    selection->dynamicCall("EndOf(QVariant&, QVariant&)", params).toInt();
}
//������ͼƬ
void QWord::insertCellPic(int row, int column, const QString& picPath)
{
    QPixmap pixmap(picPath);
   
    pixmap = pixmap.scaled(152, 76, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // ����������

    QString path= QString::fromLocal8Bit("C:\\Users\\Gao\\Desktop\\���\\�����Ż�\\����Ⱥ\\PSO1.jpg");

    pixmap.save(path);

    QAxObject* selection = m_word->querySubObject("Selection");
    QAxObject* table = selection->querySubObject("Tables(1)");
    QAxObject* range = table->querySubObject("Cell(int, int)", row, column)->querySubObject("Range");
    range->querySubObject("InlineShapes")->dynamicCall("AddPicture(const QString&)", picPath);
}
//δ֪
void QWord::setTableAutoFitBehavior(int flag)
{
    QAxObject* selection = m_word->querySubObject("Selection");
    QAxObject* table = selection->querySubObject("Tables(1)");
    if (0 <= flag & flag <= 2)
        table->dynamicCall("AutoFitBehavior(WdAutoFitBehavior)", flag);
}
//ɾ��ѡ����
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
