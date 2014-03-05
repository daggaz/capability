/*
 * TestStrategyControllable.cpp
 *
 *  Created on: 24 Feb 2014
 *      Author: jcockburn
 */

#include <iostream>

#include "BarBased.h"
#include "IChangeAtParameters.h"

using namespace std;

BarBased::BarBased(string name) : TestStrategyControllable(name)
{
}

bool BarBased::doChangeStrategy(const StrategyChangeEvent *event)
{
	static const ChangeAt defaultChangeAt(ChangeAt::IMMEDIATE);

	const IChangeAtParameters* changeAtParams = dynamic_cast<const IChangeAtParameters*>(&(event->params)); // We want a pointer here in case it doesn't cast
	const ChangeAt& changeAt = changeAtParams == NULL ? defaultChangeAt : changeAtParams->getChangeAt();

	cout << name << ": Waiting for " << changeAt.toString() << "..." << endl;
	switch (changeAt.getEvent())
	{
	case ChangeAt::END_OF_BAR:
		Thread::sleep(3000);
		break;
	case ChangeAt::END_OF_FRAME:
		Thread::sleep(7000);
		break;
	case ChangeAt::IMMEDIATE:
		break;
	}
	cout << name << ": " << changeAt.toString() << " reached!" << endl;

	return TestStrategyControllable::doChangeStrategy(event);
}
