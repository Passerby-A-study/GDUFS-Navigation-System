#include "user_interface.h"
#include "campus_map.h"
#include "path_finding.h"
#include "navigation.h"
#include "style.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <windows.h> // Windows 特定头文件
#include <limits>
#include <ctime>
using std::string;
using std::cout;
using std::endl;
using std::cin;

// 辅助函数：读取并验证菜单选项
int get_menu_choice(int min, int max) {
    int choice;
    while (true) {
        set_text_color(FOREGROUND_GREEN);
        cout << "请输入选择（ 数字 " << min << "-" << max << " ）：";
        reset_text_color(); // 重置颜色
        if (cin >> choice && choice >= min && choice <= max) {
            cin.ignore(); // 清理缓冲区
            cout << endl;
            return choice;
        }
        else {
            set_text_color(FOREGROUND_GREEN);
            cout << "无效输入！" << endl;
            reset_text_color();
            cin.clear();
            cin.ignore();
        }
    }
}

void UI_Start()
{

    while (true) {
        cout << "欢迎来到广外校园导航系统" << endl;
        cout << "1，开始" << endl;
        cout << "2，项目介绍" << endl;
        cout << "3，开发人员介绍" << endl;
        cout << "4，退出程序" << endl;
        int choice = get_menu_choice(1, 4);
        switch (choice) {
        case 1:
            system("cls");
            set_text_color(FOREGROUND_GREEN);
            cout << "地图开始加载" << endl;
            creatgraph();
            //loading_screen();
            cout << "地图加载完成！" << endl;
            reset_text_color();
            sleep();
            system("cls");
            UI_functionmenu();
            break;
        case 2:
            cout << "项目介绍：广外校园导航系统，帮助学生快速找到校园内最短路径！" << endl;
            sleep();
            break;
        case 3:
            cout << "开发人员：" << endl;
            sleep();
            break;
        case 4:
            cout << "感谢使用，再见！" << endl;

            return;
        }
    }
}

void UI_functionmenu()
{
    while (true) {
        printmap();
        cout << "请选择功能服务" << endl;
        cout << "1，地图查询" << endl;
        cout << "2，校园导航" << endl;
        cout << "3，退出" << endl;

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
        cout << "欢迎来到广外校园导航系统" << endl;
        cout << "1，输出邻接矩阵" << endl;
        cout << "2，输出邻接表" << endl;
        cout << "3，环游校园" << endl;
        cout << "4，查询起点到指定地点的最短路径" << endl;
        cout << "5，查询起点到所有地点的最短路径" << endl;
        cout << "6，退出" << endl;

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
            cout << "请输入起点（名称中不要有空格）：";
            getline(cin, start);
            int start_index = find_index(start);
            if (start_index == 0) {
                cout << "无效的起点！" << endl;           
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
            cout << "请输入起点（名称中不要有空格）：";
            getline(cin, start);
            int start_index = find_index(start);
            if (start_index == 0) {
                cout << "无效的起点！" << endl;
                sleep();
                system("cls");
                break;
            }
            cout << "请输入终点（名称中不要有空格）：";
            getline(cin, end);
            int end_index = find_index(end);
            if (end_index == 0) {
                cout << "无效的终点！" << endl;
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
            cout << "请输入起点：";
            getline(cin, start);
            int start_index = find_index(start);
            if (start_index == 0) {
                cout << "无效的起点！" << endl;
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

// 显示加载动画
void loading_screen()
{
    set_text_color(FOREGROUND_GREEN);
    // 初始化随机种子（建议放在 main()，这里仅为演示）
    srand(static_cast<unsigned int>(time(0)));

    // 随机选择 1 到 5 秒的延时
    int delay_seconds = rand() % 5 + 1; // 1 到 5 秒的随机数
    std::cout << "加载中，请稍后..." << std::endl;

    // 定义转圈字符序列
    const char* spinner = "-\\|/"; // 转圈字符
    int spinner_len = 4; // 字符数量

    // 模拟延时并显示转圈动画
    for (int i = 0; i < delay_seconds * 4; i++) { // 每秒旋转 4 次
        std::cout << "\r" << spinner[i % spinner_len] << std::flush; // 使用 \r 返回行首，显示单个字符
        Sleep(250); // Windows 下 250 毫秒延时
    }
    std::cout << "\r "; // 清除最后一个字符
    std::cout << std::endl; // 换行
    reset_text_color();
}

void sleep()
{
    set_text_color(FOREGROUND_GREEN);
    cout << "请按 ENTER 键继续" << endl;
    reset_text_color();
    getchar();
}

void UI_navichoose()
{
    while (true) {
        cout << "请选择功能服务" << endl;
        cout << "1，开始导航" << endl;
        cout << "2，排行榜" << endl;
        cout << "3，退出" << endl;

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
        cout << "请输入起点（名称中不要有空格）：";
        getline(cin, start);
        start_index = find_index(start);
        if (start_index == 0) {
            cout << "无效的起点！" << endl;
            sleep();
            system("cls");
            return;
        }
        cout << "请输入终点（名称中不要有空格）：";
        getline(cin, end);
        end_index = find_index(end);
        if (end_index == 0) {
            cout << "无效的终点！" << endl;
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
