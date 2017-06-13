#include "ITrafficLight.h"
#include "TrafficLightStateYellow.h"

TrafficLightStateYellow::TrafficLightStateYellow() {}
TrafficLightStateYellow::~TrafficLightStateYellow() {}

void TrafficLightStateYellow::changeState(ITrafficLight* trafficLight) {
	trafficLight->setYellowState();
}