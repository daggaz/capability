/*
 * SimpleCommandFactory.cpp
 *
 *  Created on: 24 Feb 2014
 *      Author: jcockburn
 */

#include "SimpleCommandFactory.h"

SimpleCommandFactory::SimpleCommandFactory(const IStrategyCommand& command) : command(command) {

}

const IStrategyCommand& SimpleCommandFactory::getCommand(const ICapability& oldCapability, const ICapability& newCapability, const IStrategyChangeParameters params) const {
	return command;
}
