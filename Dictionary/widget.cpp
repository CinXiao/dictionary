#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
type=0;
ui->setupUi(this);


load();//加载


            connect(edit_box,&QCheckBox::stateChanged,[=]()
            {

            if(edit_box->isChecked())
            {
                ui->find_edit->resize(220,32);
                ui->explain->show();
                ui->explain_lab->show();
                ui->note->show();
                ui->note_lab->show();
                ui->show_lab->hide();
                addbutton->show();
            }else
            {
                 ui->find_edit->resize(350,32);
                addbutton->hide();
                ui->show_lab->show();
                ui->explain->hide();
                ui->explain_lab->hide();
                ui->note->hide();
                ui->note_lab->hide();
            }
            });


connect(addbutton,&QPushButton::clicked,this,&Widget::add);



startTimer(500);
}


void Widget::add()
{



    if(ui->find_edit->text()==""||ui->explain->text()=="")
    {
       QDialog s;
       QLabel show(&s);
       show.setText("单词或解释为空，不能添加");
       QPushButton btn(&s);
       btn.move(50,50);
       btn.setText("关闭");
       s.setWindowFlags(Qt::FramelessWindowHint);
       s.resize(150,100);
       connect(&btn,&QPushButton::clicked,&s,&QDialog::close);
       s.exec();
       return;
    }

a->addword(ui->find_edit->text(),ui->explain->text(),ui->note->text());
ui->find_edit->setText("");
ui->explain->setText("");
ui->note->setText("");

save();

}






Widget::~Widget()
{
    delete ui;
}
void Widget::mousePressEvent(QMouseEvent *e)
{


now_nouse_x=e->x();
now_mouse_y=e->y();
if(e->button()==Qt::RightButton)
{
this->close();

}


}
void Widget::mouseMoveEvent(QMouseEvent *e)
{

  int h=ui->top->height()-10;
    if(e->y()<h)
    {
       move(e->globalX()-now_nouse_x,e->globalY()-now_mouse_y);
    }
}




void Widget::load()
{
  ui->explain->hide();
  ui->explain_lab->hide();
  ui->note->hide();
  ui->note_lab->hide();
  edit_box=new QCheckBox(this);
  edit_box->setText("编辑");
  edit_box->move(430,310);
  addbutton=new QPushButton(this);
  addbutton->resize(130,32);
  addbutton->move(360,50);
  addbutton->setText("✅");
  addbutton->hide();
        resize(500,350);
        setWindowFlags(Qt::FramelessWindowHint);
        edit_type=0;
        file.setFileName("C:/Users/Administrator/Documents/dic.dictionary");
        if(!file.open(QIODevice::ReadOnly))
        {
        qDebug()<<"文件打开失败";
        file.open(QIODevice::WriteOnly);
        file.write("V:0.1\n0\n版权所有：AF_XYY\n---关于----\nXXXXX\n");//文件前五行
        file.close();
       file_updata();



        file.close();
        qDebug()<<"创建文件成功";




        }else
        {
          file.close();
           file_updata();
        }
}

void Widget::file_updata()
   {

                file.open(QIODevice::ReadOnly);
                for(int i=0;i<5;i++)
                {
                s[i]=file.readLine();
                qDebug()<<s[i];
                }
                a=new dat(s[0],s[1],s[2],s[3],s[4]);
                for (int i=0;i<s[1].toInt();++i)
                {
                 a->w[i].w=file.readLine();
                 a->w[i].explain =file.readLine();
                 a->w[i].note =file.readLine();
                 a->w[i].proficient_value =(file.readLine()).toInt();
                }
                file.close();


   }




 void Widget::save()
   {
       file.setFileName("C:/Users/Administrator/Documents/dic.dictionary");
       file.open(QIODevice::WriteOnly);

       file.write(a->sys[0].toUtf8());
         file.write(a->sys[1].toUtf8()+"\n");
     file.write(a->sys[2].toUtf8());
          file.write(a->sys[3].toUtf8());
               file.write(a->sys[4].toUtf8());

       for(int i=0;i<a->word_value;i++)
       {
           file.write(a->w[i].w.toUtf8()+"\n");
           file.write( a->w[i].explain.toUtf8()+"\n");
           file.write( a->w[i].note.toUtf8()+"\n");
           QString temp=QString("%1").arg(a->w[i].proficient_value);
          file.write(temp.toUtf8()+"\n");

       }
        file.close();
   }


//timerevent事件） 搜索引擎（暂时）
void Widget::timerEvent(QTimerEvent *e)
{

        QString op=ui->find_edit->text()+"\n";
        QString op2=ui->find_edit->text();
        if(op=="\n")
        {
             ui->show_lab->setText("");
            return;
        }

        for(int i=0;i<a->word_value;i++)
         {
             if(a->w[i].w==op||a->w[i].w==op2||a->w[i].explain ==op||a->w[i].explain==op2)
             {
              ui->show_lab->setText("单词:  "+a->w[i].w+"\n解释: "+a->w[i].explain+"\n\n\n笔记:  "+a->w[i].note);
                break;
             }else
             {
              ui->show_lab->setText("------------找不到这个单词-----------------\n可能的原因:\n1.大小写错误（模糊查找功能正在开发中）\n2.库中没有该单词，你可以通过下面的编辑，新建\n这个单词的单词库");
             }
        }




}



