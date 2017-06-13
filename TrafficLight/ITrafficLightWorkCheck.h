#pragma once

class ITrafficLightWorkCheck
{
public:
	virtual ~ITrafficLightWorkCheck() {}
	virtual bool isWorking(int interval) = 0;
};
