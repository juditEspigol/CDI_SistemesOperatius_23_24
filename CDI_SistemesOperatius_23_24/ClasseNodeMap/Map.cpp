#include "Map.h"

Map::Map(Vector2 size, Vector2 offset)
{
	_size = size; 
	_offset = offset; 
	_grid = new NodeGrid();

	for (int x = 0; x < _size.X; x++)
	{
		NodeColumn* column = new NodeColumn(); 

		for (int y = 0; y < _size.Y; y++)
		{
			column->push_back(new Node(Vector2(x, y))); 
		}
		_grid->push_back(column); 
	}
}

Node* Map::UnSafeGetNode(Vector2 position)
{
	// NodeColumn* column = (*_grid)[position.X];
	// Node* node = (*column)[position.Y];

	return (*(*_grid)[position.X])[position.Y];
}

void Map::UnSafeDraw(Vector2 offset)
{
	Vector2 totalOffset = _offset + offset; 

	for (NodeColumn* column : *_grid)
	{
		for (Node* Node : *column)
		{
			Node->DrawContent(totalOffset);
		}
	}
}

void Map::SafeDraw(Vector2 offset)
{
	Vector2 totalOffset = _offset + offset;

	_gridMutex->lock(); 

	for (NodeColumn* column : *_grid)
	{
		for (Node* Node : *column)
		{
			Node->Lock(); 
			Node->DrawContent(totalOffset);
			Node->Unlock(); 
		}
	}
	_gridMutex->unlock(); 
}

Vector2 Map::GetOffset()
{
	_offsetMutex->lock(); 
	Vector2 offset = _offset; 
	_offsetMutex->unlock(); 

	return offset;
}

void Map::SafePickNode(Vector2 position, SafePick safePickAction)
{
	_sizeMutex->lock(); 
	Vector2 size = _size;
	_sizeMutex->unlock(); 

	if (position.X >= size.X || position.Y >= size.Y 
		|| position.X < 0 || position.Y < 0)
	{
		safePickAction(nullptr); 
		return; 
	}
	_gridMutex->lock(); 
	Node* node = UnSafeGetNode(position); 
	_gridMutex->unlock();

	node->Lock(); 
	safePickAction(node); 
	node->Unlock(); 
}

void Map::SafePickNodes(std::list<Vector2> positions, SafeMultiPick safeMultiPickAction)
{


	std::list<Node*>* nodes = new std::list<Node*>(); 

	_sizeMutex->lock();
	Vector2 size = _size;
	_sizeMutex->unlock();

	for (Vector2 pos : positions)
	{
		if (pos.X >= size.X || pos.Y >= size.Y 
			|| pos.X < 0 || pos.Y < 0)
		{
			nodes->push_back(nullptr); 
			continue; 
		}

		_gridMutex->lock();
		Node* node = UnSafeGetNode(pos);
		_gridMutex->unlock();
		nodes->push_back(node);
	}

	_safeMultiPickMutex->lock(); 
	for (Node* node : *nodes)
	{
		if(node != nullptr)
			node->Lock(); 
	}
	_safeMultiPickMutex->unlock(); 

	safeMultiPickAction(nodes); 

	for (Node* node : *nodes)
	{
		if(node != nullptr)
			node->Unlock();
	}
}

