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

	if (dicfile.is_open())//�ɹ���
	{
		dicfile.close();
		dicfile.open("C:\\DIC_dat\\" + filename, ios::in);
		
		string temp;
		dicfile >> temp;
		//cout << "��ͷ" << temp;
		if (temp == "$")
		{
			//cout << "�ҵ���ͷ,��⵽����һ���µ��ʱ�\n";
			//ȥ����ͷ
			dicfile << " ";
			//��ʼ�����ʱ���������
			max_word = 0;
			dat = new Dat[max_word];
			//д�����ݵ����ʱ��ļ�
			save();
		}
		else
		{
			//�ӵ��ʱ��ļ�����ȡ����
			read_data();
		}
		dicfile.close();
	}
	else
	{
		//��ʧ��(��ʾ�����˵��ʱ��ļ������ݹ��)
		//��ʼ�����ʱ���������
			//д�����ݵ����ʱ��ļ�
	}

}




Dic::~Dic()
{

	delete[] dat;
}

void Dic::show_all()
{

	setcolor(0x79);
	cout << "���ʱ�����:" << name<< "\t���ʸ���:"<<max_word<<endl;

	cout <<"����ID\t��������\t\t���ʽ���\t\n" ;
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
	dicfile << name<<endl;//���ʱ�����
	dicfile << max_word << endl;//���ʱ����ʸ���
	for (int i=0;i<max_word;++i)
	{
		dicfile << dat[i].word_id<<endl;//ID
		dicfile << dat[i].word<<endl;//����
		dicfile << dat[i].explain<<endl;//����
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
	cout << "����ID\t��������\t���ʽ���\n";
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
		dicfile >> dat[i].word ;//����
		dicfile >> dat[i].explain;//����
		
	}
	dicfile.close();
}