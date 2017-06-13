#pragma once

#include "ITrafficLight.h"
#include "ITrafficLightState.h"

class TrafficLightStateRed : public ITrafficLightState
{
public:
	TrafficLightStateRed();
	~TrafficLightStateRed();
	void changeState(ITrafficLight* trafficLight) override;
};