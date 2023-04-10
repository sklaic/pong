#include "game.h"

bool Game::Init(const int width, const int height)
{
    winWidth=width; winHeight=height;
    leftPaddle = new GameObject(width/100,height/10,width,height,{255,255,255});
    leftPaddle->SetPos(width/100,height/2-height/10);
    keyboardInput.addListener(leftPaddle);
    rightPaddle = new GameObject(width/100,height/10,width,height,{255,255,255});
    rightPaddle->SetPos(width-width/50,height/2-height/10);
    ball = new Ball(width/100,height/50,width,height,{255,255,255});
    disp = new Display(width,height);
    if (disp && !disp->isInitError()) return true;
    else return false;
}

void Game::GameLoop()
{
    while (isRunning) {
		HandleEvents();
		Update();
		Draw();
	}
}

void Game::Shutdown()
{
    delete leftPaddle, rightPaddle, disp;
}

void Game::SetGamestatePending(){

}

void Game::HandleEvents()
{
    SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			isRunning = false;
		}
        if(event.key.type == SDL_KEYDOWN){
            keyboardInput.pressed(event.key.keysym.scancode);
        }
        if(event.key.type == SDL_KEYUP){
            keyboardInput.released(event.key.keysym.scancode);
        }
	}
	const Uint8* keystates = SDL_GetKeyboardState(NULL);
	if (keystates[SDL_SCANCODE_ESCAPE]) {
		isRunning = false;
	}
	if (gamestate != GameState::Running) {
		if (keystates[SDL_SCANCODE_SPACE]) {
            if(gamestate == GameState::Finish){
                gamestate=GameState::Pending;//reset state
                leftPaddle->SetScore(0); rightPaddle->SetScore(0);
            }else{//start the game
			    gamestate = GameState::Running;
                ball->SetDir(1,1);
            }
		}
		return;
	}
	// Right Paddle movement - computer player logic
	rightPaddle->SetDir(0,0);
    if(ball->GetDirW()==1){//ball is heading this way, adjust position
        if(ball->GetRect()->y<(rightPaddle->GetRect()->y+rightPaddle->GetRect()->h/2))
            rightPaddle->SetDir(0,-1);//move up
        else rightPaddle->SetDir(0, 1);//move down
    }
}

void Game::Update()
{
    if(gamestate != GameState::Running) return;
	leftPaddle->Update();
	rightPaddle->Update();
  	ball->Update();
    //check position for bouncing the ball/scoring
    if(ball->GetDirW()==1){//going to the right
        if(ball->GetRect()->x+ball->GetRect()->w >= rightPaddle->GetRect()->x-12)
        {//check collision
            if(ball->GetRect()->x >= rightPaddle->GetRect()->x){
                leftPaddle->SetScore(leftPaddle->GetScore()+1);//player scored
                ball->ResetPos();
            }else if(SDL_HasIntersection(ball->GetRect(),rightPaddle->GetRect()))
                ball->SetDir(ball->GetDirW()*-1,ball->GetDirH());//bounce
        }
    }else if(ball->GetDirW()==-1){//going to the left
        if(ball->GetRect()->x <= (leftPaddle->GetRect()->x+leftPaddle->GetRect()->w+12))
        {//check collision
            if(ball->GetRect()->x <= leftPaddle->GetRect()->x){
                rightPaddle->SetScore(rightPaddle->GetScore()+1);//computer scored
                ball->ResetPos();
            }else if(SDL_HasIntersection(ball->GetRect(), leftPaddle->GetRect()))
                ball->SetDir(ball->GetDirW()*-1,ball->GetDirH());//bounce
        }
    }
    //check ball bounce for top/bottom
    if((ball->GetRect()->y >= (winHeight-ball->GetRect()->h)) ||
        (ball->GetRect()->y <= ball->GetRect()->h))
            ball->SetDir(ball->GetDirW(),ball->GetDirH()*-1);//bounce
	ball->Update();
    //check score for finish
    if((leftPaddle->GetScore()>=3) || (rightPaddle->GetScore()>=3)) gamestate=GameState::Finish;
}

void Game::Draw()
{
    disp->clearBuffer({0,0,0});
    disp->drawText(std::to_string(leftPaddle->GetScore()), winWidth/4, 30, {255,255,255});
    disp->drawText(std::to_string(rightPaddle->GetScore()), winWidth/4*3, 30, {255,255,255});
    switch (gamestate){
        case GameState::Pending:
            disp->drawText("Press space to play!", winWidth/2, winHeight, {128,255,128});
            break;
        case GameState::Finish:
            if(leftPaddle->GetScore()>=3)
                disp->drawText("You win!", winWidth/2, winHeight/2, {128,255,128});
            else disp->drawText("You lose!", winWidth/2, winHeight/2, {255,0,0});
            disp->drawText("Press space to restart.", winWidth/2, winHeight, {128,255,128});
            break;
    }
    disp->drawRect(leftPaddle->GetRect(),{255,255,255});
    disp->drawRect(rightPaddle->GetRect(),{255,255,255});
    disp->drawRect(ball->GetRect(),{255,255,255});
    disp->commit();
}
//end game.cpp