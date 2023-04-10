#include "game.h"

int main(int argc, char* argv[])
{
    Game pong;
    if(pong.Init(800,640)){
        pong.GameLoop();
    }
    pong.Shutdown();

    return 0;
}