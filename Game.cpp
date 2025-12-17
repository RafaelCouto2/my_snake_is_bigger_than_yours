#include "my_snake.h"

bool Game::running_ = true;

Game::Game() 
    : snake(std::make_unique<Snake>()), 
    mainscene(std::make_unique<Scene>()),
    fruitrand(std::make_unique<Fruit>())
{}

Snake * Game::getSnake()
{
    return this->snake.get();
}

Scene * Game::getScene()
{
    return this->mainscene.get();
}

Fruit * Game::getFruitr()
{
    return this->fruitrand.get();
}

void Game::snakeFruitCo()
{
    int dir = this->getSnake()->getDirection();
    int head_line = this->getSnake()->getHeadLine();
    int head_column = this->getSnake()->getHeadColumn();
    int fruit_line = this->getFruitr()->getFruitPos().x;
    int fruit_column = this->getFruitr()->getFruitPos().y;

    if((head_line == fruit_line) && (head_column == fruit_column))
    {
        this->getSnake()->growUp();
        this->getFruitr()->setFruit(fruit_line, fruit_column, 0);
        this->getFruitr()->setEaten(true);
    }
}


void Game::init()
{
    this->setRunning(true);
    this->getScene()->ini_scene();
    this->getSnake()->ini_snake();
    this->getFruitr()->ini_fruitr();
}   
void Game::refresh()
{
    size_t i = 0, j = 0;
    this->gotoxy(0,0);
    for (NULL; i < 9; i++)
    {
        for (j = 0; j < 20; j++)
        {
            if(this->getFruitr()->getFruit(i, j) > 0)
            {
                std::cout << '+';
                continue;
            }
            if(this->getSnake()->getSnakeAt(i, j) > 0)
            {
                std::cout << this->getSnake()->getSnakeBody();
                continue;
            }
            std::cout << this->getScene()->getScenario(i, j);
        }
        std::cout << std::endl;
    }
    std::cout.flush();
}
void Game::update()
{
    this->getSnake()->movSnake();
    this->outOfBounds();
    this->snakeFruitCo();
    this->spawnFruit();
}

void Game::outOfBounds()
{
    if((this->getSnake()->getHeadLine() < 0) || (this->getSnake()->getHeadLine() >= 9)) endgame();
    if((this->getSnake()->getHeadColumn() < 0) || (this->getSnake()->getHeadColumn() >= 20)) endgame();
}
void Game::gotoxy(short x, short y)
{
    static HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos{x, y};
    SetConsoleCursorPosition(hOut, pos);
}
void Game::spawnFruit()
{
    if(!(this->getFruitr()->isEaten())) return;
    int x,y;
    do
    {
        this->getFruitr()->randomFruit();
        x = this->getFruitr()->getFruitPos().x;
        y = this->getFruitr()->getFruitPos().y;
    }
    while (this->getSnake()->getSnakeAt(x, y) > 0);
    this->getFruitr()->setFruit(x, y, 1);
    this->getFruitr()->setEaten(false);
}
void Game::endgame()
{
    this->setRunning(false);
}
void Game::controller()
{
    this->getSnake()->controller();
}

void Game::setRunning(bool r)
{
    Game::running_ = r;
}
bool Game::isRunning()
{
    return Game::running_;
}