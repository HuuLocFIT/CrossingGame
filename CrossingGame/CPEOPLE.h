#pragma once
#include"CANIMAL.h"
#include"CVEHICLE.h"
#include"GUI.h"

#include<iostream>
using namespace std;

#define XPEOPLE 50
#define YPEOPLE 33

class CPEOPLE {
	int mX, mY;
	bool mState;
public:
	CPEOPLE();
	~CPEOPLE();

	//Move
	void Up(int y);
	void Left(int x);
	void Right(int x);
	void Down(int y);
	//Method
	bool isImpact(const CVEHICLE*, int n);
	bool isImpact(const CANIMAL*, int n);
	bool isDead();
	bool isFinish();


	void setMState(bool);
	bool getMState() {
		return mState;
	}
	void setX(int x) {
		mX = x;
	}
	void setY(int y) {
		mY = y;
	}
	int getX() {
		return mX;
	}
	int getY() {
		return mY;
	}

};
