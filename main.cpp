#include <QApplication>
#include "BuildFile.h"
#include "Login.h"
#include "globalfunction.h"
#include <QSplashScreen>

bool inputJudge(QString str1, QString str2)
{
    if (str1.length() > 4)
    {
        QMessageBox::warning(0, "拒绝", "昵称不超过四个字符！", QMessageBox::Ok);
        return false;
    }
    if (str2.length() > 6)
    {
        QMessageBox::warning(0, "拒绝", "密码不超过六个字符", QMessageBox::Ok);
        return false;
    }
    return true;
}

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QMessageBox::information(0, "提示",
                           "请注意以下两点：\n\n    昵称不多于四个字符\n\n    密码不多于六个字符",
                           QMessageBox::Ok);
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/images/成信大冬.jpg"));
    splash->show();
    for(int i=0;i<2000;i++)
    {
        splash->repaint();
    }
    splash->setPixmap(QPixmap(":/images/成信大秋.jpg"));
    splash->show();
    for(int i=0;i<2000;i++)
    {
        splash->repaint();
    }
    splash->setPixmap(QPixmap(":/images/成信大夏.jpg"));
    splash->show();
    for(int i=0;i<2000;i++)
    {
        splash->repaint();
    }
    splash->setPixmap(QPixmap(":/images/成信大春.jpg"));
    splash->show();
    for(int i=0;i<2000;i++)
    {
        splash->repaint();
    }
    delete splash;
    buildFile();
    Login login;
    login.show();
    return app.exec();
}
