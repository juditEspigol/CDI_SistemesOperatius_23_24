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

void Map::SafePickNode(Vector2 position, SafePick safePickAction)
{
	if (position.X >= _size.X || position.Y >= _size.Y)
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

