/**
 * @file user_interface.h
 * @brief �û����湦�ܵ�ͷ�ļ���
 * ���������ʼ�����˵���ʾ�͵�����������غ�����
 */

#pragma once
#include <string>

 /**
  * @brief ��ʼ���û����档
  * ��ʾ��ӭ���沢������ѭ����
  */
void UI_Start();

/**
 * @brief ��ʾ���ܲ˵���
 * �ṩ��ͼ��ѯ�͵���ѡ�
 */
void UI_functionmenu();

/**
 * @brief ��ʾ��ѯ�˵���
 * �ṩ�ڽӾ����ڽӱ��·����ѯѡ�
 */
void UI_findmenu();

/**
 * @brief ��ʾ����ѡ��˵���
 * �ṩ��ʼ�����Ͳ鿴���а�ѡ�
 */
void UI_navichoose();

/**
 * @brief ��ʾ������Ļ��
 * ʹ����ת����ģ����ع��̡�
 */
void loading_screen();

/**
 * @brief ��ʾ�������档
 * �ṩʵʱ�������ܡ�
 */
void UI_navigation();

/**
 * @brief ��ͣ����ִ�С�
 * �ȴ��û��� Enter ��������
 */
void sleep();