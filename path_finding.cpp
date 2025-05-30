#include "path_finding.h"
#include "mystack.h"
#include <iostream>

int shortest_path[MAX_ELEMENTNUM][MAX_ELEMENTNUM];  // 存储最短路径长度
int prev[MAX_ELEMENTNUM][MAX_ELEMENTNUM];          // 存储前驱节点，用于恢复路径

void floyd()
{
    // 初始化最短路径矩阵为邻接矩阵的副本
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            shortest_path[i][j] = adjm[i][j];
            prev[i][j] = (i == j) ? -1 : ((adjm[i][j] != INF) ? i : -1); // 直接相连时前驱为 i
        }
    }

    // 核心三重循环：尝试以k为中间节点更新i到j的最短路径
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (shortest_path[i][k] != INF && shortest_path[k][j] != INF &&
                    (shortest_path[i][j] == INF || shortest_path[i][j] > shortest_path[i][k] + shortest_path[k][j])) {
                    shortest_path[i][j] = shortest_path[i][k] + shortest_path[k][j];
                    prev[i][j] = k; // 更新前驱为中间节点 k
                }
            }
        }
    }

    //// 调试输出：打印 shortest_path 矩阵
    //std::cout << "最短路径矩阵：" << std::endl;
    //for (int i = 1; i <= n; i++) {
    //    for (int j = 1; j <= n; j++) {
    //        std::cout << shortest_path[i][j] << "\t";
    //    }
    //    std::cout << std::endl;
    //}

    //print_prev_array();
}

void print_prev_array()
{
    std::cout << "前驱数组：" << std::endl;
    std::cout << "\t";
    for (int j = 1; j <= n; j++) {
        std::cout << "\t" << location[j];
    }
    std::cout << std::endl;

    for (int i = 1; i <= n; i++) {
        std::cout << location[i] << "\t";
        for (int j = 1; j <= n; j++) {
            if (prev[i][j] == -1) {
                std::cout << "\t-";
            }
            else {
                std::cout << "\t" << location[prev[i][j]]; // 输出前驱地点名
            }
        }
        std::cout << std::endl;
    }
}

void print_path_start_end(int start, int end)
{
    if (start < 1 || start > n) {
        std::cout << "无效的起点！" << std::endl;
        return;
    }
    if (end < 1 || end > n) {
        std::cout << "无效的终点！" << std::endl;
        return;
    }

    std::cout << "从 " << location[start] << " 到 " << location[end] << " 的最短路径：" << std::endl;
    mystack<int> pathStack;
    int current = end;
    while (current != -1 && current != start) {
        pathStack.push(current);
        current = prev[start][current];
        if (current == prev[start][current]) break; // 避免死循环
    }
    if (current == start) pathStack.push(current);

    bool first = true;
    while (!pathStack.isempty())
    {
        if (!first) std::cout << " -> ";
        std::cout << location[pathStack.gettop()];
        pathStack.pop();
        first = false;
    }
    std::cout << "  (距离: " << shortest_path[start][end] << ")" << std::endl;
}

void print_all_paths_from(int start) {
    if (start < 1 || start > n) {
        std::cout << "无效的起点！" << std::endl;
        return;
    }

    std::cout << "从 " << location[start] << " 到各点的最短路径：" << std::endl;
    for (int end = 1; end <= n; end++) {
        if (start == end) continue; // 跳过起点到自身的路径

        if (shortest_path[start][end] == INF) {
            std::cout << "到 " << location[end] << "：不可达" << std::endl;
            continue;
        }

        // 使用栈回溯路径
        mystack<int> pathStack;
        int current = end;
        while (current != -1 && current != start) {
            pathStack.push(current);
            current = prev[start][current];
            if (current == prev[start][current]) break; // 避免死循环
        }
        if (current == start) pathStack.push(current);

        // 输出路径和距离
        std::cout << "到 " << location[end] << "：";
        bool first = true;
        while (!pathStack.isempty()) {
            if (!first) std::cout << " -> ";
            std::cout << location[pathStack.gettop()];
            pathStack.pop();
            first = false;
        }
        std::cout << "  (距离: " << shortest_path[start][end] << ")" << std::endl;
    }
}

void travel(int start)
{
    if (start < 1 || start > n) {
        std::cout << "无效的起点！" << std::endl;
        return;
    }

    bool visited[MAX_ELEMENTNUM] = { false };  // 标记地点是否已访问
    int path[MAX_ELEMENTNUM];                // 存储路径
    int path_length = 0;                     // 路径长度
    int current = start;                     // 当前位置
    int total_distance = 0;                  // 总路程

    // 初始化路径，从起点开始
    path[path_length++] = current;
    visited[current] = true;

    // 贪心策略：每次选择距离当前位置最近且未访问的地点
    for (int i = 1; i < n; i++) {  // 需要访问n-1个其他地点
        int next = -1;             // 下一个地点
        int min_dist = INF;        // 最小距离

        // 寻找距离当前位置最近且未访问的地点
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && shortest_path[current][j] < min_dist) {
                next = j;
                min_dist = shortest_path[current][j];
            }
        }

        if (next == -1) {
            std::cout << "无法完成旅行！存在不可达的地点。" << std::endl;
            return;
        }

        // 更新路径和状态
        path[path_length++] = next;
        visited[next] = true;
        total_distance += min_dist;
        current = next;
    }

    // 回到起点
    if (shortest_path[current][start] != INF) {
        path[path_length++] = start;
        total_distance += shortest_path[current][start];
    }
    else {
        std::cout << "无法返回起点！" << std::endl;
        return;
    }

    // 输出旅行路径和总路程
    std::cout << "旅行路径：";
    for (int i = 0; i < path_length; i++) {
        std::cout << location[path[i]];
        if (i != path_length - 1) std::cout << " -> ";
    }
    std::cout << std::endl << "总路程：" << total_distance << std::endl;
}