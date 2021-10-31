#pragma once
#include<windows.h>
#include<iostream>
using namespace std;

void FixConsoleWindow();

void GotoXY(int x, int y);

void ShowCur(bool CursorVisibility);

void SetColor(WORD color);

void textcolor(int x);

void setConsoleWindown(int w, int h);