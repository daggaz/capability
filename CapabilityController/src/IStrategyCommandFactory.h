/*
 * IStrategyCommandFactory.h
 *
 *  Created on: 24 Feb 2014
 *      Author: jcockburn
 */

#ifndef ISTRATEGYCOMMANDFACTORY_H_
#define ISTRATEGYCOMMANDFACTORY_H_

#include "ICapability.h"
#include "IStrategyChangeParameters.h"
#include "IStrategyCommand.h"

class IStrategyCommandFactory {
public:
	virtual const IStrategyCommand& getCommand(const ICapability& oldCapability, const ICapability& newCapability, const IStrategyChangeParameters& params) const = 0;
};

#endif /* ISTRATEGYCOMMANDFACTORY_H_ */
