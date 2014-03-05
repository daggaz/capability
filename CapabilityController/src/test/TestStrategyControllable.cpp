/*
 * TestStrategyControllable.cpp
 *
 *  Created on: 24 Feb 2014
 *      Author: jcockburn
 */

#include <iostream>

#include "TestStrategyControllable.h"
#include "TestStrategyCommand.h"

using namespace std;

TestStrategyControllable::TestStrategyControllable(string name) : name(name) {

}

void TestStrategyControllable::changeStrategy(const IStrategyCommand& command, const IStrategyChangeParameters& params, const Row* responseObject, Queue<const Row*>& responseQueue)
{
	queue.push(new StrategyChangeEvent(command, params, responseObject, responseQueue));
}

void TestStrategyControllable::run() {
	cout << toString() <<": starting" << endl;
	while (true) {
		const StrategyChangeEvent* event = queue.pop();
		bool shutdown = doChangeStrategy(event);
		delete event;
		if (shutdown)
			break;
	}
	cout << toString() <<": SHUTDOWN" << endl;
}

bool TestStrategyControllable::doChangeStrategy(const StrategyChangeEvent* event)
{
	const TestStrategyCommand& command = dynamic_cast<const TestStrategyCommand&>(event->command);
	cout << name << ": changing strategy to \"" << command.getCommand() << "\"" << endl;
	Thread::sleep(3000 + (rand() % 2000));
	cout << name << ": strategy changed " << endl;
	event->responseQueue.push(event->responseObject);
	if (command.getCommand() == "Shutdown")
		return true;
	return false;
}

string TestStrategyControllable::toString() const {
	return name;
}


StrategyChangeEvent::StrategyChangeEvent(const IStrategyCommand& command, const IStrategyChangeParameters& params, const Row* responseObject, Queue<const Row*>& responseQueue) :
		command(command), params(params), responseObject(responseObject), responseQueue(responseQueue)
{
}
