#pragma once
#include <string>

extern int steps;
extern int cur;

// ���� user �ṹ��
struct user {
    std::string name;
    int step;
};

extern user* rankings; // ȫ�ֶ�̬����洢���а�
extern int rank_size;  // ���а��С

void print_recommend(int start, int end);
void print_total_step();
void printchoices(int cur);
bool go();
void printrank();
void print_intro(int cur);
void creatrank(int steps);