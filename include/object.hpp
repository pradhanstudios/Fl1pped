#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SDL2/SDL.h>

class Object {
    SDL_Rect rect;
    int half_x, half_y;
    unsigned int color;

    public:
        Object(const int x, const int y, const int width, const int height, const unsigned int color);
        
        
        inline void Draw(SDL_Surface *window_surface) {
            SDL_FillRect(window_surface, &this->rect, this->color);
        }
        
        inline int top_left_x() {
            return this->rect.x;
        }

        inline int top_left_y() {
            return this->rect.y;
        }

        inline int bot_left_x() {
            return this->rect.x;
        }

        inline int bot_left_y() {
            return this->rect.y + this->rect.h;
        }

        inline int top_right_x() {
            return this->rect.x + this->rect.w;
        }

        inline int top_right_y() {
            return this->rect.y;
        }

        inline int bot_right_x() {
            return this->rect.x + this->rect.w;
        }

        inline int bot_right_y() {
            return this->rect.y + this->rect.h;
        }

        inline int center_x() {
            return this->rect.x + this->half_x;
        }

        inline int center_y() {
            return this->rect.y + this->half_y;
        }

};

#endif // OBJECT_HPP