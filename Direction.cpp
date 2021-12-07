#pragma once
#include <iostream>
#include <string>

class Direction
{
public:
    Direction(int x, int y) : _x(x), _y(y)
    {
        is_empty = false;
    }

    bool isNull() const
    {
        return this->is_empty;
    }

    std::string toString() const
    {
        return std::string(_x + ", " + _y);
    }

    int getX() const
    {
        return this->_x;
    }

    int getY() const
    {
        return this->_y;
    }

private:
    int _x = 0;
    int _y = 0;
    bool is_empty = true;
};
