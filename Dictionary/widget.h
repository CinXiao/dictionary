#ifndef WIDGET_H
#define WIDGET_H
#include<QMouseEvent>
#include<QEvent>
#include <QWidget>
#include"testwindow.h"
#include<QFile>
#include"word.h"
#include"dat.h"
#include<QPushButton>
#include<QByteArray>
#include<QCheckBox>
#include<QTimerEvent>
#include<QIcon>
#include<QLabel>
#include<QDialog>
#include<QObject>
#include<QRadioButton>
#include<qdebug.h>
#include<QCommandLinkButton>
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
    testwindow test;//测试功能
    dat *a,*cet4[5],*cet6;//用户数据，四级词汇数据，六级词汇数据
    QString s[5],cet4_s[5];//系统设置
    QFile file;//存储文件
    QFile CET_file;//自带的四级和六级词汇表




QPushButton *addbutton;//添加按钮
private:

    bool set_w_type=0,me_w_type=0;
    void cet_load();//cet数据装载
    void load();//初始化
    void save();//保存
   void file_updata();//更新数据

    Ui::Widget *ui;
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void timerEvent(QTimerEvent *e);



bool load_fnish=0;
public slots:
    void set1();
    void set2();


    void del();
void add();//添加单词

};
#endif // WIDGET_H
