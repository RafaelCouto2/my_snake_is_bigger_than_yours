#pragma once
#ifndef UNICODE
#define UNICODE
#endif

#include <thread>
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <random>

typedef struct pos{int x, y;} pos;

extern bool running_;

class Snake
{
    private:
        char snake_body;
        int direction;
        int snake_lengh;
        int snakemap[9][20];
        int head_line, head_column, tail_line, tail_column;
    public:
        char getSnakeBody();
        bool isColliding();
        void ini_snake();
        void ageSnake();
        void trimTail();
        void growUp();
        void controller();
        void movSnake();
        int getSnakePos(int line, int column);
        int getHeadLine();
        int getHeadColumn();
        int getDirection();
        int getTailLine();
        int getTailColumn();
        void setHeadPos(int line, int column);
};


class Scene
{
    private:
        char scenario[9][20];
    public:
        void ini_scene();
        char getScenario(int line, int column);
};

class Fruit
{
    private:
        std::random_device rd;
        int fruitmap[9][20];
        char fruit;
        bool eaten;
        pos pos;
    public:
        void randomFruit();
        void setFruitPos(int line, int column);
        void ini_fruitr();
        struct pos getFruitPos();
        void setFruit(int line, int column, int val);
        bool isEaten();
        void setEaten(bool eated);
        int getFruit(int line, int column);
};

class Game
{
    private:
        Snake * snake;
        Scene * mainscene;
        Fruit * fruitrand;
    public:
        Snake * getSnake();
        Scene * getScene();
        Fruit * getFruitr();
        void setSnake(Snake *snake);
        void setMainScene(Scene *scene);
        void setFruitRandomizer(Fruit *fruitr);
        void snakeFruitCo();
        void outOfBounds();
        Game(Snake *snake, Scene *scene, Fruit * fruitr);
};


void init();
void refresh();
void update();
bool running();
void outOfBounds();
void gotoxy(short x, short y);
void spawnFruit();
void endgame();
void controller();
void solid_snake();
void liquid_snale();
Game * getMainGame();
