#include <iostream>
using namespace std;
#include "Game.h"

// text rpg 객체버전. 총정리
int main()
{
    srand(time(nullptr));
    Game game;
    game.Init();

    while (true)
    {
        game.Update();
    }
}
