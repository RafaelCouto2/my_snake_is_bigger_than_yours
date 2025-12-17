#include "my_snake.h"

void Scene::ini_scene()
{
    this->scenario[0][0] = 201;
    this->scenario[0][20] = 187;
    this->scenario[9][0] = 200;
    this->scenario[9][20] = 188;
    
    for (size_t i = 1; i < 9; i++)
    {
        this->scenario[i][0] = 186;
        this->scenario[i][20] = 186;
    }
    
    for (size_t j = 1; j < 20; j++)
    {
            this->scenario[0][j] = 205;
            this->scenario[9][j] = 205; 
    }
    
    for (size_t i = 1; i < 9; i++)
    {
        for (size_t j = 1; j < 20; j++)
        {
            this->scenario[i][j] = '\'';
        }
    }
}

char Scene::getScenario(int line, int column)
{
    return this->scenario[line][column];
}