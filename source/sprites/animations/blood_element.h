//
// Created by xdbeef on 28.04.18.
//

#ifndef SPELUNKYDS_BLOODELEMENT_H
#define SPELUNKYDS_BLOODELEMENT_H

#include "../moving_object.h"
#include "../sprite_info.h"

class BloodElement : public MovingObject {

public:

    BloodElement();

    void updateOther() override {};

    void init() override;

    void apply_dmg(int dmg_to_apply) override {};


    void draw() override;

    void initSprite() override;

    void updateTimers() override {};

    void updateSpeed() override;

    void updateCollisionsMap(int x_current_pos_in_tiles, int y_current_pos_in_tiles) override;

    void updateCollisionsOtherMoving() override {};

    void onCollisionWithMainCharacter() override {};


    SpriteInfo *mainSpriteInfo {};
    SpriteInfo *subSpriteInfo {};

    u8 * frameGfx{};

    int living_timer{};
    int currentFrame{};
    int frameTimer{};
    int pos_inc_timer{};
    int inactive_delay{};
    bool finished{};
};



#endif //SPELUNKYDS_BLOODELEMENT_H
