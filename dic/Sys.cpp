#include "Sys.h"
#include"color.h"
bool Sys::judge(string filename)
{

	for (int i=0;i<dic_max;++i)
	{
		if (dat[i].name == filename)	return false;;
	}
	return true;

}

void Sys::pr()
{
	cout << "当前一共有：";
	setcolor(0X0c);
	cout << dic_max;
	setcolor(0x0a);
	cout << "单词本\n";
	setcolor(0x07);



	cout << "单词本ID\t单词本名称\n";
	for(int i=0;i<dic_max;++i)
	{
		if (i % 2 == 0)setcolor(0x70); else setcolor(0x87);
		cout <<"   "<<dat[i].id<<"\t\t"<<dat[i].name<<"\t\t\n" ;
	}
	setcolor(0x07);
	cout << "\n\n";



						if (dic_max==0)
					{
							setcolor(0x17);
						cout << "new:新建单词本\n";
						setcolor(0x37);
						cout << "quit:退出\n";
					}
					else {
							setcolor(0x17);
						cout << "*open:打开单词本\t";	setcolor(0x37);
						cout << "*new:新建单词本\t";	setcolor(0x17);
						cout << "*delete:删除单词本\t";	setcolor(0x37);
						cout << "*quit:退出\t\n";	setcolor(0x07);
					}










}

bool Sys::newdic_file(string dicfile_name)
{
	fstream dicfile;
	dicfile.open("C:\\DIC_dat\\"+dicfile_name,ios::out);
	dicfile << "$"<<endl;//写入头标字符，方便DIC类检查
	if (dicfile.is_open())
	{
		cout << "单词本文件创建完成";
		return true;
	}
	else
	{

		cout << "单词本文件创建失败";
		return false;
	}


}

bool Sys::newdic_dat()
{
	string tempsname;
	cout << "请输入单词本名称:";
	cin >> tempsname;
	if (!judge(tempsname))
	{
		
		MessageBox(0,TEXT("提示"),TEXT("检测到重名DIC"),MB_OK);
		return false;
	}

	Sys_dat *temp = new Sys_dat[dic_max];
	for (int i = 0; i < dic_max; ++i)
	{
		temp[i].id = dat[i].id;
		temp[i].name = dat[i].name;
	}
	delete[] dat;
	dat = new Sys_dat[dic_max + 1];
	for (int i = 0; i < dic_max; ++i)
	{
		dat[i].id = temp[i].id;
		dat[i].name = temp[i].name;
	}
	delete[] temp;
 dat[dic_max].name=tempsname;
	dat[dic_max].id = dic_max;
	cout << dat[dic_max].id << ":" << dat[dic_max].name;
	dic_max++;
	return false;
}

bool Sys::opendic()
{


	string dic_n;//实验中，通过输入一个字符，系统自动判断是DIC名称还是DIC ID号，然后打开DIC文件


	string cas ;
	cin >> cas;
	int i;
	for (i=0;i<dic_max;++i)
	{
		if (dat[i].name == cas)break;
		if (i == (dic_max - 1))
		{
			cout << "未找到文件" << endl;
			return false;
		}
		}
	

	cout << "已经打开单词本:"<<cas<<endl;
	nowdic_id = i;
	nowdic_name =cas;
	return true;
}

void Sys::delete_file()
{
	cout << "asd";
	string filename;
	cin >> filename;
	int i;
	for (i=0;i<dic_max;++i)
	{
		if (dat[i].name == filename)break;
		if (i == dic_max - 1)return;
	}

	for (int t=i;t<dic_max-1;++t)
	{
		dat[t].name = dat[t + 1].name;
		dat[t].id = t;
	}
	dic_max--;

	save_sys();


}

void Sys::save_sys()
{
	fstream file;
	file.open("C:\\DIC_dat\\sys.s",ios::out);
	file <<dic_max<<endl;//更新文件个数
	for (int i = 0; i < dic_max; ++i)//数据写入内存
	{
		
		file << dat[i].id<<endl;
		file << dat[i].name << endl;
	}

	file.close();



}

bool Sys::readfile()
{
	fstream file;
	file.open("C:\\DIC_dat\\sys.s", ios::in);//打开系统设置文件（文件表）
	if (file.is_open())//打开成功提取数据
	{

	
		file >> dic_max;//获取文件个数
		dat = new Sys_dat[dic_max];//分配内存
		for (int i = 0; i < dic_max; ++i)//数据写入内存
		{
			file >> dat[i].id;
			file >> dat[i].name;
		}

		file.close();
		return true;
	}
	return false;
}

void Sys::select_function(int i)
{
	string cas;
	pr();
	cin >> cas;
	while (1)
	{
		if (cas == "quit"||cas=="QYIT")exit(0);
		if (cas == "new" || cas == "NEW")
		{
			newdic_dat();//提示输入单词本信息
			newdic_file(dat[dic_max - 1].name);//创建单词本文件
			save_sys();//保存数据
		}
		if (cas == "open" || cas == "OPEN")
		{
			if(opendic())	break;//输入ID号打开对应单词文件
		
		}if (cas == "delete-dic" || cas == "delete-dic")delete_file();
		system("cls");
		pr();
		cin >> cas;
	}



}



Sys::Sys(string sysfile)
{
	if (readfile())//打开成功提取数据
	{
		setcolor(0x47);
		cout << "欢迎使用，系统运行正常\n";
		setcolor(0x07);
	}
	else//打开失败（第一次使用，创建默认属性,写入系统文件表）
	{
		fstream file;
		system("NO");
		system("md C:\\DIC_dat");
		file.open("C:\\DIC_dat\\sys.s", ios::out);
		dic_max = 0;
		file << dic_max<<endl;
		file.close();
	}

	select_function(0);//开始菜单功能模块（用户选择交互）

}



Sys::~Sys()
{
}



