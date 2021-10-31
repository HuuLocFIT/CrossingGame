#include"GUI.h"
extern int yMove;

void CDRAW::printBox(int x, int y, int w, int h) {
	//Vẽ đường ngang trên
	GotoXY(x, y); wcout << L'┌';
	for (int i = x + 1; i < x + w; i++) {
		GotoXY(i, y); wcout << L'─';
	}
	GotoXY(x + w, y); wcout << L'┐';

	//Vẽ đường dọc
	for (int i = y + 1; i < y + h; i++) {
		GotoXY(x, i); wcout << L'│';
		GotoXY(x + w, i); wcout << L'│';
	}

	//Vẽ đường ngang dưới
	GotoXY(x, y + h); wcout << L'└';
	for (int i = x + 1; i < x + w; i++) {
		GotoXY(i, y + h); wcout << L'─';
	}
	GotoXY(x + w, y + h); wcout << L'┘';

}
void CDRAW::printThankYou(int x, int y) {
	SetColor(10);
	printBox(x + 35, y + 16, 28, 2);
	GotoXY(x + 41, y + 17);  wcout << "Press Esc to Exit";
	int color = 0;

	while (1) {
		SetColor(color);
		if (color > 15)
			color = 0;

		GotoXY(x, y);     wcout << " __________  __    __  ________  __    __  __   ___     ___    ___ ________  __     __    __";
		GotoXY(x, y + 1); wcout << "|___    ___||  |  |  ||   __   ||  \\  |  ||  | /  /     \\  \\  /  /|   __   ||  |   |  |  |  |";
		GotoXY(x, y + 2); wcout << "    |  |    |  |__|  ||  |  |  ||   \\ |  ||  |/  /       \\  \\/  / |  |  |  ||  |   |  |  |  |";
		GotoXY(x, y + 3); wcout << "    |  |    |   __   ||  |__|  ||  |\\\\|  ||     /         \\    /  |  |  |  ||  |   |  |  |__|";
		GotoXY(x, y + 4); wcout << "    |  |    |  |  |  ||  |  |  ||  | \\|  ||  |\\  \\         |  |   |  |__|  ||  |___|  |   __";
		GotoXY(x, y + 5); wcout << "    |__|    |__|  |__||__|  |__||__|  \\__||__| \\__\\        |__|   |________||_________|  |__|";

		if (_kbhit()) {
			char press = _getch();
			if (press == 27) return;
		}
		color++;
		Sleep(1);
	}
}
void CDRAW::printBigCar(int x, int y) {
	GotoXY(x, y);     wcout << "        _______________" << endl;
	GotoXY(x, y + 1); wcout << "       / / |  |  |  |  \\" << endl;
	GotoXY(x, y + 2); wcout << " _____/ /  |__|  |__|   \\" << endl;
	GotoXY(x, y + 3); wcout << "|_|     __        __    |" << endl;
	GotoXY(x, y + 4); wcout << "|______/  \\______/  \\___|" << endl;
	GotoXY(x, y + 5); wcout << "       \\__/      \\__/" << endl;
}
void CDRAW::printBigBird(int x, int y) {
	GotoXY(x, y);     wcout << "      .---.        .-----------";
	GotoXY(x, y + 1); wcout << "     /     \\  __  /    ------";
	GotoXY(x, y + 2); wcout << "    / /     \\(  )/    -----";
	GotoXY(x, y + 3); wcout << "   //////   ' \\/ `   ---";
	GotoXY(x, y + 4); wcout << "  //// / // :    : ---";
	GotoXY(x, y + 5); wcout << " // /   /  /`    '--";
	GotoXY(x, y + 6); wcout << "//          //..\\\\";
	GotoXY(x, y + 7); wcout << "       ====UU====UU====";
	GotoXY(x, y + 8); wcout << "           '//||\\\\`";
	GotoXY(x, y + 9); wcout << "             ''``";
}
//Màn hình chính khi vào game
void CDRAW::printHomePage(int x, int y, int w, int h) {
	//x = 15, y = 1, w = 90, h = 25 
	//x = 171, y = 40
	CDRAW cdraw;
	cdraw.printBanner(44, 7);

	SetColor(_PINK);//Mau hong
	for (int i = x; i <= x + w; i++) {
		GotoXY(i, 13); wcout << L'-';
	}

	SetColor(_GREEN);//Mau xanh la
	cdraw.printBigCar(45, 19);

	SetColor(_RED);//Mau do

	GotoXY(x + 40, y + 16); wcout << "START GAME";
	GotoXY(x + 40, y + 17); wcout << "LOAD GAME";
	GotoXY(x + 40, y + 18); wcout << "INSTRUCTIONS";
	GotoXY(x + 40, y + 19); wcout << "ABOUT US";
	GotoXY(x + 40, y + 20); wcout << "EXIT GAME";

	SetColor(_BLUE);
	cdraw.printBigBird(96, 18);

	SetColor(_PINK);//Mau hong
	printBox(x, y, w, h);
}
void CDRAW::printAboutUs() {
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
void CDRAW::printInstructions() {
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
void CDRAW::printAgainHomePage() {
	CDRAW cdraw;
	system("cls");
	ShowCur(0);
	//printHomePage(15, 1, 90, 25); //In lại Home page
	cdraw.printHomePage(40, 6, 90, 25);
	SetColor(_LIGHTYELLOW);
	GotoXY(77, yMove); wcout << L'»';
}
void CDRAW::printLoading() {
	CDRAW cdraw;
	system("cls");
	ShowCur(0);
	int percent = 10;
	SetColor(7); printBox(32, 20, 101, 2);
	int xOld = 23;
	thread musicCar(MusicCarLoading);
	for (int i = 33; i <= 123; i += 10) {
		SetColor(7); GotoXY(137, 21); wcout << percent << "%";
		textcolor(121); GotoXY(i, 21); wcout << "          ";
		textcolor(0);

		DeleteImageOld(xOld, 11, 10, 9);
		SetColor(3); cdraw.printCarLoading(i, 16);

		percent += 10;
		xOld += 10;
		Sleep(600);
	}
	musicCar.join();
	wcout << endl << endl << endl;
	textcolor(_BLACK);
}
void CDRAW::printCarLoading(int x, int y) {
	GotoXY(x, y);     wcout << "   ____";
	GotoXY(x, y + 1); wcout << " _/_||_\\_";
	GotoXY(x, y + 2); wcout << "|        |";
	GotoXY(x, y + 3); wcout << "`(o)--(o)'";
}
void CDRAW::printBanner(int x, int y) {
	SetColor(_YELLOW);
	GotoXY(x, y);       wcout << " _______  _______  _______  _______  _______    _______  _______  _______  ______";
	GotoXY(x, y + 1);   wcout << "|  _____||  ___  ||  ___  ||  _____||  _____|  |  ___  ||  ___  ||  ___  ||  ___ \\";
	GotoXY(x, y + 2);   wcout << "| |      | |___| || |   | || |_____ | |_____   | |___| || |   | || |___| || |   \\ |";
	GotoXY(x, y + +3); wcout << "| |_____ | |  \\ \\ | |___| | _____| | _____| |  | |  \\ \\ | |___| || |   | || |___/ |";
	GotoXY(x, y + 4);   wcout << "|_______||_|   \\_\\|_______||_______||_______|  |_|   \\_\\|_______||_|   |_||______/";

}


void printSmallCarLTR(int x, int y) {
	GotoXY(x, y);     wcout << "   _____";
	GotoXY(x, y + 1); wcout << " _/[] []\\_";
	GotoXY(x, y + 2); wcout << "|_________|";
	GotoXY(x, y + 3); wcout << "  O     O";
}
void printSmallCrocodile(int x, int y) {
	GotoXY(x, y);	  wcout << "   _     _^ ";
	GotoXY(x, y + 1); wcout << " _/'|-^-//";
	GotoXY(x, y + 2); wcout << "|^______/";
	GotoXY(x, y + 3); wcout << " o     o";
}
void printSmallBat(int x, int y) {
	GotoXY(x, y);     wcout << "__       __";
	GotoXY(x, y + 1); wcout << ") \\__V__/ (";
	GotoXY(x, y + 2); wcout << " )__   __(";
	GotoXY(x, y + 3); wcout << "    `-'";
}
void printSmallTruck(int x, int y) {
	GotoXY(x, y);     wcout << L" ______";
	GotoXY(x, y + 1); wcout << L"│      │__";
	GotoXY(x, y + 2); wcout << L"│______│__│";
	GotoXY(x, y + 3); wcout << L" O        O";
}
void printPeople(int x, int y) {
	GotoXY(x, y);	  wcout << " O";
	GotoXY(x, y + 1); wcout << "/|\\";
	GotoXY(x, y + 2); wcout << "/ \\";
}

void MusicCarLoading() {
	PlaySound(TEXT("smb_world_clear.wav"), NULL, SND_SYNC);
}



void DeleteImageOld(int x, int y, int w, int h) {
	for (int i = 0; i < h; i++) {
		for (int j = x; j <= x + w; j++) {
			GotoXY(j, y); wcout << " ";
		}
		y++;
	}
}

