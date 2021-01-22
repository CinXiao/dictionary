#ifndef WIDGET_H
#define WIDGET_H
#include<QMouseEvent>
#include<QEvent>
#include <QWidget>
#include<QDebug>
#include<QFile>
#include"word.h"
#include"dat.h"
#include<QPushButton>
#include<QByteArray>
#include<QCheckBox>
#include<QTimerEvent>
#include<QIcon>
#include<QDialog>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int now_nouse_x,now_mouse_y;//点击鼠标位置记录

    dat *a;//数据
     QString s[5];//系统设置
    QFile file;//存储文件

QCheckBox *edit_box;
QPushButton *addbutton;//添加按钮
private:

    int type;
   bool edit_type;
    void load();//初始化
    void save();//保存
   void file_updata();//更新数据

    Ui::Widget *ui;
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void timerEvent(QTimerEvent *e);


public slots:

void add();//添加单词

};
#endif // WIDGET_H
