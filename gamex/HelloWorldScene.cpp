#pragma warning(disable:4251)
#include "HelloWorldScene.h"
#include "AppMacros.h"

USING_NS_CC;


CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    CCLabelTTF* pLabel = CCLabelTTF::create("WORD WORD", "Arial", TITLE_FONT_SIZE);
	pLabel->setColor(ccRED);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    // add the sprite as a child to this layer
	CCRect rect1(133, 333, 42, 46);
	CCScale9Sprite* btnNormal = CCScale9Sprite::create("char_bluelight.png",rect1);  
	CCScale9Sprite* btnDown = CCScale9Sprite::create("char_bluelight.png",rect1);  
	CCControlButton* controlBtn = CCControlButton::create(btnNormal);  
	controlBtn->setBackgroundSpriteForState(btnDown, CCControlStateSelected);  
	controlBtn->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));  
	controlBtn->setPreferredSize(CCSize(60, 50));  
	controlBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(HelloWorld::touchDownAction), CCControlEventTouchDown);
	this->addChild(controlBtn);  
    return true;
}

void HelloWorld::touchDownAction(CCObject* pSender, CCControlEvent event)
{
	int aaa = 0;
	++aaa;
}
void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
