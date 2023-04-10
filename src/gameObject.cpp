#include "gameObject.h"

GameObject::GameObject(int width, int height, int maxWidth, int maxHeigth, Color color): c(color)
{
    maxW=maxWidth; maxH=maxHeigth;
    w=width; rect.w=w; h=height; rect.h=h;
    rect.x=maxWidth/2-width; rect.y=maxHeigth/2-height;//set default to middle of screen
    speed=height/8; dirW=0; dirH=0;
    score=0;
}

void GameObject::SetPos(int posx, int posy)
{
    if(posx<0) posx=0; else if(posx+w>maxW) posx=maxW-w;
    if(posy<0) posy=0; else if(posy+h>maxH) posy=maxH-h;
    rect.x=posx; rect.y=posy;
}

SDL_Rect* GameObject::GetRect(){ return &rect; }

void GameObject::SetDir(int wDir, int hDir){ dirW=wDir; dirH=hDir; }

void GameObject::Update() { SetPos(rect.x + speed * dirW, rect.y + speed * dirH); }

void GameObject::SetScore(int val) { score=val; }

int GameObject::GetScore() { return score; }

void GameObject::buttonPressed(Key k)
{
	if((k==SDL_SCANCODE_W)||(k==SDL_SCANCODE_UP)) SetDir(0,-1);
	if((k==SDL_SCANCODE_S)||(k==SDL_SCANCODE_DOWN)) SetDir(0,1);
}

void GameObject::buttonReleased(Key k)
{
    switch (k){
        case SDL_SCANCODE_W:
        case SDL_SCANCODE_UP:
        case SDL_SCANCODE_S:
        case SDL_SCANCODE_DOWN:
            SetDir(0,0); break;
    }
}
//end gameObject.cpp