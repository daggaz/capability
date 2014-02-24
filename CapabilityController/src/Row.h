/*
 * Row.h
 *
 *  Created on: 24 Feb 2014
 *      Author: jcockburn
 */

#ifndef ROW_H_
#define ROW_H_

#include <vector>
#include <map>
#include "IStrategyControllable.h"
#include "ICapability.h"
#include "IStrategyCommandFactory.h"

using namespace std;

class Row {
public:
	IStrategyControllable& receiver;
	const map<const ICapability*, const IStrategyCommandFactory*>& capabilites;
	const vector<const IStrategyControllable*>& prerequisists;
	Row(IStrategyControllable& receiver, const map<const ICapability*, const IStrategyCommandFactory*>& capabilites, const vector<const IStrategyControllable*>& prerequisists);
};

#endif /* ROW_H_ */
