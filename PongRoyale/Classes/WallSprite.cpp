
#include "WallSprite.h"

#define WALL_DEPTH 10

cocos2d::Sprite* createWallSprite(cocos2d::Vec2 position, cocos2d::Size screenSize,
            enum WallType type)
{

    float width;
    float height;
    
    if (type == UP || type == BOTTOM) {
        width = screenSize.width;
        height = WALL_DEPTH;
    } else {
        width = WALL_DEPTH;
        height = screenSize.height;
    }


    auto wall = cocos2d::Sprite::create();

    auto rectNode = cocos2d::DrawNode::create();

    cocos2d::Vec2 rectangle[4];
    rectangle[0] = cocos2d::Vec2(-width/2.0, -height/2.0);
    rectangle[1] = cocos2d::Vec2(width/2.0, -height/2.0);
    rectangle[2] = cocos2d::Vec2(width/2.0, height/2.0);
    rectangle[3] = cocos2d::Vec2(-width/2.0, height/2.0);
    
    cocos2d::Color4F white(1, 0, 0, 1);
    rectNode->drawPolygon(rectangle, 4, white, 1, white);

    wall->addChild(rectNode);

    wall->setPosition(position);

    auto body = cocos2d::PhysicsBody::createBox(cocos2d::Size(width, height));
    body->setDynamic(false);

    if (type == UP) {
        body->setCategoryBitmask(1<<3);
    } else if (type == LEFT) {
        body->setCategoryBitmask(1<<4);
    } else if (type == RIGHT) {
        body->setCategoryBitmask(1<<5);
    } else if (type == BOTTOM) {
        body->setCategoryBitmask(1<<6);
    }
        
    body->setContactTestBitmask(0x02);

    wall->setPhysicsBody(body);
    
    return wall;
}
