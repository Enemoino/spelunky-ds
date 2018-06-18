//
// Created by xdbeef on 25.05.18.
//

#include <iostream>
#include "shopkeeper.h"
#include "../../globals_declarations.h"
#include "../../collisions/collisions.h"
#include "../../tiles/tile_orientation.h"
#include "../../../build/gfx_shopkeeper.h"

#define SHOPKEEPER_SPRITESHEET_OFFSET 0
#define SHOPKEEPER_POS_INC_DELTA 18
#define SHOPKEEPER_TRIGGERED_SPEED 3
#define SHOPKEEPER_ANIM_FRAME_DELTA 65
#define SHOPKEEPER_INVERT_SPEED_DELTA 100

//todo odwracanie w zależności od tego czy in_bounds + od której strony jest main_dude + podbieganie
//todo triggerowanie w zależności od tego czy !in_bounds + czy trzyma niesprzedany przedmiot
//todo spawnowanie shotguna i logika strzelania sobie + jeśli shotgun wypadnie z rąk to podniesienie w kontakcie
//todo dodać do bulletów żeby dawały dmg do main_dude <- przetestować
//todo logika biegania lewo-prawo przy triggerowaniu

//todo dodać do każdego itemu to samo co przy glove <- dodane, spróbować ubrać to jakoś w klasę abstrakcyjną
//żeby nie powtarzać kodu

void Shopkeeper::draw() {

    check_if_dude_in_shop_bounds();

    invert_speed_timer += *global::timer;
    blood_spawn_timer += *global::timer;

    if (sprite_state == SpriteState::W_LEFT) {
        mainSpriteInfo->entry->hFlip = false;
        subSpriteInfo->entry->hFlip = false;
    } else if (sprite_state == SpriteState::W_RIGHT) {
        mainSpriteInfo->entry->hFlip = true;
        subSpriteInfo->entry->hFlip = true;
    }

    mainSpriteInfo->entry->isHidden = false;
    subSpriteInfo->entry->isHidden = false;
    mainSpriteInfo->entry->vFlip = false;
    subSpriteInfo->entry->vFlip = false;

    if (stunned || killed)
        check_if_can_be_pickuped();

    set_pickuped_position(6, -2);

    if (hold_by_main_dude) {

        if (!killed)
            global::main_dude->carrying_damsel = true;

        if (global::main_dude->killed) {
            hold_by_main_dude = false;
            stunned = true;
            stunned_timer = 0;
        } else
            stunned = false;

        sprite_state = global::main_dude->state;
        mainSpriteInfo->entry->priority = OBJPRIORITY_0;
        subSpriteInfo->entry->priority = OBJPRIORITY_0;

    } else {
        mainSpriteInfo->entry->priority = OBJPRIORITY_2;
        subSpriteInfo->entry->priority = OBJPRIORITY_2;
    }

    if (!hold_by_main_dude)
        kill_mobs_if_thrown(1);

    if (bottomCollision && (stunned || killed) && !triggered) {
        apply_friction(0.5f);
    }

    set_position();

    anim_frame_timer += *global::timer;

    if (anim_frame_timer > SHOPKEEPER_ANIM_FRAME_DELTA) {
        update_animation();
    }

    make_some_movement();

    if (stunned) {
        stunned_timer += *global::timer;
        if (stunned_timer > SHOPKEEPER_STUN_TIME) {
            stunned = false;
            stunned_timer = 0;
        }
    }

}


void Shopkeeper::init() {


    sprite_state = SpriteState::W_LEFT;
    activated_by_main_dude = true;
    initSprite();

    frameGfx = (u8 *) gfx_shopkeeperTiles;
    subSpriteInfo->updateFrame(frameGfx, sprite_width * sprite_height);
    mainSpriteInfo->updateFrame(frameGfx, sprite_width * sprite_height);

    spriteType = SpritesheetType::SHOPKEEPER;

    randomizeMovement();
}

void Shopkeeper::randomizeMovement() {

    int r = rand() % 2;

    if (r == 0) {
        sprite_state = SpriteState::W_LEFT;

    } else if (r == 1) {
        if (sprite_state == SpriteState::W_RIGHT)
            sprite_state = SpriteState::W_RIGHT;
    }

    go_timer = (rand() % (1 * 2000)) + 1000;

    waitTimer = rand() % 1500;
}

