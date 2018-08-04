#include "CtrlPanel.h"
#include <QGridLayout>
#include <QVBoxLayout>
CtrlPanel::CtrlPanel(QWidget *parent) : QWidget(parent)
{
    QGridLayout* grid = new QGridLayout(this);//把各个窗口部件排列在一个网格中
    QVBoxLayout* vLay = new QVBoxLayout;
    grid->setColumnStretch(0, 1);
    grid->setColumnStretch(2, 1);
    grid->setRowStretch(0, 1);
    grid->setRowStretch(2, 1);
    grid->addLayout(vLay, 1, 1);

    vLay->addWidget(this->_back = new QPushButton("Back"));
    connect(this->_back, SIGNAL(clicked()), this, SIGNAL(sigBack()));
}

CtrlPanel::~CtrlPanel()
{

}
