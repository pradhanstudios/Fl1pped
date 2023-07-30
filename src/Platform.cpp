#include "Platform.h"

Platform::Platform(Vector2 position, Vector2 size, Color tile)
{
    this->position = position;
    this->size = size;
    this->tile = tile;
}

void Platform::draw_tile()
{
    DrawRectangleV(this->position, this->size, this->tile);
}