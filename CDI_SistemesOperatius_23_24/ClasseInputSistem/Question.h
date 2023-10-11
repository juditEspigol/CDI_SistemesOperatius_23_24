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

	void DrawAnswer(unsigned int numAnswer)
	{
		std::cout << "R[" << 1 + numAnswer << "] ---> " << _answers[numAnswer] << std::endl;
	}
	void ChangeColorAnswer(ConsoleControl::ConsoleColor foreColor, unsigned int selectedAnswer)
	{
		ConsoleControl::SetColor(foreColor); 
		ConsoleControl::SetPosition(0, 1 + selectedAnswer);
		DrawAnswer(selectedAnswer);
	}

public:
	Question(std::string question, std::vector<std::string> answers, unsigned int correctAnswer)
		: _question(question), _answers(answers), _correctAnswer(correctAnswer) { };
	~Question() { delete _lastSelection; };

	void DrawAll() 
	{
		system("cls"); 
		ConsoleControl::SetColor();
		std::cout << "Question: " << _question << std::endl;
		for (int i = 0; i < _answers.size(); i++)
			DrawAnswer(i); 
	}

	void SelectAnswer(unsigned int* selectedAnswer)
	{
		// BORRA L'ANTERIOR SELECCION
		if (_lastSelection != nullptr)
		{
			ChangeColorAnswer(ConsoleControl::WHITE, *_lastSelection); 
		}

		// SELECCIONA ANSWER ACTUAL
		if (selectedAnswer != nullptr)
		{
			ChangeColorAnswer(ConsoleControl::YELLOW, *selectedAnswer);
		}

		// ACTUALIZA LA ANTERIOR ANSWER
		_lastSelection = selectedAnswer;
	}
	void ResolveQuestion(){
		
		if (_lastSelection != nullptr && *_lastSelection != _correctAnswer)
		{
			ChangeColorAnswer(ConsoleControl::RED, *_lastSelection);
		}

		ChangeColorAnswer(ConsoleControl::GREEN, _correctAnswer);
	}
};