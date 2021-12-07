#pragma once
#include "Vampire.cpp"
#include "Direction.cpp"
#include <iostream>
#include <vector>
#include <time.h>
class Dungeon
{
public:
    Dungeon(int X, int Y, int numberOfVampires, int move) : maxX(X), maxY(Y), moves(move)
    {
        this->addVampires(numberOfVampires);
        map = new char *[maxY];

        initialVampires = numberOfVampires;
        initialMoves = move;

        for (int i = 0; i < maxY; i++)
        {
            map[i] = new char[maxX];
        }
    }

    void free()
    {
        for (int i = 0; i < maxY; i++)
        {
            delete[] map[maxX];
        }
        delete[] map;
    }

    void reload()
    {
        vampires.clear();
        this->addVampires(initialVampires);
        moves = initialMoves;
        refreshMap();
        std::cout << "reloading\n";
    }

    int getMoves() const
    {
        return this->moves;
    }

    void printStatus() const
    {
        std::cout << "Current coordinates:(" << playerX << ", " << playerY << ")\n";
        if (!vampires.empty())
        {
            for (auto &n : vampires)
            {
                n.print();
            }
            std::cout << "Moves left: " << moves << std::endl;
        }
    }

    void refreshMap()
    {
        moveVampires();
        checkStatus();

        for (int i = 0; i < maxY; i++)
        {
            for (int j = 0; j < maxX; j++)
            {
                map[i][j] = '.';
            }

            map[i][maxY] = '\n';
        }

        map[playerY][playerX] = '@';

        for (auto &n : vampires)
        {
            map[n.getY()][n.getX()] = 'V';
        }
    }
    Dungeon &operator=(const Dungeon &obj)
    {
        moves = obj.moves;
        initialVampires = obj.initialVampires;
        initialMoves = obj.initialMoves;
        vampires = obj.vampires;
        playerX = obj.playerX;
        playerY = obj.playerY;
        maxX = obj.maxX;
        maxY = obj.maxY;

        map = new char *[maxY];
        for (int i = 0; i < maxY; i++)
        {
            map[i] = new char[maxX];
        }
    }

    void movePlayer(Direction direction)
    {
        if (moves-- > 0)
        {
            if (playerX + direction.getX() >= 0 && playerX + direction.getX() < maxX)
                playerX += direction.getX();
            if (playerY + direction.getY() >= 0 && playerY + direction.getY() < maxY)
                playerY += direction.getY();
        }
    }

    void end()
    {
        free();
        moves = 0;
    }

    void drawMap()
    {
        for (int i = 0; i < maxY; i++)
        {
            for (int j = 0; j <= maxX; j++)
            {
                std::cout << map[i][j];
            }
        }
    }

    inline bool isItWin() const
    {
        return vampires.empty() && vampires.size() == 0;
    }

    auto getVampiresCount() const
    {
        return vampires.size();
    }

    int getPlayerX() const
    {
        return playerX;
    }

    int getPlayerY() const
    {
        return playerY;
    }

    void setPosition(int x, int y)
    {
        if (x >= 0 && x < maxX)
            playerX = x;
        if (y >= 0 && y < maxY)
            playerY = y;
    }

private:
    void moveVampires()
    {
        for (auto &n : vampires)
        {
            if (0 + (rand() % (1 - 0 + 1)) == 1)
            {
                if (0 + (rand() % (1 - 0 + 1)) == 1)
                {
                    if (0 + (rand() % (1 - 0 + 1)) == 1)
                        n.move(Direction(1, 0), maxX, maxY);
                    else
                        n.move(Direction(-1, 0), maxX, maxY);
                }
                else
                {
                    if (0 + (rand() % (1 - 0 + 1)) == 1)
                        n.move(Direction(0, 1), maxX, maxY);
                    else
                        n.move(Direction(0, -1), maxX, maxY);
                }
            }
        }
    }

    void checkStatus()
    {
        for (int i = 0; i < vampires.size(); i++)
        {
            if ((playerX == vampires[i].getX() && playerY == vampires[i].getY()))
            {
                deleteVampire(i);
            }
        }
    }

    void deleteVampire(int i)
    {
        vampires.erase(vampires.begin() + i);
    }

    void addVampires(int nmbr)
    {
        for (int i = 0; i < nmbr; i++)
        {
            vampires.push_back(Vampire(maxX, maxY));
        }
    }

private:
    int moves;
    int initialVampires = 0;
    int initialMoves = 0;
    std::vector<Vampire> vampires;
    int playerX = 0;
    int playerY = 0;
    int maxX;
    int maxY;
    char **map;
};
