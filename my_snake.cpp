#include "my_snake.h"

Snake *snake = NULL;
Scene *scene = NULL;
Fruit *fruitr = NULL;
Game * game = NULL;
bool running_;

void init()
{
    running_ = true;
    snake = new Snake;
    scene = new Scene;
    fruitr = new Fruit;
    game = new Game(snake, scene, fruitr);
    game->getScene()->ini_scene();
    game->getSnake()->ini_snake();
    game->getFruitr()->ini_fruitr();
}

void update()
{
    game->snakeFruitCo();
    game->getSnake()->movSnake();
    outOfBounds();
    spawnFruit();
}

void refresh()
{
    size_t i = 0, j = 0;
    gotoxy(0,0);
    for (NULL; i < 9; i++)
    {
        for (j = 0; j < 20; j++)
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
    std::cout.flush();
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

void gotoxy(short x, short y)
{
    static HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos{x, y};
    SetConsoleCursorPosition(hOut, pos);
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
    running_ = false;
}

void outOfBounds()
{
    if((game->getSnake()->getHeadLine() < 0) || (game->getSnake()->getHeadLine() >= 9)) endgame();
    if((game->getSnake()->getHeadColumn() < 0) || (game->getSnake()->getHeadColumn() >= 20)) endgame();
}

bool running()
{
    return running_;
}

Game * getMainGame()
{
    return game;
}


