#ifndef MOVECURSOR_H_
#define MOVECURSOR_H_

using std::cout;
using std::cin;
constexpr int KEY_SPACE = 32;		// SpaceBar 키

void setCursor(int c);
void gotoCursor(int xg, int yg);
void mPause(); // 정지
void moveCursor(int x, int y, int s); //커서 이동 및 출력
void getCursorPosition(int num);
void flashing();


#endif