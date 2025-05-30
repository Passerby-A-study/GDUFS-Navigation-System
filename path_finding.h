#pragma once
#include"campus_map.h"

extern int shortest_path[MAX_ELEMENTNUM][MAX_ELEMENTNUM];  // 存储最短路径长度
extern int prev[MAX_ELEMENTNUM][MAX_ELEMENTNUM];          // 存储前驱节点，用于恢复路径

void floyd();
void print_path_start_end(int start, int end);
void print_all_paths_from(int start);
void travel(int start);
void print_prev_array();
