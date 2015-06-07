#ifndef _TIMER_H_
#define _TIMER_H_

class Timer
{
public:
	Timer();
	Timer(double miliseconds);

	void Reset();
	double GetTime();
	float GetFPS(double ticks);
	void Pause(double miliseconds);

private:
	double time;
}

#endif