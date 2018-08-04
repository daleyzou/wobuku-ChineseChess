#include "infoModel.h"
#include <QFile>
#include <QDateTime>
#include <QDir>
#include <QMessageBox>

infoModel::infoModel(QObject* parent):QAbstractTableModel(parent)
{
    info.push_back("昵称");
    info.push_back("用户名");
    info.push_back("密码");
    info.push_back("年龄");
    info.push_back("性别");
    info.push_back("注册时间");
    showData();

}
int infoModel::rowCount(const QModelIndex &) const
{
    return nickName.size();
}

int infoModel::columnCount(const QModelIndex &) const
{
    return info.size();
}

QVariant infoModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }
    if (role == Qt::TextAlignmentRole)
    {
        return QVariant(Qt::AlignRight | Qt::AlignVCenter);

    }
    if (role == Qt::DisplayRole)
    {
        if (index.column() == 0)
        {
            return nickName.at(index.row());
        }
        if (index.column() == 1)
        {
            return userName.at(index.row());
        }
        if (index.column() == 2)
        {
            return password.at(index.row());
        }
        if (index.column() == 3)
        {
            return age.at(index.row());
        }
        if (index.column() == 4)
        {
            return sex.at(index.row());
        }
        if (index.column() == 5)
        {
            return registTime.at(index.row());
        }
    }
    return QVariant();
}

bool infoModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() and role == Qt::EditRole)
    {
        if (index.column() == 0)
        {
            if (!inputJudge(value.toString(), "123"))
            {
                return false;
            }
            *(nickName.begin() + index.row()) = value.toString();
        }
        if (index.column() == 2)
        {
            if (!inputJudge("爱编程", value.toString()))
            {
                return false;
            }
            *(password.begin() + index.row()) = value.toString();
        }
        if (index.column() == 3)
        {
            *(age.begin() + index.row()) = value.toInt();
        }
        if (index.column() == 4)
        {
            *(sex.begin() + index.row()) = value.toString();
        }
        return true;
    }
    return false;
}

QVariant infoModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole and orientation == Qt::Horizontal)  //第一行
    {
        return info.at(section);
    }
    if (role == Qt::DisplayRole and orientation == Qt::Vertical)    //第一列
    {
        return section + 1;
    }
    return QVariant();
}


Qt::ItemFlags infoModel::flags(const QModelIndex &index) const //返回数据是否可以被编辑
{
    Qt::ItemFlags flag = QAbstractItemModel::flags(index);
    if (index.column() != 1 && index.column() != 5)
    {
        flag |= Qt::ItemIsEditable;
    }
    return flag;
}
void infoModel::writeData()
{
    QString infoPath = QDir::currentPath();
    infoPath = infoPath + "/info";
    QString name1Path = infoPath + "/nickName.txt";
    QString name2Path = infoPath + "/userName.txt";
    QString passWordPath = infoPath + "/passWord.txt";
    QString agePath = infoPath + "/age.txt";
    QString sexPath = infoPath + "/sex.txt";
    QString registTimePath = infoPath + "/registTime.txt";

    QFile name1File(name1Path);
    QFile name2File(name2Path);
    QFile passWordFile(passWordPath);
    QFile ageFile(agePath);
    QFile sexFile(sexPath);
    QFile registTimeFile(registTimePath);

    name1File.open(QIODevice::WriteOnly);
    name2File.open(QIODevice::WriteOnly);
    passWordFile.open(QIODevice::WriteOnly);
    ageFile.open(QIODevice::WriteOnly);
    sexFile.open(QIODevice::WriteOnly);
    registTimeFile.open(QIODevice::WriteOnly);

    QTextStream name1IO(&name1File);
    QTextStream name2IO(&name2File);
    QTextStream passWordIO(&passWordFile);
    QTextStream ageIO(&ageFile);
    QTextStream sexIO(&sexFile);
    QTextStream registTimeIO(&registTimeFile);

    for (int i = 0; i < nickName.size(); i++)
    {
        name1IO << nickName.at(i) << "\n";
        name2IO << userName.at(i) << "\n";
        passWordIO << password.at(i) << "\n";
        ageIO << age.at(i) << "\n";
        sexIO << sex.at(i) << "\n";
        registTimeIO << registTime.at(i) << "\n";
    }
}

