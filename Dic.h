#pragma once
#include<string>
#include"Dat.h"
#include<iostream>
#include<fstream>
using namespace::std;


class Dic
{



public:
	
	Dic(string filename);
	~Dic();



/*单词本信息*/
	int max_word;//单词数
	string name;//单词名称（和文件相同）
/*数据,单词*/
	Dat *dat;

	/*功能*/
	void show_all();//显示单词本所有信息
	void find_word();//按单词查找单词
	void  ins_word();//修改单词
	void new_word();//新建单词
	void show_numbe();//显示一个区间的单词
	void del_word();
	void swich_word();//交换两个单词
	void sort();
	/*核心模块*/
	void read_data();
	void save();//保存数据

	void up_data(string filename);//打开新单词本


};

