#pragma once
#include"CANIMAL.h"
#include"CVEHICLE.h"
#include"GUI.h"

#define XPEOPLE 65
#define YPEOPLE 33

//Bien cua people
#define PEOPLE_BORDER_RIGHT 125
#define PEOPLE_BORDER_LEFT 3
#define PEOPLE_BORDER_UP 5
#define PEOPLE_BORDER_DOWN 30

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


	void setMState(bool isLive) {
		mState = isLive;
	};
	bool getMState() {
		return mState;
	}
	void setX(int x) {
		mX = x;
	}
	void setY(int y) {
		mY = y;
	}
	void setXY(int x, int y) {
		setX(x);
		setY(y);
	}
	int getX() {
		return mX;
	}
	int getY() {
		return mY;
	}

};
