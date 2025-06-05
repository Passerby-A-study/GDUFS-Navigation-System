/**
 * @file style.cpp
 * @brief 样式和颜色设置的实现源文件。
 * 包含 Windows 控制台颜色设置的具体实现。
 */

#include "style.h"

void set_text_color(int foreground, int background)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, foreground | background);
}

void reset_text_color()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}