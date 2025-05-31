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

// 辅助函数：读取并验证菜单选项
int get_menu_choice(int min, int max) {
    int choice;
    while (true) {
        set_text_color(FOREGROUND_YELLOW); // 黄色提示
        cout << "请输入选择（ 数字 " << min << "-" << max << " ）：";
        reset_text_color();
        if (cin >> choice && choice >= min && choice <= max) {
            cin.ignore();
            cout << endl;
            return choice;
        }
        else {
            set_text_color(FOREGROUND_YELLOW); // 黄色错误提示
            cout << "无效输入！" << endl;
            reset_text_color();
            cin.clear();
            cin.ignore();
        }
    }
}

void UI_Start() {
    while (true) {
        set_text_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); // 亮天蓝色
        cout << "欢迎来到广外校园导航系统" << endl;
        cout << "1，开始" << endl;
        cout << "2，项目介绍" << endl;
        cout << "3，开发人员介绍" << endl;
        cout << "4，退出程序" << endl;
        reset_text_color();
        int choice = get_menu_choice(1, 4);
        switch (choice) {
        case 1:
            system("cls");
            set_text_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); // 亮绿色提示
            cout << "地图开始加载" << endl;
            loading_screen();
            creatgraph();
            cout << "地图加载完成！" << endl;
            reset_text_color();
            sleep();
            system("cls");
            UI_functionmenu();
            break;
        case 2:
            set_text_color(FOREGROUND_LIGHT_SKY); // 亮天蓝色
            cout << "广外校园导航系统 - 项目介绍" << endl;
            cout << "----------------------------------------" << endl;
            cout << "本系统专为广东外语外贸大学（广外）师生设计，" << endl;
            cout << "旨在帮助您快速、便捷地在校园内找到最优路径。" << endl;
            cout << "无论您是寻找教学楼、宿舍、图书馆，还是计划" << endl;
            cout << "一次环游校园的旅程，我们都能为您提供高效的导航服务。" << endl;
            cout << endl;
            cout << "核心功能：" << endl;
            cout << "- 地图查询：查看校园的邻接矩阵和邻接表。" << endl;
            cout << "- 最短路径规划：输入起点和终点，获取最短路径。" << endl;
            cout << "- 环游校园：从任意起点探索所有地点。" << endl;
            cout << "- 实时导航：动态显示路径和可选地点。" << endl;
            cout << "- 排行榜：记录步数，与他人比拼最优路线！" << endl;
            cout << endl;
            cout << "项目亮点：" << endl;
            cout << "- 用户友好：简洁的界面设计，搭配多彩的视觉风格，提升使用体验。" << endl;
            cout << "- 高效算法：采用图论算法，确保路径规划精准高效。" << endl;
            cout << "- 个性化体验：支持实时交互，随时查看地点简介，探索校园文化。" << endl;
            cout << endl;
            cout << "我们的目标：" << endl;
            cout << "通过技术赋能校园生活，让每一位广外师生都能轻松探索校园，享受便捷的导航体验，同时感受校园的美丽与活力。" << endl;
            cout << endl;
            cout << "快来开始您的校园之旅吧！" << endl;
            cout << "----------------------------------------" << endl;
            reset_text_color();
            sleep();
            system("cls");
            break;
        case 3:
            set_text_color(FOREGROUND_LIGHT_SKY); // 亮天蓝色
            cout << "----------------------------------------" << endl;
            cout << "开发人员：" << endl
                <<"负责人：林子豪"<<endl
                <<"统筹协调项目推进"<<endl<<endl
                <<"组员：张涛，曾琪"<<endl
                <<"算法实现，功能设计"<<endl;
            cout << "----------------------------------------" << endl;
            reset_text_color();
            sleep();
            system("cls");
            break;
        case 4:
            set_text_color(FOREGROUND_LIGHT_SKY); // 亮天蓝色
            cout << "感谢使用，再见！" << endl;
            reset_text_color();
            return;
        }
    }
}

