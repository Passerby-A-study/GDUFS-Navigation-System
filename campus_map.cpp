/**
 * @file campus_map.cpp
 * @brief 校园地图实现的源文件。
 * 包含地图初始化、打印和文件输出的具体实现。
 */

#include "campus_map.h"
#include "path_finding.h"
#include <string>
#include <iostream>
#include <limits>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "style.h"

VNode adjl[MAX_ELEMENTNUM];
int adjm[MAX_ELEMENTNUM][MAX_ELEMENTNUM];
const std::string map = "╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n║ 广东外语外贸大学                                        ○体育馆                                                   	 ║\n║ 南校区地图                                            ┌─┴──┐                                                        	 ║\n║                                                     ┌─┘    └──┐                                                      	 ║\n║                                                   ┌─┘         └──┐                                                   	 ║\n║                                              ┌────┘              └──┐                                                 ║\n║                                             ┌┘                      └──┐                                              ║\n║                                            ┌┘                          └───┐                                          ║\n║                                           ┌┘                               └─┐                                        ║\n║                                          ┌┘                                  └─┐                                      ║\n║                                          │                                     └─┐                                    ║\n║                                          │              大会堂    ┌──────○艺术楼 └─┐                              	 ║\n║                                         ┌┘           ┌─────○──────┘      ├─────┬──○东北门                           	 ║\n║                                         │       ┌────┘    ┌┴──┐         ┌┘ ┌───┘ ┌┴───┐                              	 ║\n║                                         │  ┌────┘        ┌┘   └───┐   ┌─┴──┘   ┌─┘    └────┐                         	 ║\n║                                   体育场○──┤            ┌┘        └──┬┘   ┌────○学术报告厅 └─┐                      	 ║\n║                                         │  └───┐       ┌┴────────────○────┘    └─┐           └─┐                  	 ║\n║                                         │      └───┐  ┌┘        图书馆外广场     └──┐          └┐                 	 ║\n║                                         │          └──○图书馆                       └──┐        └┐                   	 ║\n║                                         └┐            ├─────┐                 ┌────────○         └┐                  	 ║\n║                                          │            └┐    └───┐          ┌──┘    实验楼A-E区    └┐                 	 ║\n║                                          └┐            └┐       └───┐   ┌──┘          ┌┘           │                 	 ║\n║                                           │             └┐          └───┤            ┌┘            └┐                	 ║\n║                                           └┐             └┐          ┌──○教学楼E-G座┌┘              │                	 ║\n║                                            └─┐            └────┐  ┌──┘  │          ┌┘               └┐             	 ║\n║                                              └─┐    教学楼A-D座○──┘     │   文心湖┌┘                 │               	 ║\n║                                        ○门诊部 └─┐             └┐       │       ┌─○──────────┐       └┐             	 ║\n║                                         └──┐     └───┐          └─┐     │     ┌─┘ └──┐       └────────○办公楼        	 ║\n║                                            └──┐      └────┐       └─┐   │   ┌─┘      └──┐      ┌──────┤              	 ║\n║                                               └──┐        └───┐     └─┐ │ ┌─┘           ├──────┘      │           	 ║\n║                                                  └──┐         └──┐    └─┼─┘             ○八角楼       │              	 ║\n║                                                     └───┐        └──────○下沉广场-教学区│             │              	 ║\n║                                                         │           ┌───┘               └┐            │              	 ║\n║                                                         ○文采园 ┌───┘                    │           ○东南门        	 ║\n║                                                      ┌──┴───────┤                        └┐       ┌──┘               	 ║\n║                                                    ┌─┘          ○下沉广场-生活区          │    ┌──┘                  	 ║\n║                                                 ┌──┘          ┌─┤                         ├────┘                     	 ║\n║                                学生公寓北苑1-4栋○           ┌─┘ │                         ○学术交流中心             	 ║\n║                                                 │         ┌─┘   ○博雅园                                              	 ║\n║          Gogo新天地○────┐                       └─┐     ┌─┘     └─┐                                                  	 ║\n║                         └────┐                    └┐  ┌─┘         │                                                  	 ║\n║                              └────┐                └┬─┘         ┌─○教工公寓1-4栋                                     	 ║\n║                                   └────┐     学生公寓北苑5-6栋┌─┘ └─┐                                                	 ║\n║                                        └────┐       ├─────────○     └─┐                                              	 ║\n║                                             └───────○又康超市 └───────┤                                              	 ║\n║                                              ┌──────┼──┐              ○友苑                                          	 ║\n║                                           ┌──┘      │  └──┐           │                                           	 ║\n║                                           │         │     └──┐  ┌─────┘                                           	 ║\n║                        学生公寓南苑7-8栋┌─○         └┐       └──┤                                                    	 ║\n║                                         │            │     ┌────○学生创业实践基地                                    	 ║\n║                                         │            ├─────┘                                                         	 ║\n║                                         │     ┌──────○学生公寓南苑9-13栋                                             	 ║\n║                                         ├─────┘                                                                      	 ║\n║                                         ○风采园                                                                      	 ║\n║                                                                                                                      	 ║\n║                                                                                                                      	 ║\n║[1]东北门 [2]东南门 [3]艺术楼 [4]学术报告厅 [5]大会堂 [6]图书馆 [7]图书馆外广场 [8]体育馆 [9]体育场 [10]教学楼A-D座    ║\n║[11]教学楼E-G座 [12]实验楼A-E区 [13]文心湖 [14]八角楼 [15]办公楼 [16]学术交流中心 [17]下沉广场-教学区                  ║\n║[18]下沉广场-生活区 [19]文采园 [20]博雅园 [21]风采园 [22]门诊部 [23]学生公寓北苑1-4栋 [24]学生公寓北苑5-6栋	        ║\n║[25]学生公寓南苑7-8栋 [26]学生公寓南苑9-13栋 [27]教工公寓1-4栋 [28]友苑 [29]又康超市 [30]学生创业实践基地              ║\n║[31]Gogo新天地                                                                                                         ║\n╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝";
std::string location[MAX_ELEMENTNUM];
std::string intro[MAX_ELEMENTNUM];
int n, m;
VNode* vl;

