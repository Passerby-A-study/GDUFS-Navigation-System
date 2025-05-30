#include "campus_map.h"
#include "path_finding.h"
#include <string>
#include <iostream>
#include <limits>
#include <sstream>
#include <fstream>
#include <iomanip>

VNode adjl[MAX_ELEMENTNUM];
int adjm[MAX_ELEMENTNUM][MAX_ELEMENTNUM];
const std::string map ="�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n�U �㶫������ó��ѧ                                        ��������                                                   	 �U\n�U ��У����ͼ                                            �����ة�����                                                        	 �U\n�U                                                     ������    ��������                                                      	 �U\n�U                                                   ������         ��������                                                   	 �U\n�U                                              ������������              ��������                                                 �U\n�U                                             ����                      ��������                                              �U\n�U                                            ����                          ����������                                          �U\n�U                                           ����                               ������                                        �U\n�U                                          ����                                  ������                                      �U\n�U                                          ��                                     ������                                    �U\n�U                                          ��              �����    ��������������������¥ ������                              	 �U\n�U                                         ����           �������������𩤩�����������      �������������Щ����𶫱���                           	 �U\n�U                                         ��       ������������    ���ة�����         ���� ���������� ���ة�������                              	 �U\n�U                                         ��  ������������        ����   ����������   �����ة�����   ������    ������������                         	 �U\n�U                                   �������𩤩���            ����        �������Щ�   ������������ѧ�������� ������                      	 �U\n�U                                         ��  ����������       ���ة������������������������𩤩�������    ������           ������                  	 �U\n�U                                         ��      ����������  ����        ͼ�����㳡     ��������          ����                 	 �U\n�U                                         ��          ��������ͼ���                       ��������        ����                   	 �U\n�U                                         ����            ��������������                 ��������������������         ����                  	 �U\n�U                                          ��            ����    ����������          ��������    ʵ��¥A-E��    ����                 	 �U\n�U                                          ����            ����       ����������   ��������          ����           ��                 	 �U\n�U                                           ��             ����          ����������            ����            ����                	 �U\n�U                                           ����             ����          ���������ѧ¥E-G������              ��                	 �U\n�U                                            ������            ������������  ��������  ��          ����               ����             	 �U\n�U                                              ������    ��ѧ¥A-D���𩤩���     ��   ���ĺ�����                 ��               	 �U\n�U                                        �����ﲿ ������             ����       ��       �����𩤩�������������������       ����             	 �U\n�U                                         ��������     ����������          ������     ��     ������ ��������       ��������������������칫¥        	 �U\n�U                                            ��������      ������������       ������   ��   ������      ��������      ����������������              	 �U\n�U                                               ��������        ����������     ������ �� ������           ����������������      ��           	 �U\n�U                                                  ��������         ��������    �����੤��             ��˽�¥       ��              	 �U\n�U                                                     ����������        �����������������³��㳡-��ѧ����             ��              	 �U\n�U                                                         ��           ����������               ����            ��              	 �U\n�U                                                         ���Ĳ�԰ ����������                    ��           ������        	 �U\n�U                                                      �������ة���������������                        ����       ��������               	 �U\n�U                                                    ������          ���³��㳡-������          ��    ��������                  	 �U\n�U                                                 ��������          ������                         ������������                     	 �U\n�U                                ѧ����Ԣ��Է1-4����           ������ ��                         ��ѧ����������             	 �U\n�U                                                 ��         ������   ����԰                                              	 �U\n�U          Gogo����ء𩤩�������                       ������     ������     ������                                                  	 �U\n�U                         ������������                    ����  ������         ��                                                  	 �U\n�U                              ������������                ���Щ���         ������̹���Ԣ1-4��                                     	 �U\n�U                                   ������������     ѧ����Ԣ��Է5-6�������� ������                                                	 �U\n�U                                        ������������       ����������������������     ������                                              	 �U\n�U                                             �������������������ֿ����� ������������������                                              	 �U\n�U                                              ���������������੤����              ����Է                                          	 �U\n�U                                           ��������      ��  ��������           ��                                           	 �U\n�U                                           ��         ��     ��������  ��������������                                           	 �U\n�U                        ѧ����Ԣ��Է7-8��������         ����       ��������                                                    	 �U\n�U                                         ��            ��     ������������ѧ����ҵʵ������                                    	 �U\n�U                                         ��            ��������������                                                         	 �U\n�U                                         ��     ����������������ѧ����Ԣ��Է9-13��                                             	 �U\n�U                                         ��������������                                                                      	 �U\n�U                                         ����԰                                                                      	 �U\n�U                                                                                                                      	 �U\n�U                                                                                                                      	 �U\n�U[1]������ [2]������ [3]����¥ [4]ѧ�������� [5]����� [6]ͼ��� [7]ͼ�����㳡 [8]������ [9]������ [10]��ѧ¥ A-D ��  �U\n�U[11]��ѧ¥ E-G �� [12]ʵ��¥ A-E �� [13]���ĺ� [14]�˽�¥ [15]�칫¥ [16]ѧ���������� [17]�³��㳡 - ��ѧ��            �U\n�U[18]�³��㳡 - ������ [19]�Ĳ�԰ [20]����԰ [21]���԰ [22]���ﲿ [23]ѧ����Ԣ��Է 1-4 �� [24]ѧ����Ԣ��Է 5-6 ��	 �U\n�U[25]ѧ����Ԣ��Է 7-8 �� [26]ѧ����Ԣ��Է 9-13 �� [27]�̹���Ԣ 1-4 �� [28]��Է [29]�ֿ����� [30]ѧ����ҵʵ������        �U\n�U[31]Gogo �����                                                                                                        �U\n�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a";
std::string location[MAX_ELEMENTNUM];
std::string intro[MAX_ELEMENTNUM];
int n, m;
VNode* vl;

