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
public:
	TestCapability(string name);
	const string& getName() const;
	virtual string toString() const;
};

#endif /* TESTCAPABILITY_H_ */
