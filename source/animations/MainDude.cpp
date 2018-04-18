//
// Created by xdbeef on 24.02.18.
//

#include <nds.h>
#include <nds/arm9/sprite.h>
#include <iostream>
#include "MainDude.h"
#include "../Globals.h"
#include "Collisions.h"
#include "../level_layout/MapUtils.h"
#include "../../build/spelunker.h"
#include "../../build/whip_left.h"
#include "../../build/pre_whip_left.h"

void MainDude::handleKeyInput() {

    if (!stunned) {
        if (global::input_handler->r_bumper_down) {
            if (bottomCollision) {
                ySpeed = -MAIN_DUDE_JUMP_SPEED;
            }
            if ((hangingOnTileLeft || hangingOnTileRight) && hangingTimer > MIN_HANGING_TIME) {
                ySpeed = -MAIN_DUDE_JUMP_SPEED;
                hangingOnTileLeft = false;
                hangingOnTileRight = false;
                hangingTimer = 0;
            }
        }
        if (global::input_handler->l_bumper_down) {
            if (!stunned && !whip) {
                if (holding_item) {

                    //throw holding item

                    for (int a = 0; a < global::sprites.size(); a++) {
                        if (global::sprites.at(a)) {
                            if ((*global::sprites.at(a)).hold_by_main_dude) {

                                if (state == 1)
                                    (*global::sprites.at(a)).xSpeed = -3;
                                else
                                    (*global::sprites.at(a)).xSpeed = 3;

                                (*global::sprites.at(a)).ySpeed = -1;

                                (*global::sprites.at(a)).hold_by_main_dude = false;
                            }
                        }
                    }


                    holding_item = false;
                } else {
                    whip = true;
                    animFrame = 0;
                }
            }
        }
        if (global::input_handler->x_key_down && !holding_item) {
            //make new bomb object

            Bomb *bomb = new Bomb();
            bomb->init();
            bomb->xSpeed = 3;
            bomb->timer = timer;
            bomb->hold_by_main_dude = true;

            global::sprites.push_back(bomb);
            holding_item = true;
        }

        if (global::input_handler->y_key_down && !holding_item && global::input_handler->down_key_held) {
            //take item from the ground
            holding_item = true;
        }


    }
    if (!stunned) {

        if (global::input_handler->left_key_held) {
            state = W_LEFT;
            hangingOnTileLeft = false;
            if (xSpeed > -MAIN_DUDE_MAX_X_SPEED && !(hangingOnTileRight || hangingOnTileLeft))
                if (speedIncTimer > X_SPEED_DELTA_TIME_MS) {
                    xSpeed -= X_SPEED_DELTA_VALUE;
                    speedIncTimer = 0;
                }
        }
        if (global::input_handler->right_key_held) {
            state = W_RIGHT;
            hangingOnTileRight = false;
            if (xSpeed < MAIN_DUDE_MAX_X_SPEED && !(hangingOnTileRight || hangingOnTileLeft)) {
                if (speedIncTimer > X_SPEED_DELTA_TIME_MS) {
                    xSpeed += X_SPEED_DELTA_VALUE;
                    speedIncTimer = 0;
                }
            }
        }

        if (global::input_handler->down_key_held) {
            hangingOnTileLeft = false;
            hangingOnTileRight = false;
            if (bottomCollision)
                crawling = true;
        } else
            crawling = false;
    } else
        crawling = false;

}


