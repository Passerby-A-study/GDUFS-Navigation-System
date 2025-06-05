/**
 * @file navigation.h
 * @brief 导航功能的头文件。
 * 包含导航相关的函数和数据结构，用于实时导航和步数记录。
 */

#pragma once
#include <string>

 /**
  * @brief 记录当前总步数。
  */
extern int steps;

/**
 * @brief 记录当前所在位置的索引。
 */
extern int cur;

/**
 * @brief 表示用户结构的结构体，包含姓名和步数。
 */
struct user {
    std::string name;   /**< 用户姓名。 */
    int step;           /**< 用户步数。 */
};

/**
 * @brief 全局动态数组，存储排行榜数据。
 */
extern user* rankings;

/**
 * @brief 排行榜的大小。
 */
extern int rank_size;

/**
 * @brief 打印推荐路径。
 * 根据起点和终点打印最短路径。
 *
 * @param start 起始位置索引。
 * @param end 终止位置索引。
 */
void print_recommend(int start, int end);

/**
 * @brief 打印总步数。
 * 输出当前累计的步数。
 */
void print_total_step();

/**
 * @brief 打印当前可选择的位置。
 * 列出从当前位置可前往的地点。
 *
 * @param cur 当前位置索引。
 */
void printchoices(int cur);

/**
 * @brief 导航到指定地点。
 * 根据用户输入导航到下一个地点，并更新步数和当前位置。
 *
 * @param des 目标位置索引。
 * @return true 如果导航继续，false 如果退出导航。
 */
bool go(int des);

/**
 * @brief 打印排行榜。
 * 显示当前排行榜数据，包括排名、用户名和步数。
 */
void printrank();

/**
 * @brief 打印当前地点的介绍。
 * 输出当前位置的名称和简介。
 *
 * @param cur 当前位置索引。
 */
void print_intro(int cur);

/**
 * @brief 创建或更新排行榜。
 * 根据当前步数更新排行榜，并从文件加载历史数据。
 *
 * @param steps 当前步数。
 */
void creatrank(int steps);