void printmap()
{
    std::cout << map << std::endl;
    return;
}

int find_index(std::string& target)
{
    for (int i = 1; i <= n; i++)
    {
        if (target == location[i])
        {
            return i;
        }
    }
    return 0; // �Ҳ���ʱ���� 0����ʾ��Ч����
}

std::string* find_location(std::string& target)
{
    for (int i = 1; i <= n; i++)
    {
        if (target == location[i])
        {
            return &location[i];
        }
    }
    return nullptr; // �Ҳ���ʱ���� nullptr
}

void creatgraph()
{
    // ��ʼ���ڽӾ���
    for (int i = 0; i < MAX_ELEMENTNUM; i++)
    {
        for (int j = 0; j < MAX_ELEMENTNUM; j++)
        {
            adjm[i][j] = INF;
        }
    }

    // ���ļ�
    std::ifstream fin("input.txt");
    if (!fin) {
        std::cout << "�����޷��� input.txt �ļ�����ȷ���ļ����ڲ�λ�ڳ���Ŀ¼�¡�" << std::endl;
        return;
    }

    // ��ȡ�ص����� n
    fin >> n;
    fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // �����з�

    // ��̬���� vl ����
    vl = new VNode[n + 1];

    // ��ȡ�ص�ͼ��
    for (int i = 1; i <= n; i++)
    {
        std::string line;
        std::getline(fin, line); // ���ж�ȡ�������룬�� "������ ѧУ����"

        // �ָ�ص�ͼ��
        size_t pos = line.find(' ');
        if (pos != std::string::npos)
        {
            location[i] = line.substr(0, pos); // ��ȡ�ص������� "������"
            intro[i] = line.substr(pos + 1);   // ��ȡ��飬�� "ѧУ����"
        }
        else
        {
            location[i] = line; // ���û�м�飬ֻ�еص���
            intro[i] = "";
        }

        vl[i].data = &location[i]; // ���� VNode �� data ָ��
        vl[i].first = nullptr;     // ��ʼ���ڽӱ�
    }

    // ��ȡ�ߵ����� m
    fin >> m;
    fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // �����з�

    // ��̬���� Edge ����
    Edge* e = new Edge[m + 1];

    // ��ȡ����Ϣ
    for (int i = 1; i <= m; i++)
    {
        std::string line;
        std::getline(fin, line); // ��ȡ���У����� "������ ����¥ 108"

        std::stringstream ss(line);
        std::string start, end;
        int w;

        // ��ȡ��㡢�յ��Ȩ��
        ss >> start; // ��ȡ��һ���ʣ���㣩
        std::string temp;
        while (ss >> temp) {
            if (ss >> std::ws && ss.peek() >= '0' && ss.peek() <= '9') {
                end = end.empty() ? temp : end + " " + temp;
                break;
            }
            end = end.empty() ? temp : end + " " + temp;
        }
        ss >> w; // ��ȡȨ��

        // �洢����Ϣ
        e[i].start = find_index(start);
        e[i].end = find_index(end);
        e[i].w = w;

        // ����Ƿ��ҵ���Ч�������յ�
        if (e[i].start == 0 || e[i].end == 0)
        {
            std::cout << "�����޷��ҵ��ص� " << start << " �� " << end << std::endl;
            continue;
        }

        // �����ڽӾ�������ͼ��
        adjm[e[i].start][e[i].end] = adjm[e[i].end][e[i].start] = e[i].w;

        // �����ڽӱ�����ͼ��˫��ߣ�
        std::string* head = &location[e[i].start];
        std::string* tail = &location[e[i].end];

        // Ϊ�����ӱ�
        ENode* el_start = new ENode;
        el_start->data = tail;
        el_start->w = e[i].w;
        el_start->next = vl[e[i].start].first;
        vl[e[i].start].first = el_start;

        // Ϊ�յ���ӱ�
        ENode* el_end = new ENode;
        el_end->data = head;
        el_end->w = e[i].w;
        el_end->next = vl[e[i].end].first;
        vl[e[i].end].first = el_end;
    }

    // ���� Floyd �㷨
    floyd();

    // �ͷ� Edge ����
    delete[] e;

    // �ر��ļ�
    fin.close();
}

