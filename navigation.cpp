/**
 * @file navigation.cpp
 * @brief �������ܵ�ʵ��Դ�ļ���
 * ���������߼���������¼�����а����ľ���ʵ�֡�
 */

#include "navigation.h"
#include "path_finding.h"
#include "campus_map.h"
#include "user_interface.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

int steps = 0;
int cur = 0;
user* rankings = nullptr;
int rank_size = 0;

void creatrank(int steps)
{
    std::ifstream fin("rank.txt");
    int file_count = 0;
    std::string temp_name;
    int temp_step;

    if (fin) {
        while (fin >> temp_name >> temp_step) {
            file_count++;
        }
        fin.close();
    }
    else {
        std::cout << "���棺�޷��� rank.txt �ļ��������������������ݵ����а�" << std::endl;
    }

    if (rankings != nullptr) {
        delete[] rankings;
        rankings = nullptr;
        rank_size = 0;
    }

    rank_size = file_count + 1;
    rankings = new user[rank_size];

    rankings[0].name = "��";
    rankings[0].step = steps;

    if (file_count > 0) {
        fin.open("rank.txt");
        int index = 1;
        while (fin >> temp_name >> temp_step) {
            rankings[index].name = temp_name;
            rankings[index].step = temp_step;
            index++;
        }
        fin.close();
    }

    for (int i = 0; i < rank_size - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < rank_size; j++) {
            if (rankings[j].step > rankings[max_idx].step) {
                max_idx = j;
            }
        }
        if (max_idx != i) {
            user temp = rankings[i];
            rankings[i] = rankings[max_idx];
            rankings[max_idx] = temp;
        }
    }
}

void print_recommend(int start, int end)
{
    print_path_start_end(start, end);
}

void print_total_step()
{
    std::cout << "������" << steps << std::endl;
}

void print_intro(int cur)
{
    std::cout << "��ӭ����" << location[cur]
        << "��\n��飺" << intro[cur] << std::endl;
}

void printchoices(int cur)
{
    ENode* e = vl[cur].first;
    int i = 1;
    std::cout << "�ܹ�ǰ���ĵص㣺" << std::endl;
    while (e != nullptr) {
        std::cout << "(" << i << ") " << *(e->data) << '\t';
        i++;
        e = e->next;
    }
    std::cout << std::endl;
}

bool go(int des)
{
    std::string next;
    int next_index;
    while (true) {
        std::cout << std::endl;
        std::cout << "��������һ���ص�����ƣ������м䲻Ҫ�пո�,���롰�˳������˳���������";
        getline(std::cin, next);
        if (next == "�˳�") return false;
        next_index = find_index(next);
        if (next_index == 0) {
            std::cout << "��Ч����㣬���������룡" << std::endl;
            continue;
        }
        break;
    }
    steps += adjm[cur][next_index];
    cur = next_index;
    if (cur == des)
    {
        std::cout << "����������" << std::endl;
        std::cout << "\n\n";
        sleep();
        return false;
    }
    return true;
}

void printrank()
{
    if (rank_size == 0 || rankings == nullptr) {
        std::cout << "���а�Ϊ�գ�" << std::endl;
        return;
    }

    std::cout << std::string(20, '=') << " ���а� " << std::string(19, '=') << std::endl;

    std::cout << std::left << std::setw(15) << "����"
        << std::setw(15) << "�û���"
        << std::setw(15) << "����" << std::endl;

    std::cout << std::string(47, '-') << std::endl;

    for (int i = 0; i < rank_size; i++) {
        std::cout << std::left << std::setw(15) << (i + 1)
            << std::setw(15) << rankings[i].name
            << std::setw(15) << rankings[i].step << std::endl;
    }
}