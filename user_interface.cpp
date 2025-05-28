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
	cout << "欢迎来到广外校园导航系统" << endl;
	cout << "1，开始" << endl;
	cout << "2，项目介绍" << endl;
	cout << "3，开发人员介绍" << endl;
	cout << "4，退出程序" << endl;
	while (cin)
	{
		cout << "请输入选择（数字 1-4 ）：";
		int choice;
		cin >> choice;
		cout << endl;
		if (!cin)
		{
			cout << "无效输入，请重新输入！" << endl;
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
				cout << "祝您生活愉快！" << endl;
				return;

			default:
				cout << "无效输入，请重新输入！" << endl;
				continue;
			}
		}
	}
}

void UI_functionmenu()
{
	printmap();

	cout << "请选择功能服务" << endl;
	cout << "1，地图查询" << endl;
	cout << "2，导航" << endl;
	cout << "3，退出" << endl;
	while (cin)
	{
		cout << "请输入选择（数字 1-3 ）：";
		int choice;
		cin >> choice;
		cout << endl;
		if (!cin)
		{
			cout << "无效输入，请重新输入！" << endl;
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
				cout << "无效输入，请重新输入！" << endl;
				continue;
			}
		}
	}
}


