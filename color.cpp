
#include"color.h"


void setcolor(int num)
{

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),num);
}
