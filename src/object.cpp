#include "object.hpp"

Object::Object(int x, int y, int w, int h, Color color) {
    this->rect = (Rectangle) {x, y, w, h};
    this->half_w = x / 2;
    this->half_h = y / 2;
    this->color = color;
}

void Object::update() {
    return;
}