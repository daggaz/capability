/*
 * TestStrategyCommand.h
 *
 *  Created on: 24 Feb 2014
 *      Author: jcockburn
 */

#ifndef TESTSTRATEGYCOMMAND_H_
#define TESTSTRATEGYCOMMAND_H_

#include <string>

using namespace std;

#include "../IStrategyCommand.h"

class TestStrategyCommand : public IStrategyCommand {
private:
	const string command;
public:
	TestStrategyCommand(string command);
	const string& getCommand() const;
};

#endif /* TESTSTRATEGYCOMMAND_H_ */
