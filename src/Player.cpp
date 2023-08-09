#include "Player.h"

Player::Player(Vector2 position, Vector2 size, Color skin, int controls[3])
{
    this->velocity = (Vector2){0.0, 0.0};
    this->acceleration.x = 0;
    this->acceleration.y = GRAVITY;
    this->rect = Rectangle{position.x, position.y, size.x, size.y};
    this->skin = skin;
    this->up = controls[0];
    this->left = controls[1];
    this->right = controls[2];
}

void Player::update_collision_points()
{
    this->collision_points.clear();
    // left is less than right
    this->point_1 = (Vector2){this->rect.x, this->rect.y};                                                // top left
    this->point_2 = (Vector2){this->rect.x + this->rect.width / 2, this->rect.y};                         // top middle
    this->point_3 = (Vector2){this->rect.x + this->rect.width, this->rect.y};                             // top right
    this->point_4 = (Vector2){this->rect.x, this->rect.y + this->rect.height / 2};                        // middle left
    this->point_5 = (Vector2){this->rect.x + this->rect.width / 2, this->rect.y + this->rect.height / 2}; // middle middle
    this->point_6 = (Vector2){this->rect.x + this->rect.width, this->rect.y + this->rect.height / 2};     // middle right
    this->point_7 = (Vector2){this->rect.x, this->rect.y + this->rect.height};                            // bottom left
    this->point_8 = (Vector2){this->rect.x + this->rect.width / 2, this->rect.y + this->rect.height};     // bottom middle
    this->point_9 = (Vector2){this->rect.x + this->rect.width, this->rect.y + this->rect.height};         // bottom right
    this->collision_points.push_back(this->point_1);
    this->collision_points.push_back(this->point_2);
    this->collision_points.push_back(this->point_3);
    this->collision_points.push_back(this->point_4);
    this->collision_points.push_back(this->point_5);
    this->collision_points.push_back(this->point_6);
    this->collision_points.push_back(this->point_7);
    this->collision_points.push_back(this->point_8);
    this->collision_points.push_back(this->point_9);
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
    // debug
    for (Vector2 pos : this->collision_points)
    {
        DrawPixelV(pos, RED);
    }
}

void Player::update(std::vector<Platform> platforms, int num_platforms)
{
    this->move(platforms, num_platforms);
}

void Player::update(Platform plat)
{
    this->move(plat);
}

void Player::move(std::vector<Platform> platforms, int num_platforms)
{
    // set acceleration values
    this->acceleration.x = 0;
    this->acceleration.y = GRAVITY;

    // player movement
    if (IsKeyDown(right))
    {
        this->acceleration.x = -ACCELERATION;
    }
    if (IsKeyDown(left))
    {
        this->acceleration.x = ACCELERATION;
    }

    // stand on platform
    // Platform collide_plat = this->collides_with_platform(platforms, num_platforms);
    std::vector<int> collide_points = this->collides_with_platform(platforms, num_platforms);
    bool collision = !(collide_points.empty());

    if (collision)
    {
        int collide_len = collide_points.size();

        // debug
        // fprintf(stderr, "plat-y: %f\tplayer-y: %f\n", collide_plat.get_position().y, this->rect.y + this->rect.height);

        // loop thru collided points
        for (int i = 0; i < collide_len; i++)
        {
            // check middles

            // left and right
            if (collide_points[i] == 4)
            {
                this->acceleration.x = ACCELERATION;
            }
            if (collide_points[i] == 6)
            {
                this->acceleration.x = -ACCELERATION;
            }

            // top and bot
            if (collide_points[i] == 2)
            {
                this->velocity.y = 1;
            }
            if (collide_points[i] == 8)
            {
                this->velocity.y = -1;
            }
        }
    }
    // }

    // jump
    if (IsKeyDown(up) && !(std::find(collide_points.begin(), collide_points.end(), 8) == collide_points.end()))
    {
        this->jump();
    }

    // 2D kinematics
    this->acceleration.x += this->velocity.x * FRICTION;
    this->velocity.x += this->acceleration.x;
    this->velocity.y += this->acceleration.y;
    this->rect.x += this->velocity.x + (0.5 * this->acceleration.x);
    this->rect.y += this->velocity.y + (0.5 * this->acceleration.y);

    // vertical screen warp
    if (this->rect.y > GetScreenHeight())
    {
        this->rect.y = 0;
    }
    if (this->rect.y < 0)
    {
        this->rect.y = GetScreenHeight();
    }
}

void Player::move(Platform plat)
{
    // set acceleration values
    this->acceleration.x = 0;
    this->acceleration.y = GRAVITY;

    if (IsKeyDown(right))
    {
        this->acceleration.x = -ACCELERATION;
    }
    if (IsKeyDown(left))
    {
        this->acceleration.x = ACCELERATION;
    }

    // stand on platform
    std::vector<Vector2> collides = this->collides_with_platform(plat);
    if (this->velocity.y > 0)
    {
        if (!collides.empty())
        {
            this->rect.y = plat.get_position().y - this->rect.height;
            this->velocity.y = 0;
        }
    }

    // jump
    if (IsKeyDown(up) && !this->collides_with_platform(plat).empty())
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

std::vector<Vector2> Player::collides_with_platform(Platform plat)
{
    this->update_collision_points();
    std::vector<Vector2> collided_points;
    for (Vector2 pos : this->collision_points)
    {
        if (CheckCollisionPointRec(pos, (Rectangle){plat.get_position().x, plat.get_position().y, plat.get_size().x, plat.get_size().y}))
        {
            collided_points.push_back(pos);
        }
    }
    return collided_points;
}

std::vector<int> Player::collides_with_platform(std::vector<Platform> platforms, int num_platforms)
{
    // initialize result
    std::vector<int> collide_arr;
    std::vector<Vector2> output;

    // loop thru each platform and add each platform the player touches to collide_arr
    for (int i = 0; i < num_platforms; i++)
    {
        output.clear();
        output = collides_with_platform(platforms[i]);
        if (!output.empty())
        {
            for (Vector2 point : output)
            {
                if (point.x == this->point_1.x && point.y == this->point_1.y)
                {
                    collide_arr.push_back(1);
                }
                if (point.x == this->point_2.x && point.y == this->point_2.y)
                {
                    collide_arr.push_back(2);
                }
                if (point.x == this->point_3.x && point.y == this->point_3.y)
                {
                    collide_arr.push_back(3);
                }
                if (point.x == this->point_4.x && point.y == this->point_4.y)
                {
                    collide_arr.push_back(4);
                }
                if (point.x == this->point_5.x && point.y == this->point_5.y)
                {
                    collide_arr.push_back(5);
                }
                if (point.x == this->point_6.x && point.y == this->point_6.y)
                {
                    collide_arr.push_back(6);
                }
                if (point.x == this->point_7.x && point.y == this->point_7.y)
                {
                    collide_arr.push_back(7);
                }
                if (point.x == this->point_8.x && point.y == this->point_8.y)
                {
                    collide_arr.push_back(8);
                }
                if (point.x == this->point_9.x && point.y == this->point_9.y)
                {
                    collide_arr.push_back(9);
                }
            }
        }
    }

    return collide_arr;
}

void Player::set_position(Vector2 position)
{
    this->rect.x = position.x;
    this->rect.y = position.y;
}