void Shopkeeper::updateSpeed() {

    limit_speed(MAX_X_SPEED_SHOPKEEPER, MAX_Y_SPEED_SHOPKEEPER);

    pos_inc_timer += *global::timer;

    if (pos_inc_timer > SHOPKEEPER_POS_INC_DELTA) {
        update_position();
        apply_gravity(GRAVITY_DELTA_SPEED * 1.5);
        pos_inc_timer = 0;
    }

}

void Shopkeeper::updateCollisionsMap(int x_current_pos_in_tiles, int y_current_pos_in_tiles) {

    MapTile *tiles[9] = {};
    Collisions::getNeighboringTiles(global::level_generator->map_tiles, x_current_pos_in_tiles,
                                    y_current_pos_in_tiles, tiles);


    bool bounce = (stunned || killed);

    standingOnLeftEdge = Collisions::isStandingOnLeftEdge(tiles, x, physical_width, x_current_pos_in_tiles);
    standingOnRightEdge = Collisions::isStandingOnRightEdge(tiles, x, physical_width, x_current_pos_in_tiles);
    bottomCollision = Collisions::checkBottomCollision(tiles, &x, &y, &ySpeed, physical_width, physical_height,
                                                       bounce, BOUNCING_FACTOR_Y);
    leftCollision = Collisions::checkLeftCollision(tiles, &x, &y, &xSpeed, physical_width, physical_height, bounce,
                                                   BOUNCING_FACTOR_X);
    rightCollision = Collisions::checkRightCollision(tiles, &x, &y, &xSpeed, physical_width, physical_height,
                                                     bounce, BOUNCING_FACTOR_X);
    upperCollision = Collisions::checkUpperCollision(tiles, &x, &y, &ySpeed, physical_width, false, 0);


    if (stunned || killed)
        return;

    if (bottomCollision && tiles[TileOrientation::RIGHT_MIDDLE] != nullptr &&
        tiles[TileOrientation::RIGHT_MIDDLE]->collidable &&
        tiles[TileOrientation::LEFT_MIDDLE] != nullptr && tiles[TileOrientation::LEFT_MIDDLE]->collidable) {
        ySpeed = -2.6 - ((rand() % 10) / 5);
        landlocked = true;
    } else
        landlocked = false;

    if (!bottomCollision) {

        if (((tiles[1] == nullptr || !tiles[1]->collidable) && (tiles[6] != nullptr && tiles[8] != nullptr))) {
            if (xSpeed > 0)
                x += 2;
        }

        if (((tiles[0] == nullptr || !tiles[0]->collidable) && (tiles[5] != nullptr && tiles[7] != nullptr))) {
            if (xSpeed < 0)
                x -= 2;
        }

    }

}

void Shopkeeper::apply_dmg(int dmg_to_apply) {

    if (dmg_to_apply == 0 || dmg_to_apply == 1) {
        return;
    }

    hitpoints -= dmg_to_apply;

    if (blood_spawn_timer > 1000) {
        if (!killed)
            spawn_blood();
        blood_spawn_timer = 0;
        ySpeed = -2.5;
    }

    if (killed)
        return;

    if (hitpoints <= 0) {
        killed = true;
        stunned = false;
        global::killed_npcs.push_back(spriteType);
    } else {
        stunned = true;
    }

}

void Shopkeeper::initSprite() {
    subSpriteInfo = global::sub_oam_manager->initSprite(gfx_shopkeeperPal, gfx_shopkeeperPalLen,
                                                        nullptr, sprite_width * sprite_height, 16, SHOPKEEPER,
                                                        true,
                                                        false,
                                                        LAYER_LEVEL::MIDDLE_BOT);
    mainSpriteInfo = global::main_oam_manager->initSprite(gfx_shopkeeperPal, gfx_shopkeeperPalLen,
                                                          nullptr, sprite_width * sprite_height, 16, SHOPKEEPER,
                                                          true,
                                                          false, LAYER_LEVEL::MIDDLE_BOT);

    frameGfx = (u8 *) gfx_shopkeeperTiles +
               ((sprite_width * sprite_height * (SHOPKEEPER_SPRITESHEET_OFFSET + 31)) / 2);

    subSpriteInfo->entry->isHidden = false;
    mainSpriteInfo->entry->isHidden = false;

    int main_x, main_y, sub_x, sub_y;
    get_x_y_viewported(&main_x, &main_y, &sub_x, &sub_y);

    set_position();

    if (sprite_state == SpriteState::W_LEFT) {
        mainSpriteInfo->entry->vFlip = false;
        subSpriteInfo->entry->vFlip = false;
    } else if (sprite_state == SpriteState::W_RIGHT) {
        mainSpriteInfo->entry->vFlip = true;
        subSpriteInfo->entry->vFlip = true;
    }


}

