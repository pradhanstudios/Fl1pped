#include "Player.h"

Player::Player(Vector2 position, Vector2 size, Color skin)
{
    this->position = position;
    this->size = size;
    this->skin = skin;
}

void Player::draw_player()
{
    // DrawTextureV(this->position, this->size, this->skin);
    DrawRectangleV(this->position, this->size, this->skin);
}

void Player::move()
{
    // set acceleration values
    this->acceleration.x = 0;
    this->acceleration.y = GRAVITY;

    if (IsKeyDown(KEY_A))
    {
        this->acceleration.x = -ACCELERATION;
    }
    if (IsKeyDown(KEY_D))
    {
        this->acceleration.x = ACCELERATION;
    }

    // FIXME: temporary until collisions
    if (this->position.y > GetScreenHeight() / 4)
    {
        this->acceleration.y = 0;
        this->velocity.y = 0;
    }

    // 2D kinematics
    this->acceleration.x += this->velocity.x * FRICTION;
    this->velocity.x += this->acceleration.x;
    this->velocity.y += this->acceleration.y;
    this->position.x += this->velocity.x + (0.5 * this->acceleration.x);
    this->position.y += this->velocity.y + (0.5 * this->acceleration.y);

    // horizontal screen warp
    if (this->position.x > GetScreenWidth())
    {
        this->position.x = 0;
    }
    if (this->position.x < 0)
    {
        this->position.x = GetScreenWidth();
    }
}