
#ifndef __WALL_SPRITE_H__
#define __WALL_SPRITE_H__

#include "cocos2d.h"

enum WallType {
    UP, RIGHT, LEFT, BOTTOM
};

cocos2d::Sprite* createWallSprite(cocos2d::Vec2 position, cocos2d::Size screenSize,
            enum WallType type);

#endif // __WALL_SPRITE_H__
