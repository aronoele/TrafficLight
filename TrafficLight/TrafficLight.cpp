#include <iostream>
#include <fstream>
#include <ctime>
#include <Windows.h>
#include <conio.h>

#include "TrafficLight.h"
#include "ITrafficLightState.h"
#include "TrafficLightStateTurnOff.h"
#include "TrafficLightStateRed.h"
#include "TrafficLightStateYellow.h"
#include "TrafficLightStateGreen.h"

using namespace std;

TrafficLight::TrafficLight()
{
	intervalBlinking_ = 500;
	setState(new TrafficLightStateTurnOff());
}

TrafficLight::~TrafficLight() {}

void TrafficLight::setState(ITrafficLightState* state) {
	delete state_;
	state_ = state;
	state_->changeState(this);
}

void TrafficLight::changeState() {
	state_->changeState(this);
}

void TrafficLight::setIntervalRed(int interval) {
	intervalRed_ = interval;
}

void TrafficLight::setIntervalGreen(int interval) {
	intervalGreen_ = interval;
}

void TrafficLight::setIntervalYellow(int interval) {
	intervalYellow_ = interval;
}

void TrafficLight::setRedState()
{
	circleTop_.setColor(COLOR_DARKGRAY);
	circleMiddle_.setColor(COLOR_DARKGRAY);
	circleBottom_.setColor(COLOR_RED);
}

void TrafficLight::setYellowState()
{
	circleTop_.setColor(COLOR_DARKGRAY);
	circleMiddle_.setColor(COLOR_YELLOW);
	circleBottom_.setColor(COLOR_DARKGRAY);
}

void TrafficLight::setGreenState()
{
	circleTop_.setColor(COLOR_GREEN);
	circleMiddle_.setColor(COLOR_DARKGRAY);
	circleBottom_.setColor(COLOR_DARKGRAY);
}

void TrafficLight::setTurnOffState()
{
	circleTop_.setColor(COLOR_DARKGRAY);
	circleMiddle_.setColor(COLOR_DARKGRAY);
	circleBottom_.setColor(COLOR_DARKGRAY);
}

void TrafficLight::draw()
{
	system("cls");
	cout << endl;
	circleTop_.draw();
	circleMiddle_.draw();
	circleBottom_.draw();
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, COLOR_WHITE);
	cout << "\n\tS - Start\n" <<
		"\tP - Pause\n" <<
		"\tE -Exit\n";
}

void TrafficLight::write(const string& str)
{
	const char* note = str.c_str();
	struct tm currentTime;
	time_t now = time(0);
	localtime_s(&currentTime, &now);
	char noteTime[26];
	asctime_s(noteTime, sizeof noteTime, &currentTime);

	ofstream out("log.txt", ios::out | ios::app);
	if (!out.is_open()) {
		cout << "Writting error\n";
	}
	out << note << '\t' << noteTime << endl;
	out.close();
}

bool TrafficLight::isWorking(int interval)
{
	int timer = 100;
	int time = 100;
	while (time < interval) {
		if (_kbhit()) {
			int charCode = _getch();//int code = static_cast<int>(charCode);
			switch (charCode) {
			case 69://e
			case 101:
				return false;
			case 80://p
			case 112:
				write("PAUSE");
				cout << "\tPause\n";
				while (true) {
					if (_kbhit()) {
						charCode = _getch();
						switch (charCode) {
						case 69://e
						case 101:
							return false;
						case 83://s
						case 115:
							write("START");
							return true;
						}
					}
				}
			}
		}
		Sleep(timer);
		time += timer;
	}
	return true;
}

void TrafficLight::exit()
{
	setTurnOffState();
	write("EXIT");
	draw();
	cout << "\tExit\n";
}

void TrafficLight::work()
{
	write("START");
	while (true) {
		setState(new TrafficLightStateRed());
		write("RED");
		draw();
		if (!isWorking(intervalRed_)) {
			exit();
			return;
		}
		setState(new TrafficLightStateGreen());
		write("GREEN");
		draw();
		if (!isWorking(intervalGreen_)) {
			exit();
			return;
		}
		for (int i = 0; i < intervalYellow_ / (2 * intervalBlinking_); i++) {
			setState(new TrafficLightStateTurnOff());
			draw();
			Sleep(intervalBlinking_);
			setState(new TrafficLightStateYellow());
			write("YELLOW");
			draw();
			if (!isWorking(intervalBlinking_)) {
				exit();
				return;
			}
		}
	}
}