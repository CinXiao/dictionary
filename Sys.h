#pragma once
#include<iostream>
#include<string>
#include"Sys_dat.h"
#include<fstream>
#include<Windows.h>
using namespace::std;
class Sys
{
public:

	bool judge(string fliename);//判断是否有同名单词本
	void pr();//打印文件表c初始化界面
	bool newdic_file(string dicfile_name);//新建单词本文件
	bool newdic_dat();//新建单词本数据 new功能模块
	bool opendic();//打开单词本 open功能模块


	void delete_file();//删除文件
	void save_sys();//保存SYS文件 
     bool readfile();//读取文件

	 void select_function(int i);//选择输入功能（用户交互核心模块）


	int nowdic_id;
	string nowdic_name;

	int dic_max;
	Sys_dat *dat;
	Sys(string sysfile);
	~Sys();
};

