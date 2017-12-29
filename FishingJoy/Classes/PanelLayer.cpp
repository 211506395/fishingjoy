#include "PanelLayer.h"
#include "GameScene.h"
#include "ScheduleCountDown.h"

PanelLayer::PanelLayer(void)
{

}

PanelLayer::~PanelLayer(void)
{

}
bool PanelLayer::init()
{
	if(!CCLayer::init())
	{
		return false;
	}

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	_goldCounter = GoldCounterLayer::create(0);
	this->addChild(_goldCounter);
	_goldCounter->setPosition(ccp(650, 25));

	ScheduleCountDown* countDown = ScheduleCountDown::create(this);

	_scheduleLabel = CCLabelTTF::create("80", "Thonburi", 60);
	_scheduleLabel->setColor(ccc3(220,20,60));
	_scheduleLabel->addChild(countDown);
	this->addChild(_scheduleLabel);
	_scheduleLabel->setPosition(ccp(550,25));

    return true;
}

void PanelLayer::setScheduleNumber(int number)
{
	_scheduleLabel->setString(CCString::createWithFormat("%d",number)->getCString());
}

void PanelLayer::scheduleTimeUp()
{
	_scheduleLabel->setVisible(false);

	GameScene* gameScene = (GameScene*)this->getParent();
	gameScene->scheduleTimeUp();
}
