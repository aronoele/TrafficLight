#pragma once

class ITrafficLight
{
public:
	virtual ~ITrafficLight() {}

	virtual void setRedState() = 0;
	virtual void setYellowState() = 0;
	virtual void setGreenState() = 0;
	virtual void setTurnOffState() = 0;
};
