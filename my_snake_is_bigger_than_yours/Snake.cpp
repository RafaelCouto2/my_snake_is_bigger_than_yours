#include "my_snake.h"

char Snake::getSnakeBody()
{
    return (this->snake_body);
}

void Snake::ini_snake()
{
    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 20; j++)
        {
            this->snakemap[i][j] = 0;
        }
    }
    this->snake_body = 254;
    this->head_line = 5;
    this->head_column = 8;
    this->snake_lengh = 3;
    this->snakemap[5][8] = 1;
    this->snakemap[6][8] = 2;
    this->snakemap[7][8] = 3;
}

int Snake::getSnakeAt(int line, int column)
{
    return this->snakemap[line][column];
}

bool Snake::move(int dir)
{
    int new_line = this->head_line;
    int new_column = this->head_column;

    switch (dir)
    {
        case 0: new_line--; break;
        case 1: new_line++; break;
        case 2: new_column--; break;
        case 3: new_column++; break;
        default: break;
    }
    
    if(this->willCollide(new_line, new_column)) return false;

    this->ageSnake();
    this->setHeadPos(new_line, new_column);
    this->snakemap[this->head_line][this->head_column] = 1;
    this->trimTail();
    return true;
}

void Snake::growUp()
{
    this->snake_lengh++;
}

int Snake::getHeadLine()
{
    return this->head_line;
}

int Snake::getHeadColumn()
{
    return this->head_column;
}

void Snake::setHeadPos(int line, int column)
{
    this->head_line = line;
    this->head_column = column;
}

void Snake::ageSnake()
{
    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 20; j++)
        {
            this->snakemap[i][j] > 0? this->snakemap[i][j]++ : NULL;
        }
    }
}

void Snake::trimTail()
{
    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 20; j++)
        {
            this->snakemap[i][j] > this->snake_lengh? this->snakemap[i][j] = 0 : NULL;
        }
    }
}

bool Snake::willCollide(int nextline, int nextcolumn) const
{
    return this->snakemap[nextline][nextcolumn] > 0;
}