#include "BuildFile.h"
#include <QTextStream>
#include <QDateTime>



void buildFile()//建立存放数据的文件
{
    QString infoPath = QDir::currentPath();
    infoPath = infoPath + "/info";
    QDir dirs;
    dirs.mkpath(infoPath);  //创建目录
    QString name1 = infoPath + "/nickName.txt";
    QString name2 = infoPath + "/userName.txt";
    QString passWord = infoPath + "/passWord.txt";
    QString age = infoPath + "/age.txt";
    QString sex = infoPath + "/sex.txt";
    QString registTime = infoPath + "/registTime.txt";

    QFile file;
    //程序第一次运行时初始化数据
    if (!file.exists(name1))
    {
        QFile newFile(name1);
        newFile.open(QIODevice::WriteOnly);
        QTextStream name1IO(&newFile);
        QString model("爱编程");
        model = model + "\n";
        name1IO << model;
        newFile.close();
    }
    if (!file.exists(name2))
    {
        QFile newFile(name2);
        newFile.open(QIODevice::WriteOnly);
        QTextStream name1IO(&newFile);
        name1IO << 20160000 << "\n";
        newFile.close();
    }
    if (!file.exists(passWord))
    {
        QFile newFile(passWord);
        newFile.open(QIODevice::WriteOnly);
        QTextStream name1IO(&newFile);
        name1IO << "10086" << "\n";
        newFile.close();
    }
    if (!file.exists(age))
    {
        QFile newFile(age);
        newFile.open(QIODevice::WriteOnly);
        QTextStream name1IO(&newFile);
        name1IO << "18" << "\n";
        newFile.close();
    }
    if (!file.exists(registTime))
    {
        QFile newFile(registTime);
        newFile.open(QIODevice::WriteOnly);
        QTextStream name1IO(&newFile);
        QDateTime time = QDateTime::currentDateTime();
        QString str = time.toString("yyyy-MM-dd");
        name1IO << str << "\n";
        newFile.close();
    }
    if (!file.exists(sex))
    {
        QFile newFile(sex);
        newFile.open(QIODevice::WriteOnly);
        QTextStream name1IO(&newFile);
        QString model("女");
        model = model + "\n";
        name1IO << model;
        newFile.close();
    }
}



























