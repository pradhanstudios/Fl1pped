#include "object.hpp"

_Object::_Object(float x, float y, float w, float h, Color color) {
    this->rect = (Rectangle) {x, y, w, h};
    this->half_w = x / 2;
    this->half_h = y / 2;
    this->color = color;
}