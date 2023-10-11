#pragma once
#include "ConsoleControl.h"
#include <thread>
#include <mutex>
#include <functional>
#include "ConsoleControl.h"

static class Timer
{
private:
	typedef std::function<void()> OntimeElapsed;
	typedef std::function<bool()> OntimeElapsedWithLoop;

public:
	Timer(){ }
	// Ejecuta una funcion cuando acaba de contar
	static void StartTimer(unsigned long timeRequired, OntimeElapsed onTimeElapsed)
	{
		std::thread* timerThread = new std::thread([timeRequired, onTimeElapsed]() {
			ConsoleControl::Wait(timeRequired);
			onTimeElapsed();
			});
		timerThread->detach();  
	}

	// Ejecuta una funcion en bucle cada vez que acaba de contar
	static void StartLoopTimer(unsigned long timeRequired, OntimeElapsedWithLoop onTimeElapsedWithLoop)
	{

	}
};