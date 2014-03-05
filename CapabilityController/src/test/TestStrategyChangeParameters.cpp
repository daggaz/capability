/*
 * TestStrategyChangeParameters.cpp
 *
 *  Created on: 24 Feb 2014
 *      Author: jcockburn
 */

#include "TestStrategyChangeParameters.h"

TestStrategyChangeParameters::TestStrategyChangeParameters(const ChangeAt& changeAt) : changeAt(changeAt)
{
}

const ChangeAt& TestStrategyChangeParameters::getChangeAt() const
{
	return changeAt;
}
