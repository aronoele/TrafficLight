#include "ITrafficLight.h"
#include "TrafficLightStateYellow.h"
#include "TrafficLightStateWriter.h"

TrafficLightStateYellow::TrafficLightStateYellow() {}
TrafficLightStateYellow::~TrafficLightStateYellow() {}

void TrafficLightStateYellow::changeState(ITrafficLight* trafficLight) {
	trafficLight->setYellowState();
	TrafficLightStateWriter log;
	log.write("YELLOW");
}