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
	cout << "��ǰһ���У�";
	setcolor(0X0c);
	cout << dic_max;
	setcolor(0x0a);
	cout << "���ʱ�\n";
	setcolor(0x07);



	cout << "���ʱ�ID\t���ʱ�����\n";
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
						cout << "new:�½����ʱ�\n";
						setcolor(0x37);
						cout << "quit:�˳�\n";
					}
					else {
							setcolor(0x17);
						cout << "*open:�򿪵��ʱ�\t";	setcolor(0x37);
						cout << "*new:�½����ʱ�\t";	setcolor(0x17);
						cout << "*delete:ɾ�����ʱ�\t";	setcolor(0x37);
						cout << "*quit:�˳�\t\n";	setcolor(0x07);
					}










}

bool Sys::newdic_file(string dicfile_name)
{
	fstream dicfile;
	dicfile.open("C:\\DIC_dat\\"+dicfile_name,ios::out);
	dicfile << "$"<<endl;//д��ͷ���ַ�������DIC����
	if (dicfile.is_open())
	{
		cout << "���ʱ��ļ��������";
		return true;
	}
	else
	{

		cout << "���ʱ��ļ�����ʧ��";
		return false;
	}


}

bool Sys::newdic_dat()
{
	string tempsname;
	cout << "�����뵥�ʱ�����:";
	cin >> tempsname;
	if (!judge(tempsname))
	{
		
		MessageBox(0,TEXT("��ʾ"),TEXT("��⵽����DIC"),MB_OK);
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


	string dic_n;//ʵ���У�ͨ������һ���ַ���ϵͳ�Զ��ж���DIC���ƻ���DIC ID�ţ�Ȼ���DIC�ļ�


	string cas ;
	cin >> cas;
	int i;
	for (i=0;i<dic_max;++i)
	{
		if (dat[i].name == cas)break;
		if (i == (dic_max - 1))
		{
			cout << "δ�ҵ��ļ�" << endl;
			return false;
		}
		}
	

	cout << "�Ѿ��򿪵��ʱ�:"<<cas<<endl;
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
	file <<dic_max<<endl;//�����ļ�����
	for (int i = 0; i < dic_max; ++i)//����д���ڴ�
	{
		
		file << dat[i].id<<endl;
		file << dat[i].name << endl;
	}

	file.close();



}

bool Sys::readfile()
{
	fstream file;
	file.open("C:\\DIC_dat\\sys.s", ios::in);//��ϵͳ�����ļ����ļ���
	if (file.is_open())//�򿪳ɹ���ȡ����
	{

	
		file >> dic_max;//��ȡ�ļ�����
		dat = new Sys_dat[dic_max];//�����ڴ�
		for (int i = 0; i < dic_max; ++i)//����д���ڴ�
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
			newdic_dat();//��ʾ���뵥�ʱ���Ϣ
			newdic_file(dat[dic_max - 1].name);//�������ʱ��ļ�
			save_sys();//��������
		}
		if (cas == "open" || cas == "OPEN")
		{
			if(opendic())	break;//����ID�Ŵ򿪶�Ӧ�����ļ�
		
		}if (cas == "delete-dic" || cas == "delete-dic")delete_file();
		system("cls");
		pr();
		cin >> cas;
	}



}



Sys::Sys(string sysfile)
{
	if (readfile())//�򿪳ɹ���ȡ����
	{
		setcolor(0x47);
		cout << "��ӭʹ�ã�ϵͳ��������\n";
		setcolor(0x07);
	}
	else//��ʧ�ܣ���һ��ʹ�ã�����Ĭ������,д��ϵͳ�ļ���
	{
		fstream file;
		system("NO");
		system("md C:\\DIC_dat");
		file.open("C:\\DIC_dat\\sys.s", ios::out);
		dic_max = 0;
		file << dic_max<<endl;
		file.close();
	}

	select_function(0);//��ʼ�˵�����ģ�飨�û�ѡ�񽻻���

}



Sys::~Sys()
{
}



