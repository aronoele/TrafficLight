#pragma once

#include "ITrafficLight.h"
#include "ITrafficLightState.h"

class TrafficLightStateYellow : public ITrafficLightState
{
public:
	TrafficLightStateYellow();
	~TrafficLightStateYellow();
	void changeState(ITrafficLight* trafficLight) override;
};