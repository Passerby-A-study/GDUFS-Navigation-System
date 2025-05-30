#pragma once
#include<string>

const int MAX_ELEMENTNUM = 105;
const int INF = 10086;

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

extern VNode adjl[MAX_ELEMENTNUM];
extern int adjm[MAX_ELEMENTNUM][MAX_ELEMENTNUM];
extern const std::string map;
extern std::string location[MAX_ELEMENTNUM];
extern std::string intro[MAX_ELEMENTNUM];
extern int n, m;
extern VNode* vl;


void printmap();
int find_index(std::string& target);
std::string* find_location(std::string& target);
void creatgraph();
void print_adjm();
void print_adjl();
void output_adj_matrix_to_file();
void output_adj_list_to_file();
