#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "raylib.h"
#include "object.hpp"
#include "config.hpp"

#define FRICTION -0.12f
#define GRAVITY 0.5f
#define ACCELERATION 1.0f
#define JUMP -11.0f

class Player : public _Object {
    float velocity_x, velocity_y;
    float acceleration_x, acceleration_y;
    float gravity_direction;
    
    public:
        Player(float x, float y, float w, float h, Color color, float gravity_direction=1) : _Object(x, y, w, h, color) {
            this->gravity_direction = gravity_direction;
            this->velocity_x = 0.0f;
            this->velocity_y = 0.0f;
            this->acceleration_x = 0.0f;
            this->acceleration_y = 0.0f;
        }
        // update
        void update(const std::vector<Object> &objects);
        // move
        void move_left();
        void move_right();
        inline void jump() {
            this->velocity_y = gravity_direction * JUMP;
        }
};

#endif // PLAYER_HPP