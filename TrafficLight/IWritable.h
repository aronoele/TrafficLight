#pragma once

#include <iostream>

class IWritable
{
public:
	virtual ~IWritable() {}
	virtual void write(const std::string& str) = 0;
};
