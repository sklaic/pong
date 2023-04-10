#ifndef GAME_H
#define GAME_H

#include "display.h"
#include "gameObject.h"
#include "ball.h"
#include "input.h"

enum GameState { Pending, Running, Finish };

/**
 * \brief Class for creating and managing gameplay
 */
class Game
{
	public:
		/**
		 * \brief Intializes game and all componets of it
		 *
         * \param width width of window
         * \param height height of window
 		 * \return true if there is error during initialization
		 */
		bool Init(const int width, const int height);
		/**
		 * \brief Main loop for game
		 */
		void GameLoop();
		/**
		 * \brief Closes game and all componets of it
		 */
		void Shutdown();

		void SetGamestatePending();

	private:
		void HandleEvents();
		void Update();
		void Draw();

		int winWidth, winHeight;
		int gamestate = GameState::Pending;
		bool isRunning = true;

		Display *disp = nullptr;
		GameObject *leftPaddle = nullptr, *rightPaddle = nullptr;
		Ball *ball = nullptr;
		Input keyboardInput;
};
#endif