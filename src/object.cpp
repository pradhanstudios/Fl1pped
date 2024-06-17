#include "object.hpp"

Object::Object(const int x, const int y, const int width, const int height, const unsigned int color) {
    this->half_x = x / 2;
    this->half_y = y / 2;
    this->rect.x = x;
    this->rect.y = y;
    this->rect.w = width;
    this->rect.h = height;
}