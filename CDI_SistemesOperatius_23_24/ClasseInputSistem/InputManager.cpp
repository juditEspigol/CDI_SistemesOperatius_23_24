#include "InputManager.h"
#include "ConsoleControl.h"

InputManager::InputManager()
{

}

InputManager::~InputManager()
{

}

void InputManager::StartListener()
{
	_isStartedMutex->lock(); 
	
	// Asegurarse de no haver encendido antes
	if (_isStarted) // Design program -> GUARD
	{ 
		_isStartedMutex->unlock(); 
		return; 
	}
	_isStarted = true; 

	_isStartedMutex->unlock();

	// Thread que ejecuta la funcion ReadLoop en segundo plano 
	_listenerThread = new std::thread(&ReadLoop, this); 
	_listenerThread->detach(); 
}

void InputManager::ReadLoop()
{
	_isStartedMutex->lock();
	bool isStarted = _isStarted;
	_isStartedMutex->unlock();

	while (isStarted) 
	{
		int keyCode = ConsoleControl::WaithForReadNextKey();

		// Search in keyBinding Map, if pressed key code exist
		// If exist -> call all lamda functions (funcion sin nombre, utilizas una funcion como una variable)

		_isStartedMutex->lock();
		isStarted = _isStarted; 
		_isStartedMutex->unlock();
	}
}

void InputManager::StopListener()
{
	/**
	* El lock i el unlock tienen que estar 
	* separados lo minimo necesario, para que no se pare mucho el juego
	*/
	_isStartedMutex->lock(); 
	_isStarted = false; 
	_isStartedMutex->unlock(); 
}
