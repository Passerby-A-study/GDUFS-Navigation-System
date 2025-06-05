/**
 * @file campus_map.h
 * @brief У԰��ͼ�����ͼ��ʾ��ͷ�ļ���
 * ���ļ�����У԰��ͼͼ�Ķ��壬�����ڽӾ����ڽӱ���صĵ�ͼ��ʼ���Ͳ�ѯ������
 */

#pragma once
#include <string>

 /**
  * @brief ͼ�����Ԫ��������
  */
const int MAX_ELEMENTNUM = 105;

/**
 * @brief �ڽӾ�����δ���ӽڵ�ʹ�õ������ֵ��
 */
const int INF = 10086;

/**
 * @brief ��ʾͼ�бߵĽṹ��������㡢�յ��Ȩ�ء�
 */
typedef struct Edge {
    int start;  /**< ��ʼ�ڵ������� */
    int end;    /**< ��ֹ�ڵ������� */
    int w;      /**< �ߵ�Ȩ�أ������ɱ����� */
} Edge;

/**
 * @brief �ڽӱ��еĽڵ�ṹ���������ݺ���һ��ָ�롣
 */
typedef struct ENode {
    std::string* data;  /**< ָ��λ���ַ�����ָ�롣 */
    int w;              /**< �ߵ�Ȩ�ء� */
    ENode* next;        /**< ָ���б�����һ���ڵ��ָ�롣 */
};

/**
 * @brief �ڽӱ��еĶ���ṹ���������ݺ͵�һ���ߡ�
 */
typedef struct VNode {
    std::string* data;  /**< ָ��λ���ַ�����ָ�롣 */
    ENode* first;       /**< ָ���һ���߽ڵ��ָ�롣 */
};

/**
 * @brief ȫ�ֶ������飬�����ڽӱ�
 */
extern VNode adjl[MAX_ELEMENTNUM];

/**
 * @brief ȫ���ڽӾ��󣬱�ʾͼ�ṹ��
 */
extern int adjm[MAX_ELEMENTNUM][MAX_ELEMENTNUM];

/**
 * @brief ȫ�ֳ����ַ�������ʾУ԰��ͼ���֡�
 */
extern const std::string map;

/**
 * @brief λ���������顣
 */
extern std::string location[MAX_ELEMENTNUM];

/**
 * @brief λ�ü�����顣
 */
extern std::string intro[MAX_ELEMENTNUM];

/**
 * @brief ͼ�еĶ���������
 */
extern int n;

/**
 * @brief ͼ�еı�������
 */
extern int m;

/**
 * @brief ��̬����Ķ����б�ָ�롣
 */
extern VNode* vl;

/**
 * @brief ��ӡУ԰��ͼ��
 * ʹ��Ԥ����ĵ�ͼ�ַ������У԰���֣���Ӧ����ɫ��������ǿ��ʾЧ����
 *
 * @note �ú���������ȫ�ֱ��� `map` ����ɫ���ú��� `set_text_color` �� `reset_text_color`��
 */
void printmap();

/**
 * @brief ����Ŀ��λ�õ�������
 * �� `location` ������������Ŀ���ַ���ƥ���������
 *
 * @param target Ŀ��λ�����ơ�
 * @return ƥ���������1 �� n������δ�ҵ��򷵻� 0��
 */
int find_index(std::string& target);

/**
 * @brief ����Ŀ��λ�õ�ָ�롣
 * �� `location` ������������Ŀ���ַ���ƥ��ĵ�ַ��
 *
 * @param target Ŀ��λ�����ơ�
 * @return ƥ��λ�õ�ָ�룬��δ�ҵ��򷵻� nullptr��
 */
std::string* find_location(std::string& target);

/**
 * @brief ����ͼ���ڽӾ�����ڽӱ�
 * �������ļ���ȡ�ص�ͱ���Ϣ����ʼ���ڽӾ�����ڽӱ������� Floyd �㷨��
 *
 * @note �����ļ� "input.txt"�����ļ������ڻ��ʽ�������������Ϣ��
 */
void creatgraph();

/**
 * @brief ��ӡ�ڽӾ���
 * ���ͼ���ڽӾ��󣬲���������浽�ļ� "adj_matrix.txt"��
 */
void print_adjm();

/**
 * @brief ��ӡ�ڽӱ�
 * ���ͼ���ڽӱ�����������浽�ļ� "adj_list.txt"��
 */
void print_adjl();

/**
 * @brief ���ڽӾ���������ļ���
 * ����ǰ���ڽӾ���д�� "adj_matrix.txt" �ļ���
 */
void output_adj_matrix_to_file();

/**
 * @brief ���ڽӱ�������ļ���
 * ����ǰ���ڽӱ�д�� "adj_list.txt" �ļ���
 */
void output_adj_list_to_file();