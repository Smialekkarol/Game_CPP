#pragma once
#include <iostream>
#include "Direction.cpp"
#include <time.h>

class Vampire
{
public:
    Vampire(const int maxX, const int maxY)
    {
        randomize(maxX, maxY);
    }

    void move(Direction direction, int maxX, int maxY)
    {

        if (_x + direction.getX() >= 0 && _x + direction.getX() < maxX)
            _x += direction.getX();
        if (_y + direction.getY() >= 0 && _y + direction.getY() < maxY)
            _y += direction.getY();
    }

    void randomize(int maxX, int maxY)
    {
        _x = rand() % maxX;
        _y = rand() % maxY;
    }

    int getX()
    {
        return _x;
    }

    int getY()
    {
        return _y;
    }

    void print() const
    {
        std::cout << "v " << _x << ", " << _y << std::endl;
    }

private:
    int _x;
    int _y;
};