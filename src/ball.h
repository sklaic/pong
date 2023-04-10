#ifndef BALL_H
#define BALL_H

#include "gameObject.h"

/**
 * \brief Ball class
 */
class Ball: public GameObject
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
        Ball(int width, int height, int maxWidth, int maxHeigth, Color color);
        /**
         * \brief Get direction of x travel
         *
         * \return x direction of travel
         */
        int GetDirW();
        /**
         * \brief Get direction of y travel
         *
         * \return y direction of travel
         */
        int GetDirH();
        /**
         * \brief Reset ball position to middle of window and flip direction
         */
        void ResetPos();
};
#endif