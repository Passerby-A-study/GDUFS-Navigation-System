#include "user_interface.h"
#include "campus_map.h"
#include "path_finding.h"
#include "navigation.h"
#include "style.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <windows.h>
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
        set_text_color(FOREGROUND_YELLOW); // ��ɫ��ʾ
        cout << "������ѡ�� ���� " << min << "-" << max << " ����";
        reset_text_color();
        if (cin >> choice && choice >= min && choice <= max) {
            cin.ignore();
            cout << endl;
            return choice;
        }
        else {
            set_text_color(FOREGROUND_YELLOW); // ��ɫ������ʾ
            cout << "��Ч���룡" << endl;
            reset_text_color();
            cin.clear();
            cin.ignore();
        }
    }
}

void UI_Start() {
    while (true) {
        set_text_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); // ������ɫ
        cout << "��ӭ��������У԰����ϵͳ" << endl;
        cout << "1����ʼ" << endl;
        cout << "2����Ŀ����" << endl;
        cout << "3��������Ա����" << endl;
        cout << "4���˳�����" << endl;
        reset_text_color();
        int choice = get_menu_choice(1, 4);
        switch (choice) {
        case 1:
            system("cls");
            set_text_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); // ����ɫ��ʾ
            cout << "��ͼ��ʼ����" << endl;
            loading_screen();
            creatgraph();
            cout << "��ͼ������ɣ�" << endl;
            reset_text_color();
            sleep();
            system("cls");
            UI_functionmenu();
            break;
        case 2:
            set_text_color(FOREGROUND_LIGHT_SKY); // ������ɫ
            cout << "����У԰����ϵͳ - ��Ŀ����" << endl;
            cout << "----------------------------------------" << endl;
            cout << "��ϵͳרΪ�㶫������ó��ѧ�����⣩ʦ����ƣ�" << endl;
            cout << "ּ�ڰ��������١���ݵ���У԰���ҵ�����·����" << endl;
            cout << "��������Ѱ�ҽ�ѧ¥�����ᡢͼ��ݣ����Ǽƻ�" << endl;
            cout << "һ�λ���У԰���ọ́����Ƕ���Ϊ���ṩ��Ч�ĵ�������" << endl;
            cout << endl;
            cout << "���Ĺ��ܣ�" << endl;
            cout << "- ��ͼ��ѯ���鿴У԰���ڽӾ�����ڽӱ�" << endl;
            cout << "- ���·���滮�����������յ㣬��ȡ���·����" << endl;
            cout << "- ����У԰�����������̽�����еص㡣" << endl;
            cout << "- ʵʱ��������̬��ʾ·���Ϳ�ѡ�ص㡣" << endl;
            cout << "- ���а񣺼�¼�����������˱�ƴ����·�ߣ�" << endl;
            cout << endl;
            cout << "��Ŀ���㣺" << endl;
            cout << "- �û��Ѻã����Ľ�����ƣ������ʵ��Ӿ��������ʹ�����顣" << endl;
            cout << "- ��Ч�㷨������ͼ���㷨��ȷ��·���滮��׼��Ч��" << endl;
            cout << "- ���Ի����飺֧��ʵʱ��������ʱ�鿴�ص��飬̽��У԰�Ļ���" << endl;
            cout << endl;
            cout << "���ǵ�Ŀ�꣺" << endl;
            cout << "ͨ����������У԰�����ÿһλ����ʦ����������̽��У԰�����ܱ�ݵĵ������飬ͬʱ����У԰�������������" << endl;
            cout << endl;
            cout << "������ʼ����У԰֮�ðɣ�" << endl;
            cout << "----------------------------------------" << endl;
            reset_text_color();
            sleep();
            system("cls");
            break;
        case 3:
            set_text_color(FOREGROUND_LIGHT_SKY); // ������ɫ
            cout << "----------------------------------------" << endl;
            cout << "������Ա��" << endl
                <<"�����ˣ����Ӻ�"<<endl
                <<"ͳ��Э����Ŀ�ƽ�"<<endl<<endl
                <<"��Ա�����Σ�����"<<endl
                <<"�㷨ʵ�֣��������"<<endl;
            cout << "----------------------------------------" << endl;
            reset_text_color();
            sleep();
            system("cls");
            break;
        case 4:
            set_text_color(FOREGROUND_LIGHT_SKY); // ������ɫ
            cout << "��лʹ�ã��ټ���" << endl;
            reset_text_color();
            return;
        }
    }
}

