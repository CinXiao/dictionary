#include "testwindow.h"

testwindow::testwindow(QWidget *parent) : QWidget(parent)
{

load_window();




}

void testwindow::load_window()
{

    this->resize(800,500);
   for(int i=0;i<4;++i)
   {
       check_btn[i].setParent(this);
       check_btn[i].resize(this->width(),50);
       check_btn[i].move(20,height()-250);

   }

for(int i=1;i<4;++i)
{
       check_btn[i].move(20,check_btn[i-1].y()+60);
}



title.setText("<h1>选择正确的解释</h1>");
title.setParent(this);





}



void testwindow::load(dat *d)
{
w=d;
}

void testwindow::closeEvent(QCloseEvent *e)
{
    emit close_fnish();

}
