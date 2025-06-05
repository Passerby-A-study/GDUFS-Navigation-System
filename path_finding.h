/**
 * @file path_finding.h
 * @brief 路径规划的头文件。
 * 包含最短路径计算和路径恢复的相关函数，使用 Floyd 算法。
 */

#pragma once
#include "campus_map.h"

 /**
  * @brief 存储最短路径长度的二维数组。
  */
extern int shortest_path[MAX_ELEMENTNUM][MAX_ELEMENTNUM];

/**
 * @brief 存储前驱节点的二维数组，用于恢复路径。
 */
extern int prev[MAX_ELEMENTNUM][MAX_ELEMENTNUM];

/**
 * @brief 使用 Floyd 算法计算所有点对之间的最短路径。
 * 初始化并更新 `shortest_path` 和 `prev` 数组。
 */
void floyd();

/**
 * @brief 打印起点到终点的最短路径。
 *
 * @param start 起始位置索引。
 * @param end 终止位置索引。
 */
void print_path_start_end(int start, int end);

/**
 * @brief 打印从起点到所有地点的最短路径。
 *
 * @param start 起始位置索引。
 */
void print_all_paths_from(int start);

/**
 * @brief 模拟从起点环游校园。
 * 使用贪心策略访问所有地点并返回起点。
 *
 * @param start 起始位置索引。
 */
void travel(int start);

/**
 * @brief 打印前驱数组。
 * 显示每个节点的前驱信息，用于调试。
 */
void print_prev_array();