#include "my_snake.h"

int main(int argc, char const *argv[])
{

    init();
    while(running())
    {
        controller();
        update();
        refresh();
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }   

    std::system("pause");
    return 0;
}
