#include "Timer.h"


using namespace std::chrono;

void Timer::startTimer()
{
	start_time = high_resolution_clock::now();
}

void Timer::stopTimer()
{
	end_time = high_resolution_clock::now();
}

long Timer::result() {
	
	return duration_cast<nanoseconds>(end_time - start_time).count();

}