//
// Created by xdbeef on 18.03.18.
//
// TODO Add b64 encoded illustration for the following collisions.
#include <iostream>
#include "Collisions.h"
#include "MainDude.h"
#include "../level_layout/MapUtils.h"

#define TILE_H 16
#define TILE_W 16

//(TILE_W * a), (TILE_H * b) makes x,y point placed in the left-upper corner of the tile from passed *mapTiles[a][b].
//Sprite's x,y positions that are given to the following functions are expected to be upper-left corner.
//The x,y coordinates go from up to down on the y's, and from left to right on the x's - (0,0) is upper-left corner of
//the map.

//Collision from upper side of the tile, with rectangle given by x,y, and width.
bool Collisions::checkUpperCollision(MapTile *neighboringTiles[9], int *xPos, int *yPos, double *ySpeed, int width) {

    int dude_tile_x = floor_div(*xPos, 16);
    int dude_tile_y = floor_div(*yPos, 16);

    bool upperCollision = false;
    bool w1 = false;
    bool w2 = false;

    for (int a = 0; a < 9; a++) {

        if (&neighboringTiles[a] == 0 /*|| !neighboringTiles[x][y]->collidable*/)
            continue;

        if (!upperCollision) {
            w1 = (*yPos < (neighboringTiles[a]->y * TILE_H) + TILE_H && (*yPos > (neighboringTiles[a]->y * TILE_H)));
            w2 = (*xPos > (neighboringTiles[a]->x * TILE_W) - width &&
                  (*xPos < (neighboringTiles[a]->x * TILE_W) + TILE_W));
            upperCollision = w1 && w2;

            if (upperCollision) {
                //fprintf(stdout, "UPPER-SIDE TILE COLLISION \n");
                *ySpeed = 0;
                *yPos = (neighboringTiles[a]->y * TILE_H) + TILE_H;
            }

        } else {
            return true;
        }
    }

    return upperCollision;
}

//Collision from bottom side of the tile, with rectangle given by x,y, width and height.
bool Collisions::checkBottomCollision(MapTile *neighboringTiles[9], int *xPos, int *yPos, double *ySpeed, int width,
                                      int height) {

    bool bottomCollision = false;
    bool w1 = false;
    bool w2 = false;

    for (int a = 0; a < 9; a++) {
//        if (neighboringTiles[a] == 0 /*|| !mapTiles[x][y]->collidable*/)
//            continue;

        if (!bottomCollision) {
            w1 = (*xPos > (neighboringTiles[a]->x * TILE_W) - width * 0.75 &&
                  *xPos < (neighboringTiles[a]->x * TILE_W) + width * 0.75);
            w2 = (*yPos <= neighboringTiles[a]->y * TILE_H) && *yPos + height >= (neighboringTiles[a]->y * TILE_H);

            bottomCollision = w1 && w2;

            if (bottomCollision) {
                *ySpeed = 0;
                *yPos = (neighboringTiles[a]->y * TILE_H) - TILE_H;
            }
        } else
            return true;
    }

    return bottomCollision;
}

//Collision from left side of the tile, with rectangle given by x,y, width and height.
bool
Collisions::checkLeftCollision(MapTile *neighboringTiles[9], int *xPos, int *yPos, double *xSpeed, int width,
                               int height,
                               bool jumping) {


    bool leftCollision = false;
    bool gap = false;
    bool w1 = false;
    bool w2 = false;

    if (jumping) {
        if (neighboringTiles[1] == 0 && neighboringTiles[6] != 0 && neighboringTiles[8] != 0) {
//            gap = true;
//
            //            *xPos = (neighboringTiles[6]->x * TILE_W) - TILE_W + 1;
//            if (*yPos < (neighboringTiles[8]->y * TILE_H) - (TILE_H * 0.025) &&
//                *yPos > (neighboringTiles[6]->y * TILE_H) + (TILE_H * 0.975)){
//                fprintf(stdout, "GAP LEFT \n");
//                return false;
//            }
        }
    }

    for (int a = 0; a < 9; a++) {


//        if (neighboringTiles[a] == 0 /*|| !mapTiles[x][y]->collidable*/)
//            continue;

        if (!leftCollision) {


            //+1 is for enabling player to cross gaps between 2 tiles (upper tile, gap, lower tile)
//            if (gap && (a == 1 || a == 8 || a == 6)) {
//                w2 = (*xPos < (neighboringTiles[a]->x * TILE_W) - 0.75 * width &&
//                      (*xPos > (neighboringTiles[a]->x * TILE_W) - width + 0));
//                w1 = (*yPos > (neighboringTiles[a]->y * TILE_H) - height &&
//                      (*yPos < (neighboringTiles[a]->y * TILE_H) + TILE_H));
//
//            }
//            else {
            w2 = (*xPos < (neighboringTiles[a]->x * TILE_W) - 0.75 * width &&
                  (*xPos > (neighboringTiles[a]->x * TILE_W) - width));
            w1 = (*yPos > (neighboringTiles[a]->y * TILE_H) - height &&
                  (*yPos < (neighboringTiles[a]->y * TILE_H) + TILE_H));

//            }
            leftCollision = w1 && w2;

            if (leftCollision) {
                //fprintf(stdout, "LEFT-SIDE TILE COLLISION \n");
                *xSpeed = 0;
                fprintf(stdout, "X SPEED 0 \n");
//                if (gap /*&& (a == 1 || a == 8 || a == 6 || a == 4)*/)
//                    *xPos = (neighboringTiles[a]->x * TILE_W) - TILE_W + 1;
//                else
                *xPos = (neighboringTiles[a]->x * TILE_W) - TILE_W;
            }

        } else {
            fprintf(stdout, "ASDASD \n");
            return true;
        };
    }

    if (!leftCollision)
        fprintf(stdout, "\n");
    else
        fprintf(stdout, "ASDASD \n");

    return leftCollision;
}