void UI_functionmenu() {
    while (true) {
        printmap();
        set_text_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); // 亮紫色
        cout << "请选择功能服务" << endl;
        cout << "1，地图查询" << endl;
        cout << "2，校园导航" << endl;
        cout << "3，退出" << endl;
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
        set_text_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); // 亮绿色
        cout << "欢迎来到广外校园导航系统" << endl;
        cout << "1，输出邻接矩阵" << endl;
        cout << "2，输出邻接表" << endl;
        cout << "3，环游校园" << endl;
        cout << "4，查询起点到指定地点的最短路径" << endl;
        cout << "5，查询起点到所有地点的最短路径" << endl;
        cout << "6，退出" << endl;
        reset_text_color();
        int choice = get_menu_choice(1, 6);
        if (choice == 6) {
            system("cls");
            return;
        }
        switch (choice) {
        case 1:
            set_text_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); // 亮绿色
            print_adjm();
            cout << endl;
            reset_text_color();
            sleep();
            system("cls");
            break;
        case 2:
            set_text_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); // 亮绿色
            print_adjl();
            cout << endl;
            reset_text_color();
            sleep();
            system("cls");
            break;
        case 3:
        {
            string start;
            set_text_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); // 亮绿色
            cout << "请输入起点（名称中不要有空格）：";
            reset_text_color();
            getline(cin, start);
            int start_index = find_index(start);
            if (start_index == 0) {
                set_text_color(FOREGROUND_LIGHT_RED); // 亮红色错误
                cout << "无效的起点！" << endl;
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
            set_text_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); // 亮绿色
            cout << "请输入起点（名称中不要有空格）：";
            reset_text_color();
            getline(cin, start);
            int start_index = find_index(start);
            if (start_index == 0) {
                set_text_color(FOREGROUND_LIGHT_RED); // 亮红色错误
                cout << "无效的起点！" << endl;
                reset_text_color();
                sleep();
                system("cls");
                break;
            }
            set_text_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); // 亮绿色
            cout << "请输入终点（名称中不要有空格）：";
            reset_text_color();
            getline(cin, end);
            int end_index = find_index(end);
            if (end_index == 0) {
                set_text_color(FOREGROUND_LIGHT_RED); // 亮红色错误
                cout << "无效的终点！" << endl;
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
            set_text_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); // 亮绿色
            cout << "请输入起点：";
            reset_text_color();
            getline(cin, start);
            int start_index = find_index(start);
            if (start_index == 0) {
                set_text_color(FOREGROUND_LIGHT_RED); // 亮红色错误
                cout << "无效的起点！" << endl;
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
    set_text_color(FOREGROUND_CYAN); // 青色
    srand(static_cast<unsigned int>(time(0)));
    int delay_seconds = rand() % 5 + 1;
    std::cout << "加载中，请稍后..." << std::endl;
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
    set_text_color(FOREGROUND_LIGHT_RED); // 亮红色
    cout << "请按 ENTER 键继续" << endl;
    reset_text_color();
    getchar();
}

void UI_navichoose() {
    while (true) {
        set_text_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); // 亮橙色
        cout << "请选择功能服务" << endl;
        cout << "1，开始导航" << endl;
        cout << "2，排行榜" << endl;
        cout << "3，退出" << endl;
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
        set_text_color(FOREGROUND_WHITE); // 白色，深蓝色背景
        printmap();
        reset_text_color();
        set_text_color(FOREGROUND_WHITE); // 白色，深蓝色背景
        cout << "请输入起点（名称中不要有空格）：";
        reset_text_color();
        getline(cin, start);
        start_index = find_index(start);
        if (start_index == 0) {
            set_text_color(FOREGROUND_LIGHT_RED); // 亮红色错误
            cout << "无效的起点！" << endl;
            reset_text_color();
            sleep();
            system("cls");
            return;
        }
        set_text_color(FOREGROUND_WHITE); // 白色，深蓝色背景
        cout << "请输入终点（名称中不要有空格）：";
        reset_text_color();
        getline(cin, end);
        end_index = find_index(end);
        if (end_index == 0) {
            set_text_color(FOREGROUND_LIGHT_RED); // 亮红色错误
            cout << "无效的终点！" << endl;
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
        set_text_color(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY); // 白色，深蓝色背景
        print_recommend(start_index, end_index);
        cout << endl << endl;
        reset_text_color();
        set_text_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); // 白色，深蓝色背景
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