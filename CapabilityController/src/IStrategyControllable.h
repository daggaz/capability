/*
 * IStrategyControllable.h
 *
 *  Created on: 24 Feb 2014
 *      Author: jcockburn
 */

#ifndef ISTRATEGYCONTROLLABLE_H_
#define ISTRATEGYCONTROLLABLE_H_

#include <iostream>

#include "IStrategyCommand.h"
#include "IStrategyChangeParameters.h"
#include "Queue.h"

using namespace std;

class Row;


class IStrategyControllable {
public:
	virtual void changeStrategy(const IStrategyCommand& command, const IStrategyChangeParameters& params, const Row* responseObject, Queue<const Row*>& responseQueue) = 0;
	virtual string toString() const = 0;
};

#endif /* ISTRATEGYCONTROLLABLE_H_ */
