#include "adminDialog.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QHeaderView>

adminDialog::adminDialog(QWidget* parent):QDialog(parent)
{
  show_widget = new QTabWidget;
  info_view = new QTableView;
  info_model = new infoModel;
  info_view->setModel(info_model);
  info_view->setItemDelegate(new infoDelegate);  //设置委托

  QString info("所有用户");
  show_widget->addTab(info_view,info);

  add_button = new QPushButton("添加");
  delete_button = new QPushButton("删除");
  write_button = new QPushButton("写入");
  close_button = new QPushButton("关闭");

  connect(add_button,SIGNAL(clicked()),info_model,SLOT(addNewData()));
  connect(delete_button,SIGNAL(clicked()),this,SLOT(getDeleteData()));
  connect(write_button,SIGNAL(clicked()),info_model,SLOT(writeData()));
  connect(close_button,SIGNAL(clicked()),this,SLOT(close()));

  connect(this,SIGNAL(deleteInfoData(int)),info_model,SLOT(deleteData(int)));
  //布局安装
  QHBoxLayout* button_layout = new QHBoxLayout;
  button_layout->addWidget(delete_button);
  button_layout->addStretch();
  button_layout->addWidget(add_button);
  button_layout->addWidget(write_button);
  button_layout->addWidget(close_button);

  QVBoxLayout* main_layout = new QVBoxLayout;
  main_layout->addWidget(show_widget);
  main_layout->addLayout(button_layout);

  setLayout(main_layout);
  setFixedSize(650,700);
  setWindowTitle("用户情况");
}


void adminDialog::getDeleteData()
{
  int e = 0;
  if(info_view->currentIndex().isValid())
  {
     e = info_view->currentIndex().row();
    emit deleteInfoData(e);
  }
}
