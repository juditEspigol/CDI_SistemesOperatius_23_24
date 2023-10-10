#pragma once
#include "ConsoleControl.h"
#include <thread>
#include <mutex>

static class Timer
{
private:
	std::thread* _timerThread;

public:
	// Ejecuta una funcion cuando acaba de contar
	void StartTimer(unsigned long miliseconsTriggerDeLay /*function lambda */) {

		_timerThread = new std::thread(&ConsoleControl::Wait, miliseconsTriggerDeLay);
		_timerThread->detach();

		// cuando el thread acabe ejecuta la funcion lambda
	}




	// Ejecuta una funcion en bucle cada vez que acaba de contar
	void StartLoopTimer(unsigned long miliseconsTriggerDeLay);
};