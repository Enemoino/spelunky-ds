//
// Created by xdbeef on 16.05.18.
//

#include <maxmod9.h>
#include "../../../build/gfx_spike_collectibles.h"
#include "chest.h"
#include "../../collisions/collisions.h"
#include "../../globals_declarations.h"
#include "../../../build/soundbank.h"
#include "moniez.h"

#define CHEST_PICKUP_OFFSET_X 8
#define CHECK_PICKUP_OFFSET_Y 2
#define CHEST_POS_INC_DELTA 15
#define CHEST_FRICTION 0.055

void Chest::draw() {

    check_if_can_be_pickuped();
    set_pickuped_position(CHEST_PICKUP_OFFSET_X, CHECK_PICKUP_OFFSET_Y);

    if (check_if_can_be_opened()) {

        frameGfx = (u8 *) gfx_spike_collectiblesTiles + (sprite_width * sprite_height * (3) / 2);
        subSpriteInfo->updateFrame(frameGfx, sprite_width * sprite_height);
        mainSpriteInfo->updateFrame(frameGfx, sprite_width * sprite_height);
        mmEffect(SFX_XCHESTOPEN);
        spawn_treasure();
        global::hud->draw();

    }

    kill_mobs_if_thrown();
    set_position();
}


void Chest::init() {
    initSprite();
}

void Chest::updateSpeed() {

    limit_speed(MAX_X_SPEED_CHEST, MAX_Y_SPEED_CHEST);

    pos_inc_timer += *global::timer;

    bool change_pos = (pos_inc_timer > CHEST_POS_INC_DELTA) && !hold_by_main_dude;

    if (change_pos) {
        update_position();
        apply_friction(CHEST_FRICTION);
        apply_gravity(GRAVITY_DELTA_SPEED);
        pos_inc_timer = 0;
    }
}

void Chest::updateCollisionsMap(int x_current_pos_in_tiles, int y_current_pos_in_tiles) {
    MapTile *tiles[9];
    Collisions::getNeighboringTiles(global::level_generator->map_tiles, x_current_pos_in_tiles, y_current_pos_in_tiles,
                                    tiles);

    bottomCollision = Collisions::checkBottomCollision(tiles, &x, &y, &ySpeed, physical_width, physical_height, true);
    leftCollision = Collisions::checkLeftCollision(tiles, &x, &y, &xSpeed, physical_width, physical_height, true);
    rightCollision = Collisions::checkRightCollision(tiles, &x, &y, &xSpeed, physical_width, physical_height, true);
    upperCollision = Collisions::checkUpperCollision(tiles, &x, &y, &ySpeed, physical_width, true);

}

void Chest::initSprite() {

    subSpriteInfo = global::sub_oam_manager->initSprite(gfx_spike_collectiblesPal, gfx_spike_collectiblesPalLen,
                                                        nullptr, sprite_width * sprite_height, sprite_width,
                                                        spriteType, true, false, LAYER_LEVEL::MIDDLE_TOP);
    mainSpriteInfo = global::main_oam_manager->initSprite(gfx_spike_collectiblesPal, gfx_spike_collectiblesPalLen,
                                                          nullptr, sprite_width * sprite_height, sprite_width,
                                                          spriteType, true, false, LAYER_LEVEL::MIDDLE_TOP);
    if (activated_by_main_dude)
        frameGfx = (u8 *) gfx_spike_collectiblesTiles + (sprite_width * sprite_height * (3) / 2);
    else
        frameGfx = (u8 *) gfx_spike_collectiblesTiles + (sprite_width * sprite_height * (2) / 2);

    subSpriteInfo->updateFrame(frameGfx, sprite_width * sprite_height);
    mainSpriteInfo->updateFrame(frameGfx, sprite_width * sprite_height);

}

void Chest::set_position() {

    int main_x, main_y, sub_x, sub_y;
    get_x_y_viewported(&main_x, &main_y, &sub_x, &sub_y);

    mainSpriteInfo->entry->x = main_x;
    mainSpriteInfo->entry->y = main_y;

    subSpriteInfo->entry->x = sub_x;
    subSpriteInfo->entry->y = sub_y;

    mainSpriteInfo->entry->vFlip = false;
    mainSpriteInfo->entry->hFlip = false;

    subSpriteInfo->entry->vFlip = false;
    subSpriteInfo->entry->hFlip = false;

}

Chest::Chest() {
    physical_height = CHEST_PHYSICAL_HEIGHT;
    physical_width = CHEST_PHYSICAL_WIDTH;
    sprite_height = CHEST_SPRITE_HEIGHT;
    sprite_width = CHEST_SPRITE_WIDTH;
    spriteType = SpritesheetType::SPIKES_COLLECTIBLES;
}

void Chest::spawn_treasure() {

    for (int a = 0; a < 4; a++) {
        Moniez *moniez = new Moniez();

        moniez->spriteType = MONIEZ_RUBY;
        moniez->value = 1200;
        moniez->init();
        global::sprites.push_back(moniez);
        moniez->x = x + CHEST_PHYSICAL_WIDTH * 0.5;
        moniez->y = y + CHEST_PHYSICAL_HEIGHT * 0.5;
        moniez->ySpeed = -1.7;

        moniez->collectible_timer = 0;

        if (rand() % 2 == 0)
            moniez->xSpeed = -0.8;
        else
            moniez->xSpeed = 0.8;
    }
}
