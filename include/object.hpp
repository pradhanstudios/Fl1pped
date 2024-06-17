#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "raylib.h"
#include "config.hpp"

class Object {
    Rectangle rect;
    Color color;
    int half_x, half_y;

    public:
        Object(int x, int y, int w, int h, Color color);

        inline void Draw_Color() {
            DrawRectangleRec(this->rect, this->color);
        }

        inline int x() {
            return this->rect.x;
        }

        inline int y() {
            return this->rect.y;
        }

        inline int width() {
            return this->rect.width;
        }

        inline int height() {
            return this->rect.height;
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
            return this->rect.y + this->rect.height;
        }

        inline int top_right_x() {
            return this->rect.x + this->rect.width;
        }

        inline int top_right_y() {
            return this->rect.y;
        }

        inline int bot_right_x() {
            return this->rect.x + this->rect.width;
        }

        inline int bot_right_y() {
            return this->rect.y + this->rect.height;
        }

        inline int center_x() {
            return this->rect.x + this->half_x;
        }

        inline int center_y() {
            return this->rect.y + this->half_y;
        }
};

#endif // OBJECT_HPP