void MainDude::updateTimers() {

    posIncTimer += *timer;
    frictionTimer += *timer;
    speedIncTimer += *timer;
    hangingTimer += *timer;

    if (whip) {
        whip_timer += *timer;
        if (whip_timer > 420 + 0 * 70) {
            whip_timer = 0;
            whip = false;
            sub_whip->entry->isHidden = true;
            main_whip->entry->isHidden = true;
            sub_pre_whip->entry->isHidden = true;
            main_pre_whip->entry->isHidden = true;
        }
    }

    if (animationFrameTimer > 65) {

        animationFrameTimer = 0;

        if (!whip || (whip && animFrame < 5))
            animFrame++;

    }

    if (!global::input_handler->left_key_held && pushing_left) {
        pushing_left = false;
        pushingTimer = 0;
    }
    if (!global::input_handler->right_key_held && pushing_right) {
        pushing_right = false;
        pushingTimer = 0;
    }

    if ((leftCollision || rightCollision) && !crawling && !hangingOnTileLeft && !hangingOnTileRight &&
        (global::input_handler->left_key_held || global::input_handler->right_key_held)) {
        pushingTimer += *timer;
        if (pushingTimer > PUSHING_TIME) {
            if (leftCollision) {
                pushing_right = true;
                pushingTimer = 0;
            } else {
                pushing_left = true;
                pushingTimer = 0;
            }
        }

    } else {
        pushingTimer = 0;
        pushing_left = false;
        pushing_right = false;
    }

    if (animFrame >= FRAMES_PER_ANIMATION && !crawling && !pushing_left && !pushing_right)
        animFrame = 0;

    if (animFrame >= 9 && crawling)
        animFrame = 0;

    if ((pushing_left || pushing_right) && animFrame >= 7)
        animFrame = 0;


    if (!bottomCollision && !hangingOnTileLeft && !hangingOnTileRight)
        jumpingTimer += *timer;

    if (bottomCollision && jumpingTimer > STUN_FALLING_TIME) {
        stunned = true;
        jumpingTimer = 0;
    } else if (bottomCollision && jumpingTimer < STUN_FALLING_TIME) {
        jumpingTimer = 0;
    }

    if (stunned)
        stunnedTimer += *timer;
    if (stunnedTimer > STUN_TIME) {
        stunned = false;
        stunnedTimer = 0;
    }


    if (xSpeed != 0 || stunned || whip || (pushing_left || pushing_right))
        animationFrameTimer += *timer;


    if (!bottomCollision)
        crawling = false;

}


void MainDude::updateSpeed() {

    if (crawling) {

        if (xSpeed > MAIN_DUDE_MAX_X_SPEED_CRAWLING)
            xSpeed = MAIN_DUDE_MAX_X_SPEED_CRAWLING;
        if (xSpeed < -MAIN_DUDE_MAX_X_SPEED_CRAWLING)
            xSpeed = -MAIN_DUDE_MAX_X_SPEED_CRAWLING;

    } else {
        if (xSpeed > MAIN_DUDE_MAX_X_SPEED)
            xSpeed = MAIN_DUDE_MAX_X_SPEED;
        if (xSpeed < -MAIN_DUDE_MAX_X_SPEED)
            xSpeed = -MAIN_DUDE_MAX_X_SPEED;
    }

    if (ySpeed > MAIN_DUDE_MAX_Y_SPEED)
        ySpeed = MAIN_DUDE_MAX_Y_SPEED;
    if (ySpeed < -MAIN_DUDE_MAX_Y_SPEED)
        ySpeed = -MAIN_DUDE_MAX_Y_SPEED;

    if (frictionTimer > FRICTION_DELTA_TIME_MS) {
        frictionTimer = 0;
        if (xSpeed > 0) {
            xSpeed -= FRICTION_DELTA_SPEED;
            if (xSpeed < 0)
                xSpeed = 0;
        }
        if (xSpeed < 0) {
            xSpeed += FRICTION_DELTA_SPEED;
            if (xSpeed > 0)
                xSpeed = 0;
        }
    }


    bool change_pos = (crawling && posIncTimer > 20) || (!crawling && posIncTimer > 10);


    if (change_pos) {
        updatePosition();
        posIncTimer = 0;

        if (!bottomCollision && !(hangingOnTileLeft || hangingOnTileRight))
            ySpeed += GRAVITY_DELTA_SPEED;
    }


}


