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
        int  direction;
        int  snake_lengh;
        int  snakemap[9][20];
        int  head_line, head_column;
    public:
        char getSnakeBody();
        void ini_snake();
        void ageSnake();
        void trimTail();
        void growUp();
        bool move(int);
        int  getSnakeAt(int line, int column);
        int  getHeadLine();
        int  getHeadColumn();
        void setHeadPos(int line, int column);
        bool willCollide(int nextline, int nextcolumn) const;
};


class Scene
{
    private:
        char scenario[10][21];
    public:
        void ini_scene();
        char getScenario(int line, int column);
};

class Fruit
{
    private:
        std::random_device rd;
        pos  pos;
        int  fruitmap[9][20];
        char fruit;
        bool eated;
    public:
        void ini_fruitr();
        void randomFruit();
        void setFruitPos(int line, int column);
        void setFruit(int line, int column, int val);
        void setEated(bool eated);
        int  getFruit(int line, int column);
        struct pos getFruitPos();
        bool haveEaten();
};

class Controller
{
    private:
        int  direction = 0;
    public:
        void changeDirection();
        int  getDirection();
};

class Game
{
    private:
        CONSOLE_SCREEN_BUFFER_INFO  hIn;
        std::unique_ptr<Snake>      snake;
        std::unique_ptr<Scene>      mainscene;
        std::unique_ptr<Fruit>      fruitrand;
        std::unique_ptr<Controller> input;
        static bool   running_;
        static bool alive;
        static short  X;
        static short  Y;
        static HANDLE hOut;
        int           score;
        void   gotoxy(short x, short y);
    public:
        Controller* getInput();
        Snake*  getSnake();
        Scene*  getScene();
        Fruit*  getFruitr();
        void    snakeFruitCo();
        void    outOfBounds();
        void    init();
        void    refresh();
        void    update();
        void    spawnFruit();
        void    endgame();
        void    controller();
        void    playAudio();
        void    setRunning(bool);
        bool    isRunning();
        Game();
};
