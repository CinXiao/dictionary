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

	bool judge(string fliename);//�ж��Ƿ���ͬ�����ʱ�
	void pr();//��ӡ�ļ���c��ʼ������
	bool newdic_file(string dicfile_name);//�½����ʱ��ļ�
	bool newdic_dat();//�½����ʱ����� new����ģ��
	bool opendic();//�򿪵��ʱ� open����ģ��


	void delete_file();//ɾ���ļ�
	void save_sys();//����SYS�ļ� 
     bool readfile();//��ȡ�ļ�

	 void select_function(int i);//ѡ�����빦�ܣ��û���������ģ�飩


	int nowdic_id;
	string nowdic_name;

	int dic_max;
	Sys_dat *dat;
	Sys(string sysfile);
	~Sys();
};

