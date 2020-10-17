/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "GameScene.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    Scene* scene = GameScene::createWithPhysics();

    scene->getPhysicsWorld()->setGravity(Vec2(0, 0));

    auto layer = GameScene::create();
    scene->addChild(layer);

    return scene;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in GameScene.cpp\n");
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // Add your paddle

    auto you = createPaddleSprite(
            cocos2d::Vec2((origin.x + visibleSize.width) / 2.0 - 50, 10));
    addChild(you);



    auto listener1 = cocos2d::EventListenerTouchOneByOne::create();
    listener1->onTouchBegan = [=](Touch* touch, Event* event){

        float dx = 75;
        if (touch->getLocation().x < visibleSize.width / 2 + origin.x) {
            dx = -dx;
        }

        auto moveBy = MoveBy::create(1, Vec2(dx, 0));
        you->runAction(RepeatForever::create(moveBy));

        return true; // if you are consuming it
    };

    // trigger when you let up
    listener1->onTouchEnded = [=](Touch* touch, Event* event){
        you->stopAllActions();
        return true;
    };

_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, this);

    // Add enemy paddles 

    auto enemy = createPaddleSprite(
            cocos2d::Vec2((origin.x + visibleSize.width) / 2.0 - 50, visibleSize.height - 20));
    addChild(enemy);

    // Add Pong Ball

    auto ball = createPongSprite(
            cocos2d::Vec2((origin.x + visibleSize.width) / 2.0 - origin.x, visibleSize.height / 2 + origin.y));
    addChild(ball);




    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the scene
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(GameScene::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);


    return true;
}


void GameScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    //Director::getInstance()->end();
    Director::getInstance()->popScene();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
