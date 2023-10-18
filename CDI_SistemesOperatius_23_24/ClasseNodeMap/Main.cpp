#include <iostream>
#include "Node.h"
#include "Map.h"
#include "ConsoleControl.h"

class Tree : public INodeContent
{
public:
	Tree() {}; 
	~Tree() {}; 
	virtual void Draw(Vector2 offset) override
	{
		Vector2 pos = offset; 
		ConsoleControl::LockMutex(); 
		ConsoleControl::SetPosition(pos.X, pos.Y); 
		ConsoleControl::SetColor(ConsoleControl::GREEN); 
		std::cout << "T"; 
		ConsoleControl::SetColor(); 
		ConsoleControl::UnlockMutex(); 
	}
};

class Coin : public INodeContent
{
public:
	Coin() {};
	~Coin() {};
	virtual void Draw(Vector2 offset) override
	{
		Vector2 pos = offset;
		ConsoleControl::LockMutex();
		ConsoleControl::SetPosition(pos.X, pos.Y);
		ConsoleControl::SetColor(ConsoleControl::YELLOW);
		std::cout << "C";
		ConsoleControl::SetColor();
		ConsoleControl::UnlockMutex();
	}
};

int main()
{
	Map* map = new Map(Vector2(10, 10), Vector2(2, 2));

	map->SafePickNode(Vector2(3, 3), [](Node* node) {

		node->SetContent(new Tree());

		}); 

	map->UnSafeDraw(); 
}