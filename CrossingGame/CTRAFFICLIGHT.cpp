#include"CTRAFFICLIGHT.h"

CTRAFFICLIGHT::CTRAFFICLIGHT() {
	this->state = 1;
}

void CTRAFFICLIGHT::setTrafficLight(int stateNum) {
	this->state = stateNum;
}

int CTRAFFICLIGHT::getTraFficLight() {
	return this->state;
}

void CTRAFFICLIGHT::setYPosition(int y) {
	this->mY = y;
}

int CTRAFFICLIGHT::getYPosition() {
	return this->mY;
}