#include "my_snake.h"

int main(int argc, char const *argv[])
{
    Game game;
    game.init();
    while(game.isRunning())
    {
        game.controller();
        game.update();
        game.refresh();
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }   
    
    std::system("pause");
    return 0;
}
