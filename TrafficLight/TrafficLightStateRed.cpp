#include "ITrafficLight.h"
#include "TrafficLightStateRed.h"

TrafficLightStateRed::TrafficLightStateRed() {}
TrafficLightStateRed::~TrafficLightStateRed() {}

void TrafficLightStateRed::changeState(ITrafficLight* trafficLight) {
	trafficLight->setRedState();
}