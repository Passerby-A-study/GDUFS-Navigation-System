#pragma once
#include"campus_map.h"

int shortest_path[MAX_ELEMENTNUM][MAX_ELEMENTNUM];  // �洢���·������
int prev[MAX_ELEMENTNUM][MAX_ELEMENTNUM];          // �洢ǰ���ڵ㣬���ڻָ�·��

void floyd();