void print_adjm()
{
    // ��ӡ��ͷ����һ��Ϊ�գ��ӵڶ��п�ʼ��ӡ�ص�����
    std::cout << std::left << std::setw(20) << ""; // ��һ��Ϊ�գ������б�ǩ
    for (int j = 1; j <= n; j++) {
        std::cout << std::left << std::setw(20) << location[j];
    }
    std::cout << std::endl;

    // ��ӡ����ʹ�ù̶���� 20 ����
    for (int i = 1; i <= n; i++) {
        std::cout << std::left << std::setw(20) << location[i];
        for (int j = 1; j <= n; j++) {
            if (adjm[i][j] == INF) {
                std::cout << std::left << std::setw(20) << "INF";
            }
            else {
                std::cout << std::left << std::setw(20) << adjm[i][j];
            }
        }
        std::cout << std::endl;
    }
    output_adj_matrix_to_file();
}
void print_adjl()
{
    for (int i = 1; i <= n; i++)
    {
        ENode* p = vl[i].first;
        std::cout << *(vl[i].data) << " : ";
        while (p != nullptr)
        {
            std::cout << *(p->data) << " (" << p->w << ")  ";
            p = p->next;
        }
        std::cout << std::endl; // ��ӻ���
    }
    output_adj_list_to_file();
}

// ����ڽӾ����ļ�
void output_adj_matrix_to_file()
{
    std::ofstream fout("adj_matrix.txt");
    if (!fout) {
        std::cout << "�����޷�������� adj_matrix.txt �ļ���" << std::endl;
        return;
    }

    fout << "�ڽӾ���" << std::endl;

    // ��ӡ��ͷ����һ��Ϊ�գ��ӵڶ��п�ʼ��ӡ�ص�����
    fout << std::left << std::setw(20) << "";
    for (int j = 1; j <= n; j++) {
        fout << std::left << std::setw(20) << location[j];
    }
    fout << std::endl;

    // ��ӡ����
    for (int i = 1; i <= n; i++) {
        fout << std::left << std::setw(20) << location[i];
        for (int j = 1; j <= n; j++) {
            if (adjm[i][j] == INF) {
                fout << std::left << std::setw(20) << "INF";
            }
            else {
                fout << std::left << std::setw(20) << adjm[i][j];
            }
        }
        fout << std::endl;
    }

    fout.close();
    std::cout << "�ڽӾ���������� adj_matrix.txt �ļ���" << std::endl;
}

// ����ڽӱ��ļ�
void output_adj_list_to_file()
{
    std::ofstream fout("adj_list.txt");
    if (!fout) {
        std::cout << "�����޷�������� adj_list.txt �ļ���" << std::endl;
        return;
    }

    fout << "�ڽӱ�" << std::endl;
    for (int i = 1; i <= n; i++) {
        ENode* p = vl[i].first;
        fout << std::left << std::setw(20) << *(vl[i].data) << " : ";
        while (p != nullptr) {
            fout << std::left << std::setw(20) << *(p->data) << " (" << p->w << ")  ";
            p = p->next;
        }
        fout << std::endl;
    }

    fout.close();
    std::cout << "�ڽӱ�������� adj_list.txt �ļ���" << std::endl;
}