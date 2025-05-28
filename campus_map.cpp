#include"campus_map.h"
#include<string>
#include<iostream>
const int MAX_ELEMENTNUM = 105;
typedef struct Edge {
	int start;
	int end;
	int w;
};
typedef struct ENode {
	std::string* data;
	int w;
	ENode* next;
};
typedef struct VNode {
	std::string* data;
	ENode* first;
};
VNode adjl[MAX_ELEMENTNUM];
int adjm[MAX_ELEMENTNUM][MAX_ELEMENTNUM];
const std::string map = "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n�U �㶫������ó��ѧ                                        ��������                                                   	�U\n�U ��У����ͼ                                            �����ة�����                                                        	�U\n�U                                                     ������    ��������                                                      	�U\n�U                                                   ������         ��������                                                   	�U\n�U                                              ������������              ��������                                                 �U\n�U                                             ����                      ��������                                              �U\n�U                                            ����                          ����������                                          �U\n�U                                           ����                               ������                                        �U\n�U                                          ����                                  ������                                      �U\n�U                                          ��                                     ������                                    �U\n�U                                          ��              �����    ��������������������¥ ������                              	�U\n�U                                         ����           �������������𩤩�����������      �������������Щ����𶫱���                           	�U\n�U                                         ��       ������������    ���ة�����         ���� ���������� ���ة�������                              	�U\n�U                                         ��  ������������        ����   ����������   �����ة�����   ������    ������������                         	�U\n�U                                   �������𩤩���            ����        �������Щ�   ������������ѧ�������� ������                      	�U\n�U                                         ��  ����������       ���ة������������������������𩤩�����    ��������           ������                  	�U\n�U                                         ��      ����������  ����        ͼ�����㳡     ��������          ����                 	�U\n�U                                         ��          ��������ͼ���                       ��������        ����                   	�U\n�U                                         ����            ��������������                 ��������������������         ����                  	�U\n�U                                          ��            ����    ����������          ��������    ʵ��¥A-E��    ����                 	�U\n�U                                          ����            ����       ����������   ��������          ����           ��                 	�U\n�U                                           ��             ����          ����������            ����            ����                	�U\n�U                                           ����             ����          ���������ѧ¥E-G������              ��                	�U\n�U                                            ������            ������������  ��������  ��          ����               ����             	�U\n�U                                              ������    ��ѧ¥A-D���𩤩���     ��   ���ĺ�����                 ��               	�U\n�U                                        �����ﲿ ������             ����       ��       �����𩤩�������������������       ����             	�U\n�U                                         ��������     ����������          ������     ��     ������ ��������       ��������������������칫¥        	�U\n�U                                            ��������      ������������       ������   ��   ������      ��������      ����������������              	�U\n�U                                               ��������        ����������     ������ �� ������           ����������������      ��           	�U\n�U                                                  ��������         ��������    �����੤��             ��˽�¥       ��              	�U\n�U                                                     ����������        �����������������³��㳡-��ѧ����             ��              	�U\n�U                                                         ��           ����������               ����            ��              	�U\n�U                                                         ���Ĳ�԰ ����������                    ��           ������        	�U\n�U                                                      �������ة���������������                        ����       ��������               	�U\n�U                                                    ������          ���³��㳡-������          ��    ��������                  	�U\n�U                                                 ��������          ������                         ������������                     	�U\n�U                                ѧ����Ԣ��Է1-4����           ������ ��                         ��ѧ����������             	�U\n�U                                                 ��         ������   ����԰                                              	�U\n�U          Gogo����ء𩤩�������                       ������     ������     ������                                                  	�U\n�U                         ������������                    ����  ������         ��                                                  	�U\n�U                              ������������                ���Щ���         ������̹���Ԣ1-4��                                     	�U\n�U                                   ������������     ѧ����Ԣ��Է5-6�������� ������                                                	�U\n�U                                        ������������       ����������������������     ������                                              	�U\n�U                                             �������������������ֿ����� ������������������                                              	�U\n�U                                              ���������������੤����              ����Է                                          	�U\n�U                                           ��������      ��  ��������           ��                                           	�U\n�U                                           ��         ��     ��������  ��������������                                           	�U\n�U                        ѧ����Ԣ��Է7-8��������         ����       ��������                                                    	�U\n�U                                         ��            ��     ������������ѧ����ҵʵ������                                    	�U\n�U                                         ��            ��������������                                                         	�U\n�U                                         ��     ����������������ѧ����Ԣ��Է9-13��                                             	�U\n�U                                         ��������������                                                                      	�U\n�U                                         ����԰                                                                      	�U\n�U                                                                                                                      	�U\n�U                                                                                                                      	�U\n�U[1]������ [2]������ [3]����¥ [4]ѧ�������� [5]����� [6]ͼ��� [7]ͼ�����㳡 [8]������ [9]������ [10]��ѧ¥ A-D ��  �U\n�U[11]��ѧ¥ E-G �� [12]ʵ��¥ A-E �� [13]���ĺ� [14]�˽�¥ [15]�칫¥ [16]ѧ���������� [17]�³��㳡 - ��ѧ��            �U\n�U[18]�³��㳡 - ������ [19]�Ĳ�԰ [20]����԰ [21]����԰ [22]���ﲿ [23]ѧ����Ԣ��Է 1-4 �� [24]ѧ����Ԣ��Է 5-6 ��	�U\n�U[25]ѧ����Ԣ��Է 7-8 �� [26]ѧ����Ԣ��Է 9-13 �� [27]�̹���Ԣ 1-4 �� [28]��Է [29]�ֿ����� [30]ѧ����ҵʵ������        �U\n�U[31]Gogo �����                                                                                                        �U\n�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a";
std::string location[MAX_ELEMENTNUM];
std::string intro[MAX_ELEMENTNUM];

void printmap()
{
	std::cout << map << std::endl;
	return;
}

int find_index(std::string& target)
{

}

std::string* find_location(std::string& target)
{

}

void creatgraph()
{
	int n,m;
	std::cin >> n;
	VNode* vl = new VNode[n + 1];
	getchar();
	for (int i = 1; i <= n; i++)
	{
		std::getline(std::cin, location[i]);
		getchar();
		std::getline(std::cin, intro[i]);
		getchar();
		vl[i].data = location + i;
		vl[i].first = nullptr;
	}
	std::cin >> m;
	Edge* e = new Edge[m + 1];
	getchar();
	for (int i = 1; i <= m; i++)
	{
		std::string start, end;
		int w;
		std::getline(std::cin, start);
		getchar();
		std::getline(std::cin, end);
		getchar();

		e[i].start = find_index(start);
		e[i].end = find_index(end);
		std::string* head = find_location(start);
		std::string* tail = find_location(end);

		std::cin >> e[i].w;
		adjm[e[i].start][e[i].end] = adjm[e[i].end][e[i].start] = e[i].w;

		ENode* el = new ENode;
		el->data = tail;
		el->w = e[i].w;
		el->next = vl[e[i].start].first;
		vl[e[i].start].first = el;

		el->data = head;
		el->w = e[i].w;
		el->next = vl[e[i].end].first;
		vl[e[i].end].first = el;
	}
}
