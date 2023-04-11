#pragma once

#include <chrono>

class Timer {

public:

	std::chrono::high_resolution_clock::time_point start_time;
	std::chrono::high_resolution_clock::time_point end_time;

	void startTimer();
	void stopTimer();
	long result();

};