//
// Created by xdbeef on 04.04.18.
//

#include "../Globals.h"
#include "../../build/ropes.h"
#include "RopeElement.h";

extern u16 map[4096];

void RopeElement::draw() {

    int main_x = x - global::camera->x;
    int main_y = y - global::camera->y;
    int sub_x = x - global::camera->x;
    int sub_y = y - global::camera->y - 192;
    
    if (this->y < 320 + 8 && this->y > 320 - 8) {

    } else if (this->y > 320) {
        main_x = -128;
        main_y = -128;
//        sub_x -= 56;
    } else if (this->y < 320) {
        sub_x = -128;
        sub_y = -128;
    }

    if (sub_y < 0 || sub_x < 0) {
        sub_x = -128;
        sub_y = -128;
    }
    if (main_y < 0 || main_x < 0) {
        main_x = -128;
        main_y = -128;
    }


    mainSpriteInfo->entry->x = main_x;
    mainSpriteInfo->entry->y = main_y;

    subSpriteInfo->entry->x = sub_x;
    subSpriteInfo->entry->y = sub_y;

    mainSpriteInfo_2->entry->x = main_x;
    mainSpriteInfo_2->entry->y = main_y + 8;

    subSpriteInfo_2->entry->x = sub_x;
    subSpriteInfo_2->entry->y = sub_y + 8;

}


void RopeElement::init() {
    subSpriteInfo = global::sub_oam_manager->initSprite(ropesPal, ropesPalLen,
                                                        nullptr, 8 * 8, 8, ROPE_ELEMENT, true, true);
    mainSpriteInfo = global::main_oam_manager->initSprite(ropesPal, ropesPalLen,
                                                          nullptr, 8 * 8, 8, ROPE_ELEMENT, true, true);

    subSpriteInfo_2 = global::sub_oam_manager->initSprite(ropesPal, ropesPalLen,
                                                          nullptr, 8 * 8, 8, ROPE_ELEMENT, true, true);
    mainSpriteInfo_2 = global::main_oam_manager->initSprite(ropesPal, ropesPalLen,
                                                            nullptr, 8 * 8, 8, ROPE_ELEMENT, true, true);

    frameGfx = (u8 *) ropesTiles + 0 * 8 * 8 / 2;
    subSpriteInfo->updateFrame(frameGfx, 8 * 8);
    mainSpriteInfo->updateFrame(frameGfx, 8 * 8);
    subSpriteInfo_2->updateFrame(frameGfx, 8 * 8);
    mainSpriteInfo_2->updateFrame(frameGfx, 8 * 8);
}

void RopeElement::updateSpeed() {
}

void RopeElement::updatePosition() {
}

void RopeElement::updateCollisionsMap(int x_current_pos_in_tiles, int y_current_pos_in_tiles) {
}

