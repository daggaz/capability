/*
 * TestStrategyCommand.cpp
 *
 *  Created on: 24 Feb 2014
 *      Author: jcockburn
 */

#include "TestStrategyCommand.h"

TestStrategyCommand::TestStrategyCommand(string command) : command(command) {

}

const string& TestStrategyCommand::getCommand() const {
	return this->command;
}
