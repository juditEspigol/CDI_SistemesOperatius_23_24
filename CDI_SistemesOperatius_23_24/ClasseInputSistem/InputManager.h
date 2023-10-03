#pragma once
#include <mutex>
#include <thread>

class InputManager
{
private:
	std::mutex* _isStartedMutex = new std::mutex();
	// Protejo la variable si diferentes threds pueden acceder a ella
	bool _isStarted = false; 

	std::thread* _listenerThread; 
	void ReadLoop(); 

public:
	InputManager(); 
	~InputManager(); 

	void StartListener();
	void StopListener();

	unsigned int AddListener(int keyCode/*, KeyBinding::OnKeyPress onKeyPress*/);
	void RemoveListener(unsigned int listenerId); 
};

