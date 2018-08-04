#include "infoDelegate.h"

infoDelegate::infoDelegate(QObject *parent):QStyledItemDelegate(parent)
{

}

QWidget* infoDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() == 4)
    {
        QComboBox *sexBox = new QComboBox(parent);
        sexBox->addItem("男");
        sexBox->addItem("女");
        return sexBox;
    }
    else
    {
        return QStyledItemDelegate::createEditor(parent, option, index);
    }
}

void infoDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QStyledItemDelegate::setEditorData(editor, index);
}
void infoDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    if (index.column() == 4)
    {
        QComboBox* sexEdit = qobject_cast<QComboBox*>(editor);
        QString sex = sexEdit->currentText();
        model->setData(index, sex);
    }
    else
    {
        QStyledItemDelegate::setModelData(editor, model, index);
    }
}
















