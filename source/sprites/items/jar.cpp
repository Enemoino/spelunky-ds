//
// Created by xdbeef on 23.04.18.
//

#include "jar.h"
#include "../moving_object.h"
#include "rock.h"
#include "../../globals_declarations.h"
#include "../../../build/gfx_spike_collectibles.h"
#include "../../collisions/collisions.h"
#include "../../tiles/map_utils.h"


void Jar::draw() {

    if (frame >= 7) {
        mainSpriteInfo->entry->isHidden = true;
        subSpriteInfo->entry->isHidden = true;
        ready_to_dispose = true;
        return;
    }

    if (hold_by_main_dude && global::input_handler->y_key_down && global::input_handler->down_key_held) {
        hold_by_main_dude = false;
        global::main_dude->holding_item = false;
    } else if (!killed && global::input_handler->y_key_down && global::input_handler->down_key_held &&
               /*bottomCollision && */!global::main_dude->holding_item) {

        if (Collisions::checkCollisionWithMainDude(x, y, 8, 8)) {
            hold_by_main_dude = true;
            global::main_dude->holding_item = true;
//            std::cout << "TOOK ITEM";
        }
    }

    if (hold_by_main_dude) {

        y = global::main_dude->y + 6;

        if (global::main_dude->state == 1) {
            x = global::main_dude->x - 2;
        } else
            x = global::main_dude->x + 10;
    }


    if (killed && frame < 7) {

        frameTimer += *global::timer;

        if (frameTimer > 50) {
            frame++;

            frameGfx = (u8 *) gfx_spike_collectiblesTiles + ((frame + 24) * sprite_height * sprite_width / 2);
            subSpriteInfo->updateFrame(frameGfx, sprite_width * sprite_height);
            mainSpriteInfo->updateFrame(frameGfx, sprite_width * sprite_height);

            frameTimer = 0;
        }

    }

    if (xSpeed > 0 || ySpeed > 0) {
        for (int a = 0; a < global::sprites.size(); a++) {
            if ((global::sprites.at(a)->spriteType == SpritesheetType::SNAKE ||
                 global::sprites.at(a)->spriteType == SpritesheetType::BAT ||
                 global::sprites.at(a)->spriteType == SpritesheetType::SPIDER)
                && !global::sprites.at(a)->killed) {
                if (Collisions::checkCollisionBodies(x, y, 8, 8, global::sprites.at(a)->x, global::sprites.at(a)->y, 16,
                                                     16)) {
                    global::sprites.at(a)->kill();
                    killed = true;
                    frame = 1;
                    mainSpriteInfo->entry->isHidden = true;
                    subSpriteInfo->entry->isHidden = true;
                    ready_to_dispose = true;
                    global::killed_npcs.push_back(spriteType);
//                    std::cout<<"HIDDEN";
                }
            }
        }
    }


    int main_x, main_y, sub_x, sub_y;
    get_x_y_viewported(&main_x, &main_y, &sub_x, &sub_y);

    mainSpriteInfo->entry->x = main_x;
    mainSpriteInfo->entry->y = main_y;

    subSpriteInfo->entry->x = sub_x;
    subSpriteInfo->entry->y = sub_y;

    mainSpriteInfo->entry->hFlip = false;
    subSpriteInfo->entry->hFlip = false;

    mainSpriteInfo->entry->vFlip = false;
    subSpriteInfo->entry->vFlip = false;

    if (global::main_dude->using_whip && !killed && global::main_dude->whip->whip_timer > 120) {
        if (Collisions::checkCollisionWithMainDudeWhip(x, y, 8, 8)) {
            killed = true;
//            mainSpriteInfo->entry->isHidden = true;
//            subSpriteInfo->entry->isHidden = true;
//            ready_to_dispose = true;
//            std::cout<<"HIDDEN";
        }
    }

}


void Jar::init() {
    initSprite();
    activated_by_main_dude = true;
}

void Jar::updateSpeed() {

    if (killed)
        return;

    limit_speed(MAX_X_SPEED_JAR, MAX_Y_SPEED_JAR);

    pos_inc_timer += *global::timer;

    bool change_pos = (pos_inc_timer > 15) && !hold_by_main_dude;

    if (change_pos) {
        apply_friction(0.2);
        update_position();
        apply_gravity(GRAVITY_DELTA_SPEED * 0.8);
        pos_inc_timer = 0;

    }
}


void Jar::updateCollisionsMap(int x_current_pos_in_tiles, int y_current_pos_in_tiles) {

    MapTile *tiles[9];
    Collisions::getNeighboringTiles(global::level_generator->map_tiles, x_current_pos_in_tiles, y_current_pos_in_tiles,
                                    tiles);

    bottomCollision = Collisions::checkBottomCollision(tiles, &x, &y, &ySpeed, physical_width, physical_height, true);
    leftCollision = Collisions::checkLeftCollision(tiles, &x, &y, &xSpeed, physical_width, physical_height, true);
    rightCollision = Collisions::checkRightCollision(tiles, &x, &y, &xSpeed, physical_width, physical_height, true);
    upperCollision = Collisions::checkUpperCollision(tiles, &x, &y, &ySpeed, physical_width, true);

    if ((abs(xSpeed) > 1 || abs(ySpeed) > 1) &&
        (bottomCollision || leftCollision || rightCollision || upperCollision)) {
        killed = true;
        mainSpriteInfo->entry->isHidden = true;
        subSpriteInfo->entry->isHidden = true;
        ready_to_dispose = true;
    }

}

void Jar::initSprite() {
    subSpriteInfo = global::sub_oam_manager->initSprite(gfx_spike_collectiblesPal, gfx_spike_collectiblesPalLen,
                                                        nullptr, sprite_width * sprite_height, 16, JAR, true, false,
                                                        LAYER_LEVEL::MIDDLE_TOP);
    mainSpriteInfo = global::main_oam_manager->initSprite(gfx_spike_collectiblesPal, gfx_spike_collectiblesPalLen,
                                                          nullptr, sprite_width * sprite_height, 16, JAR, true, false,
                                                          LAYER_LEVEL::MIDDLE_TOP);


    frameGfx = (u8 *) gfx_spike_collectiblesTiles + ((24 * sprite_height * sprite_width) / 2);
    subSpriteInfo->updateFrame(frameGfx, sprite_width * sprite_height);
    mainSpriteInfo->updateFrame(frameGfx, sprite_width * sprite_height);

}

Jar::Jar() {
    physical_height = JAR_PHYSICAL_HEIGHT;
    physical_width = JAR_PHYSICAL_WIDTH;
    sprite_height = JAR_SPRITE_HEIGHT;
    sprite_width = JAR_SPRITE_WIDTH;
    spriteType = SpritesheetType::JAR;
}

void Jar::kill() {
    killed = true;
}