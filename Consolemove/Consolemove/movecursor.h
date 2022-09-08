#ifndef MOVECURSOR_H_
#define MOVECURSOR_H_

using std::cout;
using std::cin;
constexpr int KEY_SPACE = 32;		// SpaceBar Ű

void setCursor(int c);  
void gotoCursor(int x, int y);
void cursorPause(); // ����
void moveCursor(int width, int height, int &x, int &y, int &i); //Ŀ�� �̵� �� ���
void cursorPrint(int num);
void cursorFlashing();

#endif