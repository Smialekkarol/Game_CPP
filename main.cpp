#include <iostream>
#include "Dungeon.cpp"
#include "UI.cpp"

int main()
{
    UI ui = UI(Dungeon(10, 10, 4, 100));
    ui.run();
    return 0;
}