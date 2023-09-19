/**
* DATA:19.09.23
* CLASSE: Threads ( se utiliza para optimizar
*/

#include <iostream>
#include <chrono>
#include <string>

#pragma region Function Declaration Header

// calcular el tiempo que ha pasado desde ejecutar el programa hasta justo antes de utilizar la funcion 
void PrintElapsedTime(std::chrono::system_clock::time_point start, std::chrono::system_clock::time_point end); 
void Count(int maxCounter); 
void Example01(); 
void Example02(); 
void Example03(); 
void Example04(); 
void Example05(); 
void Example06(); 

#pragma endregion 


#pragma region Global Variables

std::chrono::system_clock::time_point startDate; 

#pragma endregion 

int main()
{
	startDate = std::chrono::system_clock::now(); // fecha de cuando se habre la app

	int exampleUsed = 1; 

	switch (exampleUsed)
	{
	case 1: 
		Example01(); 
		break; 
	case 2:
		Example02();
		break;
	case 3:
		Example03();
		break;
	case 4:
		Example04();
		break;
	case 5:
		Example05();
		break;
	case 6:
		Example06();
		break;
	default:
		break;
	}

	std::cout << "Example 0" << exampleUsed << " finished" << std::endl; 
	std::string text = "";
	std::getline(std::cin, text); 
}

void PrintElapsedTime(std::chrono::system_clock::time_point start, std::chrono::system_clock::time_point end) {
	std::chrono::duration<double> elapsedTime = end - start; 
	// To do
	std::cout << "Elapsed time " << elapsedTime.count() << " seconds" << std::endl; 
	// To do
}

void Count(int maxCounter) {
	// To do extra
	for (int i = 0; i < maxCounter; i++)
	{

	}
	
	std::chrono::system_clock::time_point endData = std::chrono::system_clock::now(); 
	PrintElapsedTime(startDate, endData); 
}

void Example01() {

	unsigned long long totalCount = 1000 * 1000 * 1000; 

	Count(totalCount); 
}
void Example02() {

}
void Example03() {

}
void Example04() {

}
void Example05() {

}
void Example06() {

}