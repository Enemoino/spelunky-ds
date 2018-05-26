//
// Created by xdbeef on 30.04.18.
//

#ifndef SPELUNKYDS_TITLEMENUSIGN_H
#define SPELUNKYDS_TITLEMENUSIGN_H


#include "../moving_object.h"
#include "../menu_sign_type.h"

class TitleMenuSign : public MovingObject {

public:

    void initSprite() override;

    void updateOther() override {};

    void init() override;

    void draw() override;

    void kill() override {};

    void updateTimers() override {};

    void update_position() override ;

    void updateSpeed() override;

    void updateCollisionsMap(int x_current_pos_in_tiles, int y_current_pos_in_tiles) override;

    void updateCollisionsOtherMoving() override {};

    void onCollisionWithMainCharacter() override {};

    SpriteInfo *mainSpriteInfo_1 {};
    SpriteInfo *mainSpriteInfo_2 {};

    SpriteInfo *subSpriteInfo_1 {};
    SpriteInfo *subSpriteInfo_2 {};

    OamType oamType{};
    MenuSignType menuSignType{};
};



#endif //SPELUNKYDS_TITLEMENUSIGN_H
