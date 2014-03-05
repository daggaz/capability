/*
 * TestCapability.h
 *
 *  Created on: 24 Feb 2014
 *      Author: jcockburn
 */

#ifndef TESTCAPABILITY_H_
#define TESTCAPABILITY_H_

#include <string>

using namespace std;

#include "../ICapability.h"

class TestCapability : public ICapability {
private:
	string name;
	TestCapability(string name);
public:
	const string& getName() const;
	virtual string toString() const;

	static TestCapability A;
	static TestCapability B;
	static TestCapability Shutdown;
};

#endif /* TESTCAPABILITY_H_ */
