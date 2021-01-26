#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{

ui->setupUi(this);
load();//加载
connect(ui->set_btn,&QCommandLinkButton::clicked,[=]()
{
    me_w_type=!me_w_type;
    set_w_type=!set_w_type;
if(set_w_type)
{
        ui->set_w->show();
        ui->me_w->hide();

}else
{
ui->set_w->hide();

}
     me_w_type=0;
});


connect(ui->find_btn,&QCommandLinkButton::clicked,[=]()
{
    ui->set_w->hide();
    ui->me_w->hide();
});


connect(ui->check_color1,&QRadioButton::clicked,this,&Widget::set1);
connect(ui->check_color2,&QRadioButton::clicked,this,&Widget::set2);
//connect(ui->me_btn,&QCommandLinkButton::clicked,[=]()
//{
//me_w_type=!me_w_type;
//set_w_type=!set_w_type;
//if(me_w_type)
//{

//ui->me_w->show();
//ui->set_w->hide();

//}else
//{
//ui->me_w->hide();
//}
//set_w_type=0;
//});






            connect(ui->edit_Box,&QCheckBox::stateChanged,[=]()
            {

            if(ui->edit_Box->isChecked())
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


//            connect(ui->test_btn,&QCommandLinkButton::clicked,this,[=](){
//           test.show();
//           this->hide();
//            });

//         connect(&test,&testwindow::close_fnish,this,[=](){

//                test.hide();
//                this->show();
//            });



connect(addbutton,&QPushButton::clicked,this,&Widget::add);




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
  ui->set_w->hide();
  ui->note_lab->hide();
  ui->me_w->hide();
  addbutton=new QPushButton(this);
  addbutton->resize(130,32);
  addbutton->move(360,50);
   cet_load();//加载cet词汇
    addbutton->setIconSize(QSize(30,32));
    addbutton->setIcon(QIcon(":/ui/add2.png"));
    addbutton->setFlat(true);
    addbutton->hide();
        resize(500,350);
        setWindowFlags(Qt::FramelessWindowHint);
        file.setFileName("C:/Users/Administrator/Documents/dic.dictionary");
        if(!file.open(QIODevice::ReadOnly))
        {
        file.open(QIODevice::WriteOnly);
        file.write("V:0.1\n0\n版权所有：AF_XYY\n---关于----\nXXXXX\n");//文件前五行
        file.close();
       file_updata();
       // file.close();
               //设置文件
       file.setFileName("set.sys");
        file.open(QIODevice::WriteOnly);
        file.write("强力搜索关闭\n");
        file.write("字体样式\n");
        file.write("基佬紫\n");
        file.write("CET4打开\n");
        file.write("CET6关闭\n");
        file.write("ALL关闭\n");
        file.close();
        }else
        {
          file.close();
          file.setFileName("set.sys");
          file.open(QIODevice::ReadOnly);
          if(file.readLine()=="强力搜索关闭\n")
          {
             startTimer(500);
          }else
          {
               startTimer(5);
          }
          file.readLine();

          QString color=file.readLine();
          if(color=="基佬紫\n")
          {
              set1();

           }else if(color=="天空蓝\n")
          {
              set2();
          }

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
                }
                a=new dat(s[0],s[1],s[2],s[3],s[4]);
                test.load(a);
                for (int i=0;i<a->word_value;++i)
                {
                 a->w[i].w=file.readLine();
                 a->w[i].w.chop(1);
                 a->w[i].explain =file.readLine();
                 a->w[i].explain.chop(1);
                 a->w[i].note =file.readLine();
                 a->w[i].note.chop(1);
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
void Widget::cet_load()
{



    CET_file.setFileName("CET/CET4_A-D.dictionary");
    CET_file.open(QIODevice::ReadOnly);
    for(int i=0;i<5;i++)
    {
    cet4_s[i]=CET_file.readLine();
    }
    cet4[0]=new dat(cet4_s[0],cet4_s[1],cet4_s[2],cet4_s[3],cet4_s[4]);
             qDebug()<<cet4[0]->word_value;
             for(int i=0;i<cet4[0]->word_value;++i)
             {
                 cet4[0]->w[i].w=CET_file.readLine();
                 cet4[0]->w[i].w.chop(1);
                 cet4[0]->w[i].explain =CET_file.readLine();
                 cet4[0]->w[i].explain.chop(1);
                 cet4[0]->w[i].note =CET_file.readLine();
                 cet4[0]->w[i].note.chop(1);
                 cet4[0]->w[i].proficient_value =(CET_file.readLine()).toInt();
             }
     CET_file.close();




     CET_file.setFileName("CET/CET4_E-I.dictionary");
     CET_file.open(QIODevice::ReadOnly);
     for(int i=0;i<5;i++)
     {
     cet4_s[i]=CET_file.readLine();
     }
     cet4[1]=new dat(cet4_s[0],cet4_s[1],cet4_s[2],cet4_s[3],cet4_s[4]);
              qDebug()<<cet4[1]->word_value;
              for(int i=0;i<cet4[1]->word_value;++i)
              {
                  cet4[1]->w[i].w=CET_file.readLine();
                  cet4[1]->w[i].w.chop(1);
                  cet4[1]->w[i].explain =CET_file.readLine();
                  cet4[1]->w[i].explain.chop(1);
                  cet4[1]->w[i].note =CET_file.readLine();
                  cet4[1]->w[i].note.chop(1);
                  cet4[1]->w[i].proficient_value =(CET_file.readLine()).toInt();
              }
      CET_file.close();



      CET_file.setFileName("CET/CET4_J-N.dictionary");
      CET_file.open(QIODevice::ReadOnly);
      for(int i=0;i<5;i++)
      {
      cet4_s[i]=CET_file.readLine();
      }
      cet4[2]=new dat(cet4_s[0],cet4_s[1],cet4_s[2],cet4_s[3],cet4_s[4]);
               qDebug()<<cet4[2]->word_value;
               for(int i=0;i<cet4[2]->word_value;++i)
               {
                   cet4[2]->w[i].w=CET_file.readLine();
                   cet4[2]->w[i].w.chop(1);
                   cet4[2]->w[i].explain =CET_file.readLine();
                   cet4[2]->w[i].explain.chop(1);
                   cet4[2]->w[i].note =CET_file.readLine();
                   cet4[2]->w[i].note.chop(1);
                   cet4[2]->w[i].proficient_value =(CET_file.readLine()).toInt();
               }
       CET_file.close();




       CET_file.setFileName("CET/CET4_O-T.dictionary");
       CET_file.open(QIODevice::ReadOnly);
       for(int i=0;i<5;i++)
       {
       cet4_s[i]=CET_file.readLine();
       }
       cet4[3]=new dat(cet4_s[0],cet4_s[1],cet4_s[2],cet4_s[3],cet4_s[4]);
                qDebug()<<cet4[3]->word_value;
                for(int i=0;i<cet4[3]->word_value;++i)
                {
                    cet4[3]->w[i].w=CET_file.readLine();
                    cet4[3]->w[i].w.chop(1);
                    cet4[3]->w[i].explain =CET_file.readLine();
                    cet4[3]->w[i].explain.chop(1);
                    cet4[3]->w[i].note =CET_file.readLine();
                    cet4[3]->w[i].note.chop(1);
                    cet4[3]->w[i].proficient_value =(CET_file.readLine()).toInt();
                }
        CET_file.close();



        CET_file.setFileName("CET/CET4_U-Z.dictionary");
        CET_file.open(QIODevice::ReadOnly);
        for(int i=0;i<5;i++)
        {
        cet4_s[i]=CET_file.readLine();
        }
        cet4[4]=new dat(cet4_s[0],cet4_s[1],cet4_s[2],cet4_s[3],cet4_s[4]);
                 qDebug()<<cet4[4]->word_value;
                 for(int i=0;i<cet4[4]->word_value;++i)
                 {
                     cet4[4]->w[i].w=CET_file.readLine();
                     cet4[4]->w[i].w.chop(1);
                     cet4[4]->w[i].explain =CET_file.readLine();
                     cet4[4]->w[i].explain.chop(1);
                     cet4[4]->w[i].note =CET_file.readLine();
                     cet4[4]->w[i].note.chop(1);
                     cet4[4]->w[i].proficient_value =(CET_file.readLine()).toInt();
                 }
         CET_file.close();





}

//timerevent事件） 搜索引擎（暂时）
void Widget::timerEvent(QTimerEvent *e)
{

        QString op=ui->find_edit->text()+"\n";
        QString op2=ui->find_edit->text();
//CET文件中寻找单词****************/

      if((op[0]>="a"&&op[0]<="d")||(op[0]>="A"&&op[0]<="d"))
        {
              for(int i=0;i<cet4[0]->word_value;i++)
               {
                  if(cet4[0]->w[i].w==op||cet4[0]->w[i].w==op2||cet4[0]->w[i].explain ==op||cet4[0]->w[i].explain==op2)
                   {
                    ui->show_lab->setText("单词:  "+cet4[0]->w[i].w+"\n解释: "+cet4[0]->w[i].explain+"\n\n\n笔记:  "+cet4[0]->w[i].note);
                    break;
                   }else
                   {
                    ui->show_lab->setText("------------找不到这个单词-----------------\n可能的原因:\n1.大小写错误（模糊查找功能正在开发中）\n2.库中没有该单词，你可以通过下面的编辑，新建\n这个单词的单词库");
                   }
              }
      }else if((op[0]>="e"&&op[0]<="i")||(op[0]>="E"&&op[0]<="I"))
      {
           for(int i=0;i<cet4[1]->word_value;i++)
            {
                if(cet4[1]->w[i].w==op||cet4[1]->w[i].w==op2||cet4[1]->w[i].explain ==op||cet4[1]->w[i].explain==op2)
                {
                 ui->show_lab->setText("单词:  "+cet4[1]->w[i].w+"\n解释: "+cet4[1]->w[i].explain+"\n\n\n笔记:  "+cet4[1]->w[i].note);
                 break;
                }else
                {
                 ui->show_lab->setText("------------找不到这个单词-----------------\n可能的原因:\n1.大小写错误（模糊查找功能正在开发中）\n2.库中没有该单词，你可以通过下面的编辑，新建\n这个单词的单词库");
                }
           }
      }else if((op[0]>="J"&&op[0]<="N")||(op[0]>="j"&&op[0]<="n"))
      {

           for(int i=0;i<cet4[2]->word_value;i++)
            {
                if(cet4[2]->w[i].w==op||cet4[2]->w[i].w==op2||cet4[2]->w[i].explain ==op||cet4[2]->w[i].explain==op2)
                {
                 ui->show_lab->setText("单词:  "+cet4[2]->w[i].w+"\n解释: "+cet4[2]->w[i].explain+"\n\n\n笔记:  "+cet4[2]->w[i].note);
                 break;
                }else
                {
                 ui->show_lab->setText("------------找不到这个单词-----------------\n可能的原因:\n1.大小写错误（模糊查找功能正在开发中）\n2.库中没有该单词，你可以通过下面的编辑，新建\n这个单词的单词库");
                }
           }
      }else if((op[0]>="o"&&op[0]<="t")||(op[0]>="O"&&op[0]<="T"))
      {
           for(int i=0;i<cet4[3]->word_value;i++)
            {
                if(cet4[3]->w[i].w==op||cet4[3]->w[i].w==op2||cet4[3]->w[i].explain ==op||cet4[3]->w[i].explain==op2)
                {
                 ui->show_lab->setText("单词:  "+cet4[3]->w[i].w+"\n解释: "+cet4[3]->w[i].explain+"\n\n\n笔记:  "+cet4[3]->w[i].note);
                 break;
                }else
                {
                 ui->show_lab->setText("------------找不到这个单词-----------------\n可能的原因:\n1.大小写错误（模糊查找功能正在开发中）\n2.库中没有该单词，你可以通过下面的编辑，新建\n这个单词的单词库");
                }
           }
      }else if((op[0]>="U"&&op[0]<="Z")||(op[0]>="u"&&op[0]<="z"))
      {
           for(int i=0;i<cet4[4]->word_value;i++)
            {
                if(cet4[4]->w[i].w==op||cet4[4]->w[i].w==op2||cet4[4]->w[i].explain ==op||cet4[4]->w[i].explain==op2)
                {
                 ui->show_lab->setText("单词:  "+cet4[4]->w[i].w+"\n解释: "+cet4[4]->w[i].explain+"\n\n\n笔记:  "+cet4[4]->w[i].note);
                 break;
                }else
                {
                 ui->show_lab->setText("------------找不到这个单词-----------------\n可能的原因:\n1.大小写错误（模糊查找功能正在开发中）\n2.库中没有该单词，你可以通过下面的编辑，新建\n这个单词的单词库");
                }
           }
      }else if(op[0]=="#")
      {

           if(op=="#look look beautifulgirl 001#\n"){


               ui->hied_show->setStyleSheet("image: url(:/ui/style001.png);");

             } else if(op=="#look look beautifulgirl 002#\n"){


               ui->hied_show->setStyleSheet("image: url(:/ui/002.png);");

             }else  if(op=="#look look beautifulgirl 003#\n"){


               ui->hied_show->setStyleSheet("image: url(:/ui/003.png);");

             }else  if(op=="#look look beautifulgirl 004#\n"){


               ui->hied_show->setStyleSheet("image: url(:/ui/004.png);");

             }


           else if(op=="#delete#\n")
           {
                 del();

           }else if(op=="#look look 大帅哥#\n")
           {

               ui->hied_show->setStyleSheet("image: url(:/ui/me.png);");

           }



      }
/**********************/



/********dat里面找*******/
/*
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

*/

}


void Widget::del()
{
ui->hied_show->setStyleSheet("image: url(:/ui/style091.png);");
}

void Widget::set1()
{

    if(!load_fnish)
    {
    ui->check_color1->setChecked(true);

    }
    ui->find_btn->setStyleSheet("color:rgb(157, 38, 111);font: 75 12pt \"微软雅黑\";");
    ui->test_btn->setStyleSheet("color:rgb(157, 38, 111);font: 75 12pt \"微软雅黑\";");
    ui->top->setStyleSheet("background-color: rgb(235, 185, 255);");
    ui->find_btn->setIcon(QIcon(":/ui/find.png"));
    ui->find_btn->setIconSize(QSize(31,31));
    ui->test_btn->setIcon(QIcon(":/ui/data.png"));
    ui->test_btn->setIconSize(QSize(31,31));
    ui->me_btn->setIcon(QIcon());
    ui->me_btn->setStyleSheet("image:url(:/ui/my.png);");
    ui->set_btn->setIcon(QIcon(":/ui/more.png"));
    ui->set_btn->setIconSize(QSize(20,20));
    addbutton ->setIcon(QIcon(":/ui/blue_add.png"));
    addbutton ->setIconSize(QSize(31,31));
    ui->edit_Box ->setStyleSheet("image:url(:/ui/edit.png);");
    ui->set_ico->setStyleSheet("image:url(:/ui/set.png);");
    ui->color_ico ->setStyleSheet("image:url(:/ui/work.png);");
    ui->en_ico ->setStyleSheet("image:url(:/ui/en.png);");
    ui->about_ico->setStyleSheet("image:url(:/ui/blue_anout.png);");
    ui->name->setStyleSheet("color:rgb(157, 38, 111);font: 75 12pt \"微软雅黑\";");
    ui->soft_v->setStyleSheet("color:rgb(157, 38, 111);font: 75 12pt \"微软雅黑\";");
    ui->check_color1->setStyleSheet("color:rgb(157, 38, 111);font: 75 12pt \"微软雅黑\";");
    ui->check_color2->setStyleSheet("color:rgb(157, 38, 111);font: 75 12pt \"微软雅黑\";");
    ui->cet4_check->setStyleSheet("color:rgb(157, 38, 111);font: 75 12pt \"微软雅黑\";");
    ui->cet6_check->setStyleSheet("color:rgb(157, 38, 111);font: 75 12pt \"微软雅黑\";");
    ui->find_check->setStyleSheet("color:rgb(157, 38, 111);font: 75 12pt \"微软雅黑\";");
    ui->date_show->setStyleSheet("color:rgb(157, 38, 111);font: 75 12pt \"微软雅黑\";");


    load_fnish=true;
}

void Widget::set2()
{
if(!load_fnish){
    ui->check_color2->setChecked(true);

}
ui->find_btn->setStyleSheet("color:#80d5ff;font: 75 12pt \"微软雅黑\";");
ui->test_btn->setStyleSheet("color:#80d5ff;font: 75 12pt \"微软雅黑\";");
ui->top->setStyleSheet("background-color: rgb(128, 213, 255);");
ui->find_btn->setIcon(QIcon(":/ui/blue_find.png"));
ui->find_btn->setIconSize(QSize(31,31));
ui->test_btn->setIcon(QIcon(":/ui/blue_test.png"));
ui->test_btn->setIconSize(QSize(31,31));
ui->me_btn->setIcon(QIcon());
ui->me_btn->setStyleSheet("image:url(:/ui/blue_me.png);");
ui->set_btn->setIcon(QIcon(":/ui/blue_more.png"));
ui->set_btn->setIconSize(QSize(20,20));
addbutton ->setIcon(QIcon(":/ui/blue_add.png"));
addbutton ->setIconSize(QSize(31,31));
ui->edit_Box ->setStyleSheet("image:url(:/ui/blue_edit.png);");
ui->set_ico->setStyleSheet("image:url(:/ui/blue_set.png);");
ui->color_ico ->setStyleSheet("image:url(:/ui/blue_color.png);");
ui->en_ico ->setStyleSheet("image:url(:/ui/blue_en.png);");
ui->about_ico->setStyleSheet("image:url(:/ui/blue_anout.png);");
ui->name->setStyleSheet("color:#80d5ff;font: 75 12pt \"微软雅黑\";");
ui->soft_v->setStyleSheet("color:#80d5ff;font: 75 12pt \"微软雅黑\";");
ui->check_color1->setStyleSheet("color:#80d5ff;font: 75 12pt \"微软雅黑\";");
ui->check_color2->setStyleSheet("color:#80d5ff;font: 75 12pt \"微软雅黑\";");
ui->cet4_check->setStyleSheet("color:#80d5ff;font: 75 12pt \"微软雅黑\";");
ui->cet6_check->setStyleSheet("color:#80d5ff;font: 75 12pt \"微软雅黑\";");
ui->find_check->setStyleSheet("color:#80d5ff;font: 75 12pt \"微软雅黑\";");
ui->date_show->setStyleSheet("color:#80d5ff;font: 75 12pt \"微软雅黑\";");
    load_fnish=true;
}
