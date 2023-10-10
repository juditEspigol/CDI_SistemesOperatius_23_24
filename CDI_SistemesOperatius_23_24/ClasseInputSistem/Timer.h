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

		// LA FUNCTION LAMBDA ESTARA EN FUNCIONAMENT EL TEMPS QUE ESTIGUI EL THREAD EN FUNCIONAMENT 
		_timerThread = new std::thread(&ConsoleControl::Wait, this, miliseconsTriggerDeLay);
		_timerThread->detach();
	}

	// Ejecuta una funcion en bucle cada vez que acaba de contar
	void StartLoopTimer(unsigned long miliseconsTriggerDeLay /*function lambda*/);
};