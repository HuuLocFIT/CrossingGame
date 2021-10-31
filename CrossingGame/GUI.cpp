#include"GUI.h"

void printBox(int x, int y, int w, int h) {
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

//Vẽ Thank You
void printThankYou(int x, int y) {
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

//====================================== Vẽ xe, động vật và người ======================================
void printBigCar(int x, int y) {
	GotoXY(x, y);     wcout << "        _______________" << endl;
	GotoXY(x, y + 1); wcout << "       / / |  |  |  |  \\" << endl;
	GotoXY(x, y + 2); wcout << " _____/ /  |__|  |__|   \\" << endl;
	GotoXY(x, y + 3); wcout << "|_|     __        __    |" << endl;
	GotoXY(x, y + 4); wcout << "|______/  \\______/  \\___|" << endl;
	GotoXY(x, y + 5); wcout << "       \\__/      \\__/" << endl;
}

void printBigBird(int x, int y) {
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

void printCarLoading(int x, int y) {
	GotoXY(x, y);     wcout << "   ____";
	GotoXY(x, y + 1); wcout << " _/_||_\\_";
	GotoXY(x, y + 2); wcout << "|        |";
	GotoXY(x, y + 3); wcout << "`(o)--(o)'";
}

void DeleteImageOld(int x, int y, int w, int h) {
	for (int i = 0; i < h; i++) {
		for (int j = x; j <= x + w; j++) {
			GotoXY(j, y); wcout << " ";
		}
		y++;
	}
}

void printLoading() {
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
		SetColor(3); printCarLoading(i, 16);

		percent += 10;
		xOld += 10;
		Sleep(600);
	}
	musicCar.join();
	wcout << endl << endl << endl;
	textcolor(0);
}

