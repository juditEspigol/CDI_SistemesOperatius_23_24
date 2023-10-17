#pragma once
#include "Vector2.h"
#include "INodeContent.h"
#include <mutex>

class Node
{
private:
	Vector2 _position; 
	INodeContent* _content = nullptr;
	std::mutex* _classMutex = new std::mutex();

public:
	Node(Vector2 position); 

	INodeContent* GetContent(); 

	// No esoty declarando una funcion sino unas 
	//  instrucciones para que el compilador pueda construir una funcion
	template<typename T, typename = typename std::enable_if<std::is_base_of<INodeContent, T>::value>::type>
	T* Getcontent()
	{
		T^ contentCasted = dynamic_cast<T*>(_content); 
		return contentCasted; 
	}

	template<typename T, typename = typename std::enable_if<std::is_base_of<INodeContent, T>::value>::type>
	bool TryGetContent(T*& outContent) // quiero canviar el puntero no la informacion que tiene el puneto por eso tiene el &
	{
		T* contentCasted = dynamic_cast<T*>(_content); 

		if (contentCasted != nullptr)
		{
			outContent = contentCasted; 
			return true; 
		}
		return false; 
	}

	void SetContent(INodeContent* newContent); 
	void DrawContent(Vector2 offset); 

	void Lock(); 
	void Unlock(); 
};

