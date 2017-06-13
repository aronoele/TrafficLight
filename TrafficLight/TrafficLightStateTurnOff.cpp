#include "ITrafficLight.h"
#include "TrafficLightStateTurnOff.h"

TrafficLightStateTurnOff::TrafficLightStateTurnOff() {}
TrafficLightStateTurnOff::~TrafficLightStateTurnOff() {}

void TrafficLightStateTurnOff::changeState(ITrafficLight* trafficLight) {
	trafficLight->setTurnOffState();
}