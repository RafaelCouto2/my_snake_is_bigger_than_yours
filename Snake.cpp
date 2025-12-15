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
    
    this->snake_body = '*';
    this->direction = 0;
    this->snake_lengh = 3;
    this->snakemap[4][7] = 1;
    this->snakemap[5][7] = 2;
    this->snakemap[6][7] = 3;
    this->head_line = 4;
    this->head_column = 7;
    this->tail_line = 6;
    this->tail_column = 7;
}

int Snake::getSnakePos(int line, int column)
{
    return this->snakemap[line][column];
}

void Snake::movSnake()
{
    int new_line = this->head_line;
    int new_column = this->head_column;

    switch (this->direction)
    {
        case 0: new_line--; break;
        case 1: new_line++; break;
        case 2: new_column--; break;
        case 3: new_column++; break;
        default: break;
    }
    
    this->ageSnake();
    this->setHeadPos(new_line, new_column);
    this->snakemap[this->head_line][this->head_column] = 1;
    this->trimTail();
}

void Snake::growUp()
{
    this->snake_lengh++;
    switch(this->direction)
    {
    case 0:
    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 20; j++)
        {
            if(this->snakemap[i][j] == this->snake_lengh - 1)
            {
                this->snakemap[i + 1][j] = this->snake_lengh;
            }
        }
    }
    break;
    case 1:
    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 20; j++)
        {
            if(this->snakemap[i][j] == this->snake_lengh - 1)
            {
                this->snakemap[i - 1][j] = this->snake_lengh;
            }
        }
    }
    break;
    }
}

int Snake::getTailLine()
{
    return this->tail_line;
}
int Snake::getTailColumn()
{
    return this->tail_column;
}

int Snake::getHeadLine()
{
    return this->head_line;
}

int Snake::getHeadColumn()
{
    return this->head_column;
}

int Snake::getDirection()
{
    return this->direction;
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
            if(this->snakemap[i][j] > 0) 
            {
                this->snakemap[i][j]++;
            }
        }
    }
}
void Snake::trimTail()
{
    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 20; j++)
        {
            if(this->snakemap[i][j] > this->snake_lengh) 
            {
                this->snakemap[i][j] = 0;
            }
        }
    }
}

void Snake::controller()
{

    char c = 0;
    if(_kbhit()) c = _getch();
    switch(c)
    {
        case 72: this->direction = 0; break;
        case 80: this->direction = 1; break;
        case 75: this->direction = 2; break;
        case 77: this->direction = 3; break;
        default: break;
    }
    std::fflush(stdin);
}