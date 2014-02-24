#ifndef CAPABILITYCONTROLLER_H_
#define CAPABILITYCONTROLLER_H_

#include "AbstractCapabilityController.h"

class CapabilityController : public AbstractCapabilityController {
public:
	CapabilityController(const vector<const Row*>& table);
	void changeCapability(const ICapability& capability, const IStrategyChangeParameters& params);
};

#endif
