#include"user_interface.h"
#include"campus_map.h"
#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::endl;
using std::cin;

void UI_Start()
{
	cout << "��ӭ��������У԰����ϵͳ" << endl;
	cout << "1����ʼ" << endl;
	cout << "2����Ŀ����" << endl;
	cout << "3��������Ա����" << endl;
	cout << "4���˳�����" << endl;
	while (cin)
	{
		cout << "������ѡ������ 1-4 ����";
		int choice;
		cin >> choice;
		cout << endl;
		if (!cin)
		{
			cout << "��Ч���룬���������룡" << endl;
			cin.ignore();
			continue;
		}
		else
		{
			switch (choice)
			{
			case 1:
				//cls();
				UI_functionmenu();
				break;
			case 2:
				break;


			case 3:


			case 4:
				cout << "ף��������죡" << endl;
				return;

			default:
				cout << "��Ч���룬���������룡" << endl;
				continue;
			}
		}
	}
}

void UI_functionmenu()
{
	printmap();

	cout << "��ѡ���ܷ���" << endl;
	cout << "1����ͼ��ѯ" << endl;
	cout << "2������" << endl;
	cout << "3���˳�" << endl;
	while (cin)
	{
		cout << "������ѡ������ 1-3 ����";
		int choice;
		cin >> choice;
		cout << endl;
		if (!cin)
		{
			cout << "��Ч���룬���������룡" << endl;
			cin.ignore();
			continue;
		}
		else
		{
			switch (choice)
			{
			case 1:
			{
			
				break;
			}
			case 2:

				break;
			case 3:
				//cls();
				return;

			default:
				cout << "��Ч���룬���������룡" << endl;
				continue;
			}
		}
	}
}


