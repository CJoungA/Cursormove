#include <iostream>
#include <windows.h>
#include "movecursor.h"

int main() {
    int width, height, s;

    cout << "가로, 세로, 속도(1~5 범위를 벗어나면 5고정)를 입력하세요: ";

    cin >> width >> height >> s;
    if (s < 0 || s >= 5) {
        s = 5;
    }
    int time = 1000 / s; 

    setCursor(0);  //0 커서 숨기기 ,1 커서 보이기

    system("cls");//콘솔내용 지우기

    const char* c = "1";

    int i = 0; 
    int x = 0;
    int y = 0;
    int count = 0;

    while (true) {

        moveCursor(width,height,x,y,i);
        cursorPause();
        cout << c;
        Sleep(time);
        count++;
        if (count == width * height) {
            wprintf_s(L"\x1b[1D");
            flashing();
            break;
        }
    }

    return 0;
}

