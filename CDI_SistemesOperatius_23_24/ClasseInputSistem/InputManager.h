#pragma once
#include <mutex>
#include <thread>
#include <functional>
#include <map>
#include <list>

class InputManager
{
public:
	// Para passarle la tecla, el listener, para identificar la id
	class KeyBinding 
	{
	public:
		typedef std::function<void(int keyCode)> OnKeyPress; 

		int keyCode; 
		OnKeyPress onKeyPress;

		KeyBinding(int keyCode, OnKeyPress onKeyPress);
		~KeyBinding(); 

		unsigned int GetSubscriptionId() const;
	private:
		unsigned int _subscriptionId = 0;
	};
	
private:
	std::mutex* _isStartedMutex = new std::mutex();
	// Protejo la variable si diferentes threds pueden acceder a ella
	bool _isStarted = false; 

	typedef std::map<int, std::list<KeyBinding*>*> KeyBindingListsMap; 

	std::mutex* _listenersMapMutex = new std::mutex(); 
	KeyBindingListsMap* _listenersMap = new KeyBindingListsMap();

	std::thread* _listenerThread; 
	void ReadLoop(); 

public:
	InputManager(); 
	~InputManager(); 

	void StartListener();
	void StopListener();

	// Key binding esta definida dentro de otra classe
	unsigned int AddListener(int keyCode, KeyBinding::OnKeyPress onKeyPress);
	void RemoveListener(unsigned int subscriptionId);
};

// name espace: 