void printmap()
{
    set_text_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    std::cout << map << std::endl;
    reset_text_color();
    return;
}

int find_index(std::string& target)
{
    for (int i = 1; i <= n; i++)
    {
        if (target == location[i])
        {
            return i;
        }
    }
    return 0;
}

std::string* find_location(std::string& target)
{
    for (int i = 1; i <= n; i++)
    {
        if (target == location[i])
        {
            return &location[i];
        }
    }
    return nullptr;
}

void creatgraph()
{
    for (int i = 0; i < MAX_ELEMENTNUM; i++)
    {
        for (int j = 0; j < MAX_ELEMENTNUM; j++)
        {
            adjm[i][j] = INF;
        }
        adjm[i][i] = 0;
    }

    std::ifstream fin("input.txt");
    if (!fin) {
        std::cout << "错误：无法打开 input.txt 文件！请确保文件存在并位于程序目录下。" << std::endl;
        return;
    }

    fin >> n;
    fin.ignore();

    vl = new VNode[n + 1];

    for (int i = 1; i <= n; i++)
    {
        std::string line;
        std::getline(fin, line);

        size_t pos = line.find(' ');
        if (pos != std::string::npos)
        {
            location[i] = line.substr(0, pos);
            intro[i] = line.substr(pos + 1);
        }
        else
        {
            location[i] = line;
            intro[i] = "";
        }

        vl[i].data = &location[i];
        vl[i].first = nullptr;
    }

    fin >> m;
    fin.ignore();

    Edge* e = new Edge[m + 1];

    for (int i = 1; i <= m; i++)
    {
        std::string line;
        std::getline(fin, line);

        std::stringstream ss(line);
        std::string start, end;
        int w;

        ss >> start;
        std::string temp;
        while (ss >> temp) {
            if (ss >> std::ws && ss.peek() >= '0' && ss.peek() <= '9') {
                end = end.empty() ? temp : end + " " + temp;
                break;
            }
            end = end.empty() ? temp : end + " " + temp;
        }
        ss >> w;

        e[i].start = find_index(start);
        e[i].end = find_index(end);
        e[i].w = w;

        if (e[i].start == 0 || e[i].end == 0)
        {
            std::cout << "错误：无法找到地点 " << start << " 或 " << end << std::endl;
            continue;
        }

        adjm[e[i].start][e[i].end] = adjm[e[i].end][e[i].start] = e[i].w;

        std::string* head = &location[e[i].start];
        std::string* tail = &location[e[i].end];

        ENode* el_start = new ENode;
        el_start->data = tail;
        el_start->w = e[i].w;
        el_start->next = vl[e[i].start].first;
        vl[e[i].start].first = el_start;

        ENode* el_end = new ENode;
        el_end->data = head;
        el_end->w = e[i].w;
        el_end->next = vl[e[i].end].first;
        vl[e[i].end].first = el_end;
    }

    floyd();

    delete[] e;

    fin.close();
}

