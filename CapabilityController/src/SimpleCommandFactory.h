/*
 * SimpleCommandFactory.h
 *
 *  Created on: 24 Feb 2014
 *      Author: jcockburn
 */

#ifndef SIMPLECOMMANDFACTORY_H_
#define SIMPLECOMMANDFACTORY_H_

#include "IStrategyCommandFactory.h"
#include "IStrategyCommand.h"
#include "IStrategyChangeParameters.h"
#include "ICapability.h"

class SimpleCommandFactory: public IStrategyCommandFactory {
private:
	const IStrategyCommand& command;
public:
	SimpleCommandFactory(const IStrategyCommand& command);
	const IStrategyCommand& getCommand(const ICapability& oldCapability, const ICapability& newCapability, const IStrategyChangeParameters& params) const;
};

#endif /* SIMPLECOMMANDFACTORY_H_ */
