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
	_listenerThread = new std::thread(&InputManager::ReadLoop, this); 
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
		_listenersMapMutex->lock(); 
		KeyBindingListsMap::iterator pair = _listenersMap->find(keyCode); 
		if (pair != _listenersMap->end())
		{
			std::list<KeyBinding*>* keyBindings = pair->second;
			for (KeyBinding* keyBinding : *keyBindings)
			{
				keyBinding->onKeyPress(keyCode); 
			}
		}
		_listenersMapMutex->unlock();

		_isStartedMutex->lock();
		isStarted = _isStarted; 
		_isStartedMutex->unlock();
	}
}

void InputManager::SaveListener(KeyBinding* keyBinding)
{
	_listenersMapMutex->lock();

	KeyBindingListsMap::iterator pair = _listenersMap->find(keyBinding->keyCode);
	// Revisar si lo ha encontrado
	std::list<KeyBinding*>* keyBindings = nullptr;

	if (pair == _listenersMap->end()) // No lo ha encontrado
	{
		keyBindings = new std::list<KeyBinding*>();
		_listenersMap->emplace(keyBinding->keyCode, keyBindings);
	}
	else // Lo ha encontrado
	{
		keyBindings = pair->second;
	}
	keyBindings->push_back(keyBinding);

	_listenersMapMutex->unlock();
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

unsigned int InputManager::AddListener(int keyCode,/* unsigned long miliseconsTriggerDeLay, */KeyBinding::OnKeyPress onKeyPress)
{
	KeyBinding* binding = new KeyBinding(keyCode, onKeyPress); 

	SaveListener(binding); 

	return binding->GetSubscriptionId();
}

unsigned int InputManager::AddListenerAsync(int keyCode,/* unsigned long miliseconsTriggerDeLay,*/ KeyBinding::OnKeyPress onKeyPress) 
{
	KeyBinding* binding = new KeyBinding(keyCode, onKeyPress); 

	std::thread* safeListenerThread = new std::thread(&InputManager::SaveListener, this, binding); 

	safeListenerThread->detach(); 

	return binding->GetSubscriptionId(); 
}

void InputManager::RemoveListener(unsigned int subscriptionId)
{
	_listenersMapMutex->lock();

	for (std::pair<int, std::list<KeyBinding*>*> pair : *_listenersMap)
	{
		// Esta linia de codigo lo hace más eficiente
		std::list<KeyBinding*>* keyBindings = pair.second;
		for (KeyBinding* binding : *keyBindings)
		{
			if (binding->GetSubscriptionId() == subscriptionId)
			{
				keyBindings->remove(binding);
				_listenersMapMutex->unlock();
				return; // EARLY EXIT
			}
		}
	}
	_listenersMapMutex->unlock(); 
}

void InputManager::RemoveListenerAsync(unsigned int subscriptionId)
{
	std::thread* safeListenerThread = new std::thread(&InputManager::RemoveListener, this, subscriptionId); 
	safeListenerThread->detach(); 
}

InputManager::KeyBinding::KeyBinding(int keyCode, OnKeyPress onKeyPress)
{
	// Es importante que sea static i que sea el mismo mutex todo el rato porque sino no bloquea bien
	// si lo vuelven a llamar 
	// No lo defino como puntero porque sino nadie sabria como eliminarlo
	static std::mutex currentIdMutex;
	currentIdMutex.lock(); 
	// static: como idea general para compartir informacion
	// El static en functions crea un espacio de memoria i siempre entrara en ese espacio de memoria por lo tanto siempre 
	// accede al valor que havia en el espacio de memoria 
	static unsigned int  currentId = 0; 

	_subscriptionId = currentId;
	currentId++; 
	currentIdMutex.unlock(); 

	this->keyCode = keyCode; 
	this->onKeyPress = onKeyPress; 
}

InputManager::KeyBinding::~KeyBinding()
{

}

unsigned int InputManager::KeyBinding::GetSubscriptionId() const
{
	return _subscriptionId;
}