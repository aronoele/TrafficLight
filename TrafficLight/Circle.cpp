#include <iostream>
#include <Windows.h>

#include "Color.h"
#include "Circle.h"

Circle::Circle()
{
	color_ = Color::COLOR_DARKGRAY;
}

Circle::~Circle() {}

Color Circle::getColor()
{
	return color_;
}

void Circle::setColor(const Color& color)
{
	color_ = color;
}

void Circle::draw()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, color_);
	std::cout << "\t    *****\n" <<
		"\t ***********\n" <<
		"\t*************\n" <<
		"\t*************\n" <<
		"\t ***********\n" <<
		"\t    *****\n";
}