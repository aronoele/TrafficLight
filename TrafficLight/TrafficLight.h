#pragma once

#include <iostream>

#include "Circle.h"
#include "ITrafficLight.h"
#include "ITrafficLightState.h"
#include "ITrafficLightWorkCheck.h"
//#include "IWritable.h"

class TrafficLight : public ITrafficLight, ITrafficLightWorkCheck//, IWritable
{
public:
	TrafficLight();
	~TrafficLight();
	void setState(ITrafficLightState* state);
	void changeState();

	void setIntervalRed(int interval);
	void setIntervalGreen(int interval);
	void setIntervalYellow(int interval);
	void setRedState() override;
	void setYellowState() override;
	void setGreenState() override;
	void setTurnOffState() override;
	void draw();
	//void write(const std::string& str) override;
	bool isWorking(int interval) override;
	void work();
	void exit();

private:
	Circle circleTop_;
	Circle circleMiddle_;
	Circle circleBottom_;
	int intervalRed_;
	int intervalGreen_;
	int intervalYellow_;
	int intervalBlinking_;
	ITrafficLightState* state_;
};

