#include "my_snake.h"

void Controller::changeDirection()
{
    char c = 0;
    int newDir = this->direction;
    if(_kbhit()) c = _getch();
    switch(c)
    {
        case 72: newDir = 0; break;
        case 80: newDir = 1; break;
        case 75: newDir = 2; break;
        case 77: newDir = 3; break;
        default: break;
    }

    if ((this->direction == 0 && newDir == 1) ||
        (this->direction == 1 && newDir == 0) ||
        (this->direction == 2 && newDir == 3) ||
        (this->direction == 3 && newDir == 2))
        return;

    this->direction = newDir;
}

int Controller::getDirection() {return this->direction;};