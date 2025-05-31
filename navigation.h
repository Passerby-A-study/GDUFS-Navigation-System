#pragma once
#include <string>

extern int steps;
extern int cur;

// 定义 user 结构体
struct user {
    std::string name;
    int step;
};

extern user* rankings; // 全局动态数组存储排行榜
extern int rank_size;  // 排行榜大小

void print_recommend(int start, int end);
void print_total_step();
void printchoices(int cur);
bool go();
void printrank();
void print_intro(int cur);
void creatrank(int steps);