//Collision from right side of the tile, with rectangle given by x,y, width and height.
bool Collisions::checkRightCollision(MapTile *neighboringTiles[9], int *xPos, int *yPos, double *xSpeed, int width,
                                     int height, bool jumping) {

    bool rightCollision = false;
    bool gap = false;
    bool w1 = false;
    bool w2 = false;
    if (jumping) {
//        if (neighboringTiles[0] == 0 && neighboringTiles[7] != 0 && neighboringTiles[5] != 0) {
//            gap = true;
//            *xPos = (neighboringTiles[0]->x * TILE_W) + TILE_W;
//
//            if (*yPos < (neighboringTiles[7]->y * TILE_H) - (TILE_H * 0.025) &&
//                *yPos > (neighboringTiles[5]->y * TILE_H) + (TILE_H * 0.975)){
//                fprintf(stdout, "   GAP RIGHT  \n");
//                return false;
//            }
//        }
    }

    for (int a = 0; a < 32; a++) {

//        if (neighboringTiles[a] == 0 /*|| !mapTiles[x][y]->collidable*/)
//            continue;

        if (!rightCollision) {


//            if (gap && a == 0) {
//                w2 = (*xPos + 0 < (neighboringTiles[a]->x * TILE_W) + width &&
//                      (*xPos > (neighboringTiles[a]->x * TILE_W) + 0.75 * width));
//
//                w1 = (*yPos > (neighboringTiles[a]->y * TILE_H) - height &&
//                      (*yPos < (neighboringTiles[a]->y * TILE_H) + TILE_H));
//            } else {
            w2 = (*xPos < (neighboringTiles[a]->x * TILE_W) + width &&
                  (*xPos > (neighboringTiles[a]->x * TILE_W) + 0.75 * width));

            w1 = (*yPos > (neighboringTiles[a]->y * TILE_H) - height &&
                  (*yPos < (neighboringTiles[a]->y * TILE_H) + TILE_H));
//            }

            rightCollision = w1 && w2;

            if (rightCollision) {
//                    //fprintf(stdout, "RIGHT-SIDE TILE COLLISION \n");
                *xSpeed = 0;
                fprintf(stdout, "X SPEED 0 \n");

                *xPos = (neighboringTiles[a]->x * TILE_W) + TILE_W;
            }

        } else {
            fprintf(stdout, "RIGHT COLLISION \n");
            return true;
        }
    }


    if(rightCollision)
        fprintf(stdout, "RIGHT COLLISION \n");
    else
        fprintf(stdout, "\n");


    return rightCollision;
}

bool Collisions::isStandingOnEdge(MapTile *neighboringTiles[9], int *xPos, int *yPos, double *xSpeed, int width,
                                  int height) {

    bool standingOnEdge = false;
    bool w0 = false;
    bool w1 = false;
    bool w2 = false;

    for (int a = 0; a < 32; a++) {

        if (neighboringTiles[a] == 0 /*|| !mapTiles[x][y]->collidable*/)
            continue;


        if (!standingOnEdge) {
            return false;
/*
                if (x < 32) {

                    w0 = mapTiles[x + 1][y] == 0;
                    w1 = (*yPos <= y * TILE_H) && *yPos + height >= (y * TILE_H);
                    w2 = (*xPos >= (x * TILE_W)) && (*xPos < (x * TILE_W) + TILE_W);
                    standingOnEdge = w0 && w1 && w2;

                    if (standingOnEdge) {
                        std::cout << "STANDING ON EDGE - RIGHT" << '\n';
                    }
                }

                if (x > 0) {

                    w0 = mapTiles[x - 1][y] == 0;
                    w1 = (*yPos <= y * TILE_H) && *yPos + height >= (y * TILE_H);
                    w2 = (*xPos <= (x * TILE_W)) && (*xPos > (x * TILE_W) - width);
                    standingOnEdge = w0 && w1 && w2;
                    if (standingOnEdge) {
                        std::cout << "STANDING ON EDGE - LEFT" << '\n';
                    }

                }*/


        } else
            return true;
    }
    return standingOnEdge;
}
