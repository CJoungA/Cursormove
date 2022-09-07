#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include "movecursor.h"

void setCursor(int tf) {
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 100;  //커서 두께(1~100)
    cursorInfo.bVisible = tf;  //TRUE커서 보이게 //FALSE숨기기
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void gotoCursor(int x, int y) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}

void getCursorPosition(int num) {
    const char* msgs[2] = { "1"," "};
    CONSOLE_SCREEN_BUFFER_INFO presentCur;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &presentCur);
    puts(msgs[num]);
    gotoCursor(presentCur.dwCursorPosition.X, presentCur.dwCursorPosition.Y);
}

void cursorPause() {
    char stop;
    char start;
    int num=0;
    if (_kbhit()) {
        stop = _getch();
        flashing();
        while (true) {
            if (stop == 32) {
                start = _getch();
                if (start == 32) {
                    break;
                }
            }
            else {
                break;
            }
        }
    }
}

void moveCursor(int width, int height, int &x,int &y,int &i) {
    if (x <= width - i - 1 && y == i) { //우
        wprintf_s(L"\x1b[1C");
        x++;
    }

    else if (y < height - i - 1 && x == width - i) {//하
        wprintf_s(L"\x1b[1B");
        wprintf_s(L"\x1b[1D");
        y++;
    }

    else if (x > i + 1 && y == height - i - 1) {//좌
        wprintf_s(L"\x1b[3D");
        x--;
    }

    else if (y > i + 1 && x == i + 1) {//상
        wprintf_s(L"\x1b[1A");
        wprintf_s(L"\x1b[1D");
        y--;
        if (y == i + 1) {
            i++;
        }
    }
}
void flashing() {
    int on_off = 0;
    while (true)
    {
        getCursorPosition(on_off);
        on_off = (on_off + 1) % 2;
        Sleep(250);
        if (_kbhit()) {
            getCursorPosition(0);
            break;
        }
    }
}
