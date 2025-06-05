/**
 * @file navigation.h
 * @brief �������ܵ�ͷ�ļ���
 * ����������صĺ��������ݽṹ������ʵʱ�����Ͳ�����¼��
 */

#pragma once
#include <string>

 /**
  * @brief ��¼��ǰ�ܲ�����
  */
extern int steps;

/**
 * @brief ��¼��ǰ����λ�õ�������
 */
extern int cur;

/**
 * @brief ��ʾ�û��ṹ�Ľṹ�壬���������Ͳ�����
 */
struct user {
    std::string name;   /**< �û������� */
    int step;           /**< �û������� */
};

/**
 * @brief ȫ�ֶ�̬���飬�洢���а����ݡ�
 */
extern user* rankings;

/**
 * @brief ���а�Ĵ�С��
 */
extern int rank_size;

/**
 * @brief ��ӡ�Ƽ�·����
 * ���������յ��ӡ���·����
 *
 * @param start ��ʼλ��������
 * @param end ��ֹλ��������
 */
void print_recommend(int start, int end);

/**
 * @brief ��ӡ�ܲ�����
 * �����ǰ�ۼƵĲ�����
 */
void print_total_step();

/**
 * @brief ��ӡ��ǰ��ѡ���λ�á�
 * �г��ӵ�ǰλ�ÿ�ǰ���ĵص㡣
 *
 * @param cur ��ǰλ��������
 */
void printchoices(int cur);

/**
 * @brief ������ָ���ص㡣
 * �����û����뵼������һ���ص㣬�����²����͵�ǰλ�á�
 *
 * @param des Ŀ��λ��������
 * @return true �������������false ����˳�������
 */
bool go(int des);

/**
 * @brief ��ӡ���а�
 * ��ʾ��ǰ���а����ݣ������������û����Ͳ�����
 */
void printrank();

/**
 * @brief ��ӡ��ǰ�ص�Ľ��ܡ�
 * �����ǰλ�õ����ƺͼ�顣
 *
 * @param cur ��ǰλ��������
 */
void print_intro(int cur);

/**
 * @brief ������������а�
 * ���ݵ�ǰ�����������а񣬲����ļ�������ʷ���ݡ�
 *
 * @param steps ��ǰ������
 */
void creatrank(int steps);