#include "ITrafficLight.h"
#include "TrafficLightStateGreen.h"
#include "TrafficLightStateWriter.h"

TrafficLightStateGreen::TrafficLightStateGreen() {}
TrafficLightStateGreen::~TrafficLightStateGreen() {}

void TrafficLightStateGreen::changeState(ITrafficLight* trafficLight) {
	trafficLight->setGreenState();
	TrafficLightStateWriter log;
	log.write("GREEN");
}