/*
 * TestStrategyChangeParameters.h
 *
 *  Created on: 24 Feb 2014
 *      Author: jcockburn
 */

#ifndef TESTSTRATEGYCHANGEPARAMETERS_H_
#define TESTSTRATEGYCHANGEPARAMETERS_H_

#include "../IStrategyChangeParameters.h"
#include "BarBased/IChangeAtParameters.h"

class TestStrategyChangeParameters : public IChangeAtParameters, public IStrategyChangeParameters {
private:
	const ChangeAt& changeAt;
public:
	TestStrategyChangeParameters(const ChangeAt& changeAt);
	const ChangeAt& getChangeAt() const;
};

#endif /* TESTSTRATEGYCHANGEPARAMETERS_H_ */
