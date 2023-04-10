#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL2/SDL.h>
#include <iostream>
#include "inputListener.h"

using Color = SDL_Color;

/**
 * \brief Paddle class
 */
class GameObject: public InputListener
{
   public:
        /**
         * \brief Constructor
         * Creates and initialize object with specified dimensions
         *
         * \param width width of object
         * \param height height of object
         * \param maxWidth width of allowed travel region
         * \param maxHeight height of allowed travel region
         * \param color color of object
         */
        GameObject(int width, int height, int maxWidth, int maxHeigth, Color color);
        /**
         * \brief Set position of object within boundaries
         *
         * \param posx x position of object
         * \param posy y position of object
         */
        void SetPos(int posx, int posy);
        /**
         * \brief Get reference of object rectangle
         *
         * \return rectangle reference
         */
        SDL_Rect* GetRect();
        /**
         * \brief Set direction of travel
         *
         * \param wDir x direction of object
         * \param hDir y direction of object
         */
        void SetDir(int wDir, int hDir);
        /**
         * \brief Update position of a object
         */
        void Update();
        /**
         * \brief set score
         *
         * \param val score new value
         */
        void SetScore(int val);
        /**
         * \brief get score value
         *
         * \return score value
         */
        int GetScore();
        /**
         * \brief process button press and change movement direction
         *
         * \param k key value
         */
        void buttonPressed(Key k);
        /**
         * \brief process button release and stop movement direction
         *
         * \param k key value
         */
        void buttonReleased(Key k);

   protected:
        int w, h;//object dimension
        int dirW, dirH, speed;//direction and speed
        int maxW, maxH;//travel boundaries
        int score;
        Color c;//object color
        SDL_Rect rect;
};
#endif
