#ifndef MOVECURSOR_H_
#define MOVECURSOR_H_

using std::cout;
using std::cin;
constexpr int KEY_SPACE = 32;		// SpaceBar Ű

void setCursor(int c);
void gotoCursor(int xg, int yg);
void mPause(); // ����
void moveCursor(int x, int y, int s); //Ŀ�� �̵� �� ���
void getCursorPosition(int num);
void flashing();


#endif