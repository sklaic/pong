#include "input.h"

Input::Input(): head_(NULL) {}

void Input::addListener(InputListener* listener)
{
    listener->next_ = head_;
    head_ = listener;
}

void Input::removeListener(InputListener* listener)
{
    if (head_ == listener)
    {
        head_ = listener->next_;
        listener->next_ = NULL;
        return;
    }
    InputListener* current = head_;
    while (current != NULL)
    {
        if (current->next_ == listener)
        {
        current->next_ = listener->next_;
        listener->next_ = NULL;
        return;
        }
        current = current->next_;
    }
}

void Input::pressed(const Key k)
{
    InputListener* listener = head_;
    while (listener != NULL)
    {
        listener->buttonPressed(k);
        listener = listener->next_;
    }
}

void Input::released(const Key k)
{
    InputListener* listener = head_;
    while (listener != NULL)
    {
        listener->buttonReleased(k);
        listener = listener->next_;
    }
}
//end input.cpp