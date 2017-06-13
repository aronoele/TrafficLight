#include "ITrafficLight.h"
#include "TrafficLightStateGreen.h"

TrafficLightStateGreen::TrafficLightStateGreen() {}
TrafficLightStateGreen::~TrafficLightStateGreen() {}

void TrafficLightStateGreen::changeState(ITrafficLight* trafficLight) {
	trafficLight->setGreenState();
}