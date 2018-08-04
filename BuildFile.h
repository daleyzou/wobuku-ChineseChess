/*
 * BuildFile类的作用：
 *      在程序第一次运行时创建相关的文件
 * （nickName.txt、userName.txt、passWord.txt、age.txt、sex.txt、registTime.txt）
 * 初始化数据，给一个程序分配的用户
*/
#ifndef BUILDFILE_H
#define BUILDFILE_H

#include <QDir>
#include <QFile>

void buildFile();


#endif // BUILDFILE_H
