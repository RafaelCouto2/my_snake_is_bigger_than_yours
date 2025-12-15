#include "my_snake.h"

void Scene::ini_scene()
{
    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 20; j++)
        {
            this->scenario[i][j] = '\'';
        }
    }
}

char Scene::getScenario(int line, int column)
{
    return this->scenario[line][column];
}