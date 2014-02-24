/*
 * Row.cpp
 *
 *  Created on: 24 Feb 2014
 *      Author: jcockburn
 */

#include "Row.h"

Row::Row(IStrategyControllable& receiver, const map<const ICapability*, const IStrategyCommandFactory*>& capabilites, const vector<const IStrategyControllable*>& prerequisists)
		: receiver(receiver), capabilites(capabilites), prerequisists(prerequisists) {
}
