#include "my_snake.h"

bool Game::running_ = true;
bool Game::alive = true;
short Game::X = 0;
short Game::Y = 0;
HANDLE Game::hOut;

Game::Game()
    : snake(std::make_unique<Snake>()), 
    mainscene(std::make_unique<Scene>()),
    fruitrand(std::make_unique<Fruit>()),
    input(std::make_unique<Controller>())
{}

void Game::init()
{
    this->setRunning(true);
    this->getScene()->ini_scene();
    this->getSnake()->ini_snake();
    this->getFruitr()->ini_fruitr();
    Game::hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(Game::hOut, &this->hIn);
    Game::X = (this->hIn.dwSize.X / 2.5);
    Game::Y = (this->hIn.dwSize.Y / 3);
    this->score = 0;
}   
void Game::refresh()
{
    short new_Y = Game::Y;
    for (size_t i = 0; i < 10; i++)
    {
        this->gotoxy(Game::X, new_Y++);
        for (size_t j = 0; j < 21; j++)
        {
            if(i > 0 && i < 9 && j > 0 && j < 20)
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
            }
            std::cout << this->getScene()->getScenario(i, j);
        }
        std::cout << '\n';
    }
    this->gotoxy(Game::X, new_Y++);
    std::cout << "Score: " << this->score << '\n';
    std::cout.flush();
}

void Game::update()
{
    Game::alive = this->getSnake()->move(this->getInput()->getDirection());
    if(!alive) {this->endgame(); return;}
    this->outOfBounds();
    this->snakeFruitCo();
    this->spawnFruit();
}

void Game::spawnFruit()
{
    if(!(this->getFruitr()->haveEaten())) return;
    int x,y;
    do
    {
        this->getFruitr()->randomFruit();
        x = this->getFruitr()->getFruitPos().x;
        y = this->getFruitr()->getFruitPos().y;
    }
    while (this->getSnake()->getSnakeAt(x, y) > 0);
    this->getFruitr()->setFruit(x, y, 1);
    this->getFruitr()->setEated(false);
}

void Game::snakeFruitCo()
{
    int head_line = this->getSnake()->getHeadLine();
    int head_column = this->getSnake()->getHeadColumn();
    int fruit_line = this->getFruitr()->getFruitPos().x;
    int fruit_column = this->getFruitr()->getFruitPos().y;

    if((head_line == fruit_line) && (head_column == fruit_column))
    {
        this->score++;
        this->getSnake()->growUp();
        this->getFruitr()->setFruit(fruit_line, fruit_column, 0);
        this->getFruitr()->setEated(true);
    }
}

void Game::outOfBounds()
{
    if((this->getSnake()->getHeadLine() < 1) || (this->getSnake()->getHeadLine() >= 9)) this->endgame();
    if((this->getSnake()->getHeadColumn() < 1) || (this->getSnake()->getHeadColumn() >= 20)) this->endgame();
}

void Game::gotoxy(short x, short y)
{
    COORD pos{x, y};
    SetConsoleCursorPosition(Game::hOut, pos);
}

void Game::endgame()
{
    this->setRunning(false);
}
void Game::controller()
{
    this->getInput()->changeDirection();
}

void Game::setRunning(bool r)
{
    Game::running_ = r;
}

bool Game::isRunning()
{
    return Game::running_;
}

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

Controller * Game::getInput() 
{
    return this->input.get();
}