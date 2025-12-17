#pragma once
#ifndef UNICODE
#define UNICODE
#endif

#include <thread>
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <random>
#include <memory>

typedef struct pos{int x, y;} pos;

class Snake
{
    private:
        char snake_body;
        int direction;
        int snake_lengh;
        int snakemap[9][20];
        int head_line, head_column;
    public:
        char getSnakeBody();
        void ini_snake();
        void ageSnake();
        void trimTail();
        void growUp();
        void controller();
        void movSnake();
        int getSnakeAt(int line, int column);
        int getHeadLine();
        int getHeadColumn();
        int getDirection();
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
        std::unique_ptr<Snake> snake;
        std::unique_ptr<Scene> mainscene;
        std::unique_ptr<Fruit> fruitrand;
        static bool running_;
    public:
        Snake * getSnake();
        Scene * getScene();
        Fruit * getFruitr();
        void snakeFruitCo();
        void outOfBounds();
        void init();
        void refresh();
        void update();
        void gotoxy(short x, short y);
        void spawnFruit();
        void endgame();
        void controller();
        void setRunning(bool);
        bool isRunning();
        Game(); 
};
