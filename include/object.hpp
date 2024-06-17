#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "raylib.h"
#include "config.hpp"

// Base class for all objects
class Object {
    Rectangle rect;
    Color color;
    int half_w, half_h;

    public:
        Object(int x, int y, int w, int h, Color color);

        void update();

        inline void Draw_Color() {
            DrawRectangleRec(this->rect, this->color);
        }

        inline int x() {
            return this->rect.x;
        }

        inline void set_x(int x) {
            this->rect.x = x;
        }

        inline int y() {
            return this->rect.y;
        }

        inline void set_y(int y) {
            this->rect.y = y;
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
            return this->rect.x + this->half_w;
        }

        inline int center_y() {
            return this->rect.y + this->half_h;
        }
};

#endif // OBJECT_HPP