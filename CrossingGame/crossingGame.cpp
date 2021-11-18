#include"CGAME.h"

int yMove = 22;//Dùng để di chuyển trên Home page
char MOVING;
CGAME* cg;
bool IS_RUNNING = false;


void LoadGame() {
	CDRAW cdraw;
	SetColor(_LIGHTGREEN);
	cdraw.printBox(47, 21, 28, 2);
	GotoXY(53, 22);  wcout << "Press Esc to Exit";
	while (1) {
		if (_kbhit()) {
			char press = _getch();
			if (press == 27) return;
		}
		GotoXY(51, 18); wcout << "This is Load Game!";
	}
}

//Xử lí chính
void MainProgram(int x) {

	bool press = true;//Kiem tra nguoi dung co an phim nao chua
	int xCur = x + 37; //Toa do x cua mui ten di chuyen tren home page
	int yOld = yMove; //Toa do y cua mui ten di chuyen tren home page
	char move;
	cg = new CGAME();
	CDRAW cdraw;
	while (true) {
		if (press == true) {//Neu khong co dong lenh nay mui ten se nhay lien tuc vi khi chua duoc bam no van in ra
			//Xoa mui ten di chuyen o vi tri cu 
			GotoXY(xCur, yOld); wcout << " ";
			ShowCur(false);
			SetColor(_LIGHTYELLOW);
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
				if (move == _UPkey) {//Di len
					if (yMove > 22) {
						yMove--;
					}

					else
						yMove = 26;//Neu di len vuot qua lua chon thi di xuong lua chon cuoi
				}
				else if (move == _DOWNkey) {//Di xuong
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
				cdraw.printThankYou(40, 15);
				system("cls");
				break;
			}
			//Start Game
			else if (move == 13 && yMove == 22) {
				system("cls");
				cg->startGame();
				cg->Control();
				cdraw.printAgainHomePage();
			}
			//Load Game
			else if (move == 13 && yMove == 23) {
				system("cls");
				cg->loadGame();
				cg->Control();
				cdraw.printAgainHomePage();
			}
			//Instructions
			else if (move == 13 && yMove == 24) {
				system("cls");
				cdraw.printInstructions();
				cdraw.printAgainHomePage();
			}
			//About us
			else if (move == 13 && yMove == 25) {
				system("cls");
				cdraw.printAboutUs();
				cdraw.printAgainHomePage();
			}
		}
	}
}
int main() {

	CDRAW cdraw;
	_setmode(_fileno(stdout), _O_WTEXT);
	setConsoleWindown(1780, 700);//x = 171, y = 40
	FixConsoleWindow();

	cdraw.printHomePage(40, 6, 90, 25);
	MainProgram(40);
	return 0;
}