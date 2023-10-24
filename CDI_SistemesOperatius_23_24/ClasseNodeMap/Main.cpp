#include <iostream>
#include "Node.h"
#include "Map.h"
#include "ConsoleControl.h"

class Tree : public INodeContent
{
private:
	bool _onFire = false; 

public:
	Tree() {}; 
	~Tree() {}; 
	virtual void Draw(Vector2 offset) override
	{
		Vector2 pos = offset; 
		ConsoleControl::LockMutex(); 
		ConsoleControl::SetPosition(pos.X, pos.Y); 
		ConsoleControl::SetColor(_onFire ? ConsoleControl::RED : ConsoleControl::GREEN);
		std::cout << "T"; 
		ConsoleControl::SetColor(); 
		ConsoleControl::UnlockMutex(); 
	}

	void SetOnFire()
	{
		_onFire = true; 
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

	map->SafePickNode(Vector2(5, 3), [](Node* node) {

		node->SetContent(new Tree());

		}); 

	map->SafePickNode(Vector2(7, 3), [](Node* node) {

		node->SetContent(new Coin());

		});

	std::list<Vector2> treesPos = std::list<Vector2>(); 
	treesPos.push_back(Vector2(2, 2));
	treesPos.push_back(Vector2(2, 3));
	treesPos.push_back(Vector2(3, 2));
	treesPos.push_back(Vector2(3, 3));

	map->SafePickNodes(treesPos, [map](std::list<Node*>* nodes) {
		for (Node* node : *nodes)
		{
			if (node != nullptr)
			{
				node->SetContent(new Tree());
				node->DrawContent(map->GetOffset());
			}
		}

		}); 

	std::list<Vector2> fuegoPos = std::list<Vector2>();
	fuegoPos.push_back(Vector2(2, 2));
	fuegoPos.push_back(Vector2(3, 2));

	map->SafePickNodes(fuegoPos, [map](std::list<Node*>* nodes) {
		for (Node* node : *nodes)
		{
			Tree* tree = nullptr;
			if (node != nullptr && node->TryGetContent<Tree>(tree))
			{
				tree->SetOnFire(); 
				node->DrawContent(map->GetOffset());
			}
		}

		});

	map->UnSafeDraw(); 
}