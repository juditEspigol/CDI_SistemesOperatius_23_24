#pragma once
#include "Question.h"

class QuestionManager 
{
private:
public:
	std::vector<Question*> _questions;
	QuestionManager() 
	{
		Question* question; 
		question= new Question("¿En que juego Ganondorf tiene dos espadas?",
			{ "Twilght Princess", "Ocarina of Time", "Wind Waker" }, 
			2);
		_questions.push_back(question); 
		question = new Question("¿A que raza pertenece Link?",
			{ "Hylian", "Gerudo", "Kokiri", "Sheikah"},
			0);
		_questions.push_back(question);
		question = new Question("¿Cual es el nombre del Rey de Hyrule en Wind Waker?",
			{ "Daltus III", "Daphnes Nohansen Hyrule", "Niless Gruphenson Hyrule" },
			1);
		_questions.push_back(question);
		question = new Question("Hay 3 partes de la trifuerza: poder, sabiduria y...",
			{ "Esfuerzo", "Conocimiento", "Coraje", "Espiritu" },
			2);
		_questions.push_back(question);
		question = new Question("¿Cuantas canciones podias aprender en Ocarina of Time?",
			{ "14", "16", "10" "12" },
			3);
		_questions.push_back(question);
	}
	
	void Draw() 
	{
		for (const auto iter : _questions)
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
};