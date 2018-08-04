/*
 * adminDialog类的作用：
 *      由模型（infoModel）和委托（infoDelegate）共同控制管理员的窗口
 *      用户可以在这个窗口中实现管理员多用户的相关操作
*/
#ifndef ADMINDIALOG_H
#define ADMINDIALOG_H
#include<QDialog>
#include<QTabWidget>
#include<QPushButton>
#include<QTableView>
#include<QList>
#include<QCloseEvent>
#include"infoModel.h"
#include "infoDelegate.h"

class adminDialog:public QDialog
{
  Q_OBJECT
 private:
  QTabWidget* show_widget;
  infoModel* info_model;
  QTableView* info_view;
  QPushButton* add_button;
  QPushButton* delete_button;
  QPushButton* write_button;
  QPushButton* close_button;
 public:
  adminDialog(QWidget* parent = 0);
 signals:
  void deleteInfoData(int);
 private slots:
  void getDeleteData();  //获得当前选定的item的index
};
#endif
