#include <iostream>
#include "Node.h"

int main()
{
	Node* node = new Node(Vector2()); 

	INodeContent* iContent = node->GetContent(); 
}