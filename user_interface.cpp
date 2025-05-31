#include "user_interface.h"
#include "campus_map.h"
#include "path_finding.h"
#include "navigation.h"
#include "style.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <windows.h> // Windows �ض�ͷ�ļ�
#include <limits>
#include <ctime>
using std::string;
using std::cout;
using std::endl;
using std::cin;

// ������������ȡ����֤�˵�ѡ��
int get_menu_choice(int min, int max) {
    int choice;
    while (true) {
        set_text_color(FOREGROUND_GREEN);
        cout << "������ѡ�� ���� " << min << "-" << max << " ����";
        reset_text_color(); // ������ɫ
        if (cin >> choice && choice >= min && choice <= max) {
            cin.ignore(); // ��������
            cout << endl;
            return choice;
        }
        else {
            set_text_color(FOREGROUND_GREEN);
            cout << "��Ч���룡" << endl;
            reset_text_color();
            cin.clear();
            cin.ignore();
        }
    }
}

void UI_Start()
{

    while (true) {
        cout << "��ӭ��������У԰����ϵͳ" << endl;
        cout << "1����ʼ" << endl;
        cout << "2����Ŀ����" << endl;
        cout << "3��������Ա����" << endl;
        cout << "4���˳�����" << endl;
        int choice = get_menu_choice(1, 4);
        switch (choice) {
        case 1:
            system("cls");
            set_text_color(FOREGROUND_GREEN);
            cout << "��ͼ��ʼ����" << endl;
            creatgraph();
            //loading_screen();
            cout << "��ͼ������ɣ�" << endl;
            reset_text_color();
            sleep();
            system("cls");
            UI_functionmenu();
            break;
        case 2:
            cout << "��Ŀ���ܣ�����У԰����ϵͳ������ѧ�������ҵ�У԰�����·����" << endl;
            sleep();
            break;
        case 3:
            cout << "������Ա��" << endl;
            sleep();
            break;
        case 4:
            cout << "��лʹ�ã��ټ���" << endl;

            return;
        }
    }
}

void UI_functionmenu()
{
    while (true) {
        printmap();
        cout << "��ѡ���ܷ���" << endl;
        cout << "1����ͼ��ѯ" << endl;
        cout << "2��У԰����" << endl;
        cout << "3���˳�" << endl;

        int choice = get_menu_choice(1, 3);
        switch (choice) {
        case 1:
            system("cls");
            UI_findmenu();
            break;
        case 2:
            system("cls");
            UI_navichoose();
            break;
        case 3:
            system("cls");
            return;
        }
    }
}

void UI_findmenu()
{
    while (true) {
        printmap();
        cout << "��ӭ��������У԰����ϵͳ" << endl;
        cout << "1������ڽӾ���" << endl;
        cout << "2������ڽӱ�" << endl;
        cout << "3������У԰" << endl;
        cout << "4����ѯ��㵽ָ���ص�����·��" << endl;
        cout << "5����ѯ��㵽���еص�����·��" << endl;
        cout << "6���˳�" << endl;

        int choice = get_menu_choice(1, 6);
        if (choice == 6)
        {
            system("cls");
            return;
        }
        switch (choice) {
        case 1:
            print_adjm();
            cout << endl;
            sleep();
            system("cls");
            break;
        case 2:
            print_adjl();
            cout << endl;
            sleep();
            system("cls");
            break;
        case 3:
        {
            string start;
            cout << "��������㣨�����в�Ҫ�пո񣩣�";
            getline(cin, start);
            int start_index = find_index(start);
            if (start_index == 0) {
                cout << "��Ч����㣡" << endl;           
                sleep();
                system("cls");
                break;
            }
            travel(start_index);
            sleep();
            system("cls");
            break;
        }
        case 4:
        {
            string start, end;
            cout << "��������㣨�����в�Ҫ�пո񣩣�";
            getline(cin, start);
            int start_index = find_index(start);
            if (start_index == 0) {
                cout << "��Ч����㣡" << endl;
                sleep();
                system("cls");
                break;
            }
            cout << "�������յ㣨�����в�Ҫ�пո񣩣�";
            getline(cin, end);
            int end_index = find_index(end);
            if (end_index == 0) {
                cout << "��Ч���յ㣡" << endl;
                sleep();
                system("cls");
                break;
            }
            print_path_start_end(start_index, end_index);
            sleep();
            system("cls");
            break;
        }
        case 5:
        {
            string start;
            cout << "��������㣺";
            getline(cin, start);
            int start_index = find_index(start);
            if (start_index == 0) {
                cout << "��Ч����㣡" << endl;
                sleep();
                system("cls");
                break;
            }
            print_all_paths_from(start_index);
            sleep();
            system("cls");
            break;
        }
        }
    }
}

// ��ʾ���ض���
void loading_screen()
{
    set_text_color(FOREGROUND_GREEN);
    // ��ʼ��������ӣ�������� main()�������Ϊ��ʾ��
    srand(static_cast<unsigned int>(time(0)));

    // ���ѡ�� 1 �� 5 �����ʱ
    int delay_seconds = rand() % 5 + 1; // 1 �� 5 ��������
    std::cout << "�����У����Ժ�..." << std::endl;

    // ����תȦ�ַ�����
    const char* spinner = "-\\|/"; // תȦ�ַ�
    int spinner_len = 4; // �ַ�����

    // ģ����ʱ����ʾתȦ����
    for (int i = 0; i < delay_seconds * 4; i++) { // ÿ����ת 4 ��
        std::cout << "\r" << spinner[i % spinner_len] << std::flush; // ʹ�� \r �������ף���ʾ�����ַ�
        Sleep(250); // Windows �� 250 ������ʱ
    }
    std::cout << "\r "; // ������һ���ַ�
    std::cout << std::endl; // ����
    reset_text_color();
}

void sleep()
{
    set_text_color(FOREGROUND_GREEN);
    cout << "�밴 ENTER ������" << endl;
    reset_text_color();
    getchar();
}

void UI_navichoose()
{
    while (true) {
        cout << "��ѡ���ܷ���" << endl;
        cout << "1����ʼ����" << endl;
        cout << "2�����а�" << endl;
        cout << "3���˳�" << endl;

        int choice = get_menu_choice(1, 3);
        switch (choice) {
        case 1:
            system("cls");
            UI_navigation();
            system("cls");
            break;
        case 2:
            system("cls");
            creatrank(steps);
            printrank();
            sleep();
            system("cls");
            break;
        case 3:
            system("cls");
            return;
        }
    }
}

void UI_navigation()
{
    string start, end;
    int start_index, end_index;
    while (true)
    {
        system("cls");
        printmap();
        cout << "��������㣨�����в�Ҫ�пո񣩣�";
        getline(cin, start);
        start_index = find_index(start);
        if (start_index == 0) {
            cout << "��Ч����㣡" << endl;
            sleep();
            system("cls");
            return;
        }
        cout << "�������յ㣨�����в�Ҫ�пո񣩣�";
        getline(cin, end);
        end_index = find_index(end);
        if (end_index == 0) {
            cout << "��Ч���յ㣡" << endl;
            sleep();
            system("cls");
            return;
        }
        break;
    }
    cur = start_index;
    while (true)
    {
        system("cls");
        printmap();
        print_recommend(start_index, end_index);
        print_intro(cur);
        print_total_step();
        printchoices(cur);
        if (!go())
        {
            return;
        }
    }
}
