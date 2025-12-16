#include "my_snake.h"

int main(int argc, char const *argv[])
{

    init();
    while(1)
    {
        controller();
        refresh();
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }   

    return 0;
}