void MainDude::updateCollisionsMap(int x_current_pos_in_tiles, int y_current_pos_in_tiles) {

    MapTile *tiles[9];
    Collisions::getNeighboringTiles(global::level_generator->mapTiles, x_current_pos_in_tiles, y_current_pos_in_tiles,
                                    tiles);

    bottomCollision = Collisions::checkBottomCollision(tiles, &this->x, &this->y, &ySpeed, 16, 16, false);
    leftCollision = Collisions::checkLeftCollision(tiles, &this->x, &this->y, &xSpeed, 16, 16, false);
    rightCollision = Collisions::checkRightCollision(tiles, &this->x, &this->y, &xSpeed, 16, 16, false);
    upperCollision = Collisions::checkUpperCollision(tiles, &this->x, &this->y, &ySpeed, 16, false);
    Collisions::isStandingOnEdge(tiles, &
            this->x, &this->y, &ySpeed, 16, 16);


    canHangOnTile(tiles);

    if (upperCollision || bottomCollision) {
        hangingOnTileLeft = false;
        hangingOnTileRight = false;
    }


    if (!bottomCollision) {
        if ((tiles[1] == 0 && (tiles[6] != 0 && tiles[8] != 0))) {
            if (xSpeed > 0)
                x += 2;
        }
        if ((tiles[0] == 0 && (tiles[5] != 0 && tiles[7] != 0))) {
            if (xSpeed < 0)
                x -= 2;
        }
    }

}

void MainDude::init() {

    main_spelunker = global::main_oam_manager->initSprite(spelunkerPal, spelunkerPalLen, spelunkerTiles,
                                                          spelunkerTilesLen, 16, MAIN_DUDE);

    main_pre_whip = global::main_oam_manager->initSprite(pre_whip_leftPal, pre_whip_leftPalLen,
                                                         pre_whip_leftTiles, pre_whip_leftTilesLen, 16, PRE_WHIP);

    main_whip = global::main_oam_manager->initSprite(whip_leftPal, whip_leftPalLen,
                                                     whip_leftTiles, whip_leftTilesLen, 16, WHIP);

    sub_spelunker = global::sub_oam_manager->initSprite(spelunkerPal, spelunkerPalLen, spelunkerTiles,
                                                        spelunkerTilesLen, 16, MAIN_DUDE);
    sub_pre_whip = global::sub_oam_manager->initSprite(pre_whip_leftPal, pre_whip_leftPalLen,
                                                       pre_whip_leftTiles, pre_whip_leftTilesLen, 16, PRE_WHIP);
    sub_whip = global::sub_oam_manager->initSprite(whip_leftPal, whip_leftPalLen,
                                                   whip_leftTiles, whip_leftTilesLen, 16, WHIP);


    frameGfx = (u8 *) spelunkerTiles;
    sub_whip->entry->isHidden = true;
    main_whip->entry->isHidden = true;
    sub_pre_whip->entry->isHidden = true;
    main_pre_whip->entry->isHidden = true;
}

