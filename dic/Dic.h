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



/*���ʱ���Ϣ*/
	int max_word;//������
	string name;//�������ƣ����ļ���ͬ��
/*����,����*/
	Dat *dat;

	/*����*/
	void show_all();//��ʾ���ʱ�������Ϣ
	void find_word();//�����ʲ��ҵ���
	void  ins_word();//�޸ĵ���
	void new_word();//�½�����
	void show_numbe();//��ʾһ������ĵ���
	void del_word();
	void swich_word();//������������
	void sort();
	/*����ģ��*/
	void read_data();
	void save();//��������

	void up_data(string filename);//���µ��ʱ�


};

