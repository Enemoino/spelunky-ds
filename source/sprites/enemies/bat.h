//
// Created by xdbeef on 02.05.18.
//

#ifndef SPELUNKYDS_BAT_H
#define SPELUNKYDS_BAT_H

#include <nds/jtypes.h>
#include "../moving_object.h"
#include "../sprite_state.h"
#include "../sprite_info.h"

class Bat : public MovingObject {

public:

    void updateOther() override {};

    void init() override;

    void draw() override;

    void kill() override ;

    void updateTimers() override {};

    void updatePosition() override;

    void updateSpeed() override;

    void updateCollisionsMap(int x_current_pos_in_tiles, int y_current_pos_in_tiles) override;

    void updateCollisionsOtherMoving() override {};

    void onCollisionWithMainCharacter() override {};

    void initSprite() override;

    double pos_inc_timer;

    SpriteInfo *mainSpriteInfo = nullptr;
    SpriteInfo *subSpriteInfo = nullptr;
    u8 *frameGfx;

    sprite_state spriteState;

    int animFrame;
    int animFrameTimer;

    bool hanging;
    bool hunting;

    void set_sprite_hanging();

    void set_sprite_flying_right();

    void set_sprite_flying_left();

    void set_position();
};



#endif //SPELUNKYDS_BAT_H
