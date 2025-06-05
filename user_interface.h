/**
 * @file user_interface.h
 * @brief 用户界面功能的头文件。
 * 包含界面初始化、菜单显示和导航交互的相关函数。
 */

#pragma once
#include <string>

 /**
  * @brief 初始化用户界面。
  * 显示欢迎界面并进入主循环。
  */
void UI_Start();

/**
 * @brief 显示功能菜单。
 * 提供地图查询和导航选项。
 */
void UI_functionmenu();

/**
 * @brief 显示查询菜单。
 * 提供邻接矩阵、邻接表和路径查询选项。
 */
void UI_findmenu();

/**
 * @brief 显示导航选择菜单。
 * 提供开始导航和查看排行榜选项。
 */
void UI_navichoose();

/**
 * @brief 显示加载屏幕。
 * 使用旋转动画模拟加载过程。
 */
void loading_screen();

/**
 * @brief 显示导航界面。
 * 提供实时导航功能。
 */
void UI_navigation();

/**
 * @brief 暂停程序执行。
 * 等待用户按 Enter 键继续。
 */
void sleep();