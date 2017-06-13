#pragma once

#include "Color.h"

class Circle
{
public:
	Circle();
	~Circle();
	Color getColor();
	void setColor(const Color& color);
	void draw();
private:
	Color color_;
};
