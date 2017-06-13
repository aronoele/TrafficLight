#pragma once

#include "ITrafficLight.h"

class ITrafficLightState
{
public:
	virtual ~ITrafficLightState() {}
	virtual void changeState(ITrafficLight* trafficLight) = 0;
};
