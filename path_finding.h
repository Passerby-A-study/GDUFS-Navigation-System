#pragma once
#include"campus_map.h"

int shortest_path[MAX_ELEMENTNUM][MAX_ELEMENTNUM];  // 存储最短路径长度
int prev[MAX_ELEMENTNUM][MAX_ELEMENTNUM];          // 存储前驱节点，用于恢复路径

void floyd();