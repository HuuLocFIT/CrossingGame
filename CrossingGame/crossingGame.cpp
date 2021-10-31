#include<iostream>
#include<string>
#include<cmath>
#include<fstream>
#include<ctime>
#include<conio.h>
#include<fcntl.h> 
#include<io.h>
#include "windows.h"
#include<thread>

#include"Mylib.h"
#include"GUI.h"
#include"CGAME.h"

using namespace std;

//int yMove = 17;//Dùng để di chuyển trên Home page
int yMove = 22;//Dùng để di chuyển trên Home page
char MOVING;
CGAME* cg;

//Khoi tao cac ham
void printHomePage(int x, int y, int w, int h);

//======================================================================================================

void printAboutUs() {
	SetColor(10);
	printBox(47, 21, 28, 2);
	GotoXY(53, 22);  wcout << "Press Esc to Exit";

	while (1) {
		SetColor(6);
		GotoXY(58, 8); wcout << "MEMBERS";
		GotoXY(50, 10); wcout << "MSSV";
		GotoXY(48, 11); wcout << "20127214";
		GotoXY(48, 12); wcout << "20127233";
		GotoXY(48, 13); wcout << "20127459";
		GotoXY(48, 14); wcout << "20127522";
		GotoXY(48, 15); wcout << "20127551";
		GotoXY(63, 10); wcout << "FULLNAME";
		GotoXY(60, 11); wcout << "Ng~ Truong M.Khoi";
		GotoXY(60, 12); wcout << "Huynh The Long";
		GotoXY(60, 13); wcout << "Le Quoc Dat";
		GotoXY(60, 14); wcout << "Nguyen Huu Khai";
		GotoXY(60, 15); wcout << "Nguyen Huu Loc";

		SetColor(4);
		printBox(45, 6, 32, 11);

		if (_kbhit()) {
			char press = _getch();
			if (press == 27) return;
		}
	}
}

void LoadGame() {
	SetColor(10);
	printBox(47, 21, 28, 2);
	GotoXY(53, 22);  wcout << "Press Esc to Exit";
	while (1) {
		if (_kbhit()) {
			char press = _getch();
			if (press == 27) return;
		}
		GotoXY(51, 18); wcout << "This is Load Game!";
	}
}

void printInstructions() {
	SetColor(10);
	printBox(47, 21, 28, 2);
	GotoXY(53, 22);  wcout << "Press Esc to Exit";
	while (1) {
		if (_kbhit()) {
			char press = _getch();
			if (press == 27) return;
		}
		GotoXY(51, 18); wcout << "This is instructions!";
	}
}

//EXIT GAME
void printAgainHomePage() {
	system("cls");
	ShowCur(0);
	//printHomePage(15, 1, 90, 25); //In lại Home page
	printHomePage(40, 6, 90, 25);
	SetColor(14);
	GotoXY(77, yMove); wcout << L'»';
}

//=============================================== CLASS CVEHICLE ===============================================

//Màn hình chính khi vào game
void printHomePage(int x, int y, int w, int h) {
	//x = 15, y = 1, w = 90, h = 25 
	//x = 171, y = 40

	SetColor(6);
	GotoXY(44, 7); wcout << " _______  _______  _______  _______  _______    _______  _______  _______  ______";
	GotoXY(44, 8); wcout << "|  _____||  ___  ||  ___  ||  _____||  _____|  |  ___  ||  ___  ||  ___  ||  ___ \\";
	GotoXY(44, 9); wcout << "| |      | |___| || |   | || |_____ | |_____   | |___| || |   | || |___| || |   \\ |";
	GotoXY(44, 10); wcout << "| |_____ | |  \\ \\ | |___| | _____| | _____| |  | |  \\ \\ | |___| || |   | || |___/ |";
	GotoXY(44, 11); wcout << "|_______||_|   \\_\\|_______||_______||_______|  |_|   \\_\\|_______||_|   |_||______/";

	SetColor(5);//Mau hong
	for (int i = x; i <= x + w; i++) {
		GotoXY(i, 13); wcout << L'─';
	}

	SetColor(2);//Mau xanh la
	printBigCar(45, 19);

	SetColor(12);//Mau do
	GotoXY(x + 40, y + 16); wcout << "START GAME";
	GotoXY(x + 40, y + 17); wcout << "LOAD GAME";
	GotoXY(x + 40, y + 18); wcout << "INSTRUCTIONS";
	GotoXY(x + 40, y + 19); wcout << "ABOUT US";
	GotoXY(x + 40, y + 20); wcout << "EXIT GAME";

	SetColor(1);//Mau xanh duong
	printBigBird(96, 18);

	SetColor(5);//Mau hong
	printBox(x, y, w, h);
}

