#include "Platform.h"

Platform::Platform(Vector2 position, Vector2 size, Color tile)
{
    this->rect = Rectangle{position.x, position.y, size.x, size.y};
    this->tile = tile;
}

void Platform::draw_tile()
{
    DrawRectangleRec(this->rect, this->tile);
}

Vector2 Platform::get_position()
{
    return (Vector2){this->rect.x, this->rect.y};
}

Vector2 Platform::get_size()
{
    return (Vector2){this->rect.width, this->rect.height};
}

Rectangle Platform::get_rect()
{
    return this->rect;
}