//todo split
void MainDude::draw() {

    int main_x = x - global::camera->x;
    int main_y = y - global::camera->y;
    int sub_x = x - global::camera->x;
    int sub_y = y - global::camera->y - 192;

    if (this->y > 320) {
        main_x = -16;
        main_y = -16;
    }

    if (this->y < 320) {
        sub_x = -16;
        sub_y = -16;
    }

    main_spelunker->entry->x = main_x;
    main_spelunker->entry->y = main_y;

    sub_spelunker->entry->x = sub_x;
    sub_spelunker->entry->y = sub_y;

    int frame;
    u8 *offset;

    if (whip) {

        sub_pre_whip->entry->y = sub_y - 2;
        main_pre_whip->entry->y = main_y - 2;
        sub_whip->entry->y = sub_y;
        main_whip->entry->y = main_y;

        if (whip_timer > 100 && whip_timer < 180) {
            main_pre_whip->entry->isHidden = false;
            sub_pre_whip->entry->isHidden = false;
        } else if (whip_timer >= 220) {
            main_pre_whip->entry->isHidden = true;
            sub_pre_whip->entry->isHidden = true;
            main_whip->entry->isHidden = false;
            sub_whip->entry->isHidden = false;
        }

        if (state == 1) {

            main_whip->entry->hFlip = true;
            sub_whip->entry->hFlip = true;
            main_pre_whip->entry->hFlip = true;
            sub_pre_whip->entry->hFlip = true;

            sub_pre_whip->entry->x = sub_x + 8;
            main_pre_whip->entry->x = main_x + 8;
            sub_whip->entry->x = sub_x - 12;
            main_whip->entry->x = main_x - 12;

        } else {

            main_whip->entry->hFlip = false;
            sub_whip->entry->hFlip = false;
            main_pre_whip->entry->hFlip = false;
            sub_pre_whip->entry->hFlip = false;

            sub_pre_whip->entry->x = sub_x - 8;
            main_pre_whip->entry->x = main_x - 8;
            main_whip->entry->x = main_x + 8;
            sub_whip->entry->x = sub_x + 8;
        }

    }
    if (stunned) {
        if (animFrame > 4)
            animFrame = 0;

        frame = (3 * SPRITESHEET_ROW_WIDTH) + animFrame;
        offset = frameGfx + frame * MAIN_DUDE_WIDTH * MAIN_DUDE_HEIGHT / 2;
        main_spelunker->updateFrame(offset);
        sub_spelunker->updateFrame(offset);
    } else if (pushing_left || pushing_right) {

        if (pushing_left)
            frame = animFrame + (7) * SPRITESHEET_ROW_WIDTH;
        else
            frame = animFrame + (8) * SPRITESHEET_ROW_WIDTH + 1;


        offset = frameGfx + frame * MAIN_DUDE_WIDTH * MAIN_DUDE_HEIGHT / 2;
        main_spelunker->updateFrame(offset);
        sub_spelunker->updateFrame(offset);

    } else if (whip) {

        if (state == 1) {
            frame = (9 * SPRITESHEET_ROW_WIDTH) + 2 + animFrame;
            offset = frameGfx + frame * MAIN_DUDE_WIDTH * MAIN_DUDE_HEIGHT / 2;
        } else if (state == 0) {
            frame = (10 * SPRITESHEET_ROW_WIDTH) + 2 + animFrame;
            offset = frameGfx + frame * MAIN_DUDE_WIDTH * MAIN_DUDE_HEIGHT / 2;
        }

        main_spelunker->updateFrame(offset);
        sub_spelunker->updateFrame(offset);
    } else if (hangingOnTileRight) {
        frame = (2 * SPRITESHEET_ROW_WIDTH) + 1;
        offset = frameGfx + frame * MAIN_DUDE_WIDTH * MAIN_DUDE_HEIGHT / 2;
        main_spelunker->updateFrame(offset);
        sub_spelunker->updateFrame(offset);
    } else if (hangingOnTileLeft) {
        frame = (2 * SPRITESHEET_ROW_WIDTH);
        offset = frameGfx + frame * MAIN_DUDE_WIDTH * MAIN_DUDE_HEIGHT / 2;
        main_spelunker->updateFrame(offset);
        sub_spelunker->updateFrame(offset);
    } else if (crawling) {
        //left
        if (state == 1)
            frame = animFrame + (4) * SPRITESHEET_ROW_WIDTH;
        else
            frame = animFrame + (5) * SPRITESHEET_ROW_WIDTH + 3;


        offset = frameGfx + frame * MAIN_DUDE_WIDTH * MAIN_DUDE_HEIGHT / 2;
        main_spelunker->updateFrame(offset);
        sub_spelunker->updateFrame(offset);
    } else if (!bottomCollision) {

        if (state == 1) {
            frame = state * FRAMES_PER_ANIMATION;
            offset = frameGfx + frame * MAIN_DUDE_WIDTH * MAIN_DUDE_HEIGHT / 2;
        } else if (state == 0) {
            frame = state * FRAMES_PER_ANIMATION;
            offset = frameGfx + frame * MAIN_DUDE_WIDTH * MAIN_DUDE_HEIGHT / 2;
        }
        main_spelunker->updateFrame(offset);
        sub_spelunker->updateFrame(offset);

    } else {
        if (abs(xSpeed) != 0) {
            frame = animFrame + state * FRAMES_PER_ANIMATION;
            offset = frameGfx + frame * MAIN_DUDE_WIDTH * MAIN_DUDE_HEIGHT / 2;
        } else {
            if (state == 1) {
                frame = (2 * SPRITESHEET_ROW_WIDTH) + 2;
                offset = frameGfx + frame * MAIN_DUDE_WIDTH * MAIN_DUDE_HEIGHT / 2;
            } else if (state == 0) {
                frame = (2 * SPRITESHEET_ROW_WIDTH) + 3;
                offset = frameGfx + frame * MAIN_DUDE_WIDTH * MAIN_DUDE_HEIGHT / 2;
            }

        }
        main_spelunker->updateFrame(offset);
        sub_spelunker->updateFrame(offset);
    }

}