//Xử lí chính
void MainProgram(int x/*, int y, int w, int h*/) {
	bool press = true;//Kiem tra nguoi dung co an phim nao chua
	int xCur = x + 37; //Toa do x cua mui ten di chuyen tren home page
	int yOld = yMove; //Toa do y cua mui ten di chuyen tren home page
	char move;
	cg = new CGAME();

	while (1) {
		if (press == true) {//Neu khong co dong lenh nay mui ten se nhay lien tuc vi khi chua duoc bam no van in ra
			//Xoa mui ten di chuyen o vi tri cu 
			GotoXY(xCur, yOld); wcout << " ";
			ShowCur(0);
			SetColor(14);
			GotoXY(x + 37, yMove); wcout << L'»'; //In mui ten moi
			yOld = yMove;//Cap nhat lai vi tri yOld
			press = false;
		}
		//Kiem tra nguoi dung nhan phim de di chuyen
		if (_kbhit()) {
			move = _getch();
			//============================== Di chuyen ==============================
			if (move == -32) {
				press = true;
				move = _getch();
				if (move == 72) {//Di len
					if (yMove > 22)
						yMove--;
					else
						yMove = 26;//Neu di len vuot qua lua chon thi di xuong lua chon cuoi
				}
				else if (move == 80) {//Di xuong
					if (yMove < 26)
						yMove++;
					else
						yMove = 22;//Neu di xuong vuot qua lua chon thi di len lua chon dau
				}
			}
			//============================== Lua chon de thuc thi ==============================
			//Exit
			else if (move == 13 && yMove == 26) {
				system("cls");
				printThankYou(40, 15);
				system("cls");
				break;
			}
			//Start Game
			else if (move == 13 && yMove == 22) {
				system("cls");
				cg->startGame();
				cg->resetGame();
				thread t1(SubThread);
				
				char opt;
				while (1) {
					opt = toupper(_getch());

					if (cg->getPeople()->isDead() == false) {
						if (opt == 27) {
							cg->exitGame(&t1);
							break;
						}
						else if (opt == 'P') {
							cg->pauseGame();
						}
						else if (opt == 'R') {
							cg->resumeGame();
							t1.detach();
							t1 = thread(SubThread);
						}
						else if (opt == 'O') {
							cg->exitGame(&t1);
							system("cls");
							cg->saveGame();
							system("pause");
							break;
						}
						else if (opt == 'W' || opt == 'A' || opt == 'D' || opt == 'S') {
							MOVING = opt;
						}
					}
					else {
						system("cls");
						if (opt == 'Y')
						{
							cg->exitGame(&t1);
							cg->startGame();
							cg->resetGame();
						}
						else {
							cg->exitGame(&t1);
							break;
						}
					}
			
				}
				printAgainHomePage();
			}
			//Load Game
			else if (move == 13 && yMove == 23) {
				system("cls");
				cg->resetGame();
				cg->loadGame();
				thread t1(SubThread);

				char opt;
				while (1) {
					opt = toupper(_getch());

					if (opt == 27) {
						cg->exitGame(&t1);
						break;
					}
					else if (opt == 'P') {
						cg->pauseGame();
					}
					else if (opt == 'R') {
						cg->resumeGame();
						t1.detach();
						t1 = thread(SubThread);
					}
					else if (opt == 'O') {
						system("cls");
						cg->exitGame(&t1);
						cg->saveGame();
						system("pause");
						break;
					}
					else if (opt == 'W' || opt == 'A' || opt == 'D' || opt == 'S') {
						MOVING = opt;
					}

				}
				printAgainHomePage();
			}
			//Instructions
			else if (move == 13 && yMove == 24) {
				system("cls");
				printInstructions();
				printAgainHomePage();
			}
			//About us
			else if (move == 13 && yMove == 25) {
				system("cls");
				printAboutUs();
				printAgainHomePage();
			}
		}
	}
}


int main() {
	_setmode(_fileno(stdout), _O_WTEXT);
	FixConsoleWindow();
	setConsoleWindown(1780, 700);//x = 171, y = 40
	//printLoading();

	/*printHomePage(15, 1, 90, 25);
	MainProgram(15);*/

	printHomePage(40, 6, 90, 25);
	MainProgram(40);
	return 0;
}