void Shopkeeper::set_position() {

    int main_x, main_y, sub_x, sub_y;
    get_x_y_viewported(&main_x, &main_y, &sub_x, &sub_y);

    mainSpriteInfo->entry->x = main_x;
    mainSpriteInfo->entry->y = main_y;

    subSpriteInfo->entry->x = sub_x;
    subSpriteInfo->entry->y = sub_y;

    int temp_y = y;
    y -= 13 + (anim_frame * 0.5);

    get_x_y_viewported(&main_x, &main_y, &sub_x, &sub_y);

    y = temp_y;

}

Shopkeeper::Shopkeeper() {
    physical_height = SHOPKEEPER_PHYSICAL_HEIGHT;
    physical_width = SHOPKEEPER_PHYSICAL_WIDTH;
    sprite_height = SHOPKEEPER_SPRITE_HEIGHT;
    sprite_width = SHOPKEEPER_SPRITE_WIDTH;
    hitpoints = SHOPKEEPER_HITPOINTS;
}


void Shopkeeper::make_some_movement() {

    if (killed || stunned)
        return;

    if (waitTimer > 0 && !triggered) {
        waitTimer -= *global::timer;
    } else {

        if (go_timer > 0)
            go_timer -= *global::timer;

        if (triggered) {
            if (sprite_state == SpriteState::W_RIGHT)
                xSpeed = SHOPKEEPER_TRIGGERED_SPEED;
            else
                xSpeed = -SHOPKEEPER_TRIGGERED_SPEED;
        }

        if (go_timer <= 0 && !triggered) {
            randomizeMovement();
            xSpeed = 0;
        }

        if (invert_speed_timer < SHOPKEEPER_INVERT_SPEED_DELTA)
            return;

        invert_speed_timer = 0;

        if ((standingOnLeftEdge || standingOnRightEdge) && !triggered) {
            if (rand() % 2 == 0) {
                go_timer = 0;
            } else
                xSpeed *= -1;

        }

        if ((leftCollision || rightCollision) && !landlocked) {

            if (sprite_state == SpriteState::W_LEFT)
                sprite_state = SpriteState::W_RIGHT;
            else
                sprite_state = SpriteState::W_LEFT;

            xSpeed *= -1;
            rightCollision = false;
            leftCollision = false;
        }

    }

}

void Shopkeeper::check_if_can_be_triggered() {}

void Shopkeeper::apply_stunned_carried_sprites() {

    anim_frame = 0;
    frameGfx =
            (u8 *) gfx_shopkeeperTiles + ((sprite_width * sprite_height * (SHOPKEEPER_SPRITESHEET_OFFSET + 4)) / 2);
}

void Shopkeeper::apply_dead_carried_sprites() {
    anim_frame = 0;
    frameGfx =
            (u8 *) gfx_shopkeeperTiles + ((sprite_width * sprite_height * (SHOPKEEPER_SPRITESHEET_OFFSET + 0)) / 2);
}

void Shopkeeper::apply_dead_sprites() {
    anim_frame = 0;
    if (ySpeed == 0)
        frameGfx =
                (u8 *) gfx_shopkeeperTiles + ((sprite_width * sprite_height * (1)) / 2);
    else if (ySpeed > 0)
        frameGfx =
                (u8 *) gfx_shopkeeperTiles +
                ((sprite_width * sprite_height * (SHOPKEEPER_SPRITESHEET_OFFSET + 3)) / 2);
    else
        frameGfx =
                (u8 *) gfx_shopkeeperTiles +
                ((sprite_width * sprite_height * (SHOPKEEPER_SPRITESHEET_OFFSET + 3)) / 2);

}


