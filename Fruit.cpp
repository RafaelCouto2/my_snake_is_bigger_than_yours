#include "my_snake.h"

void Fruit::ini_fruitr()
{
    this->eaten = true;
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
    std::uniform_int_distribution<> distribc(0, 20);
    std::uniform_int_distribution<> distribl(0, 9);
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

bool Fruit::isEaten()
{
    return this->eaten;
}

void Fruit::setEaten(bool eated)
{
    this->eaten = eated;
}

pos Fruit::getFruitPos()
{
    return this->pos;
}

int Fruit::getFruit(int line, int column)
{
    return this->fruitmap[line][column];
}