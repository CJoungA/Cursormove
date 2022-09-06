#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <thread>
#include "movecursor.h"

void setCursor(int tf) {
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 100;  //커서 두께(1~100)
    cursorInfo.bVisible = 0;  //TRUE커서 보이게 //FALSE숨기기

    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void gotoCursor(int xg, int yg) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = xg;
    pos.Y = yg;
    SetConsoleCursorPosition(consoleHandle, pos);
}

void getCursorPosition(int num) {
    const char* msgs[2] = { "1"," "};
    CONSOLE_SCREEN_BUFFER_INFO presentCur;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &presentCur);
    puts(msgs[num]);
    gotoCursor(presentCur.dwCursorPosition.X, presentCur.dwCursorPosition.Y);
}

void mPause() {
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

void moveCursor(int x, int y, int s) {
    int time = 100/s;
    int count = 0;
    const char* c = "1";
    for (int i = 0; i < (y / 2) + 1; i++)
    {
        for (int j = i; j < x - i; j++) {   //왼쪽에서 오른쪽
            if (count >= x * y) {
                break;
            }
            wprintf_s(L"\x1b[1C");
            Sleep(time);
            mPause();
            count++;
            cout << c;
        }

        for (int j = i + 1; j < y - i; j++) {   //위에서 아래
            if (count >= x * y) {
                break;
            }
            wprintf_s(L"\x1b[1B");
            wprintf_s(L"\x1b[1D");
            Sleep(time);
            mPause();
            count++;
            cout << c;
        }

        for (int j = x - i - 2; j >= i; j--) {  //오른쪽에서 왼쪽
            if (count >= x * y) {
                break;
            }
            wprintf_s(L"\x1b[3D");
            Sleep(time);
            mPause();
            count++;
            cout << c;
        }

        for (int j = y - i - 2; j >= i + 1; j--) {  //아래에서 위
            if (count >= x * y) {
                break;
            }
            wprintf_s(L"\x1b[1A");
            wprintf_s(L"\x1b[1D");
            Sleep(time);
            mPause();
            count++;
            cout << c;
        }
    }
    wprintf_s(L"\x1b[1D");
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
