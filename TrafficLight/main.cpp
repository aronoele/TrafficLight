#include "TrafficLight.h"

int main()
{
	TrafficLight trafficLight;
	trafficLight.setIntervalRed(2000);
	trafficLight.setIntervalYellow(4000);
	trafficLight.setIntervalGreen(3000);

	trafficLight.work();

	return 0;
}