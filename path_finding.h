/**
 * @file path_finding.h
 * @brief ·���滮��ͷ�ļ���
 * �������·�������·���ָ�����غ�����ʹ�� Floyd �㷨��
 */

#pragma once
#include "campus_map.h"

 /**
  * @brief �洢���·�����ȵĶ�ά���顣
  */
extern int shortest_path[MAX_ELEMENTNUM][MAX_ELEMENTNUM];

/**
 * @brief �洢ǰ���ڵ�Ķ�ά���飬���ڻָ�·����
 */
extern int prev[MAX_ELEMENTNUM][MAX_ELEMENTNUM];

/**
 * @brief ʹ�� Floyd �㷨�������е��֮������·����
 * ��ʼ�������� `shortest_path` �� `prev` ���顣
 */
void floyd();

/**
 * @brief ��ӡ��㵽�յ�����·����
 *
 * @param start ��ʼλ��������
 * @param end ��ֹλ��������
 */
void print_path_start_end(int start, int end);

/**
 * @brief ��ӡ����㵽���еص�����·����
 *
 * @param start ��ʼλ��������
 */
void print_all_paths_from(int start);

/**
 * @brief ģ�����㻷��У԰��
 * ʹ��̰�Ĳ��Է������еص㲢������㡣
 *
 * @param start ��ʼλ��������
 */
void travel(int start);

/**
 * @brief ��ӡǰ�����顣
 * ��ʾÿ���ڵ��ǰ����Ϣ�����ڵ��ԡ�
 */
void print_prev_array();