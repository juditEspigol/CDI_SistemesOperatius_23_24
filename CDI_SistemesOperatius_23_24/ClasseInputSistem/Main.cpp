
#include "ConsoleControl.h"
#include "InputManager.h"
#include "Timer.h"
#include "Question.h"
#include "QuestionManager.h"

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

	QuestionManager* questionManager = new QuestionManager();

	InputManager* iManager = new InputManager(); 
	iManager->StartListener(); 

	// x = 2s + numAnswers * 2s;
	unsigned long count = 2000 + (questionManager->_questions.size() * 2000);

	Timer::StartTimer(count, []() {



		}); 


	iManager->AddListenerAsync(KB_0, [](int keyCode) {
		
		});



	// se que esto no va aqui pero de momento se queda aqui 
	for (const auto iter : questionManager->_questions)
	{
		// lo pintamos
		iter->DrawAll();

		// esperamos x tiempo a que este seleccionando a traves de inputs 


		// ensenyamos la respuesta correcta mientras waiteamos 
		Timer::StartTimer(3000, [iter]() {
			iter->SelectAnswer(new unsigned int(2));
			});
	}
	system("cls");
	std::cout << "You finished!!" << std::endl;
}