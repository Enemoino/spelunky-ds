//
// Created by xdbeef on 23.04.18.
// http://spelunky.wikia.com/wiki/Snake
//

#ifndef SPELUNKYDS_SNAKE_H
#define SPELUNKYDS_SNAKE_H

#define SNAKE_PHYSICAL_HEIGHT 16
#define SNAKE_PHYSICAL_WIDTH 16
#define SNAKE_SPRITE_HEIGHT 16
#define SNAKE_SPRITE_WIDTH 16

#define MAX_X_SPEED_SNAKE 4
#define MAX_Y_SPEED_SNAKE 4

#include "../moving_object.h"
#include "../sprite_state.hpp"
#include "../sprite_info.h"

class Snake : public MovingObject {

public:

    Snake();

    void updateOther() override {};

    void init() override;

    void draw() override;

    void apply_dmg(int dmg_to_apply) override;

    void updateTimers() override {};

    void updateSpeed() override;

    void updateCollisionsMap(int x_current_pos_in_tiles, int y_current_pos_in_tiles) override;

    void updateCollisionsOtherMoving() override {};

    void onCollisionWithMainCharacter() override {};

    void initSprite() override;

    double pos_inc_timer{};

    SpriteInfo *mainSpriteInfo{};
    SpriteInfo *subSpriteInfo{};
    u8 *frameGfx{};
    int sameDirectionInRow{};


    //Snake goes for random amount of time_utils on random direction, then waits random time_utils and the cycle goes again
    SpriteState spriteState{};
    int waitTimer{};
    int goTimer{};

    int animFrame{};
    int animFrameTimer{};

    void randomizeMovement();

    void set_position();

    void set_sprite_left();

    void set_sprite_right();
};


#endif //SPELUNKYDS_SNAKE_H
