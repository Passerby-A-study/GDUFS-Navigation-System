#pragma once
#include"campus_map.h"

extern int shortest_path[MAX_ELEMENTNUM][MAX_ELEMENTNUM];  // �洢���·������
extern int prev[MAX_ELEMENTNUM][MAX_ELEMENTNUM];          // �洢ǰ���ڵ㣬���ڻָ�·��

void floyd();
void print_path_start_end(int start, int end);
void print_all_paths_from(int start);
void travel(int start);
void print_prev_array();
