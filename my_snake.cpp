#include "my_snake.h"

Snake *snake;
Scene *scene;
Fruit *fruitr;
Game * game;

void init()
{
    snake = new Snake;
    scene = new Scene;
    fruitr = new Fruit;
    game = new Game(snake, scene, fruitr);
    game->getScene()->ini_scene();
    game->getSnake()->ini_snake();
    game->getFruitr()->ini_fruitr();
}

void refresh()
{
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
    
    game->snakeFruitCo();
    game->getSnake()->movSnake();
    spawnFruit();
    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 20; j++)
        {
            if(game->getFruitr()->getFruit(i, j) > 0)
            {
                std::cout << '+';
                continue;
            }
            if(game->getSnake()->getSnakePos(i, j) > 0)
            {
                std::cout << game->getSnake()->getSnakeBody();
                continue;
            }
            std::cout << game->getScene()->getScenario(i, j);
        }
        std::cout << std::endl;
    }
}

void spawnFruit()
{
    if(!(game->getFruitr()->isEaten())) return;
    int x,y;
    do
    {
        game->getFruitr()->randomFruit();
        x = game->getFruitr()->getFruitPos().x;
        y = game->getFruitr()->getFruitPos().y;
    }
    while (game->getSnake()->getSnakePos(x, y) > 0);
    game->getFruitr()->setFruit(x, y, 1);
    game->getFruitr()->setEaten(false);
}

void solid_snake()
{
    game->getSnake()->ageSnake();
}

void liquid_snake()
{
    game->getSnake()->trimTail();
}

void controller()
{
    game->getSnake()->controller();
}

void endgame()
{
    delete snake, scene, fruitr, game;
}

Game * getMainGame()
{
    return game;
}


