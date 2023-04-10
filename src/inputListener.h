#ifndef INPUTLISTENER_H
#define INPUTLISTENER_H

#include <SDL2/SDL.h>

using Key = SDL_Scancode;

/**
 * \brief Observer class for input
 *
 */
class InputListener
{
    friend class Input;

    public:
        /**
         * \brief Constructor
         */
        InputListener(): next_(NULL) {}
        /**
         * \brief process button press and change movement direction
         *
         * \param k key value
         */
        virtual void buttonPressed(Key k) {}
        /**
         * \brief process button release and stop movement direction
         *
         * \param k key value
         */
        virtual void buttonReleased(Key k) {}
    
    private:
        InputListener* next_;
};
#endif