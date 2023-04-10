#include "ball.h"

Ball::Ball(int width, int height, int maxWidth, int maxHeigth, Color color): 
    GameObject(width, height, maxWidth, maxHeigth, color)
{
    speed=height/4;
};

int Ball::GetDirW(){ return dirW; }

int Ball::GetDirH(){ return dirH; }

void Ball::ResetPos(){ SetPos(maxW/2-w, maxH/2-h); dirH*=-1; dirW*=-1; }
//end ball.cpp