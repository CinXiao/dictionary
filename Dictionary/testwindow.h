#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QWidget>
#include <QObject>
#include<QEvent>
#include<QPushButton>
#include "dat.h"
#include<QLabel>
#include<QLayout>

class testwindow : public QWidget
{

    Q_OBJECT
public:
    explicit testwindow(QWidget *parent = nullptr);
    dat *w;
    void load(dat *d);
    QPushButton check_btn[4];//选择按钮
    QLabel title;//标题
   QLabel sentence;//题目


private:
void closeEvent(QCloseEvent *e);

void load_window();

 signals:
void  close_fnish();


};

#endif // TESTWINDOW_H
