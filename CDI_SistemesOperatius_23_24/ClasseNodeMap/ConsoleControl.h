#pragma once
#include <mutex>
#include <iostream>
#include <mutex>

#define KB_UP 72
#define KB_DOWN 80
#define KB_LEFT 75
#define KB_RIGHT 77
#define KB_SPACE 32
#define KB_ESCAPE 27

#define KB_P 112
#define KB_J 106
#define KB_M 109
#define KB_N 110
#define KB_U 117
#define KB_C 99
#define KB_R 114

#define KB_0 48
#define KB_1 49
#define KB_2 50
#define KB_3 51
#define KB_4 52
#define KB_5 53
#define KB_6 54
#define KB_7 55
#define KB_8 56
#define KB_9 57


// static es para no crear instancias fuera
static class ConsoleControl {
private:
	std::mutex* consoleMutex = new std::mutex();
protected:
	static ConsoleControl* instance;
public:
	enum ConsoleColor {
		BLACK, DARKBLUE, DARKGREEN, DARKCYAN, DARKRED, DARKMAGENTA, DARKYELLOW, LIGHTGREY,
		DARKGREY, BLUE, GREEN, CYAN, RED, MAGENTA, YELLOW, WHITE
	};

	static void SetColor(ConsoleColor ForeColor = WHITE, ConsoleColor BackColor = BLACK); // static es que la puedo llamar sin instanciar la classe
	static void SetPosition(short int x, short int y);
	static void Clear();
	static void ClearCharacter(char character, ConsoleColor ForeColor, ConsoleColor BackColor);

	static void Wait(unsigned long milisecons);

	static int ReadNextKey(); // mira si hay una tecla pulsada en ese instante
	static int WaithForReadNextKey(); // se espera hasta que piques una tecla

	static void LockMutex();
	static void UnlockMutex();

	static ConsoleControl* GetInstance();
};

//singelton garantiza que solo hay una instancia de esta classe

// refactoring guru -> explica patrones de diseño (solucion a un problema común)