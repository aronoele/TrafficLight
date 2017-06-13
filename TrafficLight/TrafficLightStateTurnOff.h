#pragma once

#include "ITrafficLight.h"
#include "ITrafficLightState.h"

class TrafficLightStateTurnOff : public ITrafficLightState
{
public:
	TrafficLightStateTurnOff();
	~TrafficLightStateTurnOff();
	void changeState(ITrafficLight* trafficLight) override;
};