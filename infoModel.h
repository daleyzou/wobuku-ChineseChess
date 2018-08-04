/*
 * infoModel类的作用：
 *       模型
 *      设置adminDialog窗口中显示的行、列、数据
*/
#ifndef INFOMODEL_H
#define INFOMODEL_H
#include <QAbstractTableModel>
#include <QList>
#include <QVector>
#include <QVariant>
#include <QModelIndex>
#include <QTextStream>
#include "globalfunction.h"

class infoModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    QList<QString> nickName;
    QList<QString>::iterator iter1;
    QList<int> userName;
    QList<QString> password;
    QList<QString>::iterator iter2;
    QList<int> age;
    QList<QString> sex;
    QList<QString> registTime;
    QVector<QString> info;

public:
    infoModel(QObject *parent = 0);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    void showData();                //将文件中的数据展示在表格中
public slots:
    void writeData();
    void deleteData(int);
    void addNewData();
    void addNewData(QString newNickName, QString newPwd, QString newSex,int newAge);
    void modifyData(QString newNickName, QString newPwd, int location);


};

#endif // INFOMODEL_H










