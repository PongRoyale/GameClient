
#include "PongBallSprite.h"

#define BALL_RADIUS 10
#define WHITE 1

cocos2d::Sprite* createPongSprite(cocos2d::Vec2 position)
{

    auto pongNode = cocos2d::Sprite::create();

    cocos2d::Color4F white(WHITE, WHITE, WHITE, WHITE);
    auto drawNode = cocos2d::DrawNode::create();
    drawNode->drawDot(cocos2d::Vec2(0,0), BALL_RADIUS, white);

    pongNode->addChild(drawNode);

    pongNode->setPosition(position);
    auto body = cocos2d::PhysicsBody::createCircle(BALL_RADIUS);
    pongNode->setPhysicsBody(body);
    
    return pongNode;
}

