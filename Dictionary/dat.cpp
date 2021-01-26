#include "dat.h"

dat::dat(QString s1,QString s2,QString s3,QString s4,QString s5)
{

sys[0]=s1;
word_value=s2.toInt();
sys[1]=s2;
sys[2]=s3;
sys[3]=s4;
sys[4]=s5;
new_dat();


}





void dat::new_dat()
{
  w=new word[word_value];
}






void  dat::addword(QString ws,QString es,QString ns)
{
   word *temp=new word[word_value];

for(int i=0;i<word_value;++i)
{
  if(w[i].w==ws)
  {
    w[i].explain=es;
    w[i].note=ns;
    return;
  }
}




    for(int i=0;i<word_value;++i)
    {
        temp[i].w=w[i].w;
        temp[i].explain=w[i].explain;
        temp[i].note=w[i].note;
        temp[i].proficient_value=w[i].proficient_value;
    }

    word_value++;

    sys[1]=QString("%1").arg(word_value);
    w=new word[word_value];
    for(int i=0;i<word_value-1;++i)
    {
        w[i].w=temp[i].w;
        w[i].explain=temp[i].explain;
        w[i].note= temp[i].note;
        w[i].proficient_value=temp[i].proficient_value;
    }
 delete[] temp;
    w[word_value-1].w=ws;
    w[word_value-1].explain=es;
    w[word_value-1].note=ns;
    w[word_value-1].proficient_value=0;//熟练度默认为0



}