void Shopkeeper::apply_walking_sprites() {

    if (anim_frame >= 6)
        anim_frame = 0;

    if (xSpeed == 0 && ySpeed == 0)
        frameGfx = (u8 *) gfx_shopkeeperTiles +
                   ((sprite_width * sprite_height * (SHOPKEEPER_SPRITESHEET_OFFSET + 24)) / 2);
    else if (xSpeed != 0 && ySpeed == 0) {
        frameGfx = (u8 *) gfx_shopkeeperTiles +
                   ((sprite_width * sprite_height * (SHOPKEEPER_SPRITESHEET_OFFSET + anim_frame + 12)) / 2);
    } else {
        frameGfx = (u8 *) gfx_shopkeeperTiles +
                   ((sprite_width * sprite_height * (SHOPKEEPER_SPRITESHEET_OFFSET + 3)) / 2);

    }

}

void Shopkeeper::apply_stunned_sprites() {

    if (anim_frame >= 6)
        anim_frame = 0;

    if (ySpeed == 0)
        frameGfx = (u8 *) gfx_shopkeeperTiles +
                   ((sprite_width * sprite_height * (SHOPKEEPER_SPRITESHEET_OFFSET + anim_frame + 18)) / 2);
    else if (ySpeed > 0)
        frameGfx =
                (u8 *) gfx_shopkeeperTiles +
                ((sprite_width * sprite_height * (SHOPKEEPER_SPRITESHEET_OFFSET + 4)) / 2);
    else
        frameGfx =
                (u8 *) gfx_shopkeeperTiles +
                ((sprite_width * sprite_height * (SHOPKEEPER_SPRITESHEET_OFFSET + 2)) / 2);
}


void Shopkeeper::update_animation() {
    anim_frame++;

    if (stunned && !hold_by_main_dude)
        apply_stunned_sprites();
    else if (hold_by_main_dude)
        apply_dead_carried_sprites();
    else if (killed)
        apply_dead_sprites();
    else
        apply_walking_sprites();

    subSpriteInfo->updateFrame(frameGfx, sprite_width * sprite_height);
    mainSpriteInfo->updateFrame(frameGfx, sprite_width * sprite_height);
    anim_frame_timer = 0;

}

void Shopkeeper::set_shop_bounds() {

    //based on init position and constant shop layout defined in shops.h
    //right: X + 3*TILE_W
    //left: X - 7*TILE_W
    //up: y - 8*TILE_H
    //down: y + 2*TILE_H


    MapTile *shop_sign = nullptr;
    global::level_generator->get_first_tile(MapTileType::SHOP_SIGN_RARE, shop_sign);

    int tile_x = shop_sign->x * TILE_W;

    shop_bounds_up_y_px = y - (8 * TILE_H);
    shop_bounds_down_y_px = y + (2 * TILE_H);

    if (x - tile_x > 0) {
        //left oriented shop
        shop_bounds_right_x_px = x + (3 * TILE_W);
        shop_bounds_left_x_px = x - (6 * TILE_W);
    } else {
        shop_bounds_left_x_px = x - (3 * TILE_W);
        shop_bounds_right_x_px = x + (6 * TILE_W);
    }

}


//done
void Shopkeeper::check_if_dude_in_shop_bounds() {


    if (global::main_dude->x < shop_bounds_right_x_px && global::main_dude->x > shop_bounds_left_x_px &&
        global::main_dude->y > shop_bounds_up_y_px && global::main_dude->y < shop_bounds_down_y_px) {

        if (!introduced_shop_name) {
            global::hud->disable_all_prompts();
            global::hud->introduce_shop = true;
            global::hud->shop_name = "\n\n\n\nWELCOME TO SMITHY'S SUPPLY SHOP!";
            global::hud->draw();
            introduced_shop_name = true;
        }

    } else if (global::hud->holding_item_shopping) {
        triggered = true;
        de_shopify_all_items();
    }
}

void Shopkeeper::de_shopify_all_items() {
    for (int a = 0; a < 4; a++) {
        if (shop_items[a] != nullptr)
            shop_items[a]->bought = true;
    }
}