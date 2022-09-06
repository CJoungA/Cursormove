#include <iostream>
#include <windows.h>
#include <conio.h>
#include <thread>
#include "movecursor.h"

int main() {
    int x, y, s;
    int num = 1;
    int on_off = 0;

    cout << "가로, 세로, 속도(1~5 범위를 벗어나면 5고정)를 입력하세요: ";
    cin >> x >> y >> s;
    if (s < 0 || s >= 5) {
        s = 5;
    }

    setCursor(0);

    system("cls");//콘솔내용 지우기

    moveCursor(x, y, s);

    flashing();

    return 0;
}

