#pragma once
#include <windows.h>

// 设置控制台文本颜色
void set_text_color(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 获取控制台句柄
    SetConsoleTextAttribute(hConsole, color); // 设置颜色
}

// 重置控制台文本颜色为默认（通常为白色）
void reset_text_color() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 默认白色
}

//set_text_color(FOREGROUND_GREEN);
//reset_text_color();