void infoModel::deleteData(int i)
{
    if (i == 0)
    {
        QMessageBox::warning(0, "被拒绝", "\n\n我拒绝删除自己的子数据\n\n 亲！！！俺会崩溃的，不能开玩笑\n\n", QMessageBox::Ok);
        return;
    }
    beginResetModel();
    nickName.erase(nickName.begin() + i);
    userName.erase(userName.begin() + i);
    password.erase(password.begin() + i);
    age.erase(age.begin() + i);
    sex.erase(sex.begin() + i);
    registTime.erase(registTime.begin() + i);

    endResetModel();
}

void infoModel::addNewData()
{
    beginResetModel();
    int i = userName.at(userName.size() - 1);
    i = i + 1;
    nickName.push_back("我是模板");
    userName.push_back(i);
    password.push_back("10086");
    age.push_back(18);
    sex.push_back("女");
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd");
    registTime.push_back(str);

    endResetModel();
}

void infoModel::addNewData(QString newNickName, QString newPwd, QString newSex,int newAge)
{
    int i = userName.at(userName.size() - 1);
    i = i + 1;
    nickName.push_back(newNickName);
    userName.push_back(i);
    password.push_back(newPwd);
    age.push_back(newAge);
    sex.push_back(newSex);
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd");
    registTime.push_back(str);
    long t = userName.at(userName.size() - 1);
    QString str1 = "\n你的用户名是：" + QString::number(t, 10) + "\n注意牢记密码哦！\n" + "\n忘记密码请找管理员进行重置\n\n\n";
    QMessageBox::information(0, "注册成功", str1, QMessageBox::Ok);

}

void infoModel::modifyData(QString newNickName, QString newPwd, int location)
{
    iter1 = nickName.begin();
    iter2 = password.begin();
    for (int i = 0; i < location; i++)
    {
        iter1++;
        iter2++;
    }
    *(iter1) = newNickName;
    *(iter2) = newPwd;
}

void infoModel::showData()
{
    QString infoPath = QDir::currentPath();
    infoPath = infoPath + "/info";
    QString name1Path = infoPath + "/nickName.txt";
    QString name2Path = infoPath + "/userName.txt";
    QString passWordPath = infoPath + "/passWord.txt";
    QString agePath = infoPath + "/age.txt";
    QString sexPath = infoPath + "/sex.txt";
    QString registTimePath = infoPath + "/registTime.txt";

    QFile name1File(name1Path);
    QFile name2File(name2Path);
    QFile passWordFile(passWordPath);
    QFile ageFile(agePath);
    QFile sexFile(sexPath);
    QFile registTimeFile(registTimePath);

    name1File.open(QIODevice::ReadOnly);
    name2File.open(QIODevice::ReadOnly);
    passWordFile.open(QIODevice::ReadOnly);
    ageFile.open(QIODevice::ReadOnly);
    sexFile.open(QIODevice::ReadOnly);
    registTimeFile.open(QIODevice::ReadOnly);

    QTextStream name1IO(&name1File);
    QTextStream name2IO(&name2File);
    QTextStream passWordIO(&passWordFile);
    QTextStream ageIO(&ageFile);
    QTextStream sexIO(&sexFile);
    QTextStream registTimeIO(&registTimeFile);

    nickName.clear();
    userName.clear();
    password.clear();
    age.clear();
    sex.clear();
    registTime.clear();

    while (!name1IO.atEnd())
    {
        nickName.push_back(name1IO.readLine());
        userName.push_back(name2IO.readLine().toInt());
        password.push_back(passWordIO.readLine());
        age.push_back(ageIO.readLine().toInt());
        sex.push_back(sexIO.readLine());
        registTime.push_back(registTimeIO.readLine());
    }
}