void MainDude::canHangOnTile(MapTile *neighboringTiles[9]) {

    if (bottomCollision || (!leftCollision && !rightCollision))
        return;

    if (neighboringTiles[2] != 0 || neighboringTiles[3] != 0)
        return;

    bool y_bound = false;
    bool x_bound = false;

    if (rightCollision && state == W_LEFT) {

        if (neighboringTiles[5] != 0)
            return;

        x_bound = (this->x <= (neighboringTiles[0]->x * 16) + 16 && (this->x >= (neighboringTiles[0]->x * 16) + 12));
        y_bound = (this->y > (neighboringTiles[0]->y * 16) - 2) && (this->y < (neighboringTiles[0]->y * 16) + 8);
    } else if (leftCollision && state == W_RIGHT) {

        if (neighboringTiles[6] != 0)
            return;

        y_bound = (this->y > (neighboringTiles[1]->y * 16) - 2) && (this->y < (neighboringTiles[1]->y * 16) + 8);
        x_bound = (this->x <= (neighboringTiles[1]->x * 16) - 12 && (this->x >= (neighboringTiles[1]->x * 16) - 16));
    }

    if ((y_bound && x_bound) && hangingTimer > MIN_HANGING_TIME) {
        hangingTimer = 0;
        ySpeed = 0;

//        fprintf(stdout, "HANGING" + '\n');

        if (rightCollision) {
            this->y = (neighboringTiles[0]->y * 16);
            hangingOnTileRight = true;
        }
        if (leftCollision) {
            hangingOnTileLeft = true;
            this->y = (neighboringTiles[1]->y * 16);
        }
    }

}

void MainDude::updateOther() {
}

void MainDude::updatePosition() {

    double tempXspeed = abs(xSpeed);
    double tempYspeed = abs(ySpeed);

    int old_xx = -1;
    int old_yy = -1;
    int xx;
    int yy;

    while (tempXspeed > 0 || tempYspeed > 0) {
        if (tempXspeed > 0) {
            if (xSpeed > 0) {
                x += 1;
            } else if (xSpeed < 0) {
                x -= 1;
            }
        }
        if (tempYspeed > 0) {
            if (ySpeed > 0)
                y += 1;
            else if (ySpeed < 0)
                y -= 1;
        }



//            Collisions::getCenterTile(this->x, this->y, MAIN_DUDE_HEIGHT, MAIN_DUDE_WIDTH, xx, yy);
//fixme

        xx = floor_div(this->x + 0.5 * MAIN_DUDE_WIDTH, 16);
        yy = floor_div(this->y + 0.5 * MAIN_DUDE_HEIGHT, 16);

        if (old_xx != xx || old_yy != yy) {
            updateCollisionsMap(xx, yy);
        }

        old_xx = xx;
        old_yy = yy;

        tempXspeed--;
        tempYspeed--;

    }
}

