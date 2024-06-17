#include "object.hpp"

Object::Object(int x, int y, int w, int h, Color color) {
    this->rect = (Rectangle) {x, y, w, h};
    this->half_x = x / 2;
    this->half_y = y / 2;
    this->color = color;
}