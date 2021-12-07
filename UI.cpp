#include "Dungeon.cpp"
#include "Option.cpp"
#include <iostream>
#include <map>

class UI
{
public:
    UI(Dungeon dg) : dungeon(dg)
    {
    }

    void run()
    {
        std::map<char, Option> optionMap =
            {
                {'q', QUIT},
                {'r', RESET},
                {'a', LEFT},
                {'d', RIGHT},
                {'w', UP},
                {'s', DOWN},
            };

        std::cout << "q to " << optionMap.at('q').getDescription() << std::endl;
        std::cout << "r to " << optionMap.at('r').getDescription() << std::endl;
        std::cout << "a to " << optionMap.at('a').getDescription() << std::endl;
        std::cout << "d to " << optionMap.at('d').getDescription() << std::endl;
        std::cout << "w to " << optionMap.at('w').getDescription() << std::endl;
        std::cout << "s to " << optionMap.at('s').getDescription() << std::endl;

        char buffer;
        std::cout << "Press any key to continue...";
        std::cin >> buffer;

        dungeon.refreshMap();
        dungeon.printStatus();
        dungeon.drawMap();
        std::cout << "> ";

        while (true)
        {
            std::cout << "podaj znak\n";
            std::cin >> buffer;
            auto search = optionMap.find(buffer);
            if (search == optionMap.end())
            {
                std::cout << "Option not recognized\n";
                continue;
            }

            switch (search->second.getCharacter())
            {
            case 'q':
                dungeon.end();
                break;
            case 'r':
                dungeon.reload();
                break;
            case 'a':
                dungeon.movePlayer(LEFT.getDirection());
                break;
            case 'd':
                dungeon.movePlayer(RIGHT.getDirection());
                break;
            case 's':
                dungeon.movePlayer(DOWN.getDirection());
                break;
            case 'w':
                dungeon.movePlayer(UP.getDirection());
                break;
            }

            dungeon.refreshMap();
            dungeon.printStatus();
            dungeon.drawMap();
            std::cout << "> ";

            if (dungeon.isItWin())
            {
                std::cout << "You win!";
                break;
            }

            if (dungeon.getMoves() == 0)
            {
                std::cout << "You lost!";
                break;
            }
        }
    }

    Option QUIT = Option('q', "Exit the game", Direction(0, 0));
    Option RESET = Option('r', "Reset the game", Direction(0, 0));
    Option LEFT = Option('a', "move left", Direction(-1, 0));
    Option RIGHT = Option('d', "move right", Direction(1, 0));
    Option UP = Option('w', "move up", Direction(0, -1));
    Option DOWN = Option('s', "move down", Direction(0, 1));

private:
    Dungeon dungeon;
};
