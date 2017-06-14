#include <iostream>
#include <fstream>
#include <ctime>

#include "TrafficLightStateWriter.h"

using namespace std;

TrafficLightStateWriter::TrafficLightStateWriter() {}
TrafficLightStateWriter::~TrafficLightStateWriter() {}

void TrafficLightStateWriter::write(const string& str)
{
	const char* note = str.c_str();
	struct tm currentTime;
	time_t now = time(0);
	localtime_s(&currentTime, &now);
	char noteTime[26];
	asctime_s(noteTime, sizeof noteTime, &currentTime);

	ofstream out("log.txt", ios::out | ios::app);
	if (!out.is_open()) {
		cout << "Writting error\n";
	}
	out << note << '\t' << noteTime << endl;
	out.close();
}