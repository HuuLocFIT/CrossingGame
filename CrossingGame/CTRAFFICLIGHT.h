#pragma once
#include<iostream>
using namespace std;
class CTRAFFICLIGHT {


private:
	int state;     // 1- den xanh   0- den do
	int mY;
public:
	CTRAFFICLIGHT();
	void setTrafficLight(int);
	int getTraFficLight();
	void setYPosition(int);
	int getYPosition();

};
