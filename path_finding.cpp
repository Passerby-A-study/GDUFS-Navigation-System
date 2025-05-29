#include"path_finding.h"

void floyd()
{
    // 初始化最短路径矩阵为邻接矩阵的副本
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            shortest_path[i][j] = adjm[i][j];
            prev[i][j] = (i == j) ? -1 : i;  // 初始前驱为起点本身（i到j直接相连时前驱为i）
        }
    }

    // 核心三重循环：尝试以k为中间节点更新i到j的最短路径
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                // 若经过k的路径更短，则更新最短路径和前驱
                if (shortest_path[i][k] != INF && shortest_path[k][j] != INF &&
                    shortest_path[i][j] > shortest_path[i][k] + shortest_path[k][j]) {
                    shortest_path[i][j] = shortest_path[i][k] + shortest_path[k][j];
                    prev[i][j] = prev[k][j];  // 更新前驱为k到j的前驱
                }
            }
        }
    }
}
