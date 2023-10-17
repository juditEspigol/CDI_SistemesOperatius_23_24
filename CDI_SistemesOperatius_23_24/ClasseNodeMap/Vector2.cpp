#include "Vector2.h"

Vector2::Vector2()
{

}

Vector2::Vector2(int x, int y)
{
	this->X = x; 
	this->Y = y; 
}

Vector2 Vector2::operator+(Vector2 other)
{
	return Vector2(X + other.X, Y + other.Y);
}

Vector2 Vector2::operator-(Vector2 other)
{
	return Vector2(X - other.X, Y - other.Y);
}
