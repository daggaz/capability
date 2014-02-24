/*
 * ICapability.h
 *
 *  Created on: 24 Feb 2014
 *      Author: jcockburn
 */

#ifndef ICAPABILITY_H_
#define ICAPABILITY_H_

#include <string>

using namespace std;


class ICapability {
public:
	virtual string toString() const = 0;
};

#endif /* ICAPABILITY_H_ */
