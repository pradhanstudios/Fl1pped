#include "Platform.h"

Platform::Platform(Vector2 position, Color tile)
{
    this->position = position;
    this->size = 100.0;
    this->tile = tile;
}

void Platform::draw_tile()
{
    DrawRectangleV(this->position, Vector2{this->size, this->size}, this->tile);
}

Vector2 Platform::get_position()
{
    return this->position;
}

float Platform::get_size()
{
    return this->size;
}

// Color Platform::get_tile()
// {
//     return this->tile;
// }