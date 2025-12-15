#include "my_snake.h"

Game::Game(Snake * snake, Scene * scene, Fruit * fruitr)
{
    this->setSnake(snake);
    this->setMainScene(scene);
    this->setFruitRandomizer(fruitr);
}

void Game::setSnake(Snake * snake)
{
    this->snake = snake;
}

void Game::setMainScene(Scene * scene)
{
    this->mainscene = scene;
}

Snake * Game::getSnake()
{
    return this->snake;
}

Scene * Game::getScene()
{
    return this->mainscene;
}

Fruit * Game::getFruitr()
{
    return this->fruitrand;
}

void Game::setFruitRandomizer(Fruit *fruitr)
{
    this->fruitrand = fruitr;
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