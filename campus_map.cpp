#include"campus_map.h"
#include<string>
#include<iostream>
const int MAX_ELEMENTNUM = 105;
typedef struct Edge {
	int start;
	int end;
	int w;
};
typedef struct ENode {
	std::string* data;
	int w;
	ENode* next;
};
typedef struct VNode {
	std::string* data;
	ENode* first;
};
VNode adjl[MAX_ELEMENTNUM];
int adjm[MAX_ELEMENTNUM][MAX_ELEMENTNUM];
const std::string map = "╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n║ 广东外语外贸大学                                        ○体育馆                                                   	║\n║ 南校区地图                                            ┌─┴──┐                                                        	║\n║                                                     ┌─┘    └──┐                                                      	║\n║                                                   ┌─┘         └──┐                                                   	║\n║                                              ┌────┘              └──┐                                                 ║\n║                                             ┌┘                      └──┐                                              ║\n║                                            ┌┘                          └───┐                                          ║\n║                                           ┌┘                               └─┐                                        ║\n║                                          ┌┘                                  └─┐                                      ║\n║                                          │                                     └─┐                                    ║\n║                                          │              大会堂    ┌──────○艺术楼 └─┐                              	║\n║                                         ┌┘           ┌─────○──────┘      ├─────┬──○东北门                           	║\n║                                         │       ┌────┘    ┌┴──┐         ┌┘ ┌───┘ ┌┴───┐                              	║\n║                                         │  ┌────┘        ┌┘   └───┐   ┌─┴──┘   ┌─┘    └────┐                         	║\n║                                   体育场○──┤            ┌┘        └──┬┘   ┌────○学术报告厅 └─┐                      	║\n║                                         │  └───┐       ┌┴────────────○───┘    └──┐           └─┐                  	║\n║                                         │      └───┐  ┌┘        图书馆外广场     └──┐          └┐                 	║\n║                                         │          └──○图书馆                       └──┐        └┐                   	║\n║                                         └┐            ├─────┐                 ┌────────○         └┐                  	║\n║                                          │            └┐    └───┐          ┌──┘    实验楼A-E区    └┐                 	║\n║                                          └┐            └┐       └───┐   ┌──┘          ┌┘           │                 	║\n║                                           │             └┐          └───┤            ┌┘            └┐                	║\n║                                           └┐             └┐          ┌──○教学楼E-G座┌┘              │                	║\n║                                            └─┐            └────┐  ┌──┘  │          ┌┘               └┐             	║\n║                                              └─┐    教学楼A-D座○──┘     │   文心湖┌┘                 │               	║\n║                                        ○门诊部 └─┐             └┐       │       ┌─○──────────┐       └┐             	║\n║                                         └──┐     └───┐          └─┐     │     ┌─┘ └──┐       └────────○办公楼        	║\n║                                            └──┐      └────┐       └─┐   │   ┌─┘      └──┐      ┌──────┤              	║\n║                                               └──┐        └───┐     └─┐ │ ┌─┘           ├──────┘      │           	║\n║                                                  └──┐         └──┐    └─┼─┘             ○八角楼       │              	║\n║                                                     └───┐        └──────○下沉广场-教学区│             │              	║\n║                                                         │           ┌───┘               └┐            │              	║\n║                                                         ○文采园 ┌───┘                    │           ○东南门        	║\n║                                                      ┌──┴───────┤                        └┐       ┌──┘               	║\n║                                                    ┌─┘          ○下沉广场-生活区          │    ┌──┘                  	║\n║                                                 ┌──┘          ┌─┤                         ├────┘                     	║\n║                                学生公寓北苑1-4栋○           ┌─┘ │                         ○学术交流中心             	║\n║                                                 │         ┌─┘   ○博雅园                                              	║\n║          Gogo新天地○────┐                       └─┐     ┌─┘     └─┐                                                  	║\n║                         └────┐                    └┐  ┌─┘         │                                                  	║\n║                              └────┐                └┬─┘         ┌─○教工公寓1-4栋                                     	║\n║                                   └────┐     学生公寓北苑5-6栋┌─┘ └─┐                                                	║\n║                                        └────┐       ├─────────○     └─┐                                              	║\n║                                             └───────○又康超市 └───────┤                                              	║\n║                                              ┌──────┼──┐              ○友苑                                          	║\n║                                           ┌──┘      │  └──┐           │                                           	║\n║                                           │         │     └──┐  ┌─────┘                                           	║\n║                        学生公寓南苑7-8栋┌─○         └┐       └──┤                                                    	║\n║                                         │            │     ┌────○学生创业实践基地                                    	║\n║                                         │            ├─────┘                                                         	║\n║                                         │     ┌──────○学生公寓南苑9-13栋                                             	║\n║                                         ├─────┘                                                                      	║\n║                                         ○风采园                                                                      	║\n║                                                                                                                      	║\n║                                                                                                                      	║\n║[1]东北门 [2]东南门 [3]艺术楼 [4]学术报告厅 [5]大会堂 [6]图书馆 [7]图书馆外广场 [8]体育馆 [9]体育场 [10]教学楼 A-D 座  ║\n║[11]教学楼 E-G 座 [12]实验楼 A-E 区 [13]文心湖 [14]八角楼 [15]办公楼 [16]学术交流中心 [17]下沉广场 - 教学区            ║\n║[18]下沉广场 - 生活区 [19]文采园 [20]博雅园 [21]风雅园 [22]门诊部 [23]学生公寓北苑 1-4 栋 [24]学生公寓北苑 5-6 栋	║\n║[25]学生公寓南苑 7-8 栋 [26]学生公寓南苑 9-13 栋 [27]教工公寓 1-4 栋 [28]友苑 [29]又康超市 [30]学生创业实践基地        ║\n║[31]Gogo 新天地                                                                                                        ║\n╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝";
std::string location[MAX_ELEMENTNUM];
std::string intro[MAX_ELEMENTNUM];

void printmap()
{
	std::cout << map << std::endl;
	return;
}

int find_index(std::string& target)
{

}

std::string* find_location(std::string& target)
{

}

void creatgraph()
{
	int n,m;
	std::cin >> n;
	VNode* vl = new VNode[n + 1];
	getchar();
	for (int i = 1; i <= n; i++)
	{
		std::getline(std::cin, location[i]);
		getchar();
		std::getline(std::cin, intro[i]);
		getchar();
		vl[i].data = location + i;
		vl[i].first = nullptr;
	}
	std::cin >> m;
	Edge* e = new Edge[m + 1];
	getchar();
	for (int i = 1; i <= m; i++)
	{
		std::string start, end;
		int w;
		std::getline(std::cin, start);
		getchar();
		std::getline(std::cin, end);
		getchar();

		e[i].start = find_index(start);
		e[i].end = find_index(end);
		std::string* head = find_location(start);
		std::string* tail = find_location(end);

		std::cin >> e[i].w;
		adjm[e[i].start][e[i].end] = adjm[e[i].end][e[i].start] = e[i].w;

		ENode* el = new ENode;
		el->data = tail;
		el->w = e[i].w;
		el->next = vl[e[i].start].first;
		vl[e[i].start].first = el;

		el->data = head;
		el->w = e[i].w;
		el->next = vl[e[i].end].first;
		vl[e[i].end].first = el;
	}
}
