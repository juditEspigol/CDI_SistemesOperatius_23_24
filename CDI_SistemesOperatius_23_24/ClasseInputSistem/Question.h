#pragma once
#include <string>
#include <vector>

class Question
{
private:
	std::string _question; 
	std::vector<std::string> _answers;
	unsigned int _correctAnswer;
	unsigned int* _lastSelection = nullptr; 

public:
	Question(std::string question, std::vector<std::string> answers, unsigned int correctAnswer)
		: _question(question), _answers(answers), _correctAnswer(correctAnswer) { };

	void DrawAnswer(unsigned int numAnswer) 
	{
		std::cout << "R[" << numAnswer << "] ---> " << _answers[numAnswer] << std::endl;
	}

	void DrawAll() 
	{
		ConsoleControl::SetColor();
		std::cout << "Question: " << _question << std::endl;
		for (int i = 0; i < _answers.size(); i++)
		{
			DrawAnswer(i); 
		}
	}
	void SelectAnswer(unsigned int* selectedAnswer)
	{
		// BORRA L'ANTERIOR SELECCION
		if (_lastSelection != nullptr)
		{
			ConsoleControl::SetColor();
			ConsoleControl::SetPosition(0, 1 + *_lastSelection);
			DrawAnswer(*_lastSelection);
		}

		// SELECCIONA ANSWER ACTUAL
		ConsoleControl::SetColor(ConsoleControl::YELLOW); 
		ConsoleControl::SetPosition(0, 1 + *selectedAnswer); 
		DrawAnswer(*selectedAnswer);

		// ACTUALIZA LA ANTERIOR ANSWER
		_lastSelection = selectedAnswer;
	}
	void ResolveQuestion(){
		// PINTAR VERDE LA CORRECTA
		
		/*ConsoleControl::SetColor(ConsoleControl::YELLOW);
		ConsoleControl::SetPosition(0, 1 + *selectedAnswer);
		std::cout << "R[" << *selectedAnswer << "] ---> " << _answers[*selectedAnswer];*/

		// SI ESTA MAL SELECCIONADA 
	}
};