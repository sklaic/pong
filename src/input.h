#ifndef INPUT_H
#define INPUT_H

#include "inputListener.h"

/**
 * \brief Class for handling input events
 *
 */
class Input
{
    public:
        /**
         * \brief Constructor
         */
        Input();
        /**
         * \brief add listener object to linked list
         *
         * \param listener object to add on list
         */
        void addListener(InputListener* listener);
        /**
         * \brief remove listener object from linked list
         *
         * \param listener object to remove
         */
        void removeListener(InputListener* listener);
        /**
         * \brief notify all listeners for pressed key
         *
         * \param k key scancode to send
         */
        void pressed(const Key k);
        /**
         * \brief notify all listeners for released key
         *
         * \param k key scancode to send
         */
        void released(const Key k);

    private:
        InputListener* head_;
};
#endif