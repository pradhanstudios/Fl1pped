#pragma once

#include "raylib.h"
#include <vector>
#include "Platform.h"
#include "Player.h"

class Enemy
{
protected:
    Rectangle rect;
    Vector2 velocity;
    Vector2 acceleration;
    Color skin;
    int dir;
    // Texture2D skin;
    // bool can_jump;
    int bot_screen_wrap;
    int top_screen_wrap;
    std::vector<Vector2>
        collision_points;
    int collided_points[17];
    Vector2 point_1;
    Vector2 point_2;
    Vector2 point_3;
    Vector2 point_4;
    Vector2 point_5;
    Vector2 point_6;
    Vector2 point_7;
    Vector2 point_8;
    Vector2 point_9;
    Vector2 thresh_point_1;
    Vector2 thresh_point_2;
    Vector2 thresh_point_3;
    Vector2 thresh_point_4;
    Vector2 thresh_point_5;
    Vector2 thresh_point_6;
    Vector2 thresh_point_7;
    Vector2 thresh_point_8;

public:
    Enemy();
    // Player(Vector2 position, Vector2 size, Texture2D skin);
    void update_collision_points();
    Vector2 get_position() { return (Vector2){this->rect.x, this->rect.y}; };
    Vector2 get_velocity() { return this->velocity; };
    Vector2 get_acceleration() { return this->acceleration; };
    Vector2 get_size() { return (Vector2){rect.width, rect.height}; };
    // bool get_jump();
    void draw_enemy() { DrawRectangleRec(this->rect, this->skin); };
    // void update(Platform plat);
    void update(std::vector<Platform> platforms, int num_platforms) { this->move(platforms, num_platforms); };
    // void move(Platform plat);
    virtual void move(std::vector<Platform> platforms, int num_platforms) = 0;
    void jump();
    void collides_with_platform(Platform platform);
    // Platform collides_with_platform(Platform *platforms, int num_platforms);
    void collides_with_platform(std::vector<Platform> platforms, int num_platforms);
    void set_position(Vector2 position);
    int get_dir() { return this->dir; };
    void set_bot_screen_warp(int arg) { this->bot_screen_wrap = arg; };
    void set_top_screen_warp(int arg) { this->top_screen_wrap = arg; };
    void set_dir(int direction);
    Rectangle get_body() { return this->rect; };
};

class Blob : public Enemy
{
public:
    Blob(Vector2 position, Vector2 size, Color skin, int dir);
    void move(std::vector<Platform> platforms, int num_platforms);
};