void print_adjm()
{
    std::cout << std::left << std::setw(20) << "";
    for (int j = 1; j <= n; j++) {
        std::cout << std::left << std::setw(20) << location[j];
    }
    std::cout << std::endl;

    for (int i = 1; i <= n; i++) {
        std::cout << std::left << std::setw(20) << location[i];
        for (int j = 1; j <= n; j++) {
            if (adjm[i][j] == INF) {
                std::cout << std::left << std::setw(20) << "INF";
            }
            else {
                std::cout << std::left << std::setw(20) << adjm[i][j];
            }
        }
        std::cout << std::endl;
    }
    output_adj_matrix_to_file();
}

void print_adjl()
{
    for (int i = 1; i <= n; i++)
    {
        ENode* p = vl[i].first;
        std::cout << *(vl[i].data) << " : ";
        while (p != nullptr)
        {
            std::cout << *(p->data) << " (" << p->w << ")  ";
            p = p->next;
        }
        std::cout << std::endl;
    }
    output_adj_list_to_file();
}

void output_adj_matrix_to_file()
{
    std::ofstream fout("adj_matrix.txt");
    if (!fout) {
        std::cout << "错误：无法创建或打开 adj_matrix.txt 文件！" << std::endl;
        return;
    }

    fout << "邻接矩阵：" << std::endl;

    fout << std::left << std::setw(20) << "";
    for (int j = 1; j <= n; j++) {
        fout << std::left << std::setw(20) << location[j];
    }
    fout << std::endl;

    for (int i = 1; i <= n; i++) {
        fout << std::left << std::setw(20) << location[i];
        for (int j = 1; j <= n; j++) {
            if (adjm[i][j] == INF) {
                fout << std::left << std::setw(20) << "INF";
            }
            else {
                fout << std::left << std::setw(20) << adjm[i][j];
            }
        }
        fout << std::endl;
    }

    fout.close();
    std::cout << "邻接矩阵已输出到 adj_matrix.txt 文件！" << std::endl;
}

void output_adj_list_to_file()
{
    std::ofstream fout("adj_list.txt");
    if (!fout) {
        std::cout << "错误：无法创建或打开 adj_list.txt 文件！" << std::endl;
        return;
    }

    fout << "邻接表：" << std::endl;
    for (int i = 1; i <= n; i++) {
        ENode* p = vl[i].first;
        fout << std::left << std::setw(20) << *(vl[i].data) << " : ";
        while (p != nullptr) {
            fout << std::left << std::setw(20) << *(p->data) << " (" << p->w << ")  ";
            p = p->next;
        }
        fout << std::endl;
    }

    fout.close();
    std::cout << "邻接表已输出到 adj_list.txt 文件！" << std::endl;
}