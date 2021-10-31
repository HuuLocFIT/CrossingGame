#pragma once
#include<iostream>
#include<ctime>
#include<conio.h>
#include<thread>
#include"Mylib.h"



//Dinh nghia mau sac
#define _BLACK 0
#define _BLUE 1
#define _GREEN 2
#define _PINK 5
#define _YELLOW 6
#define _GRAY 7
#define _LIGHTGREEN 10
#define _RED 12
#define _LIGHTYELLOW 14
//Dinh nghia phim an nguoi dung
#define _UPkey 72
#define _DOWNkey 80
#define _ENTERkey 13
#define _LEFTkey 75
#define _RIGHTkey 77


using namespace std;

class CDRAW {
public :
	void printHomePage(int x, int y, int w, int h);
	void printBanner(int x, int y);
	void printAgainHomePage();
	void printInstructions();
	void printAboutUs();
	void printThankYou(int x, int y);
	void printBigCar(int x, int y);
	void printBigBird(int x, int y);
	void printLoading();
	void printCarLoading(int x, int y);
	void printBox(int x, int y, int w, int h);
	
};




void printSmallCarLTR(int x, int y);

void printSmallTruck(int x, int y);

void printSmallCrocodile(int x, int y);

void printSmallBat(int x, int y);

void printPeople(int x, int y);

void MusicCarLoading();



void DeleteImageOld(int x, int y, int w, int h);
