#include "my_snake.h"

void Fruit::ini_fruitr()
{
    this->eated = true;
    this->fruit = 0;
    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 20; j++)
        {
            this->fruitmap[i][j] = 0;
        }
    }
}

void Fruit::randomFruit()
{
    std::mt19937 gen(this->rd());
    std::uniform_int_distribution<> distribl(1, 8);
    std::uniform_int_distribution<> distribc(1, 19);
    int line = distribl(gen);
    int column = distribc(gen);
    this->setFruitPos(line, column);
}

void Fruit::setFruitPos(int line, int column)
{
    this->pos.x = line;
    this->pos.y = column;
}

void Fruit::setFruit(int line, int column, int val)
{
    this->fruitmap[line][column] = val;
}

bool Fruit::haveEaten()
{
    return this->eated;
}

void Fruit::setEated(bool eated)
{
    this->eated = eated;
}

pos Fruit::getFruitPos()
{
    return this->pos;
}

int Fruit::getFruit(int line, int column)
{
    return this->fruitmap[line][column];
}