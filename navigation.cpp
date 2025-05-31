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

void creatrank(int steps) {
    // 1. ����ͳ�� rank.txt �еļ�¼��
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

    // 2. �ͷžɵ� rankings ���飨������ڣ�
    if (rankings != nullptr) {
        delete[] rankings;
        rankings = nullptr;
        rank_size = 0;
    }

    // 3. ���������飨�ļ��еļ�¼�� + ��ǰ�û���
    rank_size = file_count + 1; // ���ٰ�����ǰ�û�
    rankings = new user[rank_size];

    // 4. ��ӵ�ǰ�û�
    rankings[0].name = "��";
    rankings[0].step = steps;

    // 5. ����ļ����ڣ���ȡ����
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

    // 6. ѡ�����򣨰���������
    for (int i = 0; i < rank_size - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < rank_size; j++) {
            if (rankings[j].step > rankings[max_idx].step) { // ��Ϊ���ڣ�����
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

void print_recommend(int start, int end) {
    print_path_start_end(start, end);
}

void print_total_step() {
    std::cout << "������" << steps << std::endl;
}

void print_intro(int cur) {
    std::cout << "��ӭ����" << location[cur]
        << "��\n��飺" << intro[cur] << std::endl;
}

void printchoices(int cur) {
    ENode* e = vl[cur].first;
    int i = 1;
    std::cout << "�ܹ�ǰ���ĵص㣺" << std::endl;
    while (e != nullptr) {
        std::cout << "(" << i << ") " << *(e->data) << '\t';
        i++;
        e = e->next;
    }
}

bool go() {
    std::string next;
    int next_index;
    while (true) {
        std::cout << "��������һ���ص�����ƣ������м䲻Ҫ�пո�,���롰�˳������˳���������" << std::endl;
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
    return true;
}

void printrank() {
    if (rank_size == 0 || rankings == nullptr) {
        std::cout << "���а�Ϊ�գ�" << std::endl;
        return;
    }

    // ������ʾ�����а񡱣��ܿ�� 45
    std::cout << std::string(20, '=') << " ���а� " << std::string(19, '=') << std::endl;

    // ���ñ�ͷ��ÿ�п��Ϊ 15
    std::cout << std::left << std::setw(15) << "����"
        << std::setw(15) << "�û���"
        << std::setw(15) << "����" << std::endl;

    // ����ָ���
    std::cout << std::string(47, '-') << std::endl;

    // ������а�����
    for (int i = 0; i < rank_size; i++) {
        std::cout << std::left << std::setw(15) << (i + 1)
            << std::setw(15) << rankings[i].name
            << std::setw(15) << rankings[i].step << std::endl;
    }
}