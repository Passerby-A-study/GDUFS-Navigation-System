/**
 * @file campus_map.h
 * @brief 校园地图管理和图表示的头文件。
 * 该文件包含校园地图图的定义，包括邻接矩阵、邻接表及相关的地图初始化和查询函数。
 */

#pragma once
#include <string>

 /**
  * @brief 图中最大元素数量。
  */
const int MAX_ELEMENTNUM = 105;

/**
 * @brief 邻接矩阵中未连接节点使用的无穷大值。
 */
const int INF = 10086;

/**
 * @brief 表示图中边的结构，包含起点、终点和权重。
 */
typedef struct Edge {
    int start;  /**< 起始节点索引。 */
    int end;    /**< 终止节点索引。 */
    int w;      /**< 边的权重（距离或成本）。 */
} Edge;

/**
 * @brief 邻接表中的节点结构，包含数据和下一个指针。
 */
typedef struct ENode {
    std::string* data;  /**< 指向位置字符串的指针。 */
    int w;              /**< 边的权重。 */
    ENode* next;        /**< 指向列表中下一个节点的指针。 */
};

/**
 * @brief 邻接表中的顶点结构，包含数据和第一条边。
 */
typedef struct VNode {
    std::string* data;  /**< 指向位置字符串的指针。 */
    ENode* first;       /**< 指向第一条边节点的指针。 */
};

/**
 * @brief 全局顶点数组，用于邻接表。
 */
extern VNode adjl[MAX_ELEMENTNUM];

/**
 * @brief 全局邻接矩阵，表示图结构。
 */
extern int adjm[MAX_ELEMENTNUM][MAX_ELEMENTNUM];

/**
 * @brief 全局常量字符串，表示校园地图布局。
 */
extern const std::string map;

/**
 * @brief 位置名称数组。
 */
extern std::string location[MAX_ELEMENTNUM];

/**
 * @brief 位置简介数组。
 */
extern std::string intro[MAX_ELEMENTNUM];

/**
 * @brief 图中的顶点数量。
 */
extern int n;

/**
 * @brief 图中的边数量。
 */
extern int m;

/**
 * @brief 动态分配的顶点列表指针。
 */
extern VNode* vl;

/**
 * @brief 打印校园地图。
 * 使用预定义的地图字符串输出校园布局，并应用颜色设置以增强显示效果。
 *
 * @note 该函数依赖于全局变量 `map` 和颜色设置函数 `set_text_color` 和 `reset_text_color`。
 */
void printmap();

/**
 * @brief 查找目标位置的索引。
 * 在 `location` 数组中搜索与目标字符串匹配的索引。
 *
 * @param target 目标位置名称。
 * @return 匹配的索引（1 到 n），若未找到则返回 0。
 */
int find_index(std::string& target);

/**
 * @brief 查找目标位置的指针。
 * 在 `location` 数组中搜索与目标字符串匹配的地址。
 *
 * @param target 目标位置名称。
 * @return 匹配位置的指针，若未找到则返回 nullptr。
 */
std::string* find_location(std::string& target);

/**
 * @brief 创建图的邻接矩阵和邻接表。
 * 从输入文件读取地点和边信息，初始化邻接矩阵和邻接表，并运行 Floyd 算法。
 *
 * @note 依赖文件 "input.txt"，若文件不存在或格式错误将输出错误信息。
 */
void creatgraph();

/**
 * @brief 打印邻接矩阵。
 * 输出图的邻接矩阵，并将结果保存到文件 "adj_matrix.txt"。
 */
void print_adjm();

/**
 * @brief 打印邻接表。
 * 输出图的邻接表，并将结果保存到文件 "adj_list.txt"。
 */
void print_adjl();

/**
 * @brief 将邻接矩阵输出到文件。
 * 将当前的邻接矩阵写入 "adj_matrix.txt" 文件。
 */
void output_adj_matrix_to_file();

/**
 * @brief 将邻接表输出到文件。
 * 将当前的邻接表写入 "adj_list.txt" 文件。
 */
void output_adj_list_to_file();