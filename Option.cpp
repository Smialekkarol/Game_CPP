#pragma once
#include <iostream>
#include "Direction.cpp"

class Option
{
public:
    Option(char ch, std::string desc, Direction dire) : character(ch), description(desc), direction(dire) {}

    char getCharacter()
    {
        return this->character;
    }

    Direction getDirection()
    {
        return this->direction;
    }

    friend std::ostream &operator<<(std::ostream &stream, const Option &obj)
    {
        stream << obj.description << (obj.direction.isNull() ? "vector(" + obj.direction.toString() : "");
    }

    std::string getDescription()
    {
        return description;
    }

private:
    char character;
    std::string description;
    Direction direction;
};
