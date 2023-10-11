
#include "ConsoleControl.h"
#include "InputManager.h"
#include "Timer.h"
#include "Question.h"

void main() {

	/// TRASTEAR CON LA CLASSE CONSOLE CONTROL
	/*ConsoleControl::SetColor(ConsoleControl::CYAN);
	std::cout << "Alex putero" << std::endl;
	ConsoleControl::SetColor();

	ConsoleControl::SetPosition(5, 3);
	std::cout << '?' << std::endl;

	char keyCode = ConsoleControl::WaithForReadNextKey();

	std::cout << "La key code es: " << keyCode << " -> " << static_cast<int>(keyCode);*/


	// TESTEAR INPUT MANAGER 
	/*InputManager* IManager = new InputManager();

	IManager->StartListener(); // Enciende la funcion loop con un detach

	// Para que no se cierre el programa
	while (true) 
	{
	}*/
	/*InputManager* iManager = new InputManager(); 
	int keyCodeToRead = ConsoleControl::WaithForReadNextKey(); 
	int tryes = 0; 

	iManager->AddListenerAsync(keyCodeToRead, 100011, [&tryes, iManager](int keyCode) {
		tryes++;
		std::cout << "Intento numero " << tryes << std::endl;
		}); 
	iManager->StartListener(); 

	while(true){
	}*/


	/*Timer* timer = new Timer(); 

	timer->StartTimer(1000, []() {
		std::cout << "holi";
		}); 

	timer->StartTimer(3000, []() {
		std::cout << "adios";
		});*/

	Question* question = new Question("Suspendo?", { "Si", "Seguramente", "Obvio", "Todas"}, 3);

	question->DrawAll(); 

	Timer::StartTimer(3000, [question]() {
			question->SelectAnswer(new unsigned int(2)); 
		}); 

	Timer::StartTimer(5000, [question]() {
		question->SelectAnswer(new unsigned int(1));
		});


	while (true) {}; 
}