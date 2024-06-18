#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "raylib.h"
#include "config.hpp"

// Base class for all objects
class _Object {
    protected:
        Rectangle rect;
        Color color;
        float half_w, half_h;

    public:
        _Object(float x, float y, float w, float h, Color color);

        inline void Draw_Color() {
            DrawRectangleRec(this->rect, this->color);
        }

        inline float x() {
            return this->rect.x;
        }

        inline void set_x(float x) {
            this->rect.x = x;
        }

        inline float y() {
            return this->rect.y;
        }

        inline void set_y(float y) {
            this->rect.y = y;
        }

        inline float width() {
            return this->rect.width;
        }

        inline float height() {
            return this->rect.height;
        }

        inline float top_left_x() {
            return this->rect.x;
        }

        inline float top_left_y() {
            return this->rect.y;
        }

        inline float bot_left_x() {
            return this->rect.x;
        }

        inline float bot_left_y() {
            return this->rect.y + this->rect.height;
        }

        inline float top_right_x() {
            return this->rect.x + this->rect.width;
        }

        inline float top_right_y() {
            return this->rect.y;
        }

        inline float bot_right_x() {
            return this->rect.x + this->rect.width;
        }

        inline float bot_right_y() {
            return this->rect.y + this->rect.height;
        }

        inline float center_x() {
            return this->rect.x + this->half_w;
        }

        inline float center_y() {
            return this->rect.y + this->half_h;
        }
};

// non moving objects

enum object_type {
    PLATFORM
};

class Object : public _Object {
    object_type object_type_;

    public:
        Object(float x, float y, float w, float h, Color color, object_type object_type_) : _Object(x, y, w, h, color) {
            this->object_type_ = object_type_;           
        }

        inline object_type get_object_type() {
            return this->object_type_;
        }
};

typedef Object Platform;

inline Platform build_platform(double x, double y, double w, double h, Color color) {
    return Object(x, y, w, h, color, PLATFORM);
}

#endif // OBJECT_HPP