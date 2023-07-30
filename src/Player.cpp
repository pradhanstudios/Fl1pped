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

void Player::jump()
{
    this->velocity.y = -10;
}

bool Player::collides_with_platform(Platform *platforms, int num_platforms)
{
    for (int i = 0; i < num_platforms; i++)
    {
        // TODO: check for Player collision with cur Platform
        return true; // temp
    }

    // until collisions are implemented
    return true;

    // return false;
}