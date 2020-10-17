
#include "PaddleSprite.h"

#define PADDLE_WIDTH 100
#define PADDLE_HEIGHT 10
#define WHITE 1

cocos2d::Sprite* createPaddleSprite(cocos2d::Vec2 position) 
{
    auto paddle = cocos2d::Sprite::create();

    auto rectNode = cocos2d::DrawNode::create();

    cocos2d::Vec2 rectangle[4];
    rectangle[0] = cocos2d::Vec2(0, 0);
    rectangle[1] = cocos2d::Vec2(PADDLE_WIDTH, 0);
    rectangle[2] = cocos2d::Vec2(PADDLE_WIDTH, PADDLE_HEIGHT);
    rectangle[3] = cocos2d::Vec2(0, PADDLE_HEIGHT);
    
    cocos2d::Color4F white(WHITE, WHITE, WHITE, WHITE);
    rectNode->drawPolygon(rectangle, 4, white, 1, white);

    paddle->addChild(rectNode);

    paddle->setPosition(position);
    auto body = cocos2d::PhysicsBody::createBox(cocos2d::Size(PADDLE_WIDTH, PADDLE_HEIGHT));
    paddle->setPhysicsBody(body);
    
    return paddle;
}
