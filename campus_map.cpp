#include"campus_map.h"
#include"path_finding.h"
#include<string>
#include<iostream>

void printmap()
{
	std::cout << map << std::endl;
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
}

void creatgraph()
{
	for (int i = 0; i < MAX_ELEMENTNUM; i++)
	{
		for (int j = 0; j < MAX_ELEMENTNUM; j++)
		{
			adjm[i][j] = INF;
		}
	}
	std::cin >> n;
	vl = new VNode[n + 1];
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

		floyd();
	}
}

void print_adjm()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			std::cout << adjm[i][j]<<" ";
		}
		std::cout << std::endl;
	}
}

void print_adjl()
{
	for (int i = 1; i <= n; i++)
	{
		ENode* p=vl[i].first;
		std::cout << vl[i].data << " : ";
		while (p != nullptr)
		{
			std::cout << p->data << " ( " << p->w << " )  ";
			p = p->next;
		}
	}
}
