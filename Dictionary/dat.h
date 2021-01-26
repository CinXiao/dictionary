#ifndef DAT_H
#define DAT_H

#include"QString"
#include "word.h"

class dat
{
public:
   dat(QString s1,QString s2,QString s3,QString s4,QString s5);

word *w;
int word_value;
QString sys[5];//系统属性值

void addword(QString word,QString explain,QString note);//初始化


void new_dat();//给w分配内存




};

#endif // DAT_H
