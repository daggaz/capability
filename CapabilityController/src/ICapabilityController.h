/*
 * ICapabilityController.h
 *
 *  Created on: 24 Feb 2014
 *      Author: jcockburn
 */

#ifndef ICAPABILITYCONTROLLER_H_
#define ICAPABILITYCONTROLLER_H_

class ICapabilityController {
	virtual void changeCapability(const ICapability& capability, const IStrategyChangeParameters& params) = 0;
};

#endif /* ICAPABILITYCONTROLLER_H_ */
