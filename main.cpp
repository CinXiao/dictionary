#include"Dic.h"
#include"Sys.h"
#include"color.h"
#include<sstream>

using namespace::std;

void help();



int main()
{
	Sys sys("sys");//系统初始化界面（单词本选择）
	Dic dic(sys.nowdic_name);//打开的单词本
	string cas="0xffff";
	while (cas!="quit")
	{
	
		cin >> cas;
		setcolor(0x07);
		if (cas == "home"|| cas == "HOME")sys.pr();
		if (cas == "quit"||cas=="QUIT"||cas=="EXIT"||cas=="exit")exit(0);
		if (cas == "open"||cas=="OPEN")
		{
			if(sys.opendic()) 
			{ 
				dic.up_data(sys.nowdic_name);//重新更新dic类
			}
			
		}
		if (cas == "add")dic.new_word();//添加单词
		if (cas == "show-all")dic.show_all();//显示全部单词
		if (cas == "show-number")dic.show_numbe();//显示一个区间的单词
		if (cas == "ins-word")dic.ins_word();//修改单词信息
		if (cas == "delete-dic")sys.delete_file();//删除单词本文件
		if (cas == "delete-word")dic.del_word();//删除单词
		if (cas == "switch")dic.swich_word();//删除单词
		if (cas == "sort")dic.sort();//排序单词


		if (cas == "help" || cas == "?")help();//帮助文字
		if (cas == "-*" || cas == "-*")system("cls");//清屏
		setcolor(0x97);
	}




	dic.save();//单词本文件保存
	sys.save_sys();//系统文件保存
}


void help() 
{
	setcolor(0x0a);
	cout << "O(∩_∩)O this is the help file\n"<<endl;
	cout << "open  \"词典名称\" : 打开一个词典文件\n" << endl;
	cout << "sort:对单词排序（只有打开词典文件后才可以进行这一条指令\n" << endl;
	cout << "show-all:显示所有单词\n" << endl;
	cout << "show-number X  Y:显示区间X到Y的所有单词\n" << endl;
	cout << "switch X Y:交换ID是X和Y的两个单词信息\n" << endl;
	cout << "add \"单词名称\"  \"单词解释\"：添加单词指令\n" << endl;
	cout << "delete-word  \"ID\"：删除指定ID的单词信息\n" << endl;
	setcolor(0x97);
}

