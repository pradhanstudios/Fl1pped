#include "Player.h"

Player::Player(Vector2 position, Vector2 size, Color skin)
{
    this->velocity = (Vector2){0.0, 0.0};
    this->acceleration.x = 0;
    this->acceleration.y = GRAVITY;
    this->rect = Rectangle{position.x, position.y, size.x, size.y};
    this->skin = skin;
    // this->can_jump = false;
}

Vector2 Player::get_position()
{
    return (Vector2){this->rect.x, this->rect.y};
}

Vector2 Player::get_velocity()
{
    return this->velocity;
}

Vector2 Player::get_acceleration()
{
    return this->acceleration;
}

Vector2 Player::get_size()
{
    return (Vector2){this->rect.width, this->rect.height};
}

// bool Player::get_jump()
// {
//     return this->can_jump;
// }

void Player::draw_player()
{
    // DrawTextureV(this->position, this->size, this->skin);
    DrawRectangleRec(this->rect, this->skin);
}

void Player::update(Platform plat)
{
    this->move(plat);
}

void Player::move(Platform plat)
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

    // stand on platform
    bool collides = this->collides_with_platform(plat);
    if (this->velocity.y > 0)
    {
        if (collides)
        {
            this->rect.y = plat.get_position().y - this->rect.height;
            this->velocity.y = 0;
        }
    }

    // jump
    if (IsKeyDown(KEY_W) && this->collides_with_platform(plat))
    {
        this->jump();
    }

    // 2D kinematics
    this->acceleration.x += this->velocity.x * FRICTION;
    this->velocity.x += this->acceleration.x;
    this->velocity.y += this->acceleration.y;
    this->rect.x += this->velocity.x + (0.5 * this->acceleration.x);
    this->rect.y += this->velocity.y + (0.5 * this->acceleration.y);

    // horizontal screen warp
    if (this->rect.x > GetScreenWidth())
    {
        this->rect.x = 0;
    }
    if (this->rect.x < 0)
    {
        this->rect.x = GetScreenWidth();
    }
}

void Player::jump()
{
    this->velocity.y = -10;
}

// input: list of platforms
bool Player::collides_with_platform(Platform plat)
{
    float plat_right = plat.get_position().x + plat.get_size().x;
    float play_right = this->rect.x + this->rect.width;

    float plat_bot = plat.get_position().y + plat.get_size().y;
    float play_bot = this->rect.y + this->rect.height;

    bool in_x = ((this->rect.x <= plat_right) && (play_right >= plat.get_position().x));
    bool in_y = ((play_bot >= plat.get_position().y) && (this->rect.y <= plat_bot));

    // simple collision
    return in_x && in_y;
}