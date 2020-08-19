#include "Dic.h"
#include"color.h"
Dic::Dic(string filename)
{
	up_data(filename);
}

void Dic::up_data(string filename)
{
	name = filename;

	fstream dicfile;
	dicfile.open("C:\\DIC_dat\\" + filename, ios::in);

	if (dicfile.is_open())//成功打开
	{
		dicfile.close();
		dicfile.open("C:\\DIC_dat\\" + filename, ios::in);
		
		string temp;
		dicfile >> temp;
		//cout << "表头" << temp;
		if (temp == "$")
		{
			//cout << "找到标头,检测到这是一个新单词本\n";
			//去掉标头
			dicfile << " ";
			//初始化单词本单词数据
			max_word = 0;
			dat = new Dat[max_word];
			//写入数据到单词本文件
			save();
		}
		else
		{
			//从单词本文件中提取数据
			read_data();
		}
		dicfile.close();
	}
	else
	{
		//打开失败(提示创建此单词本文件，数据归空)
		//初始化单词本单词数据
			//写入数据到单词本文件
	}

}




Dic::~Dic()
{

	delete[] dat;
}

void Dic::show_all()
{

	setcolor(0x79);
	cout << "单词本名称:" << name<< "\t单词个数:"<<max_word<<endl;

	cout <<"单词ID\t单词名称\t\t单词解释\t\n" ;
	for(int i = 0; i<max_word;++i)
	{ 
		if (i % 2 == 0)setcolor(0x17); else setcolor(0x37);

		cout<<dat[i].word_id <<"\t"<< dat[i].word <<"\t\t\t"<< dat[i].explain <<"\t\n";
		
	}
	setcolor(0x07);
}



void Dic::save()
{
	fstream dicfile;
	dicfile.open("C:\\DIC_dat\\" +name,ios::out);
	dicfile << name<<endl;//单词本名称
	dicfile << max_word << endl;//单词本单词个数
	for (int i=0;i<max_word;++i)
	{
		dicfile << dat[i].word_id<<endl;//ID
		dicfile << dat[i].word<<endl;//单词
		dicfile << dat[i].explain<<endl;//解释
	}
	dicfile.close();
}


void Dic::ins_word()
{
	int temp;
		cin >> temp;
		if (temp>=0&&temp<max_word)
		{
			string word,explain;
			
			cin >> word>>explain;
			if (word == "*"||explain=="*")
			{
				if (explain == "*")
				{
					dat[temp].word = word;
				}else  if (word == "*")
				{
					dat[temp].explain = explain;
				}

			}else{
			dat[temp].explain = explain;
			dat[temp].word = word;
			}

        	save();
    	}


}



void Dic::new_word()
{

	Dat *temp=new Dat[max_word];
	for (int i=0;i<max_word;++i)
	{	temp[i].word_id = dat[i].word_id;
		temp[i].word = dat[i].word;
		temp[i].explain= dat[i].explain;
	}
	delete[] dat;
	dat = new Dat[max_word+1];
	string cas;



	cin>>dat[max_word].word;

	cin >> dat[max_word].explain;

	dat[max_word].word_id = max_word;
	max_word++;
	for (int i = 0; i < max_word-1;++i)
	{
		dat[i].word_id = temp[i].word_id ;
		dat[i].word = temp[i].word;
		dat[i].explain = temp[i].explain;
	}
	save();
	delete[] temp;

}

void Dic::show_numbe()
{
	int x, y;
	cin >> x;
	cin >> y;
	if (x >=max_word  )x=max_word -1;
	if (y >= max_word)y = max_word - 1;
	if (x > y) { x += y; y = x - y; x -= y; };
         setcolor(0x79);
	cout << "单词ID\t单词名称\t单词解释\n";
		for (int i=x;i<=y;++i)
	{
			if (i % 2 == 0)setcolor(0x17); else setcolor(0x37);
			cout << dat[i].word_id << "\t" << dat[i].word << "\t\t\t\t" << dat[i].explain << "\t\n";

	}
		setcolor(0x07);
}

void Dic::del_word()
{

	int id;
	cin >> id;
	if (id > max_word - 1 || id < 0)return;

	for (int i=id;i<max_word-1;++i)
	{
		dat[i].word = dat[i + 1].word;
		dat[i].explain = dat[i + 1].explain;
		dat[i].word_id = i;
	}
	max_word--;
	save();
}

void Dic::read_data()
{
	fstream dicfile;
	dicfile.open("C:\\DIC_dat\\" + name, ios::in);
	dicfile >> name;
	dicfile >> max_word;
	dat = new Dat[max_word];
	for (int i = 0; i < max_word; ++i)
	{
		dicfile >>dat[i].word_id;//ID
		dicfile >> dat[i].word ;//单词
		dicfile >> dat[i].explain;//解释
		
	}
	dicfile.close();
}