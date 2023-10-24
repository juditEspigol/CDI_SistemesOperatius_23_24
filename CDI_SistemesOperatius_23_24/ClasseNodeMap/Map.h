#pragma once
#include <vector>
#include <functional>
#include <list>

#include "Node.h"
#include "Vector2.h"


// la classe map tendria que ser friend de node
class Map
{

public:
	typedef std::vector<Node*> NodeColumn; 
	typedef std::vector<NodeColumn*> NodeGrid; 
	typedef std::function<void(Node* node)> SafePick; 
	typedef std::function<void(std::list<Node*>* nodes)> SafeMultiPick; 

private:
	Vector2 _offset = Vector2(); 
	std::mutex* _offsetMutex = new std::mutex();

	Vector2 _size; 
	std::mutex* _sizeMutex = new std::mutex();

	NodeGrid* _grid = nullptr; 
	std::mutex* _gridMutex = new std::mutex(); 

	std::mutex* _safeMultiPickMutex = new std::mutex(); 

	inline Node* UnSafeGetNode(Vector2 position); 

public:
	Map(Vector2 size, Vector2 offset = Vector2()); 

	void UnSafeDraw(Vector2 offset = Vector2()); 
	void SafeDraw(Vector2 offset = Vector2());

	Vector2 GetOffset(); 

	void SafePickNode(Vector2 position, SafePick safePickAction); 

	/// <summary>
	/// This function can't be recive duplicated positions 
	/// </summary>
	void SafePickNodes(std::list<Vector2> positions, SafeMultiPick safeMultiPickAction); 
};

