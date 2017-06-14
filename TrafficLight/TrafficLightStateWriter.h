#pragma once

#include <iostream>

#include "IWritable.h"

class TrafficLightStateWriter : public IWritable {
public:
	TrafficLightStateWriter();
	~TrafficLightStateWriter();
	void write(const std::string& str) override;
};
