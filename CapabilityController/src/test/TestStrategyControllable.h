/*
 * TestStrategyControllable.h
 *
 *  Created on: 24 Feb 2014
 *      Author: jcockburn
 */

#ifndef TESTSTRATEGYCONTROLLABLE_H_
#define TESTSTRATEGYCONTROLLABLE_H_

#include "../IStrategyControllable.h"

#include <string>
#include "../Thread.h"
#include "../Queue.h"

using namespace std;

class StrategyChangeEvent {
public:
	const IStrategyCommand& command;
	const IStrategyChangeParameters& params;
	const Row* responseObject;
	Queue<const Row*>& responseQueue;

	StrategyChangeEvent(const IStrategyCommand& command, const IStrategyChangeParameters& params, const Row* responseObject, Queue<const Row*>& responseQueue);
};

class TestStrategyControllable : public IStrategyControllable, public Thread {
private:
	Queue<const StrategyChangeEvent*> queue;
protected:
	string name;
	virtual bool doChangeStrategy(const StrategyChangeEvent *event);
public:
	TestStrategyControllable(string name);
	virtual void changeStrategy(const IStrategyCommand& command, const IStrategyChangeParameters& params, const Row* responseObject, Queue<const Row*>& responseQueue);
	virtual string toString() const;
	void run();
};

#endif /* TESTSTRATEGYCONTROLLABLE_H_ */
