#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

using Color = SDL_Color;

/**
 * \brief Class for creating and managing a drawing on the screen
 *
 */
class Display
{
    public:
        /**
         * \brief Constructor
         * Creates and initialize window with specified dimensions
         *
         * \param width width of window
         * \param height height of window
         */
        Display(int width, int height);
        /**
         * \brief Destructor
         * Closes windows and cleans
         */
        ~Display();
        /**
         * \brief Returns erorr status of initialization
         *
         * \return true if there is error during initialization
         */
        bool isInitError();
        /**
         * \brief Clears image buffer with defined color
         *
         * \param c color of cleared background
         */
        void clearBuffer(Color c);
        /**
         * \brief Draws rectangle into image buffer
         *
         * \param rect game rectangle object with position and size
         * \param c color of rectangle
         */
        void drawRect(SDL_Rect *rect, Color c);
        /**
         * \brief Draws text into image buffer
         *
         * \param txt text to draw
         * \param x central position of text
         * \param y top position of text
         * \param c color of rectangle
         */
        void drawText(std::string txt, int x, int y, Color c);
        /**
         * \brief Renders image buffer to window
         */
        void commit();

    private:
        int winWidth, winHeigth;
        bool initError;
        SDL_Renderer* renderer=nullptr;//image buffer
        SDL_Window* window=nullptr;
        TTF_Font* font=nullptr;
};
#endif