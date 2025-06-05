/**
 * @file path_finding.cpp
 * @brief 路径规划实现的源文件。
 * 包含 Floyd 算法和路径恢复的具体实现。
 */

#include "path_finding.h"
#include "mystack.h"
#include <iostream>

int shortest_path[MAX_ELEMENTNUM][MAX_ELEMENTNUM];
int prev[MAX_ELEMENTNUM][MAX_ELEMENTNUM];

void floyd()
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            shortest_path[i][j] = adjm[i][j];
            prev[i][j] = (i == j) ? -1 : ((adjm[i][j] != INF) ? i : -1);
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (shortest_path[i][k] != INF && shortest_path[k][j] != INF &&
                    (shortest_path[i][j] == INF || shortest_path[i][j] > shortest_path[i][k] + shortest_path[k][j])) {
                    shortest_path[i][j] = shortest_path[i][k] + shortest_path[k][j];
                    prev[i][j] = k;
                }
            }
        }
    }
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
                std::cout << "\t" << location[prev[i][j]];
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
        if (current == prev[start][current]) break;
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

void print_all_paths_from(int start)
{
    if (start < 1 || start > n) {
        std::cout << "无效的起点！" << std::endl;
        return;
    }

    std::cout << "从 " << location[start] << " 到各点的最短路径：" << std::endl;
    for (int end = 1; end <= n; end++) {
        if (start == end) continue;

        if (shortest_path[start][end] == INF) {
            std::cout << "到 " << location[end] << "：不可达" << std::endl;
            continue;
        }

        mystack<int> pathStack;
        int current = end;
        while (current != -1 && current != start) {
            pathStack.push(current);
            current = prev[start][current];
            if (current == prev[start][current]) break;
        }
        if (current == start) pathStack.push(current);

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

    bool visited[MAX_ELEMENTNUM] = { false };
    int path[MAX_ELEMENTNUM];
    int path_length = 0;
    int current = start;
    int total_distance = 0;

    path[path_length++] = current;
    visited[current] = true;

    for (int i = 1; i < n; i++) {
        int next = -1;
        int min_dist = INF;

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

        path[path_length++] = next;
        visited[next] = true;
        total_distance += min_dist;
        current = next;
    }

    if (shortest_path[current][start] != INF) {
        path[path_length++] = start;
        total_distance += shortest_path[current][start];
    }
    else {
        std::cout << "无法返回起点！" << std::endl;
        return;
    }

    std::cout << "旅行路径：";
    for (int i = 0; i < path_length; i++) {
        std::cout << location[path[i]];
        if (i != path_length - 1) std::cout << " -> ";
    }
    std::cout << std::endl << "总路程：" << total_distance << std::endl;
}