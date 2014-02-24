/*
 * TestCapability.cpp
 *
 *  Created on: 24 Feb 2014
 *      Author: jcockburn
 */

#include "TestCapability.h"


TestCapability::TestCapability(string name) : name(name) {

}

const string& TestCapability::getName() const {
	return this->name;
}

string TestCapability::toString() const {
	return getName();
}
