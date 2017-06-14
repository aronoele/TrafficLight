#include "ITrafficLight.h"
#include "TrafficLightStateRed.h"
#include "TrafficLightStateWriter.h"

TrafficLightStateRed::TrafficLightStateRed() {}
TrafficLightStateRed::~TrafficLightStateRed() {}

void TrafficLightStateRed::changeState(ITrafficLight* trafficLight) {
	trafficLight->setRedState();
	TrafficLightStateWriter log;
	log.write("RED");
}