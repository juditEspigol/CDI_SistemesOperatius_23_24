
#include "ConsoleControl.h"


void main() {

	/// TRASTEAR CON LA CLASSE CONSOLE CONTROL
	ConsoleControl::SetColor(ConsoleControl::CYAN); 
	std::cout << "Alex putero" << std::endl; 
	ConsoleControl::SetColor();

	ConsoleControl::SetPosition(5, 3); 
	std::cout << '?' << std::endl; 

	char keyCode = ConsoleControl::WaithForReadNextKey(); 

	std::cout << "La key code es: " << keyCode << " -> " << static_cast<int>(keyCode);
}