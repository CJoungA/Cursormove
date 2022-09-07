#ifndef MOVECURSOR_H_
#define MOVECURSOR_H_

using std::cout;
using std::cin;
constexpr int KEY_SPACE = 32;		// SpaceBar 키

void setCursor(int c);
void gotoCursor(int xg, int yg);
void cursorPause(); // 정지
void moveCursor(int width, int height, int &x, int &y, int &i); //커서 이동 및 출력
void getCursorPosition(int num);
void flashing();


#endif