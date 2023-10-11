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
	// Ejecuta una funcion cuando acaba de contar
	static void StartTimer(unsigned long timeRequiredMilisecons, OntimeElapsed onTimeElapsed)
	{
		std::thread* timerThread = new std::thread([timeRequiredMilisecons, onTimeElapsed]() {
			ConsoleControl::Wait(timeRequiredMilisecons);
			onTimeElapsed();
			});
		timerThread->detach();  
	}

	// Ejecuta una funcion en bucle cada vez que acaba de contar
	static void StartLoopTimer(unsigned long timeRequiredMilisecons, OntimeElapsedWithLoop onTimeElapsedWithLoop)
	{
		std::thread* thread = new std::thread([timeRequiredMilisecons, onTimeElapsedWithLoop]() {
			bool continueLoop = true;
			while (continueLoop)
			{
				ConsoleControl::Wait(timeRequiredMilisecons);
				continueLoop = onTimeElapsedWithLoop();
			}
			}); 
		thread->detach(); 
	}
};