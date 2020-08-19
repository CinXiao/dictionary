#include"Dic.h"
#include"Sys.h"
#include"color.h"
#include<sstream>
using namespace::std;
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
		if (cas == "show-num")dic.show_numbe();//显示一个区间的单词
		if (cas == "ins-word")dic.ins_word();//修改单词信息
		if (cas == "delete-dic")sys.delete_file();//删除单词本文件
		if (cas == "delete-word")dic.del_word();//删除单词


		setcolor(0x97);
	}




	dic.save();//单词本文件保存
	sys.save_sys();//系统文件保存
}




