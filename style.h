#pragma once
#include <windows.h>

// ���ÿ���̨�ı���ɫ
void set_text_color(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // ��ȡ����̨���
    SetConsoleTextAttribute(hConsole, color); // ������ɫ
}

// ���ÿ���̨�ı���ɫΪĬ�ϣ�ͨ��Ϊ��ɫ��
void reset_text_color() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Ĭ�ϰ�ɫ
}

//set_text_color(FOREGROUND_GREEN);
//reset_text_color();