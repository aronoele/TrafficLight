#pragma once

#include "ITrafficLight.h"
#include "ITrafficLightState.h"

class TrafficLightStateGreen : public ITrafficLightState
{
public:
	TrafficLightStateGreen();
	~TrafficLightStateGreen();
	void changeState(ITrafficLight* trafficLight) override;
};