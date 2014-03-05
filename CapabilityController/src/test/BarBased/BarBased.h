/*
 * TestStrategyControllable.h
 *
 *  Created on: 24 Feb 2014
 *      Author: jcockburn
 */

#ifndef BARBASED_H_
#define BARBASED_H_

#include "../TestStrategyControllable.h"

using namespace std;

class BarBased : public TestStrategyControllable {
protected:
	virtual bool doChangeStrategy(const StrategyChangeEvent* event);
public:
	BarBased(string name);
};

#endif /* BARBASED_H_ */