void UI_functionmenu() {
    while (true) {
        printmap();
        set_text_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); // ����ɫ
        cout << "��ѡ���ܷ���" << endl;
        cout << "1����ͼ��ѯ" << endl;
        cout << "2��У԰����" << endl;
        cout << "3���˳�" << endl;
        reset_text_color();
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

void UI_findmenu() {
    while (true) {
        printmap();
        set_text_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); // ����ɫ
        cout << "��ӭ��������У԰����ϵͳ" << endl;
        cout << "1������ڽӾ���" << endl;
        cout << "2������ڽӱ�" << endl;
        cout << "3������У԰" << endl;
        cout << "4����ѯ��㵽ָ���ص�����·��" << endl;
        cout << "5����ѯ��㵽���еص�����·��" << endl;
        cout << "6���˳�" << endl;
        reset_text_color();
        int choice = get_menu_choice(1, 6);
        if (choice == 6) {
            system("cls");
            return;
        }
        switch (choice) {
        case 1:
            set_text_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); // ����ɫ
            print_adjm();
            cout << endl;
            reset_text_color();
            sleep();
            system("cls");
            break;
        case 2:
            set_text_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); // ����ɫ
            print_adjl();
            cout << endl;
            reset_text_color();
            sleep();
            system("cls");
            break;
        case 3:
        {
            string start;
            set_text_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); // ����ɫ
            cout << "��������㣨�����в�Ҫ�пո񣩣�";
            reset_text_color();
            getline(cin, start);
            int start_index = find_index(start);
            if (start_index == 0) {
                set_text_color(FOREGROUND_LIGHT_RED); // ����ɫ����
                cout << "��Ч����㣡" << endl;
                reset_text_color();
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
            set_text_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); // ����ɫ
            cout << "��������㣨�����в�Ҫ�пո񣩣�";
            reset_text_color();
            getline(cin, start);
            int start_index = find_index(start);
            if (start_index == 0) {
                set_text_color(FOREGROUND_LIGHT_RED); // ����ɫ����
                cout << "��Ч����㣡" << endl;
                reset_text_color();
                sleep();
                system("cls");
                break;
            }
            set_text_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); // ����ɫ
            cout << "�������յ㣨�����в�Ҫ�пո񣩣�";
            reset_text_color();
            getline(cin, end);
            int end_index = find_index(end);
            if (end_index == 0) {
                set_text_color(FOREGROUND_LIGHT_RED); // ����ɫ����
                cout << "��Ч���յ㣡" << endl;
                reset_text_color();
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
            set_text_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); // ����ɫ
            cout << "��������㣺";
            reset_text_color();
            getline(cin, start);
            int start_index = find_index(start);
            if (start_index == 0) {
                set_text_color(FOREGROUND_LIGHT_RED); // ����ɫ����
                cout << "��Ч����㣡" << endl;
                reset_text_color();
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

void loading_screen() {
    set_text_color(FOREGROUND_CYAN); // ��ɫ
    srand(static_cast<unsigned int>(time(0)));
    int delay_seconds = rand() % 5 + 1;
    std::cout << "�����У����Ժ�..." << std::endl;
    const char* spinner = "-\\|/";
    int spinner_len = 4;
    for (int i = 0; i < delay_seconds * 4; i++) {
        std::cout << "\r" << spinner[i % spinner_len] << std::flush;
        Sleep(250);
    }
    std::cout << "\r ";
    std::cout << std::endl;
    reset_text_color();
}

void sleep() {
    set_text_color(FOREGROUND_LIGHT_RED); // ����ɫ
    cout << "�밴 ENTER ������" << endl;
    reset_text_color();
    getchar();
}

void UI_navichoose() {
    while (true) {
        set_text_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); // ����ɫ
        cout << "��ѡ���ܷ���" << endl;
        cout << "1����ʼ����" << endl;
        cout << "2�����а�" << endl;
        cout << "3���˳�" << endl;
        reset_text_color();
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

void UI_navigation() {
    string start, end;
    int start_index, end_index;
    while (true) {
        system("cls");
        set_text_color(FOREGROUND_WHITE); // ��ɫ������ɫ����
        printmap();
        reset_text_color();
        set_text_color(FOREGROUND_WHITE); // ��ɫ������ɫ����
        cout << "��������㣨�����в�Ҫ�пո񣩣�";
        reset_text_color();
        getline(cin, start);
        start_index = find_index(start);
        if (start_index == 0) {
            set_text_color(FOREGROUND_LIGHT_RED); // ����ɫ����
            cout << "��Ч����㣡" << endl;
            reset_text_color();
            sleep();
            system("cls");
            return;
        }
        set_text_color(FOREGROUND_WHITE); // ��ɫ������ɫ����
        cout << "�������յ㣨�����в�Ҫ�пո񣩣�";
        reset_text_color();
        getline(cin, end);
        end_index = find_index(end);
        if (end_index == 0) {
            set_text_color(FOREGROUND_LIGHT_RED); // ����ɫ����
            cout << "��Ч���յ㣡" << endl;
            reset_text_color();
            sleep();
            system("cls");
            return;
        }
        break;
    }
    cur = start_index;
    while (true) {
        system("cls");
        printmap();
        set_text_color(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY); // ��ɫ������ɫ����
        print_recommend(start_index, end_index);
        cout << endl << endl;
        reset_text_color();
        set_text_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); // ��ɫ������ɫ����
        print_intro(cur);
        print_total_step();
        cout << endl;
        printchoices(cur);
        reset_text_color();
        if (!go()) {
            return;
        }
    }
}