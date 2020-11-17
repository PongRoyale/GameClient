
#include "PongBallSprite.h"

#define BALL_RADIUS 10
#define WHITE 1

cocos2d::Sprite* createPongSprite(cocos2d::Vec2 position)
{

    auto pongNode = cocos2d::Sprite::create();

    cocos2d::Color4F white(WHITE, WHITE, WHITE, WHITE);
    auto drawNode = cocos2d::DrawNode::create();
    drawNode->drawDot(cocos2d::Vec2(-5,-5), BALL_RADIUS, white);

    pongNode->addChild(drawNode);

    pongNode->setPosition(position);

    auto body = cocos2d::PhysicsBody::createCircle(BALL_RADIUS);
    body->setCategoryBitmask(0x02);
    //body->setCollisionBitmask(0x01);
    //body->setContactTestBitmask(0x01);
    body->setContactTestBitmask((1<<7) - 1 - 2);
    body->setVelocity(cocos2d::Vec2(10, -60));
    pongNode->setPhysicsBody(body);

    //auto moveBy = cocos2d::MoveBy::create(1, cocos2d::Vec2(10, -100.0));
    //pongNode->runAction(cocos2d::RepeatForever::create(moveBy));


    return pongNode;
}

