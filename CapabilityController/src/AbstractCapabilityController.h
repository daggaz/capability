/*
 * AbstractCapabilityController.h
 *
 *  Created on: 24 Feb 2014
 *      Author: jcockburn
 */

#ifndef ABSTRACTCAPABILITYCONTROLLER_H_
#define ABSTRACTCAPABILITYCONTROLLER_H_

#include <vector>
using namespace std;

#include "Row.h"
#include "ICapability.h"
#include "Queue.h"
#include "ICapabilityController.h"

class AbstractCapabilityController : public ICapabilityController {
protected:
	const vector<const Row*>& table;
	const ICapability* currentCapabilty = NULL;
	Queue<const Row*> queue;
public:
	AbstractCapabilityController(const vector<const Row*>& table);
};


#endif /* ABSTRACTCAPABILITYCONTROLLER_H_ */
